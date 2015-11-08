//
// Created by Ashish Aapan on 07/11/15.
//
#include <glm/gtx/string_cast.hpp>
#include "utilityFunctions.hpp"

#include "ApplicationLogic/Shader.hpp"
#include "ApplicationLogic/PointLights.hpp"
namespace TerrainDemo {
  void updateGridShader1(Grid *grid) {

    glm::mat4 getView = grid->current_cam->GetViewProjection();

    std::string v("view");
    std::string m("model");


    TransformData t1 = grid->getTransdata();




    glm::mat4 model = t1.GetModel();


    GLuint hold_view = grid->shader->getLocation(v);
    GLuint hold_model = grid->shader->getLocation(m);


    glUniformMatrix4fv(hold_view, 1, GL_FALSE, &getView[0][0]);
    glUniformMatrix4fv(hold_model, 1, GL_FALSE, &model[0][0]);
  }

  void updateTerrainShader1(Terrain* terr){
    //model-view information
    static float rotation = 0.0f;
    glm::mat4 getView = terr->current_cam->GetViewProjection();
    glm::vec3 pos = glm::vec3(0.0, 0.0, 0.0);
    glm::vec3 scale = glm::vec3(1.0, 1.0, 1.0);
    glm::vec3 rot = glm::vec3(0.0, rotation,0.0);
    rotation+=0.001f;
    TransformData t1 = terr->getTransdata();
    glm::mat4 model = t1.GetModel();
    //lighting information
    glm::vec3 lightPos(0.0,3.0,0.0);
    glm::vec3 lightColor(1.0,sinf(glm::degrees(rotation)),1.0);
    Pointlight p(terr->current_cam,t1,lightPos,lightColor,lightColor,lightColor);








    //set uniform strings
    std::string viewString("view");
    std::string modelString("model");

    //TODO seperate light vars from here(add to terrain shader itself
    //set light uniform vars
    //attenuation control
    float constant;float linear;float quadratic;

    std::string lightPosString("pointLights[0].position");
    std::string lightDiffuseString("pointLights[0].diffuse");
    std::string lightAmbientString("pointLights[0].ambient");
    std::string lightSpecularString("pointLights[0].specular");
    std::string lightConstantString("pointLights[0].constant");
    std::string lightLinearString("pointLights[0].linear");
    std::string lightQuadraticString("pointLights[0]quadrtic");
    //fetch uniforms

    GLuint hold_light_pos = terr->shader->getLocation(lightPosString);
    GLuint hold_light_diffuse = terr->shader->getLocation(lightDiffuseString);
    GLuint hold_light_ambient = terr->shader->getLocation(lightAmbientString);
    GLuint hold_light_specular = terr->shader->getLocation(lightSpecularString);
    GLuint hold_light_constant = terr->shader->getLocation(lightConstantString);
    GLuint hold_light_linear = terr->shader->getLocation(lightLinearString);
    GLuint hold_light_quadratic = terr->shader->getLocation(lightQuadraticString);


    //fetch uniforms
    GLuint hold_view = terr->shader->getLocation(viewString);
    GLuint hold_model = terr->shader->getLocation(modelString);


    //update the unifotms
    glUniformMatrix4fv(hold_view, 1, GL_FALSE, &getView[0][0]);
    glUniformMatrix4fv(hold_model, 1, GL_FALSE, &model[0][0]);
    //update light uniforms
    glUniform3f(hold_light_pos,lightPos.x,lightPos.y,lightPos.z);
    glUniform3f(hold_light_ambient,lightColor.r,lightColor.g,lightColor.b);
    glUniform3f(hold_light_diffuse,lightColor.r,lightColor.g,lightColor.b);
    glUniform3f(hold_light_specular,lightColor.r,lightColor.g,lightColor.b);

    glUniform1f(hold_light_constant, p.getConstant());
    glUniform1f(hold_light_linear, p.getLinear());
    glUniform1f(hold_light_quadratic, p.getQuadratic());







  }





}