//
// Created by Ashish Aapan on 09/11/15.
//

#include "TempCanvas.hpp"
#include <QDebug>
#include <opencv2/highgui.hpp>
//TODO diable these debug macros
#define DEBUG_CANVAS

#ifdef DEBUG_CANVAS
#include <QOpenGLContext>
#endif
TempCanvas::TempCanvas(QWidget *parent):QOpenGLWidget(parent)
{
  timer = new QTimer(this);
  QObject::connect(timer,SIGNAL(timeout()),this,SLOT(FixedUpdate()));
  timer->start(timestep);
}

TempCanvas::~TempCanvas()
{
}

void TempCanvas::resizeGL(int w, int h)
{
  glViewport(0,0,w,h);
  glOrtho(0,w,h,0,-1,1);
}

void TempCanvas::paintGL()
{

  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glEnable(GL_DEPTH_TEST);
// Accept fragment if it closer to the camera than the former one
  //TODO see less equal vs less
  glDepthFunc(GL_LEQUAL);




}


void TempCanvas::initializeGL()
{


  setupGlew();


  glOrtho(0,width(),height(),0,-1,1);
  glLoadIdentity();

#ifdef DEBUG_CANVAS
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


}
void TempCanvas::setupGlew() const {
  glewExperimental = GL_TRUE;
  if (glewInit() != GLEW_OK) {

    qWarning("Failed to initialize GLEW\n");
  }
}

void TempCanvas::FixedUpdate() {




  this->repaint();



}