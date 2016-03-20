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

      void setDrawMode(bool mode);

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

        void setMinMaxTesselationFactors(int MinTess,int MaxTess);

    private:
        const glm::vec3 corner;
        GLuint dimension;
        GLdouble maxHeight = 10.0f;
        float FixedTess = 1.0f;

     public:
      GLdouble getMaxHeight() const {
          return maxHeight;
      }
      glm::vec2 getMinMaxLevel(){
          return glm::vec2(MinTess,MaxTess);
      }
     private:
      Textures heightmap;
        Textures textures;

        TerrainDrawMode drawMode;
        int MinTess = 1,MaxTess = 10.0f;
        float isCameraBased = 0.75;
        std::function<void(Terrain*)> updateTerrainShader;





        void updateHeightMapTexture(const cv::Mat & heightMap);

        virtual void DrawGameObject() override;
        virtual void InputUpdate();




        //helper method for instances
        friend void updateTerrainShader1(Terrain* terr);

    };
}

#endif //CGPROJECT_TERRAIN_H
