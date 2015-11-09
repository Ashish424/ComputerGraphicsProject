//
// Created by Ashish Aapan on 08/11/15.
//

#include "Plant.hpp"
#include "ApplicationLogic/Shader.hpp"
#include "Turtle.hpp"
namespace TerrainDemo {

Plant::Plant(const TerrainDemo::MainCamera *cam,
             const TransformData &transdata,
             TerrainDemo::Shader *shader,
             std::function<void(Plant *)> updatePlantShader,
             std::shared_ptr<std::vector<Edge>> edges)
    : Model(cam, transdata, shader),updatePlantShader(updatePlantShader) {




  //data for openGL


  positions.reserve(2*edges->size());



  //push vertices for gl lines
  for(unsigned int i = 0;i<edges->size();i++){
    positions.push_back(glm::vec3(edges->at(i).first));
    positions.push_back(glm::vec3(edges->at(i).second));

  }









  glGenVertexArrays(1,&vertexArrayObject);
  glBindVertexArray(vertexArrayObject);

  glGenBuffers(NUM_BUFFERS, &vertexBuffers[0]);



  //bind a particular buffer
  glBindBuffer(GL_ARRAY_BUFFER,vertexBuffers[POSITION]);
  //taking data from RAM to GPU
  glBufferData(GL_ARRAY_BUFFER,positions.size()* sizeof(positions[0]),&positions[0],GL_STATIC_DRAW);


  //tell we have attribute 0
  glEnableVertexAttribArray(0);
  //describe attrib 0
  glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,0,0);




  glBindVertexArray(0);


}


  void Plant::InputUpdate() {

  }
  void Plant::DrawGameObject() {

    glBindVertexArray(vertexArrayObject);





    this->shader->Use();
    this->updatePlantShader(this);



    glDrawArrays(GL_LINES,0,this->positions.size());

    glBindVertexArray(0);




  }
}