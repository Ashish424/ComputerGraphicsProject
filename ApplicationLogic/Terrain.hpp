//
// Created by Ashish Aapan on 21/10/15.
//

#ifndef CGPROJECT_TERRAIN_H
#define CGPROJECT_TERRAIN_H

#include <opencv2/core/mat.hpp>
#include "Model.hpp"
namespace TerrainDemo {
    class Terrain : public Model {


    public:
        Terrain(const MainCamera *cam, const TransformData &transdata, const Shader *shader, unsigned int dimX,
                    unsigned int dimZ, double maxHeight, const std::string &heightImage);
        void updateHeightMap(const cv::Mat & img);



    private:
        const glm::vec3 corner;
        GLuint dimX,dimZ;
        GLdouble maxHeight;
        cv::Mat heightMap;
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

        //updates normals and heights of vertices
        void updatePositionData(const cv::Mat &img);
        void updateNormalData();
        void linearizeData(std::vector<glm::vec3> &linearVertexData, std::vector<glm::vec3> &linearNormalData) const;

    };
}

#endif //CGPROJECT_TERRAIN_H
