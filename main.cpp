#include <GL/glew.h>
#include <iostream>
#include <QApplication>
#include <QSurfaceFormat>
#include <opencv2/core/mat.hpp>
#include <ApplicationLogic/Agents/MountainAgent.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <ApplicationLogic/Agents/CoastlineAgent.hpp>
#include "QtCode/MainWindow.hpp"
#include "ApplicationLogic/L-Systems/LSystem.hpp"
#include "ApplicationLogic/L-Systems/Turtle.hpp"

void setContext();
void mountainSpace();
void TestingLsys();
void demoIslandSpace();


int main(int argc,char *argv[]) {
    using namespace std;

    QApplication app(argc, argv);
    setContext();
    TestingLsys();

    //demoIslandSpace();
    //mountainSpace();

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


}

using namespace std;
void demoIslandSpace(){

    std::string imgOutput = "/Users/tgz/Desktop/CoastLine.jpg";
    std::string rawOutput = "/Users/tgz/Desktop/rawOutput.jpg";

    //Driver
    srandom(time(NULL));
    Data img; //An array for the image
    int m_height = 4096;
    int m_width = 4096;
    cv::Mat im = cv::Mat::zeros(4096,4096,CV_8UC1);
    CoastlineAgent *agent = new CoastlineAgent(m_width*m_height*2, &img, m_width, m_height, 0, m_width - 1, 0, m_height - 1);
    std::memset(img.imageIntData, 0, sizeof(int)*m_height*m_width);
    agent->doWork();
    for(int i=0; i<1024; i++){
        for(int j=0; j<1024; j++){
            if(img.imageIntData[i][j] > 0){
                im.at<uchar>(i,j) = 255;
            }
            //std::printf("(%d,%d): %d | ",i,j,img.img[i][j]);
        }
    }
    cv::imwrite(rawOutput.c_str(),im);


    /*
     * Here, by commenting gaussianBlur and uncommenting blur
     * will make a smooth but an island with less feature.
     *
     * Uncommenting both will make bigger island.
     */
    cv::GaussianBlur(im, im, cv::Size(121,121),1.5,1.5);
    //cv::blur(im,im,cv::Size(31,31));


    cv::blur(im , im, cv::Size(3,3));
    /*
     * Contrast stretching and equalizeHist are both doing same
     * thing but with different goals, contrast stretching keeps
     * almost all the information provided by the above code
     * where as equalizeHist will change the values of pixel of
     * image to make its histogram equal..
     * Though I prefer contrast stretching as the information
     * is preserved.
     */
    for(int i=0; i<1024; i++){
        for(int j=0; j<1024; j++){
            int a = im.at<uchar>(i, j);
            /*
             * Pixel values are multiplied
             * to the slope to stretch the low
             * value pixels
             */
            int slope = 30;
            a *= slope;
            if( a > 255)a=255;
            im.at<uchar>(i, j) = (uchar)a;
            //std::printf("(%d,%d): %d | ",i,j,img.img[i][j]);
        }
    }
    //cv::GaussianBlur(im, im, cv::Size(3,3),1.5,1.5);
    //cv::equalizeHist(im, im);

    /*
     * median Blur is used to smooth the contour regions without
     * disturbing the edges
     */
    cv::medianBlur(im , im, 31);

    cv::imwrite(imgOutput.c_str(),im);
    cv::imshow("myWindow",im);
    cout << "Hello, World!" << endl;
}