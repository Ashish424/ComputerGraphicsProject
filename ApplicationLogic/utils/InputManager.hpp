//
// Created by Priyanshu Singh on 30/11/15.
//

#ifndef CGPROJECT_INPUTMANAGER_HPP
#define CGPROJECT_INPUTMANAGER_HPP


#include <glm/glm.hpp>

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

 private:
  static bool keys[KEYS::COUNT];
  static glm::vec2 mousePos;
  static glm::vec2 screenInfo;
};


#endif //CGPROJECT_INPUTMANAGER_HPP