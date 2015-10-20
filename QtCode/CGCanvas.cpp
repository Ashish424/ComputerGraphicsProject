//
// Created by Ashish Aapan on 13/10/15.
//

#include "CGCanvas.hpp"
#include <QDebug>
#include <glm/glm.hpp>
#include <QSurfaceFormat>
#include <QOpenGLContext>
CGCanvas::CGCanvas(QWidget *parent):QOpenGLWidget(parent)
{
    QSurfaceFormat glFormat;
    glFormat.setVersion(4,1);
    glFormat.setProfile(QSurfaceFormat::CoreProfile);
    glFormat.setDefaultFormat(glFormat);
    glFormat.setSwapInterval(1);
    setFormat(glFormat);
    timer = new QTimer(this);
    QObject::connect(timer,SIGNAL(timeout()),this,SLOT(FixedUpdate()));
    timer->start(16);
}

CGCanvas::~CGCanvas()
{

//    delete g1;
//    delete terr;
}

void CGCanvas::resizeGL(int w, int h)
{
    glViewport(0,0,w,h);
    glOrtho(0,w,h,0,-1,1);
}

void CGCanvas::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


//TODO delete these comments
//    s1->Bind();
//    s1->Update(*trans1,*c1);
//    t1->Bind(0);
//    m1->Draw();
//    g1->draw();





}


void CGCanvas::initializeGL()
{


    glewExperimental = GL_TRUE;
    if (glewInit() != GLEW_OK) {

        //        qWarning("Failed to initialize GLEW\n");
    }

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
    glClearColor(0.0f,0.0f,1.0f,1.0f);





}

void CGCanvas::FixedUpdate() {


    slideAhead+=0.00016;
//    this->trans1->getM_pos().x = sinf(slideAhead*50);

    this->repaint();





}