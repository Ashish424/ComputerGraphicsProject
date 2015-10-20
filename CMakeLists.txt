cmake_minimum_required(VERSION 3.3)
project(CgProject)
#C++ flags
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -W -Wall -Wextra -pedantic")

#enable mocing for Qt files
set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)




set(SOURCE_FILES main.cpp)



#Application logic files here
set(SOURCE_FILES  ${SOURCE_FILES}   ApplicationLogic/Shader.cpp ApplicationLogic/Shader.hpp)
set(SOURCE_FILES  ${SOURCE_FILES}   ApplicationLogic/GameObject.cpp ApplicationLogic/GameObject.hpp)
set(SOURCE_FILES  ${SOURCE_FILES}   ApplicationLogic/TransformData.cpp ApplicationLogic/TransformData.hpp)
set(SOURCE_FILES  ${SOURCE_FILES}   ApplicationLogic/Model.cpp ApplicationLogic/Model.hpp )
set(SOURCE_FILES  ${SOURCE_FILES}   ApplicationLogic/Model.cpp ApplicationLogic/Model.hpp )
set(SOURCE_FILES  ${SOURCE_FILES}   ApplicationLogic/Grid.cpp ApplicationLogic/Grid.hpp )
set(SOURCE_FILES  ${SOURCE_FILES}   ApplicationLogic/Vertices.hpp )
set(SOURCE_FILES  ${SOURCE_FILES}   ApplicationLogic/World.cpp ApplicationLogic/World.hpp )
set(SOURCE_FILES  ${SOURCE_FILES}   ApplicationLogic/MainCamera.cpp ApplicationLogic/MainCamera.hpp)
set(SOURCE_FILES  ${SOURCE_FILES}   ApplicationLogic/Light.cpp ApplicationLogic/Light.hpp )
#Agents files
set(SOURCE_FILES  ${SOURCE_FILES} ApplicationLogic/Agents/Agent.hpp)
set(SOURCE_FILES  ${SOURCE_FILES}   ApplicationLogic/Agents/CoastlineAgent.cpp ApplicationLogic/Agents/CoastlineAgent.hpp)


#QtCode files here
set(SOURCE_FILES  ${SOURCE_FILES}   QtCode/CGCanvas.cpp QtCode/CGCanvas.hpp )
set(SOURCE_FILES  ${SOURCE_FILES}   QtCode/MainWindow.cpp QtCode/MainWindow.hpp )



#subdirectories
add_subdirectory("${PROJECT_SOURCE_DIR}/QtCode")
add_subdirectory("${PROJECT_SOURCE_DIR}/ApplicationLogic")


add_executable(CgProject ${SOURCE_FILES})








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


