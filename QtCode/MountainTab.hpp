//
// Created by Priyanshu Singh on 01/12/15.
//

#ifndef CGPROJECT_MOUNTAINTAB_HPP
#define CGPROJECT_MOUNTAINTAB_HPP


#include <QWidget>
#include <ApplicationLogic/Agents/MountainAgent.hpp>

namespace Ui {
    class MountainTab;
}

class MountainTab : public QWidget
{
Q_OBJECT

public:
    explicit MountainTab(QWidget *parent = 0);
    ~MountainTab();
public slots:
    void setChangedImage(cv::Mat mat);
private:
    Ui::MountainTab *ui;
    std::vector<cv::Mat> images;
    MountainAgent *agent;
    cv::Mat originalImage;
    cv::Mat outputImage;
    int tokenValue;
    std::pair<int, int>startingPoint;
    int distToChangeDirection;
    int outputHeight;
    int outputWidth;
    bool checkImage(cv::Mat);
private slots:
    void setTokenValue();
    void setStartingPoint();
    void setDistanceToChangeDirection();
    void applyChanges();
    void commputeMatVector();
    void setSpinBox(int);
    void setSlider(double);
    void generate();



};


#endif //CGPROJECT_MOUNTAINTAB_HPP
