cmake_minimum_required(VERSION 3.3)
project(CgProject)


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -W -Wall -Wextra -pedantic")


set(SOURCE_FILES ${SOURCE_FILES}


        ${CMAKE_CURRENT_SOURCE_DIR}/LSystem.hpp ${CMAKE_CURRENT_SOURCE_DIR}/LSystem.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/Turtle.hpp ${CMAKE_CURRENT_SOURCE_DIR}/Turtle.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/Plant.hpp ${CMAKE_CURRENT_SOURCE_DIR}/Plant.cpp

        PARENT_SCOPE
)









