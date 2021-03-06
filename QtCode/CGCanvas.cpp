//
// Created by Ashish Aapan on 13/10/15.
//

#include "CGCanvas.hpp"

#include <QKeyEvent>
#include <QDebug>
#include "ApplicationLogic/utils/InputManager.hpp"
#include <opencv2/highgui.hpp>
//TODO diable these debug macros
#define DEBUG_TEMP




#ifdef DEBUG_TEMP
#include <QOpenGLContext>
#endif
CGCanvas::CGCanvas(QWidget *parent):QOpenGLWidget(parent)
{
    timer = new QTimer(this);
    QObject::connect(timer,SIGNAL(timeout()),this,SLOT(FixedUpdate()));
    timer->start(timestep);
    setFocusPolicy(Qt::FocusPolicy::ClickFocus);
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
    //TODO see less equal vs less
    glDepthFunc(GL_LEQUAL);





    world->update();

}


void CGCanvas::initializeGL()
{


    setupGlew();


    glOrtho(0,width(),height(),0,-1,1);
    glLoadIdentity();

#ifdef DEBUG_TEMP
    QOpenGLContext *cont = context();
    qDebug() << "Context valid: " << cont->isValid();
    qDebug() << "Really used OpenGl: " << cont->format().majorVersion() << "." << cont->format().minorVersion();
    qDebug() << "OpenGl information: VENDOR:       " << (const char*)glGetString(GL_VENDOR);
    qDebug() << "                    RENDERDER:    " << (const char*)glGetString(GL_RENDERER);
    qDebug() << "                    VERSION:      " << (const char*)glGetString(GL_VERSION);
    qDebug() << "                    GLSL VERSION: " << (const char*)glGetString(GL_SHADING_LANGUAGE_VERSION);
    qDebug() << "endstuff\n";
#endif
    glClearColor(0.0f,0.0f,0.0f,1.0f);

    world = new TerrainDemo::World(width(), height(), timestep);
//    glm::vec3 pos = glm::vec3(0.0,0.0,0.0);
//    glm::vec3 scale  = glm::vec3(1.0,1.0,1.0);
//    glm::vec3 rot = glm::vec3(0.0,0.0,0.0);


//    TransformData t1(pos,rot,scale);
//    pnoise = PerlinNoise(time(NULL));
//    img = cv::Mat::zeros(300,300,CV_8UC1);
//    tt=0.1;
//    for(int i=0; i<img.rows; ++i){
//        for(int j=0; j<img.cols; ++j){
//            double x = (double)j/((double)img.cols);
//            double y = (double)i/((double)img.rows);
//            double n = pnoise.noise(x,y,tt);
//            img.at<uchar>(i,j) = (uchar) floor(n*255);
//        }
//    }
//    cv::imshow("PerlinNoise",img);
}
void CGCanvas::setupGlew() const {
    glewExperimental = GL_TRUE;
    if (glewInit() != GLEW_OK) {

        qWarning("Failed to initialize GLEW\n");
    }
}

void CGCanvas::FixedUpdate() {


//
//    tt+=0.01;
//    for(int i=0; i<img.rows; ++i){
//        for(int j=0; j<img.cols; ++j){
//            double x = (double)j/((double)img.cols);
//            double y = (double)i/((double)img.rows);
//            //scale here multiply by a bigger no.
//            double n = pnoise.noise(25*x,25*y,tt);
//            img.at<uchar>(i,j) = (uchar) floor(n*255);
//        }
//    }
    //cv::imshow("PerlinNoise",img);
    slideAhead+=0.00016;

    this->repaint();



}

void CGCanvas::keyPressEvent(QKeyEvent *event) {
    QWidget::keyPressEvent(event);
    if(event->key() == Qt::Key::Key_W)InputManager::setKey(InputManager::KEYS::W, true);
    else if(event->key() == Qt::Key::Key_S)InputManager::setKey(InputManager::KEYS::S, true);
    else if(event->key() == Qt::Key::Key_A)InputManager::setKey(InputManager::KEYS::A, true);
    else if(event->key() == Qt::Key::Key_D)InputManager::setKey(InputManager::KEYS::D, true);

}

void CGCanvas::keyReleaseEvent(QKeyEvent *event) {
    QWidget::keyReleaseEvent(event);
    if(event->key() == Qt::Key::Key_W)InputManager::setKey(InputManager::KEYS::W, false);
    else if(event->key() == Qt::Key::Key_S)InputManager::setKey(InputManager::KEYS::S, false);
    else if(event->key() == Qt::Key::Key_A)InputManager::setKey(InputManager::KEYS::A, false);
    else if(event->key() == Qt::Key::Key_D)InputManager::setKey(InputManager::KEYS::D, false);

}


void CGCanvas::mousePressEvent(QMouseEvent *ev) {
    QWidget::mousePressEvent(ev);
    InputManager::setMousePressed(true);
    InputManager::setMouseCoords(glm::vec2(ev->localPos().x(), ev->localPos().y()),glm::vec2(width(),height()));



}
void CGCanvas::mouseReleaseEvent(QMouseEvent *ev) {
    QWidget::mouseReleaseEvent(ev);
    InputManager::setMousePressed(false);
    InputManager::setMouseMoved(false);


}
void CGCanvas::mouseMoveEvent(QMouseEvent *ev) {
    QWidget::mouseMoveEvent(ev);
    InputManager::setMousePressed(false);
    InputManager::setMouseMoved(true);
    InputManager::setMouseCoords(glm::vec2(ev->localPos().x(), ev->localPos().y()),glm::vec2(width(),height()));


}
TerrainDemo::Terrain *CGCanvas::getTerrain() {
    return world->getCuurentTerrain();
}
