#include <GL/glew.h>
#include <iostream>
#include <QApplication>
#include <QSurfaceFormat>
#include <opencv2/core/mat.hpp>
#include <ApplicationLogic/Agents/MountainAgent.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <ApplicationLogic/Agents/CoastlineAgent.hpp>
#include <ApplicationLogic/utils/PerlinNoise.hpp>
#include "QtCode/MainWindow.hpp"
#include "ApplicationLogic/L-Systems/LSystem.hpp"
#include "ApplicationLogic/L-Systems/Turtle.hpp"
#define THRESHOLD 0
#define COAST_COLOR 100
void setContext();
void mountainSpace();
void TestingLsys();
void demoIslandSpace();


int main(int argc,char *argv[]) {
    using namespace std;

    QApplication app(argc, argv);
    setContext();
    //TestingLsys();

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
    // cvNamedWindow("Mountain Random", CV_WINDOW_AUTOSIZE);
    cv::imshow("Mountain Random",image);
    cv::waitKey(0);
    //MountainAgent::makeMountains(image, 255);
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
     //An array for the image
    int m_height = 1024;
    int m_width = 1024;
    cv::Mat im = cv::Mat::zeros(1024,1024,CV_8UC1);
    //CoastlineAgent *agent = new CoastlineAgent(m_width*m_height*2, &img, m_width, m_height, 0, m_width - 1, 0, m_height - 1);

    CoastlineAgent agent(m_height*m_width*2, m_height, m_width);
    CoastlineAgent::setThresholdValue(600);
    //std::memset(img.imageIntData, 0, sizeof(int)*m_height*m_width);
    agent.doWork();
//    for(int i=0; i<m_height; i++){
//        for(int j=0; j<m_width; j++){
//            if(img.imageIntData[i][j] > 0){
//                im.at<uchar>(i,j) = 255;
//            }
//            //std::printf("(%d,%d): %d | ",i,j,img.img[i][j]);
//        }
//    }
    im = agent.getImage();
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
    for(int i=0; i<m_height; i++){
        for(int j=0; j<m_width; j++){
            int a = im.at<uchar>(i, j);
            /*
             * Pixel values are multiplied
             * to the slope to stretch the low
             * value pixels
             */
            int slope =100;
            a *= slope;
            if( a > 255)a=255;
            a = (a > 0)?COAST_COLOR:0;
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
    cout << "Coastline Completed!!" << endl;
    cv::waitKey(0);

    ///////////////////////////////////////////////////////////////////////////////////

//    for(int i=0; i<im.rows; i++){
//        for(int j=0; j<im.cols; j++){
//            im.at<uchar>(i,j) = 255;
//        }
//    }
    cv::imshow("myWindow",im);
    cv::waitKey(0);
    cv::Mat org = im.clone();
    //TODO make mountain GUI
    MountainAgent mountainAgent(5000, im, std::make_pair(im.cols/2, im.rows/2),100);
    mountainAgent.doWork();
    cv::imshow("myWindow",im);
    cout << "Mountain Completed!!" << endl;
    cv::waitKey(0);

    //MountainAgent::makeMountains(im);
    cv::Mat temp,final;
    cv::distanceTransform(im, im, CV_DIST_L2, 3);
    cv::normalize(im, temp, 0, 1., cv::NORM_MINMAX);
    final = temp.clone();
    for(int i=0; i<temp.rows; i++){
        for(int j=0; j<temp.cols; j++){
            final.at<float>(i,j) /= 2.0f;
        }
    }
    im = org.clone();
    mountainAgent = MountainAgent(10000, im, std::make_pair(im.cols/2, im.rows/2),100);
    mountainAgent.doWork();
    cv::distanceTransform(im, im, CV_DIST_L2, 3);
    cv::normalize(im, temp, 0, 1., cv::NORM_MINMAX);
    for(int i=0; i<temp.rows; i++){
        for(int j=0; j<temp.cols; j++){
            final.at<float>(i,j) += temp.at<float>(i,j)/4.0f;
        }
    }
    im = org.clone();
    mountainAgent = MountainAgent(30000, im, std::make_pair(im.cols/2, im.rows/2),100);
    mountainAgent.doWork();
    cv::distanceTransform(im, im, CV_DIST_L2, 3);
    cv::normalize(im, temp, 0, 1., cv::NORM_MINMAX);
    for(int i=0; i<temp.rows; i++){
        for(int j=0; j<temp.cols; j++){
            final.at<float>(i,j) += temp.at<float>(i,j)/8.0f;
        }
    }
    im = org.clone();
    mountainAgent = MountainAgent(60000, im, std::make_pair(im.cols/2, im.rows/2),100);
    mountainAgent.doWork();
    cv::distanceTransform(im, im, CV_DIST_L2, 3);
    cv::normalize(im, temp, 0, 1., cv::NORM_MINMAX);
    for(int i=0; i<temp.rows; i++){
        for(int j=0; j<temp.cols; j++){
            final.at<float>(i,j) += temp.at<float>(i,j)/16.0f;
        }
    }
    im = org.clone();
    mountainAgent = MountainAgent(90000, im, std::make_pair(im.cols/2, im.rows/2),100);
    mountainAgent.doWork();
    cv::distanceTransform(im, im, CV_DIST_L2, 3);
    cv::normalize(im, temp, 0, 1., cv::NORM_MINMAX);
    for(int i=0; i<temp.rows; i++){
        for(int j=0; j<temp.cols; j++){
            final.at<float>(i,j) += temp.at<float>(i,j)/32.0f;
        }
    }

    im = final.clone();
    cv::imshow("myWindow",im);
    cv::waitKey(0);
//    for(int i=0; i<im.rows; i++){
//        for(int j=0; j<im.cols; j++){
//            im.at<float>(i,j)=1.0-im.at<float>(i,j);
//        }
//    }
    cv::imshow("myWindow",im);
    cv::waitKey(0);
    cv::Mat aa = cv::Mat::zeros(im.rows, im.cols, CV_8UC1);
    for(int i=0; i<aa.rows; i++){
        for(int j=0; j<aa.cols; j++){
            aa.at<uchar>(i,j) = (uchar) (im.at<float>(i, j) * 80)+60;
        }
    }
    PerlinNoise n(time(NULL));
    cv::Mat image = aa.clone();
//    for(int i=0; i<image.rows; i++){
//        for(int j=0; j< image.cols; j++){
//            //TODO have different falloff functions here
//            float ans = image.at<uchar>(i,j)/255.0;
//            float x = j;x/=image.cols;
//            float y = i;y/=image.rows;
//            for(int k=1; k<4; k++){
//                float f =  2*k + 5;
//                float a = 2*k*k + 3;
//                ans += 1/f*n.noise(x*a,y*a,0.8);
//            }
//            ans = std::min(ans,1.0f);
//            ans *= 255;
//            ans -= 20;
//            image.at<uchar>(i, j) = (uchar) ans;
//        }
//    }

    cout << "Mountain height map Completed!!" << endl;
    cv::imshow("myWindow",image);
    cv::waitKey(0);
    cv::imwrite("./Assets/demo.png", image);


    //TODO make beach agent
    //TODO try to add ambient occlusion
}