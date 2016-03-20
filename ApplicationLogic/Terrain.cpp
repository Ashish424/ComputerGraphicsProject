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
#include <ApplicationLogic/utils/InputManager.hpp>



//#define DEBUG_TERRAIN
namespace TerrainDemo {








    Terrain::Terrain(const MainCamera *cam,
                         const TransformData &transdata,
                         Shader *shader,
                         unsigned int dimension,
                         const std::string & heightmap,
                         const std::vector<std::string> & textures,
                         const TerrainDrawMode &mode,
                         std::function<void(Terrain *)> updateTerrainShader) :
        Model(cam,transdata,shader), dimension(dimension), maxHeight(maxHeight), heightmap(heightmap), textures(textures,false), drawMode(mode), updateTerrainShader(updateTerrainShader) {

                //setup Opengl State


                glGenVertexArrays(1,&vertexArrayObject);
                glBindVertexArray(vertexArrayObject);
                //a patch of 4 vertices
                glPatchParameteri( GL_PATCH_VERTICES, 4);

                glBindVertexArray(0);










    }
    void Terrain::setDrawMode(bool mode) {

        drawMode = (mode)?TerrainDrawMode::WIREFRAME:TerrainDrawMode::FILLED;


    }





void Terrain::DrawGameObject() {





        glBindVertexArray(vertexArrayObject);





        this->shader->Use();
        //TODO update geometry here
        drawMode = InputManager::getCurrentUimode();
        maxHeight = InputManager::getTerrainDepth();

        MinTess = InputManager::getMinTessLevel();
        MaxTess = InputManager::getMaxTesslevel();
        FixedTess = InputManager::getFixedTessLevel();
        isCameraBased = InputManager::getGetIsCam();












        std::string heightUniform("heightMapDisplacer");
        qDebug("here height before height map updating");
        heightmap.Bind(this->shader,0,heightUniform,0);
        updateHeightMap(InputManager::getHeightImage());



        std::string textureSampler0("textureSamplers[0]");
        std::string textureSampler1("textureSamplers[1]");
        std::string textureSampler2("textureSamplers[2]");



        textures.Bind(this->shader,1,textureSampler0,0);
        textures.Bind(this->shader,2,textureSampler1,1);
        textures.Bind(this->shader,3,textureSampler2,2);



    //TODO update textures here


        this->updateTerrainShader(this);

         if(drawMode == TerrainDrawMode::WIREFRAME){

            glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
         }
        else {
             glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
         }

        glDrawArraysInstanced(GL_PATCHES, 0, 4, dimension * dimension);
        //restore state back
        glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
        glBindVertexArray(0);

    }
    void Terrain::InputUpdate() {

    }


void Terrain::updateHeightMap(const cv::Mat &updatedData) {


    qDebug("updating terrain data");
    heightmap.update(updatedData,0);




}
void Terrain::setMinMaxTesselationFactors(int MinTess, int MaxTess) {

    this->MinTess = MinTess;
    this->MaxTess = MaxTess;

}





void Terrain::updateHeightMapTexture(const cv::Mat &heightMap) {





}
}