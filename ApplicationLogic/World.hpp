//
// Created by Ashish Aapan on 13/10/15.
//

#ifndef CGPROJECT_WORLD_H
#define CGPROJECT_WORLD_H


#include <vector>
#include <opencv2/core/mat.hpp>
#include "GameObject.hpp"
#include "Shader.hpp"
#include "Model.hpp"
#include "Terrain.hpp"


namespace TerrainDemo {

    class World {

    public:

        World(int width, int height, float timestep);

        ~World();
        //TODO add arguemnts for mouse callbacks here
        void update();

    public:
        MainCamera* cam;
        //game objects and stuff is dynamically allocated
        std::vector<Model* >objects;
        std::vector<Shader* >shaders;
        //TODO add vector of lights here
        //imp always make sure NUM_SHADERS last element in this list
        enum{
            BasicShader,
            TerrainShader,
            NUM_SHADERS
        };



    private:
        int width;
        int height;
        float timestep;
        float slideahead;
        float cameraMouseSensitivity = 0.05f;
        float cameraSpeed = 0.2f;
        glm::vec2 prevMousePos;
     public:
      Terrain *getCuurentTerrain() const {
          return cuurentTerrain;
      }
     private:
      Terrain* cuurentTerrain;




        void putshaders();
        void putCam();
        void putmodels();
        void putTerrain();

        void updateTerrain();
        void updateShaders();
        void updateObjects();
        void updateCamera();
        void camerakeyboardUpdate(float cameraSpeed);
        void cameraMouseUpdate(float sensivity);












    };


}

#endif //CGPROJECT_WORLD_H
