#include <GL/glew.h>
#include <iostream>
#include <QApplication>
#include <QSurfaceFormat>
#include <opencv2/core/mat.hpp>
#include <ApplicationLogic/Agents/MountainAgent.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include "QtCode/MainWindow.hpp"


void setContext();
void mountainSpace();

int main(int argc,char *argv[]) {
    using namespace std;

    QApplication app(argc, argv);
    setContext();

    mountainSpace();

    MainWindow w;
    w.show();
//    FindDialog* f1 = new FindDialog;
//    f1->show();

//    cout << "Hello, World!" << endl;
    return app.exec();

}


void setContext(){

    QSurfaceFormat format;
    format.setVersion(4, 1);
    format.setProfile(QSurfaceFormat::CoreProfile);
//  format.setDepthBufferSize(24);
//  format.setStencilBufferSize(8);
    format.setSwapInterval(1);
    QSurfaceFormat::setDefaultFormat(format);

}

void mountainSpace(){
    cv::Mat image = cv::Mat::zeros(700, 700, CV_8UC1);
    MountainAgent agent(2000, image, std::make_pair(350, 350),100);
    agent.doWork();
    cv::imshow("Mountain Random",image);
    cv::waitKey(1);
    MountainAgent::makeMountains(image, 255);
    cv::imshow("Mountain Random",image);
    return;
}