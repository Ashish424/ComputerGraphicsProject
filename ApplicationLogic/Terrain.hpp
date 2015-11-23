//
// Created by Ashish Aapan on 21/10/15.
//

#ifndef CGPROJECT_TERRAIN_H
#define CGPROJECT_TERRAIN_H

#include <opencv2/core/mat.hpp>
#include <ApplicationLogic/utils/PerlinNoise.hpp>
#include <functional>
#include "Model.hpp"
namespace TerrainDemo {
    enum class TerrainDrawMode {WIREFRAME,FILLED };
    class Terrain : public Model {


    public:
        //TODO remove this old constructor
        Terrain(const MainCamera *cam,
                           const TransformData &transdata,
                           Shader *shader,
                           unsigned int dimX,
                           unsigned int dimZ,
                           double maxHeight,
                           const std::string &heightImage,
                           std::function<void(Terrain *)> updateTerrainShader);




      Terrain(const MainCamera *cam,const TransformData &transdata,
              Shader *shader,
              const glm::vec3 & origin,
              const std::string &heightImage,
              unsigned int dimX,unsigned int dimZ,
              std::function<void(Terrain *)> updateTerrainShader,
              const TerrainDrawMode & mode);
        //GUI event handlers
        void updateHeightMap(const cv::Mat &updatedData);
        void setDrawMode(const TerrainDrawMode & mode);
        void setMinMaxTesselationFactors(int MinTess,int MaxTess);

    private:
        const glm::vec3 corner;
        GLuint dimX,dimZ;
        GLdouble maxHeight;
        cv::Mat heightMap;
        TerrainDrawMode drawMode;
        std::function<void(Terrain*)> updateTerrainShader;



      //vector of vectors for terrain
      std::vector< std::vector< glm::vec3> > VertexData;
      std::vector< std::vector<glm::vec3> > FinalNormals;


        virtual void DrawGameObject() override;
        virtual void InputUpdate() ;
        //helper method for loading image
        //TODO add this functionality
        cv::Mat loadImage(const std::string &filepath);

        enum{
            POSITION,
            NORMAL,
            TEXTCORD,
            ELEMENT_BUFFER,
            NUM_BUFFERS

        };
        GLuint vertexBuffers[NUM_BUFFERS];
        //TODO form texture class
        GLuint texture;


        //helper methods

        //updates normals and heights of vertices
        void updatePositionData(const cv::Mat &img);
        void updateNormalData();
        void linearizeData(std::vector<glm::vec3> &linearVertexData, std::vector<glm::vec3> &linearNormalData) const;

        //helper method for instances
        friend void updateTerrainShader1(Terrain* terr);

    };
}

#endif //CGPROJECT_TERRAIN_H
