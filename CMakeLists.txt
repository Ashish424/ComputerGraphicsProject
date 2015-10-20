cmake_minimum_required(VERSION 3.3)
project(CgProject)
#C++ flags
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -W -Wall -Wextra -pedantic")

#enable mocing for Qt files
set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)




set(SOURCE_FILES main.cpp Shader.cpp Shader.hpp)
add_executable(CgProject ${SOURCE_FILES})

#subdirectories
add_subdirectory("${PROJECT_SOURCE_DIR}/QtCode")
add_subdirectory("${PROJECT_SOURCE_DIR}/ApplicationLogic")





#glew setup
include_directories("${PROJECT_SOURCE_DIR}/externalLibs/glew/1.12.0/include/Gl")
#include dirs for assimp
include_directories("${PROJECT_SOURCE_DIR}/externalLibs/assimp/3.1.1/include")





find_package(OpenGL)
find_package( Qt5Core REQUIRED )
find_package( Qt5Widgets REQUIRED )
find_package( Qt5Gui REQUIRED )
find_package(Qt5OpenGL)




#linking qt libs
qt5_use_modules(CgProject Core Widgets Gui )


#linking glew,assimp and opengl libs
target_link_libraries (CgProject

        "${PROJECT_SOURCE_DIR}/externalLibs/glew/1.12.0/lib/libGLEW.a"
        "${PROJECT_SOURCE_DIR}/externalLibs/assimp/3.1.1/lib/libassimp.3.1.1.dylib"
        ${OPENGL_LIBRARIES}

)


