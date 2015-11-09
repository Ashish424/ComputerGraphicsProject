//
// Created by Priyanshu Singh on 13/10/15.
//

#include <iostream>
#include <stdlib.h>
#include <cmath>
#include "CoastlineAgent.hpp"
#pragma clang diagnostic push

int dirList[8][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}, {1,1}, {1,-1}, {-1,1}, {-1,-1}};
CoastlineAgent::~CoastlineAgent() {

}
//

void CoastlineAgent::doWork() {
    srandom(time(NULL));
    int w = maxX - minX + 1;
    int h = maxY - minY + 1;
    if( w*h <= 128){
        int dir = (int) (random()%8);
        std::pair<int, int> point = choosePoint(dir);
        while(tokens > 0 && point.first != -1 && point.second != -1){

            std::pair<int, int> attr = std::make_pair(random()%(width), random()%(height));
            std::pair<int, int> repul = std::make_pair(random()%(width), random()%(height));
            double score = -1e9;
            int mxx=0,mxy=0;
            for(int j=0; j<8; j++){
                int xx = point.first + dirList[j][0];
                int yy = point.second + dirList[j][1];
                if(isValid(xx,yy) && !isLand(xx, yy)){
                    std::pair<int, int> pt = std::make_pair(xx,yy);
                    double sp = distance(pt,repul) - 2*distance(pt, attr) +3*minDistFromEdge(pt);
                    if(sp > score){
                        mxx = xx;
                        mxy = yy;
                        score = sp;
                    }
                }
            }
            if(score > 1.2e3){
                img->imageIntData[mxx][mxy]=111;
            }
            point = choosePoint(dir);
            tokens--;
        }
    }else{

        int add=0;
        if(tokens & 1)add= 1;
        CoastlineAgent *child1,*child2;
        if(w > h){
            child1 = new CoastlineAgent(tokens/2 ,img, width, height, minX,minX+w/2,minY, maxY);
            child2 = new CoastlineAgent(tokens/2 + add,img, width, height, minX+w/2 +1, maxX, minY, maxY);
        }else{
            child1 = new CoastlineAgent(tokens/2,img, width, height, minX, maxX, minY,minY+h/2);
            child2 = new CoastlineAgent(tokens/2 + add,img, width, height, minX, maxX, minY + h/2 + 1, maxY);
        }
        child1->doWork();
        child2->doWork();
        //TODO free child data in recursion here
        delete child1;
        delete child2;
    }
}

bool CoastlineAgent::isSurrounded(int x, int y) {
    for(int j=0; j<8; j++){
        int xx=x + dirList[j][0];
        int yy=y + dirList[j][1];
        if(isValid(xx,yy) && !isLand(xx,yy)){return false;}
    }
    return true;
}

bool CoastlineAgent::isLand(int x, int y) {
    return (img->imageIntData[x][y] > 10);
}

bool CoastlineAgent::isValid(int x, int y) {
    return (x>=minX && x<=maxX && y >= minY  && y<=maxY);
}

CoastlineAgent::CoastlineAgent(int tokens, Data *img, int width, int height, int minX, int maxX, int minY,
                               int maxY): Agent(tokens) {
    this->img = img;
    this->width = width;
    this->height = height;
    this->minX = minX;
    this->maxX = maxX;
    this->minY = minY;
    this->maxY = maxY;
}

std::pair<int, int> CoastlineAgent::choosePoint(int dir) {
    std::pair<int, int> point;
    int maxLoop = 10000;
    if(random()%2){
        point = std::make_pair((random()%2)?minX:maxX, (random()%(maxY-minY+1)+minY));
    }else{
        point = std::make_pair((random()%(maxX-minX+1)+minX), (random()%2)?minY:maxY);
    }
    //point = std::make_pair((random()%(maxX-minX+1)+minX), (random()%(maxY-minY+1)+minY));
    int x=point.first,y=point.second;
    while(isSurrounded(x, y)){
        maxLoop--;
        if(maxLoop<0)return std::make_pair(-1,-1);
        x += dirList[dir][0];
        y += dirList[dir][1];
        int xx = x;
        int yy = y;
        while (!isValid(xx,yy)) {
            maxLoop--;
            if(maxLoop<0)return std::make_pair(-1,-1);
            dir = (int) (random() % 8);
            xx = x + dirList[dir][0];
            yy = y + dirList[dir][1];
        }
        x = xx;
        y = yy;
    }
    return point;
}

double CoastlineAgent::distance(std::pair<int, int> pt1, std::pair<int, int> pt2) {
    return std::sqrt((pt1.first - pt2.first)*(pt1.first - pt2.first) + (pt1.second - pt2.second)*(pt1.second - pt2.second));
}

double CoastlineAgent::minDistFromEdge(std::pair<int, int> point) {
    int a = (point.first > width-1-point.first)?width-point.first-1:point.first;
    int b = (point.second > height-1-point.second)?height-point.second-1:point.second;
    return (a>b)?b:a;
}

#pragma clang diagnostic pop