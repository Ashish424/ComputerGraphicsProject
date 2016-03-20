//
// Created by Ashish Aapan on 23/10/15.
//

#include "Textures.hpp"
#include "SOIL.h"
#include "Shader.hpp"
#include <QDebug>
#include <opencv2/imgcodecs.hpp>

#define printOpenGLError() printOglError(__FILE__, __LINE__)

int printOglError(char *file, int line)
{

    GLenum glErr;
    int    retCode = 0;

    glErr = glGetError();
    if (glErr != GL_NO_ERROR)
    {
        printf("glError in file %s @ line %d: %s\n",
               file, line, gluErrorString(glErr));
        retCode = 1;
    }
    return retCode;
}
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
                qDebug("is greyscale name is %s",textures.at(i).c_str());


                ImageData = SOIL_load_image(textures.at(i).c_str(), &width, &height, &channels, SOIL_LOAD_RGBA);
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
                glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE,ImageData);

//            glTexImage2D(GL_TEXTURE_2D, 0, GL_R8, width, width, 0, GL_RED, GL_UNSIGNED_BYTE,ImageData);





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
void Textures::update(cv::Mat src, int index) {

    std::vector<cv::Mat> imgs;
    imgs.push_back(src);
    imgs.push_back(src);
    imgs.push_back(src);
    cv::merge(&imgs[0],3,src);
    cv::imwrite("./Assets/ap.png",src);
    //qDebug("here");
    int loadedWidth;
    int loadedHeight;
    unsigned char *ImageData;
    int channels;
    ImageData = SOIL_load_image("./Assets/ap.png", &loadedWidth, &loadedHeight, &channels, SOIL_LOAD_RGBA);



    //qDebug("about image Data here");
    //qDebug("image height is %d",loadedHeight);
    //qDebug("image width is %d",loadedWidth);
    //qDebug("image channels is %d",channels);


    if(ImageData == NULL){
        qDebug("error file not found");
    }
//

//
//
//

    if(!src.data){
        qDebug("data not there");
    }


    //update texture and texture unit
    glBindTexture(GL_TEXTURE_2D, textureIds.at(index));

    glTexSubImage2D(GL_TEXTURE_2D,0,0,0,loadedWidth,loadedHeight, GL_RGBA,GL_UNSIGNED_BYTE,ImageData);

//    GL_TEXTURE_2D, , GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE,ImageData);


//THIS IS THE BUG !!!!!!!!!!!!!!!!!!!!!!
//    glBindTexture(GL_TEXTURE_2D, 0);
    SOIL_free_image_data(ImageData);





}
}