#ifndef DRIVER_H
#define DRIVER_H

#include <QMainWindow>
#include "opencv2/opencv.hpp"
#include <opencv2/core/core.hpp>
#include <QDialog>

namespace Ui {
class driver;
}

class driver : public QMainWindow
{
    Q_OBJECT

public:
    explicit driver(QWidget *parent = 0);
    ~driver();

private:
    Ui::driver *ui;
    cv::VideoCapture cap;
    QImage qcam;
    QTimer* tmrTimer;
public slots:
    void showVideo();
};

#endif // DRIVER_H
