//
// Created by Ashish Aapan on 13/10/15.
//

#include <glm/gtx/string_cast.hpp>
#include "World.hpp"

#include "Grid.hpp"

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














    }


    void World::putCam() {
        this->cam = new MainCamera(glm::vec3(1.0f,1.0f,1.0f),70.0f,(float)width/height,1.0f,5,glm::vec3(0,1,0),glm::vec3(-3*1,-3*1,-3*1));

    }


    void World::putmodels() {

        glm::vec3 pos = glm::vec3(0.0, 0.0, 0.0);
        glm::vec3 scale = glm::vec3(1.0, 1.0, 1.0);
        glm::vec3 rot = glm::vec3(0.0, 0.0, 0.0);

        TransformData t1(pos, rot, scale);
        objects.push_back(
                new Grid(this->cam, t1, this->shaders[BasicShader], 0.1f, 10, glm::vec4(0.0f, 0.5f, 0.5f, 1.0f)));


    }

    void World::updateShaders() {


        shaders[BasicShader]->Use();
        shaders[BasicShader]->update([](MainCamera &cam, Shader &shad) -> void {
            glm::mat4 getView = cam.GetViewProjection();

            std::string v("view");
            std::string m("model");


            glm::vec3 pos = glm::vec3(0.0, 0.0, 0.0);
            glm::vec3 scale = glm::vec3(1.0, 1.0, 1.0);
            glm::vec3 rot = glm::vec3(0.0, 0.0, 0.0);

            TransformData t1(pos, rot, scale);


            glm::mat4 model = t1.GetModel();

//            printf("model matrix %s\n",glm::to_string(model).c_str());
            GLuint hold_view = shad.getLocation(v);
            GLuint hold_model = shad.getLocation(m);


            glUniformMatrix4fv(hold_view, 1, GL_FALSE, &getView[0][0]);
            glUniformMatrix4fv(hold_model, 1, GL_FALSE, &model[0][0]);


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


}