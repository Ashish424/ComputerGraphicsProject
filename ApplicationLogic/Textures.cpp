//
// Created by Ashish Aapan on 23/10/15.
//

#include "Textures.hpp"
#include "SOIL.h"
#include "Shader.hpp"
#include <QDebug>
namespace TerrainDemo {




    void Textures::Bind(Shader *ptr, int texUnit, const std::string &uniformVar, int index) {

        glActiveTexture(GL_TEXTURE0+texUnit);
        glBindTexture(GL_TEXTURE_2D,textureIds.at(index));
        GLuint uniformLoc = ptr->getLocation(uniformVar);
        glUniform1i(uniformLoc,texUnit);


    }
    Textures::~Textures() {
        glDeleteTextures(textureIds.size(),&textureIds[0]);

    }
    void Textures::initLoad(std::vector<std::string> textures, bool isGreyScale) {


        for(int i = 0;i<textures.size();i++)textureIds.push_back(0);

        glGenTextures(textures.size(), &textureIds[0]);

        for(int i =0;i<textures.size();i++)
        {

            int width;
            int height;
            unsigned char *ImageData;
            int channels;



            if(isGreyScale) {

                ImageData = SOIL_load_image(textures.at(i).c_str(), &width, &height, &channels, SOIL_LOAD_L);
            }
            else {
                ImageData = SOIL_load_image(textures.at(i).c_str(), &width, &height, &channels, SOIL_LOAD_RGBA);
            }




//        //TODO error handling in gui if path not valid

            if(ImageData == NULL){
                qDebug("error file not found");
            }
            glBindTexture(GL_TEXTURE_2D, textureIds.at(i));
            if(!isGreyScale)
                glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE,ImageData);
            else
                glTexImage2D(GL_TEXTURE_2D, 0, GL_R8, width, height, 0, GL_RED, GL_UNSIGNED_BYTE,ImageData);





            glGenerateMipmap(GL_TEXTURE_2D);
            SOIL_free_image_data(ImageData);
            glBindTexture(GL_TEXTURE_2D, 0);


        }




    }
Textures::Textures(const std::vector<std::string> &texturePaths, bool isGreyScale) {

    initLoad(texturePaths, isGreyScale);

    }
Textures::Textures(const std::string &texturePath, bool isGreyScale) {

    std::vector<std::string> temp;
    temp.push_back(texturePath);
    initLoad(temp, isGreyScale);
    }

Textures::Textures(const std::vector<cv::Mat> &texData) {


    }
Textures::Textures(const cv::Mat &texData) {

    }
void Textures::initMat(const std::vector<cv::Mat> &texData) {

    for(int i = 0;i<texData.size();i++)textureIds.push_back(0);


}
}