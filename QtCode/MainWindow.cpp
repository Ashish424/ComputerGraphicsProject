//
// Created by Ashish Aapan on 13/10/15.
//

#include "MainWindow.hpp"
#include "CGCanvas.hpp"
#include <QOpenGLContext>


MainWindow::~MainWindow() {
    QSurfaceFormat glFormat;
    glFormat.setVersion(4,1);
    glFormat.setProfile(QSurfaceFormat::CoreProfile);
    glFormat.setDefaultFormat(glFormat);
    glFormat.setSwapInterval(1);
}

MainWindow::MainWindow(QWidget *parent) {
    this->mainWindowGL = new CGCanvas(this);
    this->resize(640,480);
    this->setCentralWidget(mainWindowGL);
}