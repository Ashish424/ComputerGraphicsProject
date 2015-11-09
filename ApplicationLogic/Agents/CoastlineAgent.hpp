//
// Created by Priyanshu Singh on 13/10/15.
//

#ifndef CGPROJECT_COASTLINEAGENT_H
#define CGPROJECT_COASTLINEAGENT_H

#include <utility>
#include "Agent.hpp"
class Data{
public:
    int imageIntData[1024][1024];
};
class CoastlineAgent: public Agent {
private:
    bool isSurrounded(int x,int y);
    bool isLand(int x, int y);
    bool isValid(int x, int y);
    std::pair<int, int> choosePoint(int dir);
    double distance(std::pair<int, int> pt1, std::pair<int, int> pt2);
    double minDistFromEdge(std::pair<int, int> point);
public:
    Data *img;
    int width;
    int height;
    int minX,minY,maxX,maxY;
    CoastlineAgent(int tokens, Data *img, int width, int height, int minX, int maxX, int minY, int maxY);
    void doWork();//recursive
    //virtual destructor
    virtual ~CoastlineAgent();


};


#endif //CGPROJECT_COASTLINEAGENT_H
