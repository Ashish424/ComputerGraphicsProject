cmake_minimum_required(VERSION 3.3)
project(CgProject)
#C++ flags
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -W -Wall -Wextra -pedantic")

#enable mocing for Qt files
set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)




set(SOURCE_FILES main.cpp)


#TODO make the project cross platform compatible by using GLint instead of ints

#Agents files
#set(SOURCE_FILES  ${SOURCE_FILES} ApplicationLogic/Agents/Agent.hpp)
#set(SOURCE_FILES  ${SOURCE_FILES}   ApplicationLogic/Agents/CoastlineAgent.cpp ApplicationLogic/Agents/CoastlineAgent.hpp)
#


#subdirectories
add_subdirectory("${PROJECT_SOURCE_DIR}/QtCode")
add_subdirectory("${PROJECT_SOURCE_DIR}/ApplicationLogic")
add_subdirectory("${PROJECT_SOURCE_DIR}/ApplicationLogic/Agents")


add_executable(CgProject ${SOURCE_FILES})








#glew setup
include_directories("${PROJECT_SOURCE_DIR}/externalLibs/glew/1.12.0/include/Gl")
#include dirs for assimp
include_directories("${PROJECT_SOURCE_DIR}/externalLibs/assimp/3.1.1/include")
#include dir for soil
#TODO cleanup stuff from soil
include_directories("${PROJECT_SOURCE_DIR}/externalLibs/SOIL/src")





find_package(OpenGL)
find_package( Qt5Core REQUIRED )
find_package( Qt5Widgets REQUIRED )
find_package( Qt5Gui REQUIRED )
find_package(Qt5OpenGL)
find_package(OpenCV)




#linking qt libs
qt5_use_modules(CgProject Core Widgets Gui )


#linking glew,assimp and opengl libs
target_link_libraries (CgProject

        "${PROJECT_SOURCE_DIR}/ExternalLibs/glew/1.12.0/lib/libGLEW.a"


        "${PROJECT_SOURCE_DIR}/ExternalLibs/assimp/3.1.1/lib/libassimp.3.1.1.dylib"
        "${PROJECT_SOURCE_DIR}/ExternalLibs/SOIL/lib/libSOIL.dylib"
        ${OPENGL_LIBRARIES}
        ${OpenCV_LIBRARIES}


)


