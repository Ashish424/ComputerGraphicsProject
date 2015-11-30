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

            qDebug("value of dimension is %d",dimension);
                glGenVertexArrays(1,&vertexArrayObject);
                glBindVertexArray(vertexArrayObject);
                //a patch of 4 vertices
                glPatchParameteri( GL_PATCH_VERTICES, 4);

                glBindVertexArray(0);










    }
    void Terrain::setDrawMode(const TerrainDrawMode &mode) {

        drawMode = mode;


    }





void Terrain::DrawGameObject() {

//TODO set the required uniform vars in Terrain Shader
//



        glBindVertexArray(vertexArrayObject);




        //TODO update shaders here
        this->shader->Use();
        //TODO update geometry here
        // TODO update heightmap here
        std::string heightUniform("heightMapDisplacer");
        heightmap.Bind(this->shader,0,heightUniform,0);


        std::string textureTes("tester");
        textures.Bind(this->shader,1,textureTes,0);

        //TODO update textures here
        // textures.Bind(this->shader)

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

}
void Terrain::setMinMaxTesselationFactors(int MinTess, int MaxTess) {

}
}