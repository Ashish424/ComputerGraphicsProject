#include <iostream>
#include <QApplication>

#include "QtCode/MainWindow.hpp"

int main(int argc,char *argv[]) {
    using namespace std;

    QApplication app(argc,argv);
    MainWindow w;
    w.show();
//    FindDialog* f1 = new FindDialog;
//    f1->show();

//    cout << "Hello, World!" << endl;
    return app.exec();

}