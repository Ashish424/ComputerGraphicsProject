//
// Created by Priyanshu Singh on 06/11/15.
//

#include <assert.h>
#include <qlogging.h>
#include <iostream>
#include <ApplicationLogic/utils/PerlinNoise.hpp>
#include <opencv2/imgproc.hpp>
#include "MountainAgent.hpp"

#define __SUP_HEIGHT__ 400
uchar MountainAgent::bgColor = 0;
MountainAgent::MountainAgent(int tokens, cv::Mat &img, std::pair<int, int> startingPoint, int changeDirection): Agent(tokens) {
    assert(img.channels() == 1);
    image = img;
    point = startingPoint;
    changeDirc = changeDirection;
}

void MountainAgent::makeMountains(cv::Mat &image) {
    cv::distanceTransform(image, image, CV_DIST_L2, 3);
    cv::normalize(image, image, 0, 1., cv::NORM_MINMAX);
}

void MountainAgent::doWork() {
    float direction = M_PI/4;
    float addDirection = M_PI/4;
    float _x = point.first;
    float _y = point.second;
    int chngCount = changeDirc;

    srandom((unsigned int) time(NULL));
    while(tokens--){

        if(chngCount==0){
            float d = random()%100+1;
            direction += randomAngle(-M_PI/4, M_PI/4);
            //std::cerr<< d <<"\n";
            chngCount = changeDirc;
        }

        direction += randomAngle(-M_PI/100,M_PI/100);
        chngCount--;
        //std::cerr<<x<<" "<<y<<"\n";
        while(_x >= image.cols || _y >= image.rows || _x < 0 || _y < 0){
            _x = random()%image.cols;
            _y = random()%image.rows;
        }

        int x = (int) _x, y = (int) _y;
        assert(_x >=0 && _y >= 0 && x < image.cols && y < image.rows);
        image.at<uchar>(y, x) = bgColor;
        _x += sinf(direction);
        _y += cosf(direction);

    }
}

double MountainAgent::randomAngle(double a, double b) {
    double X = ((double)rand())/(double)RAND_MAX;
    return a + (b - a) * X;
}