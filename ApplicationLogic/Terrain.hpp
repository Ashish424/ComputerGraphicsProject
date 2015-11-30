//
// Created by Ashish Aapan on 21/10/15.
//

#ifndef CGPROJECT_TERRAIN_H
#define CGPROJECT_TERRAIN_H

#include <opencv2/core/mat.hpp>
#include <ApplicationLogic/utils/PerlinNoise.hpp>
#include <functional>
#include "Model.hpp"
#include "Textures.hpp"
namespace TerrainDemo {
    enum class TerrainDrawMode {WIREFRAME,FILLED };
    class Terrain : public Model {


    public:
      Terrain(const MainCamera *cam,
                       const TransformData &transdata,
                       Shader *shader,
                       unsigned int dimension,
                       const std::string & heightmap,
                       const std::vector<std::string> & textures,
                       const TerrainDrawMode &mode,
                       std::function<void(Terrain *)> updateTerrainShader);



      //GUI event handlers
        void updateHeightMap(const cv::Mat &updatedData);
        void setDrawMode(const TerrainDrawMode & mode);
        void setMinMaxTesselationFactors(int MinTess,int MaxTess);

    private:
        const glm::vec3 corner;
        GLuint dimension;
        GLdouble maxHeight;
        Textures heightmap;
        Textures textures;
        TerrainDrawMode drawMode;
        std::function<void(Terrain*)> updateTerrainShader;



      //vector of vectors for terrain
      std::vector< std::vector< glm::vec3> > VertexData;
      std::vector< std::vector<glm::vec3> > FinalNormals;


        virtual void DrawGameObject() override;
        virtual void InputUpdate() ;




        //helper method for instances
        friend void updateTerrainShader1(Terrain* terr);

    };
}

#endif //CGPROJECT_TERRAIN_H
