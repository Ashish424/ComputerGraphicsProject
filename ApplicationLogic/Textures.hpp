//
// Created by Ashish Aapan on 23/10/15.
//

#ifndef CGPROJECT_TEXTURE_H
#define CGPROJECT_TEXTURE_H

#include <string>
#include <GL/glew.h>
#include <vector>
#include <opencv2/core/mat.hpp>
#include "Shader.hpp"

namespace TerrainDemo {




    struct TextureInfo {

      cv::Mat image;

    };



    class Textures {

    public:

        void Bind(Shader *ptr, int texUnit, const std::string &uniformVar,int index);
        ~Textures();
        //TODO add constructor for these as well
        Textures(const std::vector<cv::Mat> & texData);
        Textures(const cv::Mat & texData);

        Textures(const std::vector<std::string> &texturePaths, bool isGreyScale = true);
        Textures(const std::string &texturePath, bool isGreyScale = true);
        void update(cv::Mat src, int index);
    protected:
    private:
        Textures(const Textures &other) { }
        void operator=(const Textures &other) { }
        std::vector<GLuint> textureIds;
        void initLoad(std::vector<std::string> textures, bool isGreyScale);
        //TODO add this according to priyanshu
        void initMat(const std::vector<cv::Mat> & texData);
        bool isMatConstructed;
    };

}
#endif //CGPROJECT_TEXTURE_H
