//
// Created by Ashish Aapan on 21/10/15.
//

#include "Terrain.hpp"
#include <vector>
#include "Shader.hpp"
#include <QDebug>
#include "SOIL.h"
#include <opencv2/core/core.hpp>
#include <opencv2/opencv.hpp>
#include <glm/gtx/string_cast.hpp>



//#define DEBUG_TERRAIN
namespace TerrainDemo {

    Terrain::Terrain(const MainCamera *cam, const TransformData &transdata, const Shader *shader, unsigned int dimX,
                unsigned int dimZ, double maxHeight, const std::string &heightImage) :
    Model(cam,transdata,shader),corner(-0.5f,-0.2f,-0.5f),dimX(dimX),dimZ(dimZ)
    {


        cv::Mat heightImg(loadImage(heightImage));
        //vector of vectors for terrain
        std::vector< std::vector< glm::vec3> > VertexData(dimZ,std:: vector<glm::vec3>(dimX));
        std::vector<std::vector< glm::vec2> > CoordsData(dimZ, std::vector<glm::vec2>(dimX));




        cv::Size imgSize= heightImg.size();
        int imgX = imgSize.width-1;
        int imgZ = imgSize.height-1;
        //texture is aligned as required.
        for(GLuint i = 0;i< dimZ;i++) {
            for (GLuint j = 0; j < dimX; j++) {


                double scaleZ = i/(double)(dimZ -1);
                double scaleX = j/(double)(dimX-1);

                int imgPosX = (int)(scaleX*imgX);
                int imgPosZ=  (int)(scaleZ*imgZ);
                double height = maxHeight*heightImg.at<uchar>(imgPosZ,imgPosX)/(255.0f);
                //TODO see terrain zero level?
                VertexData[i][j] = glm::vec3(corner.x+scaleX, corner.y+height, corner.z+scaleZ);
                CoordsData[i][j] = glm::vec2(scaleX, scaleZ);

            }

        }


        //precalculate normals for each of the  triangle of each quad
        std::vector<std:: vector<glm::vec3> > vNormals[2];
            vNormals[0] = std::vector<std::vector<glm::vec3>>(dimZ - 1,std:: vector<glm::vec3>(dimX - 1));
            vNormals[1] = std::vector<std::vector<glm::vec3>>(dimZ - 1, std::vector<glm::vec3>(dimX - 1));

        for(GLuint i = 0;i<dimZ-1;i++) {
            for (GLuint  j = 0; j < dimX - 1; j++) {
                glm::vec3 vTriangle0[] =
                        {
                                VertexData[i][j],
                                VertexData[i + 1][j],
                                VertexData[i + 1][j + 1]
                        };

                glm::vec3 vTriangle1[] =
                        {
                                VertexData[i + 1][j + 1],
                                VertexData[i][j + 1],
                                VertexData[i][j]
                        };

                glm::vec3 vTriangleNorm0 = glm::cross(vTriangle0[0] - vTriangle0[1], vTriangle0[1] - vTriangle0[2]);
                glm::vec3 vTriangleNorm1 = glm::cross(vTriangle1[0] - vTriangle1[1], vTriangle1[1] - vTriangle1[2]);

                vNormals[0][i][j] = glm::normalize(vTriangleNorm0);
                vNormals[1][i][j] = glm::normalize(vTriangleNorm1);
            }
        }

        std::vector< std::vector<glm::vec3> > FinalNormals = std::vector< std::vector<glm::vec3> >(dimZ, std::vector<glm::vec3>(dimX));

        //calculating vextex normals by averaging triangle normals
        for(GLuint i = 0;i<dimZ;i++) {
            for (GLuint j = 0; j < dimX; j++) {

                glm::vec3 FinalNormal = glm::vec3(0.0f, 0.0f, 0.0f);

                // Look for upper-left triangles
                if (j != 0 && i != 0)
                    for (int k = 0; k < 2; k++)FinalNormal += vNormals[k][i - 1][j - 1];
                // Look for upper-right triangles
                if (i != 0 && j != dimX - 1)FinalNormal += vNormals[0][i - 1][j];
                // Look for bottom-right triangles
                if (i != dimZ - 1 && j != dimX - 1)
                    for (int k = 0; k < 2; k++)FinalNormal += vNormals[k][i][j];
                // Look for bottom-left triangles
                if (i != dimZ - 1 && j != 0)
                    FinalNormal += vNormals[1][i][j - 1];
                FinalNormal = glm::normalize(FinalNormal);

                FinalNormals[i][j] = FinalNormal; // Store final normal of j-th vertex in i-th row
            }
        }

        std::vector<GLuint> elementIndex;
        //elemnt array buffer
        GLuint  PrimitiveRestartIndex = dimZ*dimX;
        for(GLuint i=  0;i<dimZ-1; i++)
        {
            for(GLuint j = 0;j<dimX;j++)
            {
                for (GLint k = 0; k < 2; k++) {
                    GLint iRow = i + (1 - k);
                    GLint iIndex = iRow* dimX + j;
                    elementIndex.push_back(iIndex);
                }
            }
            // Restart triangle strips
            elementIndex.push_back(PrimitiveRestartIndex);
        }

        //Linearize vectors to send to OpenGL
        std::vector<glm::vec3> linearVertexData;linearVertexData.reserve(dimZ*dimX);
        std::vector<glm::vec3> linearNormalData;linearNormalData.reserve(dimZ*dimX);
        std::vector<glm::vec2> linearTextcoord;linearTextcoord.reserve(dimZ*dimX);


        for(GLuint i = 0;i<dimZ;i++) {
            for (GLuint j = 0; j < dimX; j++) {
                linearVertexData.push_back(VertexData[i][j]);
                linearNormalData.push_back(FinalNormals[i][j]);
                linearTextcoord.push_back(CoordsData[i][j]);
            }
        }



        glGenVertexArrays(1,&vertexArrayObject);
        glBindVertexArray(vertexArrayObject);

        //generate required number of buffers for vertex positions
        glGenBuffers(NUM_BUFFERS, &vertexBuffers[0]);

        //element array buffer
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,vertexBuffers[ELEMENT_BUFFER]);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, elementIndex.size()*sizeof(elementIndex[0]),&elementIndex[0] , GL_STATIC_DRAW);

        glBindBuffer(GL_ARRAY_BUFFER,vertexBuffers[POSITION]);
        glBufferData(GL_ARRAY_BUFFER,linearVertexData.size()* sizeof(linearVertexData[0]),&linearVertexData[0],GL_STATIC_DRAW);
        //tell we have attribute 0(Positions)
        glEnableVertexAttribArray(0);
        //describe attrib 0
        glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,0,0);

        glBindBuffer(GL_ARRAY_BUFFER,vertexBuffers[NORMAL]);
        glBufferData(GL_ARRAY_BUFFER,linearNormalData.size()* sizeof(linearNormalData[0]),&linearNormalData[0],GL_STATIC_DRAW);
        //tell we have attribute 1(Normals)
        glEnableVertexAttribArray(1);
        glVertexAttribPointer(1,3,GL_FLOAT,GL_FALSE,0,0);

        glBindBuffer(GL_ARRAY_BUFFER,vertexBuffers[TEXTCORD]);
        glBufferData(GL_ARRAY_BUFFER,linearTextcoord.size()*sizeof(linearTextcoord[0]),&linearTextcoord[0],GL_STATIC_DRAW);
        //tell we have attribute 2(Text coords)
        glEnableVertexAttribArray(2);
        glVertexAttribPointer(2,2,GL_FLOAT,GL_FALSE,0,0);



        glBindVertexArray(0);

    }

    void Terrain::DrawGameObject() {

//TODO set the required uniform vars in Terrain Shader
//
//        spTerrain.SetUniform("fRenderHeight", vRenderScale.y);
//        spTerrain.SetUniform("fMaxTextureU", float(iCols)*0.1f);
//        spTerrain.SetUniform("fMaxTextureV", float(iRows)*0.1f);

//        spTerrain.SetUniform("HeightmapScaleMatrix", glm::scale(glm::mat4(1.0), glm::vec3(vRenderScale)));

        glBindVertexArray(vertexArrayObject);
        glBindTexture(GL_TEXTURE_2D, texture);
        //TODO update shaders here
//        this->shader->update(,this->current_cam);
        this->shader->Use();
        glEnable(GL_PRIMITIVE_RESTART);
        glPrimitiveRestartIndex(dimZ*dimX);
        //TODO replace this with size of vector
        GLuint  NumIndices =  (dimZ-1)*dimX*2 + dimZ-1;

        glDrawElements(GL_TRIANGLE_STRIP, NumIndices, GL_UNSIGNED_INT, 0);

        glDisable(GL_PRIMITIVE_RESTART);

        glBindVertexArray(0);

    }
    void Terrain::InputUpdate() {

    }


//TODO mipmaps generation

//TODO have multiple textures-shaders-model setup correct.
    cv::Mat Terrain::loadImage(const std::string &filepath) {

        GLint width;
        GLint height;
        GLubyte *ImageData;
        GLint channels;

        using namespace cv;
        Mat imageHeight = Mat(imread(filepath.c_str(), CV_LOAD_IMAGE_GRAYSCALE));


        ImageData = SOIL_load_image(filepath.c_str(),&width,&height,&channels,SOIL_LOAD_RGBA);

#ifdef DEBUG_TERRAIN
        qDebug("channles obtanied are %d",channels);

        qDebug("dim valus are %u %u",dimZ,dimX);
#endif
        if(ImageData == NULL){
            qDebug("error file not found");
        }
        //TODO error handling in gui if path not valid

#ifdef DEBUG_TERRAIN
        qDebug("channles obtanied are %d",channels);
#endif
        glGenTextures(1, &texture);
        glBindTexture(GL_TEXTURE_2D, texture);

        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE,ImageData);
        glGenerateMipmap(GL_TEXTURE_2D);



        glBindTexture(GL_TEXTURE_2D, 0);

        //TODO free image
        SOIL_free_image_data(ImageData);

        return imageHeight;

    }

}