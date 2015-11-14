# Project : Nemesis
# Version : 1
# Part    : Server

cmake_minimum_required(VERSION 3.0)
project(Server)

# Necessary for Google Test
add_definitions(-std=gnu++0x)

# Header search path
include_directories(database)

# Uncomment to generate .exe
#set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")

set(SOURCE_FILES main.cpp)
add_executable(serverRun ${SOURCE_FILES})

# Adding sub directories
# database  - Source files
# test - Unit test files
add_subdirectory(database)

# Test directories
add_subdirectory(test)

target_link_libraries(serverRun database)