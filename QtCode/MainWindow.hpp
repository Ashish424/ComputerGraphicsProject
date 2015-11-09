//
// Created by Ashish Aapan on 13/10/15.
//

#ifndef CGPROJECT_MAINWINDOW_H
#define CGPROJECT_MAINWINDOW_H


#include <QMainWindow>

class CGCanvas;
class TempCanvas;
class QStackedWidget;
class MainWindow:public QMainWindow {

    void keyPressEvent(QKeyEvent *keyEvent) override;

public:
    explicit MainWindow(QWidget *parent=nullptr);

//non extendable destructor is non-virtual
    ~MainWindow();
    QStackedWidget *OperationStackedWidget;
    CGCanvas *mainWindowGL;
    TempCanvas *tempWindowGL;
  //selects the mainWindow or tempwindow
    int SetCurrent;

};


#endif //CGPROJECT_MAINWINDOW_H
