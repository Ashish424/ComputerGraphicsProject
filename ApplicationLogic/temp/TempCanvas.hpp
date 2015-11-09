//
// Created by Ashish Aapan on 09/11/15.
//

#ifndef CGPROJECT_TEMPCANVAS_HPP
#define CGPROJECT_TEMPCANVAS_HPP




#include <GL/glew.h>
#include <QOpenGLWidget>
#include <QTimer>
#include <opencv2/core/mat.hpp>
#include <ApplicationLogic/utils/PerlinNoise.hpp>
#include "ApplicationLogic/World.hpp"
#include "ApplicationLogic/Grid.hpp"


class TempCanvas : public QOpenGLWidget
{
 Q_OBJECT

 public:
  TempCanvas(QWidget *parent=0);
  ~TempCanvas();

 protected:
  void initializeGL();
  void resizeGL(int w, int h);
  void paintGL();

 private slots:
  void FixedUpdate();

 private:

  QTimer* timer;
  float timestep = 16;
  float slideAhead = 0;
  void setupGlew() const;
};


#endif //CGPROJECT_TEMPCANVAS_HPP
