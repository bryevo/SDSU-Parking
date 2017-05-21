#include "driver.h"
#include "ui_driver.h"
#include "opencv2/opencv.hpp"
#include <opencv2/core/core.hpp>
#include <QtCore>

using namespace std;
using namespace cv;
driver::driver(QWidget *parent) : QMainWindow(parent), ui(new Ui::driver) {
    ui->setupUi(this);
    try {
        cap.open("/Users/brye/Desktop/PS12 Front 547PM.MP4");
        if (!cap.isOpened()) {  // if not success, exit program
        cout << "Cannot open the video cam" << endl;
        }
        double width = cap.get(CV_CAP_PROP_FRAME_WIDTH); //get the width of frames of the video
        double height = cap.get(CV_CAP_PROP_FRAME_HEIGHT); //get the height of frames of the video
        cout << "Frame size : " << width << " x " << height << endl;
        } catch (exception &e) {
            cout << e.what() << endl;
        }
    tmrTimer = new QTimer(this);
    connect(tmrTimer, SIGNAL(timeout()), this, SLOT(showVideo()));
    tmrTimer->start(0);
}

driver::~driver()
{
    delete ui;
}

void driver::showVideo() {
    Mat cam;
    cap >> cam;
    cv::resize(cam, cam, Size(640, 360), 0, 0, INTER_CUBIC);
    QImage qcam((uchar*) cam.data, cam.cols, cam.rows, static_cast<int>(cam.step), QImage::Format_RGB888);   //RBG values are inverted
    ui->lbl_vid->setPixmap(QPixmap::fromImage(qcam.rgbSwapped()));
}
