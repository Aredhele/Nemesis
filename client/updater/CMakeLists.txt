cmake_minimum_required(VERSION 3.3)
project(NemesisUpdater)

set(SFML_ROOT  "${CMAKE_SOURCE_DIR}/SFML-2.3.2" ${CMAKE_MODULE_PATH})
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

link_directories(${CMAKE_CURRENT_SOURCE_DIR}/lib)
include_directories(${CMAKE_SOURCE_DIR}/include)

set(SOURCE_FILES include/tools/Configuration.hpp include/tools/HashTool.hpp include/tools/Parser.hpp
        include/tools/ParserException.hpp include/tools/Vector2Str.hpp include/view/VisualObject.hpp
        tools/HashTool.cpp tools/Parser.cpp tools/ParserException.cpp tools/Vector2Str.cpp view/VisualObject.cpp
        tools/Configuration.cpp main.cpp connection/FTPManager.cpp include/connection/FTPManager.hpp
        connection/FileManager.cpp include/connection/FileManager.hpp connection/ServerConnection.cpp
        include/connection/ServerConnection.hpp view/VisualObject.cpp include/view/RenderEngine.hpp
        view/RenderEngine.cpp view/Log.cpp include/view/Log.hpp view/Button.cpp
        include/view/Button.hpp include/tools/Patch.hpp view/Surrounder.cpp include/view/Surrounder.hpp include/view/ProgressBar.hpp view/ProgressBar.cpp include/view/AnimatableObject.hpp view/AnimatableObject.cpp)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")

message(WARNING "CMake runtime output Directory : ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")

add_executable(NemesisUpdater ${SOURCE_FILES})


target_link_libraries(NemesisUpdater crypto)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})

find_package(SFML 2 REQUIRED system window graphics network audio)

if(SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(NemesisUpdater ${SFML_LIBRARIES})
endif()