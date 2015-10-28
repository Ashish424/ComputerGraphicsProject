//
// Created by Ashish Aapan on 13/10/15.
//

#ifndef CGPROJECT_WORLD_H
#define CGPROJECT_WORLD_H


#include <vector>
#include <opencv2/core/mat.hpp>
#include <ApplicationLogic/utils/PerlinNoise.hpp>
#include "GameObject.hpp"
#include "Shader.hpp"
#include "Model.hpp"


namespace TerrainDemo {

    class World {

    public:

        World(int width, int height, float timestep);

        ~World();
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




        void putshaders();
        void putCam();
        void putmodels();

        void updateShaders();
        void updateObjects();

        //TODO remove this perlin image
        cv::Mat img;
        cv::Mat updatedImage();
        PerlinNoise pnoise;











    };


}

#endif //CGPROJECT_WORLD_H
