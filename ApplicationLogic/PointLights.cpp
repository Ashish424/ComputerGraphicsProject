//
// Created by Ashish Aapan on 13/10/15.
//

#include "PointLights.hpp"
namespace TerrainDemo {

    Pointlight::Pointlight(const MainCamera *cam,
                 const TransformData &transdata,
                 const glm::vec3 &position,
                 const glm::vec3 &ambient,
                 const glm::vec3 &diffuse,
                 const glm::vec3 &specular) : GameObject(cam,transdata),position(position),ambient(ambient),diffuse(diffuse),specular(specular)
    {

        //TODO set these values option in constructor
        this->constant = 1.0;
        this->linear =0.7;
        this->quadratic = 1.8;




    }

    void Pointlight::InputUpdate() {




    }
    //update uniforms here as well
    void Pointlight::DrawGameObject() {

    }
}