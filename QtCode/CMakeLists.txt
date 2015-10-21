cmake_minimum_required(VERSION 3.3)
project(CgProject)


set(SOURCE_FILES  ${SOURCE_FILES}
        ${CMAKE_CURRENT_SOURCE_DIR}/CGCanvas.cpp ${CMAKE_CURRENT_SOURCE_DIR}/CGCanvas.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/MainWindow.cpp ${CMAKE_CURRENT_SOURCE_DIR}/MainWindow.hpp
        PARENT_SCOPE)


