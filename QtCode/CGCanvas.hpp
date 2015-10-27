//
// Created by Ashish Aapan on 13/10/15.
//

#ifndef CGPROJECT_CGCANVAS_H
#define CGPROJECT_CGCANVAS_H

#include <GL/glew.h>
#include <QOpenGLWidget>
#include <QTimer>
#include "ApplicationLogic/World.hpp"
#include "ApplicationLogic/Grid.hpp"


class CGCanvas : public QOpenGLWidget
{
    Q_OBJECT

public:
    CGCanvas(QWidget *parent=0);
    ~CGCanvas();
//    void printContextInformation();

    // QOpenGLWidget interface
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
    TerrainDemo::World* world;


  void setupGlew() const;
};


#endif //CGPROJECT_CGCANVAS_H
