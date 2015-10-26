#include <iostream>
#include <QApplication>
#include <QSurfaceFormat>
#include "QtCode/MainWindow.hpp"


void setContext();
int main(int argc,char *argv[]) {
    using namespace std;

  QApplication app(argc, argv);
  setContext();


    MainWindow w;
    w.show();
//    FindDialog* f1 = new FindDialog;
//    f1->show();

//    cout << "Hello, World!" << endl;
    return app.exec();

}


void setContext(){

  QSurfaceFormat format;
  format.setVersion(4, 1);
  format.setProfile(QSurfaceFormat::CoreProfile);
//  format.setDepthBufferSize(24);
//  format.setStencilBufferSize(8);
  format.setSwapInterval(1);
  QSurfaceFormat::setDefaultFormat(format);

}