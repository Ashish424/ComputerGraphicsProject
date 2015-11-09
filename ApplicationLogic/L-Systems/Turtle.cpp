//
// Created by Ashish Aapan on 08/11/15.
//

#include "Turtle.hpp"
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/string_cast.hpp>
#define DEBUG_TURTLE
#define VAL 10
namespace TerrainDemo {


  Turtle::Turtle(std::shared_ptr<std::string> patternString,const glm::vec4 & initialPosition,const glm::vec3  & direction ):
      position(initialPosition), direction(direction), matStack(new std::stack<glm::mat4>()),edges(new std::vector<Edge>) {
    glm::normalize(this->direction);

    std::string & pattern = *patternString;
    //initilize this Identity matrix
    glm::mat4 turtleData = glm::mat4();
    //add translation to it
    turtleData = glm::translate(turtleData,glm::vec3(this->position));





    glm::vec4 currentPos = this->position;
    glm::vec4 nextPos;



    //parsing the string for movement of the tutrle
    for(unsigned int i = 0;i<pattern.length();i++){
      //TODO replace it with the general language for parsing stuff
      //Current language is
      //F: move forward a certain length (e.g. 10 pixels)
      //• +: turn left 30 degrees
      //• -: turn right 30 degrees

      if(pattern.at(i) == 'F'){


        //TODO parse the amount to move forward
        float amount = 1;
        //move forward in the required direction
        glm::vec3 moveahead = amount*glm::vec3(turtleData*glm::vec4(this->direction,0.0));
//        printf("move ahead is %s\n",glm::to_string(moveahead).c_str());
        modifyTransData(turtleData,moveahead);
//        turtleData = glm::translate(turtleData,moveahead);
//        printf("the current pos is %s\n",glm::to_string(currentPos).c_str());
//        printf("turtle f data is %s\n",glm::to_string(turtleData).c_str());
//        printf("mvoeahed is %s\n",glm::to_string(moveahead).c_str());
        //find translation part of the matrix,add to the position
        nextPos = (turtleData*glm::vec4(0.0,0.0,0.0,1.0));
        //TODO see this
        //move the current pointer ahead

        Edge e(currentPos,nextPos);
        edges->push_back(e);
        currentPos = nextPos;

      }
      else if(pattern.at(i) == '+' ){

        //TODO seperate helper function for these rotations
        //rotating along Z-axis anticlockwise(left rotation)

        modifyRotationData(turtleData,glm::vec3(0.0, 0.0, 1.0),glm::radians(90.0f));

//        turtleData = glm::rotate(turtleData, glm::radians(90.0f), glm::vec3(0.0, 0.0, 1.0));
        //only use the direction 3X3 part of the matrix
//        this->direction = glm::vec3(turtleData*glm::vec4(this->direction,0.0));

      }
      else if(pattern.at(i) == '-' ){



        //TODO seperate helper function for these rotations
        //rotating along Z-axis anticlockwise(left rotation)
        modifyRotationData(turtleData,glm::vec3(0.0, 0.0, 1.0),glm::radians(-90.0f));

//        turtleData = glm::rotate(turtleData,glm::radians( -90.0f), glm::vec3(0.0, 0.0, 1.0));
//        printf("matrix state%s \n",glm::to_string(turtleData).c_str());
//        this->direction = glm::vec3(turtleData*glm::vec4(this->direction,0.0));
//        printf("rotated vector is %s\n",glm::to_string(this->direction).c_str());


      }
      else if(pattern.at(i) == '['){
        //pushing data here

        matStack->push(turtleData);
        currentPos = (turtleData*glm::vec4(0.0,0.0,0.0,1.0));



      }
      else if(pattern.at(i) == ']'){
        turtleData = matStack->top();

        //TODO restore position and direction here
        matStack->pop();
        //restore the current position var and direction here
        currentPos = (turtleData*glm::vec4(0.0,0.0,0.0,1.0));


      }


    }
#ifdef DEBUG_TURTLE
    for(unsigned int i = 0;i<edges->size();i++){
      printf("%s %s\n",glm::to_string(edges->at(i).first).c_str(),glm::to_string(edges->at(i).second).c_str());
    }
#endif


  }
  void Turtle::modifyTransData(glm::mat4 &mat, const glm::vec3 &add) {
    mat[3][0]+= add.x;
    mat[3][1]+= add.y;
    mat[3][2]+= add.z;


  }
  void Turtle::modifyRotationData(glm::mat4 &mat, const glm::vec3 &axis, float radianAngle) {
    //get the current rotation part
    glm::mat3 rotPart = glm::mat3(mat);
    //find new rotation part
    glm::mat4 other = glm::mat4();
    other = glm::rotate(other,radianAngle,axis);
    rotPart = glm::mat3(other)*rotPart;

    for(int i = 0;i<3;i++)
      for(int j =0;j<3;j++){
        mat[i][j] = rotPart[i][j];
      }

  }

  Turtle::~Turtle() {


    delete matStack;
  }

}