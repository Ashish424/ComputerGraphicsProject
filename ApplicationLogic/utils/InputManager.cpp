//
// Created by Ashish Aapan on 30/11/15.
//

#include "InputManager.hpp"

#include <QDebug>
bool InputManager::keys[KEYS::COUNT] = {0};
bool InputManager::MousePressed = false;
bool InputManager::mouseMoved = false;
TerrainDemo::TerrainDrawMode InputManager::currentUimode = TerrainDemo::TerrainDrawMode::WIREFRAME ;
glm::vec2 InputManager::mousePos(0.5,0.5);
glm::vec2 InputManager::screenInfo(1.0,1.0);
float InputManager::TerrainDepth = 10.0f;
float InputManager::fixedTessLevel = 10.0f;
float InputManager::minTessLevel = 1.0f;
float InputManager::maxTesslevel = 10.0f;
float InputManager::getIsCam = 0.75f;
cv::Mat InputManager::heightImg;


bool isMousePressed();
glm::vec2 InputManager::getMouseCoords() {
//    normalize coords
    float x_pos = mousePos.x/screenInfo.x;
    float y_pos = mousePos.y/screenInfo.y;

    x_pos = -1+2*(x_pos);
    y_pos = -1+2*(y_pos);
    return glm::vec2(x_pos,y_pos);







}
void InputManager::setMouseCoords(glm::vec2 mousePos, glm::vec2 screenInfo) {
    InputManager::mousePos = mousePos;
    InputManager::screenInfo =screenInfo;

}
void InputManager::setMousePressed(bool val) {
    MousePressed = val;

}

void InputManager::setMouseMoved(bool val) {
    mouseMoved = val;

}
void InputManager::setTerrainDrawMode(bool isWireFrame) {
    currentUimode = (isWireFrame)?(TerrainDemo::TerrainDrawMode::WIREFRAME):(TerrainDemo::TerrainDrawMode::FILLED);


}
void InputManager::setUpdatedHeightMap(const cv::Mat & src) {
    heightImg = src;
}

cv::Mat InputManager::getHeightImage(){


    return heightImg;

}
