//
// Created by Ashish Aapan on 13/10/15.
//

#include <glm/gtx/string_cast.hpp>
#include "World.hpp"
#include "Terrain.hpp"
#include "Grid.hpp"
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <QDebug>
#include "ApplicationLogic/utils/InputManager.hpp"
#include "PointLights.hpp"
#include "ApplicationLogic/utils/utilityFunctions.hpp"
//#define WORLD_DEBUG

namespace TerrainDemo {



//your playground to put stuff
    World::World(int width, int height, float timestep) :width(width),height(height),timestep(timestep) {

        putshaders();
        putCam();
        putmodels();
        putTerrain();
        prevMousePos = glm::vec2(0.0,0.0);


    }





//everything updates here
    void World::update() {

        slideahead+=timestep;

        updateCamera();
        //update Terrain
        updateTerrain();
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
        indexVec[TerrainShader].push_back(ShaderDefinition(GL_VERTEX_SHADER,"./shaders/TerrainShader/TerrainVertexShader.glsl"));
        indexVec[TerrainShader].push_back(ShaderDefinition(GL_FRAGMENT_SHADER,"./shaders/TerrainShader/TerrainFragShader.glsl"));
        indexVec[TerrainShader].push_back(ShaderDefinition(GL_TESS_CONTROL_SHADER,"./shaders/TerrainShader/TerrainTCSHader.glsl"));
        indexVec[TerrainShader].push_back(ShaderDefinition(GL_TESS_EVALUATION_SHADER,"./shaders/TerrainShader/TerrainTEShader.glsl"));


        //vector of uniforms for each shader in pair
        uniformsVec[TerrainShader].push_back("model");
        uniformsVec[TerrainShader].push_back("view");


        //vertex shader uniforms
        uniformsVec[TerrainShader].push_back("dimension");



        //vertex shader uniforms
//        uniformsVec[TerrainShader].push_back("");



        //tesselation shader uniforms
        uniformsVec[TerrainShader].push_back("cameraPos");
        uniformsVec[TerrainShader].push_back("doCameraTessel");
        uniformsVec[TerrainShader].push_back("minTessLevel");
        uniformsVec[TerrainShader].push_back("maxTessLevel");
        uniformsVec[TerrainShader].push_back("fixedTessLevel");
        uniformsVec[TerrainShader].push_back("heightMapdepth");



        //texture uniforms
        uniformsVec[TerrainShader].push_back("heightMapDisplacer");





        //TODO remove this uniform
        uniformsVec[TerrainShader].push_back("tester");




        //TODO light seperate
//      uniformsVec[TerrainShader].push_back("pointLights[0].position");
//      uniformsVec[TerrainShader].push_back("pointLights[0].diffuse");
//      uniformsVec[TerrainShader].push_back("pointLights[0].ambient");
//      uniformsVec[TerrainShader].push_back("pointLights[0].specular");
//      uniformsVec[TerrainShader].push_back("pointLights[0].constant");
//      uniformsVec[TerrainShader].push_back("pointLights[0].linear");
//      uniformsVec[TerrainShader].push_back("pointLights[0].quadratic");



        shaders.push_back(new Shader(indexVec[TerrainShader],uniformsVec[TerrainShader]));





    }


    void World::putCam() {
//        MainCamera::MainCamera(const glm::vec3 &pos, float fov, float aspect, float zNear, float zFar, const glm::vec3 &up, const glm::vec3 &forward, CameraType type) :


//
//        this->cam = new MainCamera(glm::vec3(0.0f, 0.0f, 3.0f), 70.0f, (float) width / height, 1.0f, 5,
//                                   glm::vec3(0, 1, 0), glm::vec3(0, 0, -3*1),CameraType::Perspective
//        );

//
        this->cam = new MainCamera(glm::vec3(30.0f, 30.0f, 30.0f), 70.0f, (float) width / height, 0.1f,500,
                                   glm::vec3(0, 1, 0), glm::vec3(-1, -1, -1),CameraType::Perspective);

    }


    void World::putmodels() {

        glm::vec3 pos = glm::vec3(0.0, 0.0, 0.0);
        glm::vec3 scale = glm::vec3(1.0, 1.0, 1.0);
        glm::vec3 rot = glm::vec3(0.0, 0.0, 0.0);

        TransformData t1(pos, rot, scale);


        std::string heightmapPath("./Assets/testHeightmap.png");
        std::vector<std::string> textures;

//        objects.push_back(
//            new Terrain(this->cam,
//                        t1,
//                        this->shaders[TerrainShader],
//                        64,
//                        heightmapPath,
//                        textures,
//                        TerrainDrawMode::WIREFRAME,
//                        &updateTerrainShader1));


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






        cameraMouseUpdate(this->cameraMouseSensitivity);
//        double fre = 0.1;
//        static glm::vec3 cameraPos =  this->cam->getM_position();
//        static double angle = 0.0f;
//        glm::vec3 displace(sinf(fre*angle),sinf(fre*angle),sinf(fre*angle));
//        displace*=6;
//        angle+=0.15;
//        this->cam->setM_position(cameraPos+displace);

        //once the foucs point moved update the camera position in the required direction

//        qDebug("camera pseed is %f\n",this->cameraSpeed);
        camerakeyboardUpdate(this->cameraSpeed);







    }
    void World::updateShaders() {}


    void World::updateObjects() {

        for(unsigned int i = 0;i<objects.size();i++){
            if(objects.at(i))objects.at(i)->update();
        }



    }


    World::~World() {
        delete cam;
        delete cuurentTerrain;
        for(unsigned int i = 0;i<objects.size();i++)delete objects[i];
        for(unsigned int i = 0;i<shaders.size();i++)delete shaders[i];


    }

void World::putTerrain() {
    glm::vec3 pos = glm::vec3(0.0, 0.0, 0.0);
    glm::vec3 scale = glm::vec3(1.0, 1.0, 1.0);
    glm::vec3 rot = glm::vec3(0.0, 0.0, 0.0);

    TransformData t1(pos, rot, scale);


    std::string heightmapPath("./Assets/testHeightmap.png");
    std::vector<std::string> textures;
    textures.push_back("./Assets/bricks.jpg");


    this->cuurentTerrain = new Terrain(this->cam,
                t1,
                this->shaders[TerrainShader],
                64,
                heightmapPath,
                textures,
                TerrainDrawMode::FILLED,
                &updateTerrainShader1);

}
void World::updateTerrain() {
    this->cuurentTerrain->update();

}


void World::camerakeyboardUpdate(float cameraSpeed) {
    glm::vec3 finalVec(0.0,0.0,0.0);
    bool executed = false;
    if(InputManager::getKey(InputManager::KEYS::W)){


        finalVec = cam->getM_position()+cam->getM_forward()*cameraSpeed;
        executed = true;
    }

    else if(InputManager::getKey(InputManager::KEYS::D)){
        finalVec =  cam->getM_position()+glm::cross(cam->getM_forward(),cam->getM_up())*cameraSpeed;
        executed = true;
    }
    else if(InputManager::getKey(InputManager::KEYS::A)){
        finalVec = cam->getM_position()-1.0f*glm::cross(cam->getM_forward(),cam->getM_up())*cameraSpeed;
        executed = true;
    }
    else if(InputManager::getKey(InputManager::KEYS::S)){
        finalVec = cam->getM_position()-1.0f*cam->getM_forward()*cameraSpeed;
        executed = true;
    }
    if(executed) {

        cam->setM_position(finalVec);
    }
}
void World::cameraMouseUpdate(float sensivity) {

    //TODO rotate camera based on the mouse movement
    glm::vec2 MousePos = InputManager::getMouseCoords();
    glm::vec2 deltaMovement = MousePos-prevMousePos;
    prevMousePos  = MousePos;



    glm::mat4 rotor;
    rotor = glm::rotate(rotor,-deltaMovement.y,glm::cross(cam->getM_up(), -cam->getM_forward()));
    cam->ApplyRotation(rotor);
    glm::mat4 rotor2;
    rotor2 = glm::rotate(rotor2,-deltaMovement.x,glm::vec3(0.0,1.0,0.0));

    cam->ApplyRotation(rotor2);

}
}