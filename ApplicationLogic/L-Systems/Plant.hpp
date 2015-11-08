//
// Created by Ashish Aapan on 08/11/15.
//

#ifndef CGPROJECT_PLANT_HPP
#define CGPROJECT_PLANT_HPP
#include "ApplicationLogic/Model.hpp"
namespace TerrainDemo {
  class Plant: public Model {

   public:
    Plant(const TerrainDemo::MainCamera *cam, const TransformData &transdata, TerrainDemo::Shader *shader);
   private:
    void InputUpdate() override ;
    void DrawGameObject()override ;
  };

}
#endif //CGPROJECT_PLANT_HPP
