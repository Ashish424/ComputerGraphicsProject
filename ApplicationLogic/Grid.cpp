//
// Created by Ashish Aapan on 13/10/15.
//
#include "Grid.hpp"
#include "Vertices.hpp"
#include "Shader.hpp"
namespace TerrainDemo {
    Grid::Grid(const MainCamera *cam,
                 const TransformData &transdata,
                  Shader *shader,
                 GLfloat scale,
                 GLuint size,
                 glm::vec4 color,
                 std::function<void(Grid *)> updateGridShader) :
            Model(cam, transdata, shader),updateGridShader(updateGridShader) {


        std::vector<VertexPosColor>  vertices;
        gridSize = (size+1)*4;

        vertices.reserve(gridSize);


        float maxPos = size*scale/2;




        for(unsigned int i = 0;i<size+1;i++){
            float position = maxPos- i*scale;

            //horizontal lines
            vertices.push_back(VertexPosColor(glm::vec3(maxPos,0.0f,position),color));

            vertices.push_back(VertexPosColor(glm::vec3(-maxPos,0.0f,position),color));

            //vertical lines
            vertices.push_back(VertexPosColor(glm::vec3(position,0.0f,maxPos),color));

            vertices.push_back(VertexPosColor(glm::vec3(position,0.0f,-maxPos),color));





        }

        std::vector<glm::vec3> positions;
        std::vector<glm::vec4> colors;


        positions.reserve(gridSize);
        colors.reserve(gridSize);

        for(unsigned int i = 0;i < gridSize;i++){
            positions.push_back(*vertices[i].getPos());
            colors.push_back(*vertices[i].getColor());

        }






        glGenVertexArrays(1,&vertexArrayObject);
        glBindVertexArray(vertexArrayObject);

//        //initially fill vector
//        for (unsigned int i = 0;i<NUM_BUFFERS;i++){
//            vertexArrayBuffers.push_back(0);
//
//        }

        //generate required number of buffers for vertex positions
        glGenBuffers(NUM_BUFFERS, &vertexBuffers[0]);



        //bind a particular buffer
        glBindBuffer(GL_ARRAY_BUFFER,vertexBuffers[POSITION]);
        //taking data from RAM to GPU
        glBufferData(GL_ARRAY_BUFFER,gridSize* sizeof(positions[0]),&positions[0],GL_STATIC_DRAW);


        //enable we have attribute 0
        glEnableVertexAttribArray(0);
        //describe attrib 0
        glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,0,0);


//    bind a particular buffer
        glBindBuffer(GL_ARRAY_BUFFER,vertexBuffers[COLOR]);
//    taking data from RAM to GPU
        glBufferData(GL_ARRAY_BUFFER,gridSize* sizeof(colors[0]),&colors[0],GL_STATIC_DRAW);

//    enable we have attribute 1
        glEnableVertexAttribArray(1);
        glVertexAttribPointer(1,4,GL_FLOAT,GL_FALSE,0,0);




        glBindVertexArray(0);










    }

    Grid::~Grid(){


    }


    void Grid::DrawGameObject() {


        glBindVertexArray(vertexArrayObject);
        this->shader->Use();
        updateGridShader(this);
        glDrawArrays(GL_LINES,0,gridSize);

        glBindVertexArray(0);


    }

    void Grid::InputUpdate() {

    }
}