//
// Created by Priyanshu Singh on 22/11/15.
//

#include "MainWindow.hpp"
#include "ui_mainwindow.hpp"
#include "coastlinetab.hpp"
#include "CGCanvas.hpp"
#include "MountainTab.hpp"
#include "TerrainDisplayTab.hpp"

MainWindow::MainWindow(QWidget *parent) :
        QMainWindow(parent),
        ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    CoastLineTab* coastLineTab = new CoastLineTab();
    MountainTab* mountainTab = new MountainTab();
    ui->tabWidget->addTab(coastLineTab, "Coastline");
    ui->tabWidget->addTab(mountainTab, "Mountain");
    ui->tabWidget->addTab(new TerrainDisplayTab(), "CGCanvas");

    connect(coastLineTab, SIGNAL(coastlineImageChanged(cv::Mat)), mountainTab, SLOT(setChangedImage(cv::Mat)));
}

MainWindow::~MainWindow()
{
    delete ui;
}
