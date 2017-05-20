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
        cap.open("rtsp://sdsuparking:aztecs@192.168.1.6:8000");
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
    bool bSuccess = cap.read(cam); // read a new frame from video
    if (!bSuccess) { //if not success, break loop
       cout << "Cannot read a frame from video stream" << endl;
    }
    QImage qcam((uchar*)cam.data, cam.cols, cam.rows, cam.step, QImage::Format_RGB888);
    ui->lbl_vid->setPixmap(QPixmap::fromImage(qcam));
}
