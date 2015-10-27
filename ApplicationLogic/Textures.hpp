//
// Created by Ashish Aapan on 23/10/15.
//

#ifndef CGPROJECT_TEXTURE_H
#define CGPROJECT_TEXTURE_H

#include <string>
#include <GL/glew.h>

namespace TerrainDemo {



    //TODO Textures filtering and wrapping support as well)
    //TODO Base class for textures 2d and 3d,cubemaps
    class Textures {

    public:
        Textures(const std::string &filePath, unsigned int unit = 0);
        void Bind();
        virtual  ~Textures();
        unsigned int getUnit() const { return unit; }

    protected:
    private:
        Textures(const Textures &other) { }
        void operator=(const Textures &other) { }
        GLuint textureId;
        unsigned int unit;

    };

}
#endif //CGPROJECT_TEXTURE_H
