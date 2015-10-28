//
// Created by Ashish Aapan on 13/10/15.
//

#include "CGCanvas.hpp"
#include <QDebug>
#include <glm/glm.hpp>
#include <QSurfaceFormat>
#include <QOpenGLContext>
#include <opencv2/highgui.hpp>

CGCanvas::CGCanvas(QWidget *parent):QOpenGLWidget(parent)
{
    timer = new QTimer(this);
    QObject::connect(timer,SIGNAL(timeout()),this,SLOT(FixedUpdate()));
    timer->start(timestep);
}

CGCanvas::~CGCanvas()
{
delete world;

}

void CGCanvas::resizeGL(int w, int h)
{
    glViewport(0,0,w,h);
    glOrtho(0,w,h,0,-1,1);
}

void CGCanvas::paintGL()
{

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST);
// Accept fragment if it closer to the camera than the former one
    glDepthFunc(GL_LESS);





    world->update();

}


void CGCanvas::initializeGL()
{


    setupGlew();


    glOrtho(0,width(),height(),0,-1,1);
    glLoadIdentity();

    QOpenGLContext *cont = context();
    qDebug() << "Context valid: " << cont->isValid();
    qDebug() << "Really used OpenGl: " << cont->format().majorVersion() << "." << cont->format().minorVersion();
    qDebug() << "OpenGl information: VENDOR:       " << (const char*)glGetString(GL_VENDOR);
    qDebug() << "                    RENDERDER:    " << (const char*)glGetString(GL_RENDERER);
    qDebug() << "                    VERSION:      " << (const char*)glGetString(GL_VERSION);
    qDebug() << "                    GLSL VERSION: " << (const char*)glGetString(GL_SHADING_LANGUAGE_VERSION);
    qDebug() << "endstuff\n";
    glClearColor(0.0f,0.0f,0.0f,1.0f);

    world = new TerrainDemo::World(width(), height(), timestep);
    glm::vec3 pos = glm::vec3(0.0,0.0,0.0);
    glm::vec3 scale  = glm::vec3(1.0,1.0,1.0);
    glm::vec3 rot = glm::vec3(0.0,0.0,0.0);


    TransformData t1(pos,rot,scale);
    long long seed = (int) time(NULL);
    pnoise[0] = PerlinNoise(seed);
    seed = (seed*33331 + 1001)%1000000007;
    pnoise[1] = PerlinNoise(seed);
    seed = (seed*33331 + 1001)%1000000007;
    pnoise[2] = PerlinNoise(seed);
    seed = (seed*33331 + 1001)%1000000007;
    pnoise[3] = PerlinNoise(seed);
    img = cv::Mat::zeros(300,300,CV_8UC1);
    tt=0.1;
    for(int i=0; i<img.rows; ++i){
        for(int j=0; j<img.cols; ++j){
            double x = (double)j/((double)img.cols);
            double y = (double)i/((double)img.rows);
            long double n = 0;
            for(int k=0; k<4;++k){
                n += (1.0/(3*k+1.0))*pnoise[k].noise((2*k+7)*x,(2*k+7)*y,tt);
            }
            img.at<uchar>(i,j) = (uchar) floor(n*255);
        }
    }
    cv::imshow("PerlinNoise",img);
}
void CGCanvas::setupGlew() const {
    glewExperimental = GL_TRUE;
    if (glewInit() != GLEW_OK) {

        qWarning("Failed to initialize GLEW\n");
    }
}

void CGCanvas::FixedUpdate() {




    tt+=0.1;
    for(int i=0; i<img.rows; ++i){
        for(int j=0; j<img.cols; ++j){
            double x = (double)j/((double)img.cols);
            double y = (double)i/((double)img.rows);
            //scale here multiply by a bigger no.
            long double n = 0;
            for(int k=0; k<4;++k){
                n += (1.0/(3*k+2.0))*pnoise[k].noise((3*k+2)*x,(3*k+2)*y,tt);
            }
            img.at<uchar>(i,j) = (uchar) floor(n*255);
        }
    }
    cv::imshow("PerlinNoise",img);
    slideAhead+=0.00016;

    this->repaint();



}