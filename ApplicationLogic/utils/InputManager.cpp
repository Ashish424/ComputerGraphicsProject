//
// Created by Ashish Aapan on 30/11/15.
//

#include "InputManager.hpp"

#include <QDebug>
bool InputManager::keys[KEYS::COUNT] = {0};
bool InputManager::MousePressed = false;
bool InputManager::mouseMoved = false;
glm::vec2 InputManager::mousePos(0.5,0.5);
glm::vec2 InputManager::screenInfo(1.0,1.0);



bool isMousePressed();
glm::vec2 InputManager::getMouseCoords() {
//    normalize coords
    float x_pos = mousePos.x/screenInfo.x;
    float y_pos = mousePos.y/screenInfo.y;

    x_pos = -1+2*(x_pos);
    y_pos = -1+2*(y_pos);
//    qDebug("x and y pos are %f %f",x_pos,y_pos);
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
