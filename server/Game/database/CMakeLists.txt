cmake_minimum_required(VERSION 3.0)

project(database)

add_definitions(-std=c++11)
include_directories(../include)

set(HEADER_FILES
        ../include/database/Querie.hpp
        ../include/database/Table.hpp
        ../include/database/Field.hpp)

set(SOURCE_FILES
        Querie.cpp
        Table.cpp
        Field.cpp)

add_library(database STATIC ${SOURCE_FILES} ${HEADER_FILES})
