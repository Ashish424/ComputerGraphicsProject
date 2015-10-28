//
// Created by Priyanshu Singh on 28/10/15.
//

#ifndef CGPROJECT_PERLINNOISE_HPP
#define CGPROJECT_PERLINNOISE_HPP

#include <vector>

class PerlinNoise {

    std::vector<int> p;
public:

    PerlinNoise();

    PerlinNoise(unsigned int seed);

    double noise(double x, double y, double z);
private:
    double fade(double t);
    double lerp(double t, double a, double b);
    double grad(int hash, double x, double y, double z);
};




#endif //CGPROJECT_PERLINNOISE_HPP
