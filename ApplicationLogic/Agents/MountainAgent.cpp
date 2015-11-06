//
// Created by Priyanshu Singh on 06/11/15.
//

#include <assert.h>
#include <qlogging.h>
#include <iostream>
#include <ApplicationLogic/utils/PerlinNoise.hpp>
#include "MountainAgent.hpp"

MountainAgent::MountainAgent(int tokens, cv::Mat &img, std::pair<int, int> startingPoint, int changeDirection): Agent(tokens) {
    assert(img.channels() == 1);
    image = img;
    point = startingPoint;
    changeDirc = changeDirection;
}

void MountainAgent::makeMountains(cv::Mat &image, uchar color) {
    cv::Mat dis = cv::Mat::zeros(image.rows,image.cols, CV_32FC1);
    std::vector< std::pair<int, int> > curve;
    for(int i=0; i<image.rows; i++){
        for(int j=0; j<image.cols; j++){
            if(image.at<uchar>(i, j) == 255){
                curve.push_back(std::make_pair(j, i));
            }
        }
    }
    PerlinNoise n[3];
    for(int i=0; i<3; i++)n[i]=PerlinNoise((unsigned int) random());
    float max_dis=0;
    for(int y = 0; y < image.rows; y++){
        for(int x = 0; x < image.cols; x++){
            float distance = 1e9;
            for(int z = 0; z < curve.size(); z++){
                float nx = curve[z].first;
                float ny = curve[z].second;
                float d = sqrtf((x-nx)*(x-nx) + (y-ny)*(y-ny));
                distance = std::min(distance,d);
            }
            dis.at<float>(y, x) = distance;
            max_dis = std::max(max_dis, distance);
        }
    }

    for(int i=0; i<image.rows; i++){
        for(int j=0; j< image.cols; j++){
            dis.at<float>(i, j) /= max_dis;
            dis.at<float>(i, j) = 1 - dis.at<float>(i, j);
            image.at<uchar>(i, j) = (uchar) (255 * dis.at<float>(i, j));
            float ans = image.at<uchar>(i,j);
            ans /= 300;
            float x = j;x/=image.cols;
            float y = i;y/=image.rows;
            for(int k=1; k<4; k++){
                float f =  k*k + 10;
                float a = 2*k*k + 3;
                ans += 1/f*n[k-1].noise(x*a,y*a,0.8);
            }
            ans = std::min(ans,1.0f);
            ans *= 255;
            image.at<uchar>(i, j) = (uchar) ans;
        }
    }
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
            direction += M_PI/8 - (addDirection * d)/ 100;
            std::cerr<< d <<"\n";
            chngCount = changeDirc;
        }

        chngCount--;
        int x = _x, y = _y;
        assert(x >=0 && y >= 0 && x < image.cols && y < image.rows);
        image.at<uchar>(y, x) = 255;
        _x += sinf(direction);
        _y += cosf(direction);
        if(_x >= image.cols || _y >= image.rows || _x < 0 || _y < 0){
            _x = random()%image.cols;
            _y = random()%image.rows;
        }

    }
}
