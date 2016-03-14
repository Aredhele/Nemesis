cmake_minimum_required(VERSION 3.0)

project(clientConnector)


set(SFML_ROOT  "${CMAKE_SOURCE_DIR}/SFML-2.3.2" ${CMAKE_MODULE_PATH})
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
include_directories(${CMAKE_SOURCE_DIR}/include)

set(HEADER_FILES
        ../include/clientConnector/ClientServer.hpp
        ../../../../NemesisOldServer/include/ConsoleDisplayer.hpp
        ../include/clientConnector/ClientThread.hpp
        ../include/clientConnector/Game.hpp
        ../include/tool/tool.hpp)

set(SOURCE_FILES
        ClientServer.cpp ClientThread.cpp Game.cpp ../tool/tool.cpp WarmUp.cpp ../include/clientConnector/WarmUp.hpp Player.cpp ../include/clientConnector/Player.hpp)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")

add_library(clientConnector STATIC ${SOURCE_FILES} ${HEADER_FILES})


set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})

find_package(SFML 2 REQUIRED system window graphics network audio)

if(SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(clientConnector ${SFML_LIBRARIES})
endif()