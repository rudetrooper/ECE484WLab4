#include "brightncontrast.h"
#include "ui_brightncontrast.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <QtGui>
#include <QtCore>
#include <QtNetwork>
#include <QFileDialog>
#include <QMessageBox>
#include <QPainter>
#include <QPoint>

using namespace std;

BrightNContrast::BrightNContrast(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::BrightNContrast)
{
    ui->setupUi(this);
}

BrightNContrast::~BrightNContrast()
{
    delete ui;
}
/*
 * Load Original image from filesystem
 */
void BrightNContrast::on_LoadOriginal_clicked()
{
    QString imagePath=QFileDialog::getOpenFileName(this, tr("Open File"), "", tr("BMP (*.bmp)"));
    imageObject = new QImage();
    imageObject->load(imagePath);
    image = QPixmap::fromImage(*imageObject);

    scene = new QGraphicsScene(this);
    //scene->addPixmap(image);
    scene->addPixmap(image.scaled(211,211)); //scale image preview to match viewer size
    scene->setSceneRect(image.rect());
    ui->OriginalView->setScene(scene);
}

/*
 * Load Overlay image from filesystem
 */
void BrightNContrast::on_LoadOverlay_clicked()
{
    QString imagePath=QFileDialog::getOpenFileName(this, tr("Open File"), "", tr("BMP (*.bmp)"));
    imageObjectOver = new QImage();
    imageObjectOver->load(imagePath);
    imageOver = QPixmap::fromImage(*imageObjectOver);

    scene = new QGraphicsScene(this);
    //scene->addPixmap(image);
    scene->addPixmap(imageOver.scaled(211,211)); //scale image preview to match viewer size
    scene->setSceneRect(imageOver.rect());
    ui->OverlayView->setScene(scene);
}

/*
 * Save generated image
 */
void BrightNContrast::on_pushButton_clicked()
{
    QFile f(QFileDialog::getSaveFileName() + ".bmp");
    f.open(QIODevice::WriteOnly);
    image.save(&f);
    f.close();
}
void BrightNContrast::on_BrightSlider_sliderReleased()
{
    // convert Contrast slider value to byte array for UDP
    // ternary operator used to check if slider value is less then 10
    // if so concatenate a '0'
    QByteArray contrast = (ui->ContrastSlider->value() < 10)?'0'+QByteArray::number(ui->ContrastSlider->value()):QByteArray::number(ui->ContrastSlider->value());
    // convert Bright slider value to byte array for UDP
    // ternary operator used to check if slider value is less then 10
    // if so concatenate a '0'
    QByteArray brightness = (ui->BrightSlider->value() < 10)?'0'+QByteArray::number(ui->BrightSlider->value()):QByteArray::number(ui->BrightSlider->value());
    //broadcastData(contrast+brightness);
}
void BrightNContrast::on_ContrastSlider_sliderReleased()
{
    // convert Contrast slider value to byte array for UDP
    // ternary operator used to check if slider value is less then 10
    // if so concatenate a '0'
    QByteArray contrast = (ui->ContrastSlider->value() < 10)?'0'+QByteArray::number(ui->ContrastSlider->value()):QByteArray::number(ui->ContrastSlider->value());
    // convert Bright slider value to byte array for UDP
    // ternary operator used to check if slider value is less then 10
    // if so concatenate a '0'
    QByteArray brightness = (ui->BrightSlider->value() < 10)?'0'+QByteArray::number(ui->BrightSlider->value()):QByteArray::number(ui->BrightSlider->value());
    //broadcastData(contrast+brightness);
}
/*
 * Send data using UDP protocol
 */
void BrightNContrast::broadcastData(QByteArray data)
{
    //create UDP socket
    udpSocket = new QUdpSocket(this);
    //pointer connects to socket,
    udpSocket->bind(QHostAddress("192.168.0.14"), 80);
    //send data to device using above IP and port num
    udpSocket->writeDatagram(data,QHostAddress("192.168.0.14"), 80);
}

/*
 * Send Image to FPGA using UDP protocol
 */
void BrightNContrast::SendImage(QImage *img){
    // Transform Image -> QByte Array
    QByteArray imb;
    QBuffer buffer(&imb);
    buffer.open(QIODevice::WriteOnly);
    // writes image to buffer in BMP format
    img->save(&buffer, "BMP");
    QByteArray * toSend = NULL;
    // for DEBUG: report back to user that image is sent
    qDebug()<< "size = " << img->byteCount() << " " << imb.size() << " " << buffer.size() << endl;
    // configure UDP packets to send only 1024 bytes
    // UDP socket buffer: 1024 bytes
    while (imb.size() > 1024){
        // extract 1024 lSB
        // delete contents of toSend array
        if (toSend != NULL) {
            delete toSend;
            toSend=NULL;
        }
        (toSend = (new QByteArray(imb)))->resize(1024);
        // send datagrams
        broadcastData(*toSend);
        // get rid of least significant 1024 bytes
        imb.remove(0,1024);
    }
    // send the last set of bytes ( <= 1024 bytes)
    broadcastData(imb);
}
/*
 * Transfer original image over UDP
 */
void BrightNContrast::on_TransferOriginal_clicked(){
    QByteArray array;
    char ch = '0';
    array.append(ch);
    broadcastData(array);
    // send image via UDP
    SendImage(imageObject);
    // for DEBUG: report back to user that image is sent
    qDebug()<< "done sending original image" << endl;
}

/*
 * Transfer overlay image over UDP
 */
void BrightNContrast::on_TransferOverlay_clicked(){
    QByteArray array;
    char ch = '1';
    array.append(ch);
    std::string imS = std::to_string(imageObjectOver->byteCount());
    char const *pchar = imS.c_str();
    array.append(pchar);
    broadcastData(array);
    // send image via UDP

    SendImage(imageObjectOver);
    // for DEBUG: report back to user that image is sent
    qDebug()<< "done sending overlay image" << endl;
}

/*
 * Closes the overlay displayed on the HPS screen
 */
void BrightNContrast::on_closeOverlay(){
    QByteArray array;
    char ch = (over) ? '2' :'3';
    array.append(ch);
    // send byte indicator
    broadcastData(array);
    // toggle overlay signal: so that user can choose whether to overlay or not
    // by pressing the button once or twice (as opposed to having 2 different buttons)
    over = !(over);
}

void BrightNContrast::on_BrightSlider_valueChanged(int position)
{
    QByteArray Contrast = (ui->ContrastSlider->value() < 10)?'0'+QByteArray::number(ui->ContrastSlider->value()): QByteArray::number(ui->ContrastSlider->value());
    QByteArray Brightness = (ui->BrightSlider->value() < 10)?'0'+QByteArray::number(ui->BrightSlider->value()): QByteArray::number(ui->BrightSlider->value());
    //broadcastData(Contrast+Brightness);
    int brightScale = 255/99;
    int brightChange = (position * brightScale);
    //int brightDecrease = (0-position) * brightScale;

    QColor brightValue;
    QImage im(*imageObject);
    im=im.convertToFormat(QImage::Format_Grayscale8);
    //im=im.scaled(1000,1000,Qt::IgnoreAspectRatio);
    //ui->BrightSlider->setRange(0,99);
    for(int i = 0; i < im.height(); i++)
    {
        for(int j = 0; j< im.width(); j++)
        {
            brightValue = imageObject->pixel(i,j);
            int r = brightValue.red()*brightChange/255*2;
            int g = brightValue.green()*brightChange/255*2;
            int b = brightValue.blue()*brightChange/255*2;

            if(r>=255)
            {
                r=255;
            }
            if(g>=255)
            {
                g=255;
            }
            if(b>=255)
            {
                b=255;
            }
            brightValue.setRgb(r,g,b,255);
            im.setPixelColor(i,j,brightValue);
        }
    }
    imageGen = QPixmap::fromImage(im);
    sceneGen = new QGraphicsScene(this);
    sceneGen->addPixmap(imageGen);
    sceneGen->setSceneRect(imageGen.rect());

    ui->GenerateView->setScene(sceneGen);

}

void BrightNContrast::on_ContrastSlider_valueChanged(int value)
{

    int Contrast = ui->ContrastSlider->value();
    QColor brightValue;
    QImage im(*imageObject);
    im=im.convertToFormat(QImage::Format_Grayscale8);
         QColor pixel;

         int picPixels = im.width()*im.height();                                            //total number of pixels in the image
         double pixProbr[255];
         double pixProbg[255];
         double pixProbb[255];
         double cumulProbr[255];
         double cumulProbg[255];
         double cumulProbb[255];
         int pixIntsCountr[255];
         int pixIntsCountg[255];
         int pixIntsCountb[255];
            for(int i=0;i<255;i++){                                                                     //fills arrays with 0's
                     pixProbr[i]=0;     pixProbg[i]=0;     pixProbb[i]=0;
                     cumulProbr[i]=0;   cumulProbg[i]=0;   cumulProbb[i]=0;
                     pixIntsCountr[i]=0;pixIntsCountg[i]=0;pixIntsCountb[i]=0;
                 }

         for(int x=0;x<im.height();x++){
            for(int y=0;y<im.width();y++){
               for(int j=0;j<255;j++)
               {
                if(im.pixelColor(x,y).red()==j)     {pixIntsCountr[j]++;}                            //finds the 'intensity' of the color and adds it at the matching array value
                if(im.pixelColor(x,y).green()==j)   {pixIntsCountg[j]++;}
                if(im.pixelColor(x,y).blue()==j)    {pixIntsCountb[j]++;}
               }
            }
         }
         for(int k=0;k<255;k++)                                                                         //finds the probability of each intensity from the number of times it occurs in the image
         {
             pixProbr[k]= static_cast<double>(pixIntsCountr[k]) / static_cast<double>(picPixels);
             pixProbg[k]= static_cast<double>(pixIntsCountg[k]) / static_cast<double>(picPixels);
             pixProbb[k]= static_cast<double>(pixIntsCountb[k]) / static_cast<double>(picPixels);
         }
         for(int l=0;l<255;l++)                                                                         //finds the cumulative probability of the previous proability array
         {
            cumulProbr[l+1]= static_cast<double>(pixProbr[l]) + static_cast<double>(cumulProbr[l]);
            cumulProbg[l+1]= static_cast<double>(pixProbg[l]) + static_cast<double>(cumulProbg[l]);
            cumulProbb[l+1]= static_cast<double>(pixProbb[l]) + static_cast<double>(cumulProbb[l]);
         }

         for(int y = 0;y<im.height();y++){
             for(int x = 0;x<im.width();x++){
                 for(int i=0;i<255;i++){
                     if(im.pixelColor(x,y).red()==i)
                     {
                        double rInt=(cumulProbr[i]*static_cast<double>(Contrast));                  // recalls the cumulative probability of the color and
                        double gInt=(cumulProbg[i]*static_cast<double>(Contrast));
                        double bInt=(cumulProbb[i]*static_cast<double>(Contrast));
                        if(rInt>255) {rInt=255;}
                        if(gInt>255) {gInt=255;}
                        if(bInt>255) {bInt=255;}
                         pixel.setRed(static_cast<int>(rInt));
                         pixel.setGreen(static_cast<int>(gInt));
                         pixel.setBlue(static_cast<int>(bInt));
                         im.setPixelColor(x,y,pixel);
                         break;
                     }
                 }
             }
         }

         imageGen = QPixmap::fromImage(im);
         sceneGen = new QGraphicsScene(this);
         sceneGen->addPixmap(imageGen);
         sceneGen->setSceneRect(imageGen.rect());
         ui->GenerateView->setScene(sceneGen);
}
