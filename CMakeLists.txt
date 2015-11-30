cmake_minimum_required(VERSION 3.3)
project(CgProject)
#C++ flags
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -W -Wall -Wextra -pedantic")
set(CMAKE_PREFIX_PATH /Users/tgz/Documents/Devlopment/Qt/5.5/clang_64)
#enable mocing for Qt files
set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)


#add brew install paths
set(CMAKE_LIBRARY_PATH ${CMAKE_LIBRARY_PATH} /usr/local/Cellar)
set(CMAKE_LIBRARY_PATH ${CMAKE_LIBRARY_PATH} /opt/local/lib)


set(CMAKE_INCLUDE_PATH ${CMAKE_INCLUDE_PATH} /usr/local/include)
set(CMAKE_INCLUDE_PATH ${CMAKE_INCLUDE_PATH} /usr/local/Cellar/)

set(SOURCE_FILES main.cpp ApplicationLogic/Agents/MountainAgent.cpp ApplicationLogic/Agents/MountainAgent.hpp QtCode/CoastLineTab.cpp QtCode/CoastLineTab.hpp QtCode/ui_coastlinetab.hpp QtCode/ui_mainwindow.hpp QtCode/MainWindow.cpp QtCode/MainWindow.hpp ApplicationLogic/utils/InputManager.hpp ApplicationLogic/utils/InputManager.cpp ApplicationLogic/utils/InputManager.hpp QtCode/MountainTab.cpp QtCode/MountainTab.hpp QtCode/ui_mountaintab.hpp)


#TODO make the project cross platform compatible by using GLint instead of ints




#subdirectories
add_subdirectory("${PROJECT_SOURCE_DIR}/QtCode")
add_subdirectory("${PROJECT_SOURCE_DIR}/ApplicationLogic")
add_subdirectory("${PROJECT_SOURCE_DIR}/ApplicationLogic/Agents")
add_subdirectory("${PROJECT_SOURCE_DIR}/ApplicationLogic/utils")
add_subdirectory("${PROJECT_SOURCE_DIR}/ApplicationLogic/L-Systems")
#TODO move this work from here
add_subdirectory("${PROJECT_SOURCE_DIR}/ApplicationLogic/temp")



#include dir thank you El-Captain
include_directories("/usr/local/include/")



link_directories("/opt/local/lib")
#glew setup
include_directories("${PROJECT_SOURCE_DIR}/externalLibs/glew/1.12.0/include/Gl")
#include dirs for assimp
include_directories("${PROJECT_SOURCE_DIR}/externalLibs/assimp/3.1.1/include")
#include dir for soil
#TODO cleanup stuff from soil
include_directories("${PROJECT_SOURCE_DIR}/externalLibs/SOIL/src")


add_executable(CgProject ${SOURCE_FILES})



find_package(OpenGL)
find_package(Qt5Core REQUIRED )
find_package(Qt5Widgets REQUIRED )
find_package(Qt5Gui REQUIRED )
find_package(Qt5OpenGL)
find_package(OpenCV)




#linking qt libs
#TODO replace this by the new recommended way
qt5_use_modules(CgProject Core Widgets Gui )


#linking glew,assimp and opengl libs
target_link_libraries (CgProject

        "${PROJECT_SOURCE_DIR}/ExternalLibs/glew/1.12.0/lib/libGLEW.a"
        "${PROJECT_SOURCE_DIR}/ExternalLibs/assimp/3.1.1/lib/libassimp.3.1.1.dylib"
        "-lSOIL"
#        "${PROJECT_SOURCE_DIR}/ExternalLibs/SOIL/lib/libSOIL.dylib"
        ${OPENGL_LIBRARIES}
        ${OpenCV_LIBRARIES}
)


