cmake_minimum_required(VERSION 3.3)
project(CgProject)


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -W -Wall -Wextra -pedantic")


set(SOURCE_FILES ${SOURCE_FILES}


        ${CMAKE_CURRENT_SOURCE_DIR}/PerlinNoise.cpp ${CMAKE_CURRENT_SOURCE_DIR}/PerlinNoise.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/utilityFunctions.hpp ${CMAKE_CURRENT_SOURCE_DIR}/utilityFunctions.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/utilityFunctions.hpp ${CMAKE_CURRENT_SOURCE_DIR}/utilityFunctions.cpp


        PARENT_SCOPE
)









