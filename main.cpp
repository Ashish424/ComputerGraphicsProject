#include <GL/glew.h>
#include <iostream>
#include <QApplication>
#include <QSurfaceFormat>
#include <opencv2/core/mat.hpp>
#include <ApplicationLogic/Agents/MountainAgent.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include "QtCode/MainWindow.hpp"
#include "ApplicationLogic/L-Systems/LSystem.hpp"
#include "ApplicationLogic/L-Systems/Turtle.hpp"

void setContext();
void mountainSpace();
void TestingLsys();

int main(int argc,char *argv[]) {
    using namespace std;

    QApplication app(argc, argv);
    setContext();
    TestingLsys();


//    mountainSpace();

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

void TestingLsys(){

    TerrainDemo::Rules r1;
    r1["F"] = "F[-F]F[+F][F]";

    TerrainDemo::LSystem l1("F",r1);
    std::shared_ptr<std::string> gen = l1.getLSysString(1,false);
    printf("the generated string is  %s\n",gen->c_str());

    TerrainDemo::Turtle t1(gen,glm::vec4(0.0,0.0,0.0,1.0),glm::vec3(0.0,1.0,0.0));



}