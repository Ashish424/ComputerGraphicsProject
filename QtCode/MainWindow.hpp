//
// Created by Priyanshu Singh on 22/11/15.
//

#ifndef CGPROJECT_MAINWINDOW_HPP
#define CGPROJECT_MAINWINDOW_HPP

#include <QMainWindow>
#include "CGCanvas.hpp"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

};


#endif //CGPROJECT_MAINWINDOW_HPP
