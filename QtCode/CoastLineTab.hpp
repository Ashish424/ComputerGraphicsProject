//
// Created by Priyanshu Singh on 22/11/15.
//

#ifndef CGPROJECT_COASTLINETAB_HPP
#define CGPROJECT_COASTLINETAB_HPP


#include <QWidget>
#include <opencv2/core/core.hpp>
#include "ApplicationLogic/Agents/CoastlineAgent.hpp"

namespace Ui {
    class CoastLineTab;
}

class CoastLineTab : public QWidget
{
Q_OBJECT

public:
    explicit CoastLineTab(QWidget *parent = 0);

    ~CoastLineTab();

signals:
    void coastlineImageChanged(cv::Mat);

private slots:
    void setTokensValue(int value);
    void setPatchSizeValue(int value);
    void setImageWidth(int value);
    void setImageHeight(int value);
    void setAgentThreshold(int value);
    void applyFilters();
    void generate();

private:
    Ui::CoastLineTab *ui;
    CoastlineAgent *agent;
    cv::Mat outputImage;
    cv::Mat originalImage;

    // Agent Info
    int tokens;
    int patchSize;
    int agentThershold;

    // Image Info
    int imageWidth;
    int imageHeight;

    // Raster properties
    int outputWidth;
    int outputHeight;


};

#endif //CGPROJECT_COASTLINETAB_HPP
