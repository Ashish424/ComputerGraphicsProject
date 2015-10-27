//
// Created by Ashish Aapan on 13/10/15.
//

#ifndef CGPROJECT_MODEL_H
#define CGPROJECT_MODEL_H

#include "GameObject.hpp"
#include <GL/glew.h>
#include <vector>
namespace TerrainDemo {
    class Shader;
    class Model :public GameObject {

    public:
        Model(const MainCamera *cam,const TransformData & transdata,const Shader * shader);



        virtual ~Model();




    protected:
    public:
        void setShader(const Shader *shader) {
            Model::shader = shader;
        }

    protected:
        const Shader* shader;
        GLuint vertexArrayObject;


    };
    //TODO add support for materials


}


#endif //CGPROJECT_MODEL_H
