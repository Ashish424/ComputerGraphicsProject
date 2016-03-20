//
// Created by Ashish Aapan on 12/10/15.
//


#include <iostream>
#include <fstream>
#include <glm/gtx/string_cast.hpp>
#include "Shader.hpp"
#include <qdebug.h>



TerrainDemo::Shader::Shader(const std::vector<ShaderDefinition> & shaderIndexes,const std::vector<std::string> & uniforms)


{
    //create program
    programID = glCreateProgram();



    //find shaders
    for(unsigned int i =0;i < shaderIndexes.size();i++){
        //attach shaders and store there ids
        shaders.push_back(CreateShader(shaderIndexes.at(i).first,LoadShader(shaderIndexes.at(i).second)));
        glAttachShader(programID,shaders[i]);
    }

    //link here
    glLinkProgram(programID);
    CheckShaderError(programID, GL_LINK_STATUS, true, "Error linking shader program");


    glValidateProgram(programID);

    for(unsigned int i = 0;i<uniforms.size();i++) {
        uniformsMap[uniforms[i]] = glGetUniformLocation(programID, uniforms[i].c_str());
        if(uniformsMap[uniforms[i]] == -1){
            qDebug("extraction error for uniform var %s",uniforms[i].c_str());
            printf("%u extraction error\n",uniformsMap[uniforms[i]]);
        }
    }









}

TerrainDemo::Shader::~Shader() {

    //deleting shader data
    for(unsigned int i = 0; i < shaders.size(); i++)
    {
        glDetachShader(programID,shaders[i]);
        glDeleteShader(shaders[i]);
//        printf("bye bye shader\n");
    }
    //delete program
    glDeleteProgram(programID);

}


void TerrainDemo::Shader::Use()const {

    glUseProgram(this->programID);




}




std::string TerrainDemo::Shader::LoadShader(const std::string& fileName)
{
    std::ifstream file;
    file.open((fileName).c_str());

    std::string output;
    std::string line;

    if(file.is_open())
    {
        while(file.good())
        {
            getline(file, line);
            output.append(line + "\n");
        }
    }
    else
    {
        std::cerr << "Unable to load shader: " << fileName << std::endl;
    }

    return output;
}



GLuint TerrainDemo::Shader::CreateShader( GLenum type,const std::string& text)
{
    GLuint shader = glCreateShader(type);

    if(shader == 0)
        std::cerr << "Error compiling shader type " << type << std::endl;

    const GLchar* p[1];
    p[0] = text.c_str();
    GLint lengths[1];
    lengths[0] = text.length();

    glShaderSource(shader, 1, p, lengths);
    glCompileShader(shader);

    CheckShaderError(shader, GL_COMPILE_STATUS, false, "Error compiling shader!");

    return shader;
}




void TerrainDemo::Shader::CheckShaderError(GLuint shader, GLuint flag, bool isProgram, const std::string& errorMessage)
{
    GLint success = 0;
    GLchar error[1024] = { 0 };

    if(isProgram)
        glGetProgramiv(shader, flag, &success);
    else
        glGetShaderiv(shader, flag, &success);

    if(success == GL_FALSE)
    {
        if(isProgram)
            glGetProgramInfoLog(shader, sizeof(error), NULL, error);
        else
            glGetShaderInfoLog(shader, sizeof(error), NULL, error);

        std::cerr << errorMessage << ": " << error << std::endl;
    }
}

//, const std::vector<TerrainDemo::Lights> &
void TerrainDemo::Shader::update(void (*update_fp)(TerrainDemo::MainCamera &, TerrainDemo::Shader &),MainCamera &mainCamera){
//TODO make sure this works
    //make sure this shader in use before playing with Uniforms
        this->Use();
        update_fp(mainCamera,*this);






}

GLuint TerrainDemo::Shader::getLocation(const std::string &name) {

    return uniformsMap[name];
}
