#include "driver.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    driver w;
    w.show();
    printf("SDSU PARKING APP TEST\n\n");

    return a.exec();
}
