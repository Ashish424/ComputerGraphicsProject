//
// Created by Ashish Aapan on 23/10/15.
//

#include "Textures.hpp"
#include "SOIL.h"
#include <QDebug>
namespace TerrainDemo {

    Textures::Textures(const std::string &filePath, unsigned int unit):unit(unit) {
        int width;
        int height;
        unsigned char *ImageData;
        int channels;

        ImageData = SOIL_load_image(filePath.c_str(),&width,&height,&channels,SOIL_LOAD_RGBA);

        if(ImageData == NULL){
            qDebug("error file not found");
        }
        //TODO error handling in gui if path not valid




        glGenTextures(1, &textureId);
        glBindTexture(GL_TEXTURE_2D, textureId);

        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE,ImageData);
        glGenerateMipmap(GL_TEXTURE_2D);




        SOIL_free_image_data(ImageData);
        glBindTexture(GL_TEXTURE_2D, 0);

    }


    void Textures::Bind() {

        glActiveTexture(GL_TEXTURE0+unit);
        glBindTexture(GL_TEXTURE_2D,textureId);

    }
    Textures::~Textures() {
        glDeleteTextures(1,&textureId);

    }
}