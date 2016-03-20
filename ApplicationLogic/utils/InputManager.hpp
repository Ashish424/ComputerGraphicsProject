//
// Created by Priyanshu Singh on 30/11/15.
//

#ifndef CGPROJECT_INPUTMANAGER_HPP
#define CGPROJECT_INPUTMANAGER_HPP


#include <glm/glm.hpp>
#include <ApplicationLogic/Terrain.hpp>

class InputManager {




 public:
  //returns relative mouse coords between -1 and 1
  static glm::vec2 getMouseCoords();
  static void setMouseCoords(glm::vec2 mousePos, glm::vec2 screenInfo);
  enum KEYS{
    W,
    S,
    D,
    A,
    COUNT
  };
  static bool getKey(KEYS k){
      return keys[k];
  }

  static void setKey(KEYS k, bool val){
      keys[k] = val;
  }
  static void setMousePressed(bool val);
  static bool getMousePressed() {
      return MousePressed;

  }
  static bool  getMouseMoving(){
      return mouseMoved;
  }
  void static setMouseMoved(bool val);


  static const TerrainDemo::TerrainDrawMode &getCurrentUimode() {
      return currentUimode;
  }
  static void setTerrainDrawMode(bool isWireFrame);
 private:
  static bool keys[KEYS::COUNT];
  static glm::vec2 mousePos;
  static glm::vec2 screenInfo;
  static bool MousePressed;
  static bool mouseMoved;
  static TerrainDemo::TerrainDrawMode currentUimode;
  static float TerrainDepth;

  static float fixedTessLevel;
  static float minTessLevel;
  static float maxTesslevel;
 public:
  static float getGetIsCam() {
      return getIsCam;
  }
  static void setGetIsCam(float getIsCam) {
      InputManager::getIsCam = getIsCam;
  }
 private:
  static float getIsCam;
  static cv::Mat heightImg;


 public:
  static float getFixedTessLevel() {
      return fixedTessLevel;
  }
  static void setFixedTessLevel(float fixedTessLevel) {
      InputManager::fixedTessLevel = fixedTessLevel;
  }
  static float getMinTessLevel() {
      return minTessLevel;
  }
  static void setMinTessLevel(float minTessLevel) {
      InputManager::minTessLevel = minTessLevel;
  }
  static float getMaxTesslevel() {
      return maxTesslevel;
  }
  static void setMaxTesslevel(float maxTesslevel) {
      InputManager::maxTesslevel = maxTesslevel;
  }
 public:
  static float getTerrainDepth() {
      return TerrainDepth;
  }
  static void setTerrainDepth(float TerrainDepth) {
      InputManager::TerrainDepth = TerrainDepth;
  }
  static void setUpdatedHeightMap(const cv::Mat & src);
  static cv::Mat getHeightImage();



};


#endif //CGPROJECT_INPUTMANAGER_HPP