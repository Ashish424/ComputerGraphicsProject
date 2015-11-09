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



#include <ApplicationLogic/L-Systems/Plant.hpp>
#include "ApplicationLogic/World.hpp"
#include "ApplicationLogic/Grid.hpp"
#include <QPushButton>

class TerrainDemo_Shader;
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
  void clickedNext();

 private:

  QTimer* timer;
  float timestep = 16;
  float slideAhead = 0;
  void setupGlew() const;
  //TODO remove this temp method

  TerrainDemo::Plant * plant;
  TerrainDemo::Shader* shad;
  QPushButton * nextButton;
  int NextPlant;


};


#endif //CGPROJECT_TEMPCANVAS_HPP
