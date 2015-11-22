//
// Created by Priyanshu Singh on 13/10/15.
//

#ifndef CGPROJECT_COASTLINEAGENT_H
#define CGPROJECT_COASTLINEAGENT_H

#include <utility>
#include <opencv2/core/mat.hpp>
#include "Agent.hpp"

class CoastlineAgent: public Agent {

public:
    static void setThresholdValue(double thresholdValue) {
        CoastlineAgent::thresholdValue = thresholdValue;
    }

private:

    bool isSurrounded(int x,int y);
    bool isLand(int x, int y);
    bool isValid(int x, int y);
    std::pair<int, int> choosePoint(int dir);
    double distance(std::pair<int, int> pt1, std::pair<int, int> pt2);
    double minDistFromEdge(std::pair<int, int> point);
    CoastlineAgent(int tokens, cv::Mat &image, int width, int height, int minX, int maxX, int minY, int maxY);

public:
    static double thresholdValue;

    static void setPatchSize(int patchSize) {
        CoastlineAgent::patchSize = (patchSize<4)?4:patchSize;
    }

    static int patchSize;
    cv::Mat image;
    int width;
    int height;
    int minX,minY,maxX,maxY;
    CoastlineAgent(int tokens, int rows, int cols);

    void doWork();//recursive

    cv::Mat getImage();

    //virtual destructor
    virtual ~CoastlineAgent();




};

#endif //CGPROJECT_COASTLINEAGENT_H
