//
// Created by Ashish Aapan on 13/10/15.
//

#include <glm/gtx/string_cast.hpp>
#include "World.hpp"
#include "Terrain.hpp"
#include "Grid.hpp"
#include <QDebug>
#include "PointLights.hpp"
#include "ApplicationLogic/utils/utilityFunctions.hpp"
//#define WORLD_DEBUG

namespace TerrainDemo {



//your playground to put stuff
    World::World(int width, int height, float timestep) :width(width),height(height),timestep(timestep) {

        putshaders();
        putCam();
        putmodels();


    }





//everything updates here
    void World::update() {

        slideahead+=timestep;


        updateCamera();
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
        indexVec[TerrainShader].push_back(ShaderDefinition(GL_VERTEX_SHADER,"./shaders/TerrainShader/LegacyTerrainShaders/TerrainVertex.glsl"));
        indexVec[TerrainShader].push_back(ShaderDefinition(GL_FRAGMENT_SHADER,"./shaders/TerrainShader/LegacyTerrainShaders/TerrainFrag.glsl"));

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



        shaders.push_back(new Shader(indexVec[TerrainShader],uniformsVec[TerrainShader]));





    }


    void World::putCam() {
//        MainCamera::MainCamera(const glm::vec3 &pos, float fov, float aspect, float zNear, float zFar, const glm::vec3 &up, const glm::vec3 &forward, CameraType type) :


//
//        this->cam = new MainCamera(glm::vec3(0.0f, 0.0f, 3.0f), 70.0f, (float) width / height, 1.0f, 5,
//                                   glm::vec3(0, 1, 0), glm::vec3(0, 0, -3*1),CameraType::Perspective
//        );

//
        this->cam = new MainCamera(glm::vec3(1.0f, 1.0f, 1.0f), 70.0f, (float) width / height, 0.1f, 5,
                                   glm::vec3(0, 1, 0), glm::vec3(-3 * 1, -3 * 1, -3 * 1),CameraType::Perspective);

    }


    void World::putmodels() {

        glm::vec3 pos = glm::vec3(0.0, 0.0, 0.0);
        glm::vec3 scale = glm::vec3(1.0, 1.0, 1.0);
        glm::vec3 rot = glm::vec3(0.0, 0.0, 0.0);

        TransformData t1(pos, rot, scale);

        objects.push_back(
            new Terrain(this->cam,
                        t1,
                        this->shaders[TerrainShader],
                        512,
                        512,
                        1.0,
                        "./Assets/testHeightmap.png",
                        &updateTerrainShader1));
        objects.push_back(
            new Grid(this->cam,
                     t1,
                     this->shaders[BasicShader],
                     0.1f,
                     20,
                     glm::vec4(1.0f, 0.5f, 0.5f, 1.0f),
                     &updateGridShader1));





    }


    //callback for updating camera based on mouse input
    void World::updateCamera() {

    }
    void World::updateShaders() {}


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

}