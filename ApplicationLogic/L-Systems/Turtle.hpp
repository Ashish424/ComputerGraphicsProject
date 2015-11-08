//
// Created by Ashish Aapan on 08/11/15.
//

#ifndef CGPROJECT_TURTLE_HPP
#define CGPROJECT_TURTLE_HPP

#include <glm/glm.hpp>
#include <memory>
#include <string>
#include <stack>
#include <vector>

namespace TerrainDemo {
  typedef std::pair<glm::vec4,glm::vec4> Edge;
  class Turtle {
   public:
    Turtle(std::shared_ptr<std::string> patternString,const glm::vec4 & initialPosition ,const glm::vec3 & direction);
    ~Turtle();
   private:
    //orignal position and direction of the turtle
    glm::vec4 position;
    glm::vec3 direction;
    //heap based stack
    std::stack<glm::mat4> * matStack;

    //TODO return this vector by making it shared ptr
    //edges contain vertices for glLines
    std::vector<Edge>* edges;

    void modifyTransData(glm::mat4 &mat, const glm::vec3 &add);
    void modifyRotationData(glm::mat4 &mat, const glm::vec3 &axis, float radianAngle);
    //helper functions

  };

}
#endif //CGPROJECT_TURTLE_HPP
