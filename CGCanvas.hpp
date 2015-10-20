//
// Created by Ashish Aapan on 13/10/15.
//

#ifndef CGPROJECT_CGCANVAS_H
#define CGPROJECT_CGCANVAS_H

#include "glew.h"
#include <QOpenGLWidget>
#include <QTimer>

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
    float slideAhead = 0;



};


#endif //CGPROJECT_CGCANVAS_H
