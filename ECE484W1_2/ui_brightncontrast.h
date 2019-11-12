/********************************************************************************
** Form generated from reading UI file 'brightncontrast.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BRIGHTNCONTRAST_H
#define UI_BRIGHTNCONTRAST_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BrightNContrast
{
public:
    QWidget *centralWidget;
    QGraphicsView *OriginalView;
    QGraphicsView *OverlayView;
    QPushButton *LoadOriginal;
    QSlider *BrightSlider;
    QSlider *ContrastSlider;
    QLabel *brightness;
    QLabel *contrast;
    QPushButton *TransferOriginal;
    QGraphicsView *GenerateView;
    QLabel *Overlay;
    QLabel *Generated;
    QPushButton *LoadOverlay;
    QLabel *Original;
    QPushButton *pushButton;
    QPushButton *TransferOverlay;
    QPushButton *pushButton_2;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *BrightNContrast)
    {
        if (BrightNContrast->objectName().isEmpty())
            BrightNContrast->setObjectName(QStringLiteral("BrightNContrast"));
        BrightNContrast->resize(695, 526);
        centralWidget = new QWidget(BrightNContrast);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        OriginalView = new QGraphicsView(centralWidget);
        OriginalView->setObjectName(QStringLiteral("OriginalView"));
        OriginalView->setGeometry(QRect(20, 20, 211, 211));
        OverlayView = new QGraphicsView(centralWidget);
        OverlayView->setObjectName(QStringLiteral("OverlayView"));
        OverlayView->setGeometry(QRect(459, 20, 211, 211));
        OverlayView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        OverlayView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        LoadOriginal = new QPushButton(centralWidget);
        LoadOriginal->setObjectName(QStringLiteral("LoadOriginal"));
        LoadOriginal->setGeometry(QRect(60, 260, 121, 32));
        BrightSlider = new QSlider(centralWidget);
        BrightSlider->setObjectName(QStringLiteral("BrightSlider"));
        BrightSlider->setGeometry(QRect(280, 30, 22, 181));
        BrightSlider->setOrientation(Qt::Vertical);
        ContrastSlider = new QSlider(centralWidget);
        ContrastSlider->setObjectName(QStringLiteral("ContrastSlider"));
        ContrastSlider->setGeometry(QRect(350, 30, 22, 181));
        ContrastSlider->setOrientation(Qt::Vertical);
        brightness = new QLabel(centralWidget);
        brightness->setObjectName(QStringLiteral("brightness"));
        brightness->setGeometry(QRect(250, 220, 81, 16));
        contrast = new QLabel(centralWidget);
        contrast->setObjectName(QStringLiteral("contrast"));
        contrast->setGeometry(QRect(340, 220, 59, 16));
        TransferOriginal = new QPushButton(centralWidget);
        TransferOriginal->setObjectName(QStringLiteral("TransferOriginal"));
        TransferOriginal->setGeometry(QRect(200, 260, 171, 31));
        GenerateView = new QGraphicsView(centralWidget);
        GenerateView->setObjectName(QStringLiteral("GenerateView"));
        GenerateView->setGeometry(QRect(459, 260, 211, 201));
        Overlay = new QLabel(centralWidget);
        Overlay->setObjectName(QStringLiteral("Overlay"));
        Overlay->setGeometry(QRect(530, 0, 71, 16));
        Generated = new QLabel(centralWidget);
        Generated->setObjectName(QStringLiteral("Generated"));
        Generated->setGeometry(QRect(520, 240, 81, 20));
        LoadOverlay = new QPushButton(centralWidget);
        LoadOverlay->setObjectName(QStringLiteral("LoadOverlay"));
        LoadOverlay->setGeometry(QRect(60, 300, 121, 32));
        Original = new QLabel(centralWidget);
        Original->setObjectName(QStringLiteral("Original"));
        Original->setGeometry(QRect(90, 0, 67, 17));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(60, 380, 121, 31));
        TransferOverlay = new QPushButton(centralWidget);
        TransferOverlay->setObjectName(QStringLiteral("TransferOverlay"));
        TransferOverlay->setGeometry(QRect(200, 300, 171, 31));
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(60, 340, 121, 31));
        BrightNContrast->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(BrightNContrast);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 695, 22));
        BrightNContrast->setMenuBar(menuBar);
        mainToolBar = new QToolBar(BrightNContrast);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        BrightNContrast->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(BrightNContrast);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        BrightNContrast->setStatusBar(statusBar);

        retranslateUi(BrightNContrast);

        QMetaObject::connectSlotsByName(BrightNContrast);
    } // setupUi

    void retranslateUi(QMainWindow *BrightNContrast)
    {
        BrightNContrast->setWindowTitle(QApplication::translate("BrightNContrast", "BrightNContrast", Q_NULLPTR));
        LoadOriginal->setText(QApplication::translate("BrightNContrast", "Load Original", Q_NULLPTR));
        brightness->setText(QApplication::translate("BrightNContrast", "Brightness", Q_NULLPTR));
        contrast->setText(QApplication::translate("BrightNContrast", "Contrast", Q_NULLPTR));
        TransferOriginal->setText(QApplication::translate("BrightNContrast", "Transfer test image", Q_NULLPTR));
        Overlay->setText(QApplication::translate("BrightNContrast", "Overlay", Q_NULLPTR));
        Generated->setText(QApplication::translate("BrightNContrast", "Generated", Q_NULLPTR));
        LoadOverlay->setText(QApplication::translate("BrightNContrast", "Load Overlay", Q_NULLPTR));
        Original->setText(QApplication::translate("BrightNContrast", "Original", Q_NULLPTR));
        pushButton->setText(QApplication::translate("BrightNContrast", "Save Image", Q_NULLPTR));
        TransferOverlay->setText(QApplication::translate("BrightNContrast", "Transfer overflow image", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("BrightNContrast", "Close Overlay", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class BrightNContrast: public Ui_BrightNContrast {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BRIGHTNCONTRAST_H
