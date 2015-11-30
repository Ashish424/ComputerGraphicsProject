//
// Created by Priyanshu Singh on 22/11/15.
//

#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>
#include "CoastLineTab.hpp"
#include "ui_coastlinetab.hpp"

CoastLineTab::CoastLineTab(QWidget *parent) :
        QWidget(parent),ui(new Ui::CoastLineTab),tokens(1),patchSize(1),imageWidth(1),imageHeight(1),outputWidth(480),outputHeight(640)
{
    ui->setupUi(this);
    agent = nullptr;
    originalImage = cv::Mat::zeros(imageHeight, imageWidth, CV_8UC1);
    outputImage = cv::Mat::zeros(imageHeight, imageWidth, CV_8UC1);


    //Agent Properties
    connect(ui->tokenSpinBox, SIGNAL(valueChanged(int)), this, SLOT(setTokensValue(int)));
    connect(ui->patchSpinBox, SIGNAL(valueChanged(int)), this, SLOT(setPatchSizeValue(int)));
    connect(ui->agentThresholdSpinBox, SIGNAL(valueChanged(int)), this, SLOT(setAgentThreshold(int)));

    //Image Properties
    connect(ui->widthSpinBox, SIGNAL(valueChanged(int)), this, SLOT(setImageWidth(int)));
    connect(ui->heightSpinBox, SIGNAL(valueChanged(int)), this, SLOT(setImageHeight(int)));
    //TODO make it work
    connect(ui->showOriginalCheckBox, SIGNAL(), this, SLOT());

    //Filter Properties
    connect(ui->gaussBlurSlider, SIGNAL(valueChanged(int)), this, SLOT(applyFilters()));
    connect(ui->sigmaXSpinBox, SIGNAL(valueChanged(double)), this, SLOT(applyFilters()));
    connect(ui->sigmaYSpinBox, SIGNAL(valueChanged(double)), this, SLOT(applyFilters()));
    connect(ui->stretchSlider, SIGNAL(valueChanged(int)), this, SLOT(applyFilters()));
    connect(ui->thresholdSilder, SIGNAL(valueChanged(int)), this, SLOT(applyFilters()));
    connect(ui->boxBlurSlider, SIGNAL(valueChanged(int)), this, SLOT(applyFilters()));
    connect(ui->medianBlurSlider, SIGNAL(valueChanged(int)), this, SLOT(applyFilters()));

    //generate button
    connect(ui->generateBtn, SIGNAL(clicked(bool)), this, SLOT(generate()));

}

CoastLineTab::~CoastLineTab()
{
    delete ui;
}

void CoastLineTab::setTokensValue(int value) {
    tokens = value;
}

void CoastLineTab::setPatchSizeValue(int value) {
    patchSize = value;
}

void CoastLineTab::setImageWidth(int value) {
    imageWidth = value;
}

void CoastLineTab::setImageHeight(int value) {
    imageHeight = value;
}

void CoastLineTab::setAgentThreshold(int value) {
    agentThershold = value;
}

void CoastLineTab::generate() {
    // agent
    agent = new CoastlineAgent(tokens, imageHeight, imageWidth);
    CoastlineAgent::setThresholdValue(agentThershold);
    CoastlineAgent::setPatchSize(patchSize);
    srandom(time(NULL));
    agent->doWork();

    originalImage = agent->getImage();

    applyFilters();

    // deallocating agent
    delete agent;
}

void CoastLineTab::applyFilters() {
    if(originalImage.empty())return;
//    std::cerr<<"Here";
//    std::cerr<<originalImage.rows<<" "<<originalImage.cols<<" "<<ui->gaussBlurSlider->value()<<"\n";
//    //
    int kernalSize = ui->gaussBlurSlider->value()|1;
    double sigmaX = ui->sigmaXSpinBox->value();
    double sigmaY = ui->sigmaYSpinBox->value();
    cv::GaussianBlur(originalImage, outputImage,
                     cv::Size(kernalSize, kernalSize),
                     sigmaX, sigmaY);


    kernalSize = ui->boxBlurSlider->value()|1;
    cv::blur(outputImage, outputImage,cv::Size(kernalSize,kernalSize));

    int slope = ui->stretchSlider->value();
    int threshold = ui->thresholdSilder->value();
    for(int i=0; i<outputImage.rows; i++){
        for(int j=0; j<outputImage.cols; j++){
            int a = outputImage.at<uchar>(i, j);
            /*
             * Pixel values are multiplied
             * to the slope to stretch the low
             * value pixels
             */
            a *= slope;
            if( a > 255)a=255;
            a = (a > threshold)?255:0;
            outputImage.at<uchar>(i, j) = (uchar)a;
            //std::printf("(%d,%d): %d | ",i,j,img.img[i][j]);
        }
    }


    kernalSize = ui->medianBlurSlider->value() | 1;
    cv::medianBlur(outputImage, outputImage, kernalSize);

    cv::Mat output;
    cv::resize(outputImage, output, cv::Size(outputHeight,outputWidth));
    QImage qimg((uchar*)output.data, output.cols, output.rows, output.step, QImage::Format_Grayscale8);
    ui->rasterLabel->setPixmap(QPixmap::fromImage(qimg));

    emit coastlineImageChanged(outputImage.clone());

}

