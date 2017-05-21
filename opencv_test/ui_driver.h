/********************************************************************************
** Form generated from reading UI file 'driver.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DRIVER_H
#define UI_DRIVER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_driver
{
public:
    QWidget *centralWidget;
    QLabel *lbl_vid;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *driver)
    {
        if (driver->objectName().isEmpty())
            driver->setObjectName(QStringLiteral("driver"));
        driver->resize(719, 449);
        centralWidget = new QWidget(driver);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        lbl_vid = new QLabel(centralWidget);
        lbl_vid->setObjectName(QStringLiteral("lbl_vid"));
        lbl_vid->setGeometry(QRect(40, 20, 640, 360));
        lbl_vid->setAutoFillBackground(true);
        driver->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(driver);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 719, 22));
        driver->setMenuBar(menuBar);
        mainToolBar = new QToolBar(driver);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        driver->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(driver);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        driver->setStatusBar(statusBar);

        retranslateUi(driver);

        QMetaObject::connectSlotsByName(driver);
    } // setupUi

    void retranslateUi(QMainWindow *driver)
    {
        driver->setWindowTitle(QApplication::translate("driver", "driver", Q_NULLPTR));
        lbl_vid->setText(QApplication::translate("driver", "Video", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class driver: public Ui_driver {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DRIVER_H
