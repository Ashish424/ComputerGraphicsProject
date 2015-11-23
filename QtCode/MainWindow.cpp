//
// Created by Priyanshu Singh on 22/11/15.
//

#include "MainWindow.hpp"
#include "ui_mainwindow.hpp"
#include "coastlinetab.hpp"

MainWindow::MainWindow(QWidget *parent) :
        QMainWindow(parent),
        ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tabWidget->addTab(new CoastLineTab(), "Coastline");
    ui->tabWidget->addTab(new CGCanvas,"CG");

}

MainWindow::~MainWindow()
{
    delete ui;
}
