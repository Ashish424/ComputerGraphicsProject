//
// Created by Ashish Aapan on 21/10/15.
//

#ifndef CGPROJECT_TERRAIN_H
#define CGPROJECT_TERRAIN_H

#include "Model.hpp"
namespace TerrainDemo {
    class Terrain : public Model {


    public:
        Terrain(const MainCamera *cam, const TransformData &transdata, const Shader *shader, unsigned int dimX,
                    unsigned int dimZ, double maxHeight, const std::string &heightImage);



    private:
        const glm::vec3 corner;
        unsigned int dimX,dimZ;

        virtual void DrawGameObject() override;
        virtual void InputUpdate() ;
        //helper method for loading image
        //TODO add this functionality
        void loadImage();

        enum{
            POSITION,
            NORMAL,
            TEXTCORD,
            ELEMENT_BUFFER,
            NUM_BUFFERS

        };
        GLuint vertexBuffers[NUM_BUFFERS];
    };
}

#endif //CGPROJECT_TERRAIN_H
