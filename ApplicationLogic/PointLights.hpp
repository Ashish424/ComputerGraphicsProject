//
// Created by Ashish Aapan on 13/10/15.
//

#ifndef CGPROJECT_LIGHT_H
#define CGPROJECT_LIGHT_H
#include "GameObject.hpp"
#include <glm/glm.hpp>
//TODO lighting support for shaders
namespace TerrainDemo {
    class Pointlight: public GameObject {
        public:
            Pointlight(const MainCamera *cam,
                         const TransformData &transdata,
                         const glm::vec3 &position,
                         const glm::vec3 &ambient,
                         const glm::vec3 &diffuse,
                         const glm::vec3 &specular);

        private:
        //TODO override the draw update for having a visual representation of Lights
        virtual void InputUpdate() override ;
        virtual void DrawGameObject();
        private:
            glm::vec3 position;
            //attenuation control
            float constant;float linear;float quadratic;
            glm::vec3 ambient;
            glm::vec3 diffuse;
            glm::vec3 specular;


        public:
            void setPosition(const glm::vec3 &position) {
                Pointlight::position = position;
            }
            void setAmbient(const glm::vec3 &ambient) {
                Pointlight::ambient = ambient;
            }
            void setDiffuse(const glm::vec3 &diffuse) {
                Pointlight::diffuse = diffuse;
            }
            void setSpecular(const glm::vec3 &specular) {
                Pointlight::specular = specular;
            }
            float getConstant() const {
                return constant;
            }
            float getLinear() const {
                return linear;
            }
            float getQuadratic() const {
                return quadratic;
            }
            const glm::vec3 &getPosition() const {
                return position;
            }


            const glm::vec3 &getAmbient() const {
                return ambient;
            }
            const glm::vec3 &getDiffuse() const {
                return diffuse;
            }
            const glm::vec3 &getSpecular() const {
                return specular;
            }

    };

}
#endif //CGPROJECT_LIGHT_H
