//
// Created by Ashish Aapan on 08/11/15.
//

#ifndef CGPROJECT_PLANT_HPP
#define CGPROJECT_PLANT_HPP
#include "ApplicationLogic/Model.hpp"
#include <functional>

#include "Turtle.hpp"
namespace TerrainDemo {
  class Plant: public Model {

   public:
    Plant(const TerrainDemo::MainCamera *cam,
              const TransformData &transdata,
              TerrainDemo::Shader *shader,
              std::function<void(Plant *)> updatePlantShader,
              std::shared_ptr<std::vector<Edge>> edges);
   private:
    void InputUpdate() override ;
    void DrawGameObject()override ;

    enum{
      POSITION,
      NUM_BUFFERS

    };
    GLuint vertexBuffers[NUM_BUFFERS];
    std::vector<glm::vec3> positions;
    //helper function for shader update
    friend void updatePlantnShader1(Plant *plant);
    std::function<void(Plant *)> updatePlantShader;

  };

}
#endif //CGPROJECT_PLANT_HPP
