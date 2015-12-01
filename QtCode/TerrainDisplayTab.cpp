//
// Created by Ashish Aapan on 22/11/15.
//

#include "TerrainDisplayTab.hpp"
#include "ui_terraindisplaytab.hpp"
#include "CGCanvas.hpp"

TerrainDisplayTab::TerrainDisplayTab(QWidget *parent) : QWidget(parent),
    ui(new Ui::TerrainDisplayTab)
{
    ui->setupUi(this);
    //ui->renderWidget = new CGCanvas();
    //ui->renderWidget->setFocus();
}

TerrainDisplayTab::~TerrainDisplayTab() {

}
