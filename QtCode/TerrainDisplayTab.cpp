//
// Created by Ashish Aapan on 22/11/15.
//

#include "TerrainDisplayTab.hpp"
#include "ui_terraindisplaytab.hpp"
TerrainDisplayTab::TerrainDisplayTab(QWidget *parent) : QWidget(parent),
    ui(new Ui::CoastLineTab)
{
    ui->setupUi(this);
}

CoastLineTab::~CoastLineTab()
{
    delete ui;
}