//
// Created by Ashish Aapan on 13/10/15.
//

#include "Model.hpp"
#include "Shader.hpp"

namespace TerrainDemo {



    Model::Model(const TerrainDemo::MainCamera *cam, const TransformData &transdata, Shader *shader):
    GameObject(cam,transdata),shader(shader)
    {}

    Model::~Model() {
        glDeleteVertexArrays(1,&vertexArrayObject);

    }
}