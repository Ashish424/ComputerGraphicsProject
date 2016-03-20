//
// Created by Ashish Aapan on 22/11/15.
//

#include <ApplicationLogic/utils/InputManager.hpp>
#include "TerrainDisplayTab.hpp"
#include "ui_terraindisplaytab.hpp"
#include "CGCanvas.hpp"

TerrainDisplayTab::TerrainDisplayTab(QWidget *parent) : QWidget(parent),
    ui(new Ui::TerrainDisplayTab)
{
    ui->setupUi(this);
    //ui->renderWidget = new CGCanvas();
    //ui->renderWidget->setFocus();
    //connect(ui->wireframeCheckBox_3, SIGNAL(toggled(bool)), ui->renderWidget->getTerrain(), SLOT(setDrawMode(bool)));
    ui->adaptTessCheckBox_3->setChecked(true);
    connect(ui->wireframeCheckBox_3, SIGNAL(clicked(bool)), this, SLOT(setMode(bool)));
    connect(ui->adaptTessCheckBox_3, SIGNAL(clicked(bool)), ui->fixedTessQSlider_3, SLOT(setDisabled(bool)));
    connect(ui->adaptTessCheckBox_3, SIGNAL(clicked(bool)), ui->maxTessSpinBox_3, SLOT(setEnabled(bool)));
    connect(ui->adaptTessCheckBox_3, SIGNAL(clicked(bool)), ui->minTessSpinBox_3, SLOT(setEnabled(bool)));
    connect(ui->maxDepthQSlider_3, SIGNAL(valueChanged(int)), this, SLOT(setTerrainHeight(int)));
    connect(ui->fixedTessQSlider_3, SIGNAL(valueChanged(int)), this, SLOT(setFixedTessellation(int)));
    connect(ui->adaptTessCheckBox_3, SIGNAL(clicked(bool)), this, SLOT(setAdaptTessellation(bool)));
    connect(ui->maxTessSpinBox_3, SIGNAL(valueChanged(double)), this, SLOT(setMaxTessLevel(double)));
    connect(ui->minTessSpinBox_3, SIGNAL(valueChanged(double)), this, SLOT(setMinTessLevel(double)));
}

TerrainDisplayTab::~TerrainDisplayTab() {

}
void TerrainDisplayTab::setMode(bool b) {
    InputManager::setTerrainDrawMode(b);
}
void TerrainDisplayTab::setTerrainHeight(int i) {
    InputManager::setTerrainDepth(i+1);
}
void TerrainDisplayTab::setFixedTessellation(int i) {
    InputManager::setFixedTessLevel((float)i/10.0f + 1.0f);
}
void TerrainDisplayTab::setAdaptTessellation(bool b) {
    InputManager::setGetIsCam((b)?0.75f:0.25f);
}
void TerrainDisplayTab::setMinTessLevel(double d) {
    InputManager::setMinTessLevel(d+1);
}
void TerrainDisplayTab::setMaxTessLevel(double d) {
    InputManager::setMaxTesslevel(d+1);
}
void TerrainDisplayTab::setMatImage(cv::Mat images) {
    InputManager::setUpdatedHeightMap(images);
}
