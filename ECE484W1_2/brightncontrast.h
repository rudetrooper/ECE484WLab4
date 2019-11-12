#ifndef BRIGHTNCONTRAST_H
#define BRIGHTNCONTRAST_H
#include <QtNetwork>
#include <QMainWindow>
#include <QGraphicsScene>

class QUdpSocket;
namespace Ui {
class BrightNContrast;
}

class BrightNContrast : public QMainWindow
{
    Q_OBJECT

public:
    explicit BrightNContrast(QWidget *parent = nullptr);
    ~BrightNContrast();
    // Broadcast slider values over UDP
    void broadcastData(QByteArray data);

private slots:
    // load original image
    void on_LoadOriginal_clicked();    
    // load overlay image
    void on_LoadOverlay_clicked();
    // save generated image locally
    void on_pushButton_clicked();
    // transfer original image to FPGA over virtual RS-232 interface
    void on_TransferOriginal_clicked();
    // transfer overlay image to FPGA over virtual RS-232 interface
    void on_TransferOverlay_clicked();
     void on_closeOverlay();
    // listens for brightness slider value
    void on_BrightSlider_sliderReleased();
    // listens for contrast slider value
    void on_ContrastSlider_sliderReleased();

    void on_BrightSlider_valueChanged(int position);

    void on_ContrastSlider_valueChanged(int value);
    void SendImage(QImage *img);

private:
    Ui::BrightNContrast *ui;
    bool over;
    QPixmap image;
    QPixmap imageOver;
    QPixmap imageGen;
    QImage *imageObject;
    QImage *imageObjectOver;
    QImage *imageObjectGen;
    QUdpSocket *udpSocket=nullptr;
    QGraphicsScene *scene;
    QGraphicsScene *sceneGen;
};

#endif // BRIGHTNCONTRAST_H
