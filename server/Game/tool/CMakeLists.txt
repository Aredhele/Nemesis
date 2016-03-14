cmake_minimum_required(VERSION 3.0)

project(tool)

add_definitions(-std=c++11)
include_directories(../include)

set(HEADER_FILES
        ../include/tool/Vector2Str.hpp
        ../include/tool/tool.hpp
        )

set(SOURCE_FILES
        ../tool/tool.cpp
        ../tool/Vector2Str.cpp)

add_library(tool STATIC ${SOURCE_FILES} ${HEADER_FILES})
