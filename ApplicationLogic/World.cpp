//
// Created by Ashish Aapan on 13/10/15.
//

#include <glm/gtx/string_cast.hpp>
#include "World.hpp"
#include "Terrain.hpp"
#include "Grid.hpp"
#include <QDebug>
#include "PointLights.hpp"
//#define WORLD_DEBUG

namespace TerrainDemo {



//your playground to put stuff
    World::World(int width, int height, float timestep) :width(width),height(height),timestep(timestep) {

        putshaders();
        putCam();
        putmodels();
        //TODO remove this from here
        pnoise = PerlinNoise(time(NULL));

    }





//everything updates here
    void World::update() {

        slideahead+=timestep;

        //update shaders
        //TODO pass vector of current objects to these
        updateShaders();
        //TODO update camera here
        //update objects
        updateObjects();
    }

    void World::putshaders() {
        shaders.clear();

        //vector of pairs for each shader
        std::vector< std::vector<ShaderDefinition> > indexVec(NUM_SHADERS);
        std::vector<std::vector<std::string> > uniformsVec(NUM_SHADERS);


        //shader0
        indexVec[BasicShader].push_back(ShaderDefinition(GL_VERTEX_SHADER,"./shaders/basicShader/basicVertex.glsl"));
        indexVec[BasicShader].push_back(ShaderDefinition(GL_FRAGMENT_SHADER,"./shaders/basicShader/basicFrag.glsl"));

        //vector of uniforms for each shader in pair
        uniformsVec[BasicShader].push_back("model");
        uniformsVec[BasicShader].push_back("view");

        //simple shader for testing
        shaders.push_back(new Shader(indexVec[BasicShader],uniformsVec[BasicShader]));


        //shader1(Terrain shader)
        indexVec[TerrainShader].push_back(ShaderDefinition(GL_VERTEX_SHADER,"./shaders/TerrainShader/TerrainVertex.glsl"));
        indexVec[TerrainShader].push_back(ShaderDefinition(GL_FRAGMENT_SHADER,"./shaders/TerrainShader/TerrainFrag.glsl"));

        //vector of uniforms for each shader in pair
        uniformsVec[TerrainShader].push_back("model");
        uniformsVec[TerrainShader].push_back("view");


        //TODO light seperate
      uniformsVec[TerrainShader].push_back("pointLights[0].position");
      uniformsVec[TerrainShader].push_back("pointLights[0].diffuse");
      uniformsVec[TerrainShader].push_back("pointLights[0].ambient");
      uniformsVec[TerrainShader].push_back("pointLights[0].specular");
      uniformsVec[TerrainShader].push_back("pointLights[0].constant");
      uniformsVec[TerrainShader].push_back("pointLights[0].linear");
      uniformsVec[TerrainShader].push_back("pointLights[0].quadratic");







      //simple shader for testing
        shaders.push_back(new Shader(indexVec[TerrainShader],uniformsVec[TerrainShader]));














    }


    void World::putCam() {
//        MainCamera::MainCamera(const glm::vec3 &pos, float fov, float aspect, float zNear, float zFar, const glm::vec3 &up, const glm::vec3 &forward, CameraType type) :


//
//        this->cam = new MainCamera(glm::vec3(0.0f, 0.0f, 3.0f), 70.0f, (float) width / height, 1.0f, 5,
//                                   glm::vec3(0, 1, 0), glm::vec3(0, 0, -3*1),CameraType::Perspective
//        );

//
        this->cam = new MainCamera(glm::vec3(1.0f, 1.0f, 1.0f), 70.0f, (float) width / height, 1.0f, 5,
                                   glm::vec3(0, 1, 0), glm::vec3(-3 * 1, -3 * 1, -3 * 1),CameraType::Perspective
        );

    }


    void World::putmodels() {

        glm::vec3 pos = glm::vec3(0.0, 0.0, 0.0);
        glm::vec3 scale = glm::vec3(1.0, 1.0, 1.0);
        glm::vec3 rot = glm::vec3(0.0, 0.0, 0.0);

        TransformData t1(pos, rot, scale);

        objects.push_back(
                new Terrain(this->cam,t1,this->shaders[TerrainShader],128,128,1.0,"./Assets/testHeightmap.png"));
        objects.push_back(
                new Grid(this->cam, t1, this->shaders[BasicShader], 0.1f, 20, glm::vec4(1.0f, 0.5f, 0.5f, 1.0f)));





    }

    void World::updateShaders() {


        this->shaders[BasicShader]->Use();
        this->shaders[BasicShader]->update([](MainCamera &cam, Shader &shad) -> void {
            glm::mat4 getView = cam.GetViewProjection();

            std::string v("view");
            std::string m("model");


            glm::vec3 pos = glm::vec3(0.0, 0.0, 0.0);
            glm::vec3 scale = glm::vec3(1.0, 1.0, 1.0);
            glm::vec3 rot = glm::vec3(0.0, 0.0, 0.0);

            TransformData t1(pos, rot, scale);


            glm::mat4 model = t1.GetModel();


            GLuint hold_view = shad.getLocation(v);
            GLuint hold_model = shad.getLocation(m);


            glUniformMatrix4fv(hold_view, 1, GL_FALSE, &getView[0][0]);
            glUniformMatrix4fv(hold_model, 1, GL_FALSE, &model[0][0]);


        }, *this->cam);



        this->shaders[TerrainShader]->Use();
        this->shaders[TerrainShader]->update([](MainCamera &cam, Shader &shad) -> void {


          //model-view information
          static float rotation = 0.0f;
          glm::mat4 getView = cam.GetViewProjection();
          glm::vec3 pos = glm::vec3(0.0, 0.0, 0.0);
          glm::vec3 scale = glm::vec3(1.0, 1.0, 1.0);
          glm::vec3 rot = glm::vec3(0.0, rotation,0.0);
          rotation+=0.001f;
          TransformData t1(pos, rot, scale);
          glm::mat4 model = t1.GetModel();
          //lighting information
          glm::vec3 lightPos(0.0,3.0,0.0);
          glm::vec3 lightColor(1.0,sinf(glm::degrees(rotation)),1.0);
          Pointlight p(&cam,t1,lightPos,lightColor,lightColor,lightColor);








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

          GLuint hold_light_pos = shad.getLocation(lightPosString);
          GLuint hold_light_diffuse = shad.getLocation(lightDiffuseString);
          GLuint hold_light_ambient = shad.getLocation(lightAmbientString);
          GLuint hold_light_specular = shad.getLocation(lightSpecularString);
          GLuint hold_light_constant = shad.getLocation(lightConstantString);
          GLuint hold_light_linear = shad.getLocation(lightLinearString);
          GLuint hold_light_quadratic = shad.getLocation(lightQuadraticString);


          //fetch uniforms
          GLuint hold_view = shad.getLocation(viewString);
          GLuint hold_model = shad.getLocation(modelString);
#ifdef WORLD_DEBUG
            qDebug("value of viewString is %u",hold_view);
            qDebug("value of model is %u",hold_model);
#endif

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


        }, *this->cam);


    }


    void World::updateObjects() {

        for(unsigned int i = 0;i<objects.size();i++){
            if(objects.at(i))objects.at(i)->update();
        }

    }


    World::~World() {
        delete cam;
        for(unsigned int i = 0;i<objects.size();i++)delete objects[i];
        for(unsigned int i = 0;i<shaders.size();i++)delete shaders[i];


    }
    cv::Mat World::updatedImage(){
      static float tt = 0.0;
      tt+=0.01;
      for(int i=0; i<img.rows; ++i){
        for(int j=0; j<img.cols; ++j){
          double x = (double)j/((double)img.cols);
          double y = (double)i/((double)img.rows);
//scale here multiply by a bigger no.
          double n = pnoise.noise(10*x,10*y,tt);
          img.at<uchar>(i,j) = (uchar) floor(n*255);
        }
      }

    }

}