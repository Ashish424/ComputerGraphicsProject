cmake_minimum_required(VERSION 3.3)
project(CgProject)


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -W -Wall -Wextra -pedantic")


set(SOURCE_FILES ${SOURCE_FILES}
        ${CMAKE_CURRENT_SOURCE_DIR}/GameObject.hpp ${CMAKE_CURRENT_SOURCE_DIR}/GameObject.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/Shader.cpp ${CMAKE_CURRENT_SOURCE_DIR}/Shader.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/TransformData.cpp ${CMAKE_CURRENT_SOURCE_DIR}/TransformData.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/Model.cpp ${CMAKE_CURRENT_SOURCE_DIR}/Model.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/Grid.cpp  ${CMAKE_CURRENT_SOURCE_DIR}/Grid.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/Vertices.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/World.cpp  ${CMAKE_CURRENT_SOURCE_DIR}/World.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/MainCamera.cpp ${CMAKE_CURRENT_SOURCE_DIR}/MainCamera.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/Light.cpp ${CMAKE_CURRENT_SOURCE_DIR}/Light.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/Terrain.cpp ${CMAKE_CURRENT_SOURCE_DIR}/Terrain.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/Material.cpp ${CMAKE_CURRENT_SOURCE_DIR}/Material.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/Textures.cpp ${CMAKE_CURRENT_SOURCE_DIR}/Textures.hpp





        #only headers
        ${CMAKE_CURRENT_SOURCE_DIR}/utilityFunctions.hpp

        PARENT_SCOPE)









