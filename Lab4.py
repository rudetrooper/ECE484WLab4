#!/usr/bin/env python
# -*- coding: utf-8 -*-
#
#  Lab4.py
#  

import os
import io
from PIL import Image
import cv2
import numpy as np
import socket
import logging
import time
import sys # for terminal input
import netifaces as ni

#Server Info: need IP address and port
ni.ifaddresses('eth0')
UDP_IP = ni.ifaddresses('eth0')[ni.AF_INET][0]['addr']
#UDP_IP = "192.168.0.14"
UDP_PORT = 80
# Display an image
def displayImage(img_show):
	try:
		# Display image on window "FullScreen"
		cv2.imshow('FullScreen', img_show)
		# wait 1 ms
		cv2.waitKey(1)
	# if an exception occurs print exception
	except Exception as e:
		print(str(e))
#function that computes min and max pixel values of an image
def compute_min_max (img1):
	max = img1[0,0]
	min = img1[0,0]
	# loop through all pixels to find
	# min and max
	for i in range(img1.shape[0]):
		for j in range(img1.shape[1]):
			# min computation
			if img1[i,j] < min:
				min = img1[i,j]
			# max computation
			if img1[i,j] > max:
				max= img1[i,j]
	return (min,max)
	
#function that modifies both the contrast and
# brightness of the image: done so that
# only one for loop is used to adjust both
def mod_cr_br(img1,s1,s2,position_c,position_b):
	# code to measure time this computation takes
	start_time = time.time()
	# multiplier setup for brightness adjustment
	if(position_b < 50):
		# decrease brightness
		# map position to a multiplier value [0.02,1]
		multiplier = float(position_b) / 50.0
	else:
		# increase brightness
		# map position to a multiplier value [1,10]
		multiplier = (position_b-50)*0.18 +1
	# contrast adjustment
	# case 1: compress brightness histogram (lower contrast)
	if(position_c < 50):
		# determine compression number: how much
		#the brightness histogram will be compressed on each side
		compress_num = float(s2-s1) * 0.4
		# determine 50 levels of compression: when position_c is 50:
		# no compression, when position is 0 : very high compression
		compress_fact = compress_num / 50.0
		new_position= 50 - position_c
		# determine to what values [t1, t2] to compress based on slider position
		t1 = int(float(s1) + compress_fact * float(new_position))
		t2= int(float(s2) - compress_fact * float(new_position))
		# case 2: stretch brightness histogram (higher contrast)
	else:
		# determine 50 levels of stretch on each side of brightness histogram
		stretch_s1 = float(s1)/50.0
		stretch_s2 = float(255-s2)/50.0
		new_position = position_c - 50
		# determine to what values [t1, t2] to stretch based on slider position
		t1 = int(s1 - (stretch_s1 * float(new_position)))
		t2 = int(s2 + (stretch_s2 * float(new_position)))
	# compress or stretch brightness histogram:
	# go from distribution [s1, s2] -> [t1, t2]
	# linear stretching formula: f(pixel) = a*pixel + b
	# calc a and b for formula
	a = (1.0*float(t2-t1) )/ float(s2-s1)
	b= float(t1) - (float(s1)*a)
	# modify image
	for i in range(img1.shape[0]):
		for j in range(img1.shape[1]):
			# contrast adjustment
			img1[i,j] = min(img1[i,j]*a +b,255)
			# brightness adjustment
			img1[i,j] = min(img1[i,j]*multiplier,255)
	print ("Time taken: ",time.time() - start_time)

# Function overlays an image over the original image
def overlayOp(origImg, ovImg, ovPos=(0,0)):
	# Resizes the image, so that it's smaller than original
	ovImg=cv2.resize(ovImg, (50, 50))
	#.shape accesses the sizes of the images.
	y1, x1= ovImg.shape
	y2, x2= origImg.shape
	#position of the overlay
	y3, x3 = ovPos[0], ovPos[0]
	#operations for blending the two images into one image
	for i in range(y1):
		for j in range(x1):
		# make sure overlay does not go out of range of original image dimensions
			if x3+i >= x2 or y3+j >= y2:
				continue
		# To perform overlay, replace the original image's pixels
		# with pixels of the overlay image at the specified postion
		origImg[x3+i][y3+j]=ovImg[i][j]
	return origImg

# UDP socket Setup
sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
sock.bind((UDP_IP, UDP_PORT))
# UDP Server Listener
print("READY")

# define this image since it is to be accessed later
image_orig = None
# needed display configuration
os.system('export DISPLAY=":0"')
# configure image to show on Full Screen
cv2.namedWindow("FullScreen", cv2.WINDOW_NORMAL)
cv2.setWindowProperty("FullScreen",cv2.WND_PROP_FULLSCREEN, cv2.cv.CV_WINDOW_FULLSCREEN)
#initialize min and max to be used later
s1 = 0
s2 = 255
# infinite loop for program execution
while (True):
	#receive a byte of data that indicates the latter operation
	c=''
	while (c==''):
		c = sock.recv(1)
		print(c)
	# read first character of data and decide what to do based upon it
	# action for showing the original image
	if(c == '0'):
		dSize = sock.recv(6)
		print(dSize)
		print("original image")
		# size of original image
		data_s = dSize
		#data_s = 263222
		b=""
		# keep receiving data from socket in chunks to read all bytes of image
		while data_s > 0:
			data = sock.recv(data_s)
			# data concatenation
			b+=data
			# feedback to receive less data
			data_s = data_s - len(data)
		# let user know image is received
		print("Done")
		# convert image bytes to readable "BMP" image
		image = Image.open(io.BytesIO(b)).convert("L")
		# code left to resize image
		# image can be resized (lower resolution) if command line arguments are
		# passed to the program
		if (len(sys.argv)>1):
			size = int(sys.argv[1]),int(sys.argv[1])
			image = image.resize(size,Image.ANTIALIAS)
		# make copies of original image
		image_orig = np.array(image.copy())
		img_display = np.array(image.copy())
		# find the min and max of image pixel distribution
		# to be used for contrast adjustment
		s1,s2 = compute_min_max(image_orig)
		# display newly loaded image
		displayImage(img_display)

	# receive overlay
	elif (c == '1'):
		print("overlay image")
		# size of overlay to be received
		dSize = sock.recv(6)
		print(dSize)
		data_s = dSize #308278
		b=""
		# Receiving image data packets
		while data_s > 0:
			data = sock.recv(data_s)
			b+=data
			data_s = data_s - len(data)
		# convert image bytes to readable "BMP" image
		image2 = Image.open(io.BytesIO(b)).convert("L")
		# save overlay image in a file
		img2 = np.array(image2)
		cv2.imwrite('overlay.bmp',img2)
		# let user know it's successful
		print("Overlay Image Received")
	# Display modified overlay over original image
	elif (c== '2'):
		# read overlay image
		img_overlay = cv2.imread('overlay.bmp',0)
		# get modified overlaid image
		img_display = overlayOp(image_orig.copy(), img_overlay,(100,100))
		# display result
		displayImage(img_display)
		# let user know overlay is ON
		print ("Overlay ON")
	# discard overlay action
	elif (c=='3'):
		img_display = image_orig.copy()
		# let user know overlay is OFF
		print ("Overlay OFF")
		# display original image
		displayImage(img_display)
	# slider values action
	elif (c == '4'):
		try:
			# receive slider values (4 bytes)
			slider_values = ""
			slider_values = sock.recv(4)
			# continually receive slider data until all data packets have been recieved
			while (len(slider_values) < 4):
				slider_values = sock.recv(4)
			# convert each slider value into an integer
			position_b = (int)(slider_values[2])*10+(int)(slider_values[3])
			position_c = (int)(slider_values[0])*10+(int)(slider_values[1])
			# call function to modify brightness and contrast
			img_display = image_orig.copy()
			mod_cr_br(img_display,s1,s2,position_c,position_b)
			# display result
			displayImage(img_display)
		# code executed in case of an exception
		except Exception as e:
			print("Wrong with slider value ",str(e))
	else:
		pass
