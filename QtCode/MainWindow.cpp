//
// Created by Ashish Aapan on 13/10/15.
//

#include "MainWindow.hpp"
#include "CGCanvas.hpp"
#include <QOpenGLContext>
#include <QStackedWidget>
//TODO remove this header
#include "ApplicationLogic/temp/TempCanvas.hpp"



MainWindow::~MainWindow() {
    QSurfaceFormat glFormat;
    glFormat.setVersion(4,1);
    glFormat.setProfile(QSurfaceFormat::CoreProfile);
    glFormat.setDefaultFormat(glFormat);
    glFormat.setSwapInterval(1);
}

MainWindow::MainWindow(QWidget *parent) {



    this->resize(640,480);

    //create stacked widget
    OperationStackedWidget = new QStackedWidget(this);
    this->setCentralWidget(OperationStackedWidget);

    //add stuff to stack widget
    OperationStackedWidget->setObjectName(QStringLiteral("OperationStackedWidget"));
    OperationStackedWidget->setGeometry(QRect(620, 90, 191, 171));
    this->mainWindowGL = new CGCanvas(OperationStackedWidget);
    this->tempWindowGL = new TempCanvas(OperationStackedWidget);

    OperationStackedWidget->addWidget(mainWindowGL);
    OperationStackedWidget->addWidget(tempWindowGL);




}