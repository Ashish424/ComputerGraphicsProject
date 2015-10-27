//
// Created by Ashish Aapan on 13/10/15.
//

#ifndef CGPROJECT_GRID_H
#define CGPROJECT_GRID_H


//Class for Testing Grid
#include <GL/glew.h>
#include "Model.hpp"
#include <glm/glm.hpp>
namespace TerrainDemo {

    class Grid: public Model{
    public:
        Grid(const MainCamera *cam, const TransformData &transdata, const Shader *shader, GLfloat scale, GLuint size,
                       glm::vec4 color);



        ~Grid();

    private:
        virtual void DrawGameObject() override;
        virtual void InputUpdate();


    private:
        GLuint gridSize;
        enum{
            POSITION,
            COLOR,
            NUM_BUFFERS

        };
        GLuint vertexBuffers[NUM_BUFFERS];
    };
}


#endif //CGPROJECT_GRID_H
