//
// Created by Priyanshu Singh on 06/11/15.
//

#ifndef CGPROJECT_MOUNTAINAGENT_HPP
#define CGPROJECT_MOUNTAINAGENT_HPP

#include <opencv2/core/mat.hpp>
#include "Agent.hpp"

//TODO make this work with coastline agents and integerate it with main project!
class MountainAgent: public Agent {
private:
    cv::Mat image;
    std::pair<int ,int> point;
    int changeDirc;
    double randomAngle(double a, double b);
    static uchar bgColor;
public:
    void doWork();
    MountainAgent(int tokens, cv::Mat &img, std::pair<int, int> startingPoint, int changeDirection);
    static void makeMountains(cv::Mat &image);
};


#endif //CGPROJECT_MOUNTAINAGENT_HPP
