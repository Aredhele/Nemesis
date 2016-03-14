# Project : Nemesis
# Version : 1
# Part    : Server

cmake_minimum_required(VERSION 3.0)
project(Server)

# Necessary for Google Test
link_directories(${CMAKE_CURRENT_SOURCE_DIR}/connector/lib)
add_definitions(-std=gnu++0x)

# Header search path
include_directories(include)

# Uncomment to generate .exe
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")

set(SOURCE_FILES main.cpp)

add_executable(serverRun ${SOURCE_FILES})

target_link_libraries(serverRun
        tool
        database
        connector
        mysqlclient
        clientConnector)

# Adding sub directories
# database  - Source files
# test - Unit test files
add_subdirectory(database)
add_subdirectory(clientConnector)
add_subdirectory(connector)
add_subdirectory(test)
add_subdirectory(tool)

