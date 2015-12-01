//
// Created by Priyanshu Singh on 01/12/15.
//

#include <opencv2/imgproc.hpp>
#include <iostream>
#include "MountainTab.hpp"
#include "ui_mountaintab.hpp"
#define MAX_LEVEL 10
MountainTab::MountainTab(QWidget *parent) :
        QWidget(parent),tokenValue(1),outputWidth(480),outputHeight(640),
        ui(new Ui::MountainTab)
{
    ui->setupUi(this);

    connect(ui->degraderQSlider, SIGNAL(valueChanged(int)), this, SLOT(setSpinBox(int)));
    connect(ui->degraderSpinBox, SIGNAL(valueChanged(double)), this, SLOT(setSlider(double)));
    connect(ui->LevelQSlider, SIGNAL(valueChanged(int)), this, SLOT(applyChanges()));
    connect(ui->degraderQSlider, SIGNAL(valueChanged(int)), this, SLOT(applyChanges()));
    connect(ui->tokenMultiQSpinBox, SIGNAL(valueChanged(int)), this, SLOT(generate()));
    connect(ui->m_generateBtn, SIGNAL(released()), this, SLOT(generate()));
    connect(ui->m_tokenSpinBox, SIGNAL(valueChanged(int)), this, SLOT(setTokenValue()));
    connect(ui->distanceSpinBox, SIGNAL(valueChanged(int)), this, SLOT(setDistanceToChangeDirection()));
    connect(ui->startingPointSpinBoxY, SIGNAL(valueChanged(int)), this, SLOT(setStartingPoint()));
    connect(ui->startingPointSpinBoxX, SIGNAL(valueChanged(int)), this, SLOT(setStartingPoint()));

}

MountainTab::~MountainTab()
{
    delete ui;
}

void MountainTab::setTokenValue() {
    tokenValue = ui->m_tokenSpinBox->value();
}

void MountainTab::setStartingPoint() {
    startingPoint = std::make_pair(ui->startingPointSpinBoxX->value(),
                                    ui->startingPointSpinBoxY->value());
}

void MountainTab::setDistanceToChangeDirection() {
    distToChangeDirection = ui->distanceSpinBox->value();
}

void MountainTab::commputeMatVector() {
    if(originalImage.empty())return;
    outputImage = originalImage.clone();
    agent = new MountainAgent(tokenValue, outputImage, startingPoint, distToChangeDirection);
    agent->doWork();
    images.clear();
    MountainAgent::makeMountains(outputImage);
    images.push_back(outputImage);
    delete agent;
    int maxLevel = ui->LevelQSlider->maximum();
    int tok = tokenValue;
    for(int i=0; i<maxLevel-1; i++){
        cv::Mat im = originalImage.clone();
        int multi = ui->tokenMultiQSpinBox->value();
        tok += tokenValue*multi;
        agent = new MountainAgent(tok ,im ,std::make_pair(0,0), distToChangeDirection);
        agent->doWork();
        MountainAgent::makeMountains(im);
        images.push_back(im);
        delete agent;
    }
}

void MountainTab::setChangedImage(cv::Mat mat){
    originalImage = mat;
    if(originalImage.empty())return;
    commputeMatVector();
    applyChanges();
}

void MountainTab::applyChanges() {
    if(originalImage.empty())return;
    double degrade = ui->degraderSpinBox->value();
    int level = ui->LevelQSlider->value();

    outputImage = cv::Mat::zeros(outputImage.rows,outputImage.cols,CV_32FC1);
    double m = 1.0;
    double normalize = 0;
    for(int i = 0;i < level; i++){
        m *= degrade;
        normalize += m;
        for(int r=0; r<outputImage.rows; r++){
            for(int c=0; c<outputImage.cols; c++){
                outputImage.at<float>(r,c) += (float) (m * images[i].at<float>(r, c));
            }
        }
    }

    cv::Mat output = cv::Mat::zeros(outputImage.rows, outputImage.cols, CV_8UC1);
    for(int r=0; r<outputImage.rows; r++){
        for(int c=0; c<outputImage.cols; c++){
            outputImage.at<float>(r,c) /= normalize;
            output.at<uchar>(r, c) = (uchar) (180 * outputImage.at<float>(r, c)) + 75;
        }
    }



    cv::resize(output, output, cv::Size(outputHeight,outputWidth));
    QImage qimg((uchar*)output.data, output.cols, output.rows, output.step, QImage::Format_Grayscale8);
    ui->rasterLabel->setPixmap(QPixmap::fromImage(qimg));
}

void MountainTab::setSpinBox(int i) {
    ui->degraderSpinBox->setValue((double)i/(double)(ui->degraderQSlider->maximum()+1));
}

void MountainTab::setSlider(double d) {
    ui->degraderQSlider->setValue((int) (d * 100));
}

void MountainTab::generate() {
    if(originalImage.empty())return;
    commputeMatVector();
    applyChanges();
}
