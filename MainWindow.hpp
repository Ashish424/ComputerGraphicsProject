//
// Created by Ashish Aapan on 13/10/15.
//

#ifndef CGPROJECT_MAINWINDOW_H
#define CGPROJECT_MAINWINDOW_H


#include <QMainWindow>

class CGCanvas;
class MainWindow:public QMainWindow {
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent=nullptr);

//non extendable destructor is non-virtual
    ~MainWindow();
    CGCanvas *mainWindowGL;

};


#endif //CGPROJECT_MAINWINDOW_H
