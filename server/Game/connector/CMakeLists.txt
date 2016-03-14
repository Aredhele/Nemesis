cmake_minimum_required(VERSION 3.0)

project(connector)

add_definitions(-std=c++11)
include_directories(../include)

set(HEADER_FILES
        ../include/connector/MySQLConnector.hpp
        ../include/database/Table.hpp
        ../include/database/Field.hpp)

set(SOURCE_FILES
        MySQLConnector.cpp
        ../database/Table.cpp
        ../database/Field.cpp)

add_library(connector STATIC ${SOURCE_FILES} ${HEADER_FILES})
