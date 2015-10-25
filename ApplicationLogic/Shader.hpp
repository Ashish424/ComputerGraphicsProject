//
// Created by Ashish Aapan on 12/10/15.
//

#ifndef CGPROJECT_SHADER_H
#define CGPROJECT_SHADER_H

#include "glew.h"
#include <string>
#include <vector>
#include <map>
#include <utility>
#include "MainCamera.hpp"



/*TODO
 * implement copy constructor and move for the shader class
 * Add support for tranform data and other data so same shader
 * with different tranformation matrix can be used by same shader
 * for different object
 *
*/
namespace TerrainDemo {
typedef std::pair<GLenum,std::string> ShaderDefinition;

class Model;
class Light;

class Shader {


public:

    Shader(const std::vector<ShaderDefinition> & shaderIndexes,const std::vector<std::string> & uniforms);
    ~Shader();
    void Use()const;//bind this shader
    void update(
        void (*update_fp)(TerrainDemo::MainCamera &, TerrainDemo::Shader &),
        MainCamera &mainCamera);

    GLuint getLocation(std::string &name);

private:
    static std::string LoadShader(const std::string& fileName);
    static GLuint CreateShader(GLenum type,const std::string& text);
    static void CheckShaderError(GLuint shader, GLuint flag, bool isProgram, const std::string& errorMessage);




private:
    std::vector<GLuint> shaders;//shaders stored here
    std::map<std::string,GLuint> uniformsMap;//each Instance updates this guy accordingly
    GLuint programID;




};


}

#endif //CGPROJECT_SHADER_H
