cmake_minimum_required(VERSION 3.0)

project(database)

add_definitions(-std=c++11)

set(HEADER_FILES
        ItemDB.hpp)

set(SOURCE_FILES
        ItemDB.cpp)

add_library(database STATIC ${SOURCE_FILES} ${HEADER_FILES})
