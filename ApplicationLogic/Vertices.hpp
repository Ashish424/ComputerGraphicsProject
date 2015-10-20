//
// Created by Ashish Aapan on 13/10/15.
//

#ifndef CGPROJECT_VERTICES_H
#define CGPROJECT_VERTICES_H

#include <glm/glm.hpp>
namespace TerrainDemo {
    class VertexPosTexNormal {

    public:

        //position,texture and normal
        VertexPosTexNormal(const glm::vec3 &pos, const glm::vec2 &textCord, const glm::vec3 &normal):
                pos(pos),textCord(textCord),normal(normal)
        {}

    public:
        const glm::vec3 *getPos() { return &pos; }


        const glm::vec2 *getTextCord() { return &textCord; }


        const glm::vec3 *getNormal() { return &normal; }


    private:
        glm::vec3 pos;
        glm::vec2 textCord;
        glm::vec3 normal;

    };

    class VertexPosColor {

    public:
        //constructor for common cases;
        //position and color
        VertexPosColor(const glm::vec3 &pos, const glm::vec4 &color) :
                pos(pos), color(color) { }


    public:
        const glm::vec3 *getPos() { return &pos; }

        const glm::vec4 *getColor() { return &color; }


    private:
        glm::vec3 pos;
        glm::vec4 color;

    };
}






#endif //CGPROJECT_VERTICES_H
