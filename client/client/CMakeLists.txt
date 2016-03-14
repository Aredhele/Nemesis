cmake_minimum_required(VERSION 3.3)
project(NemesisClient)

set(SFML_ROOT  "${CMAKE_SOURCE_DIR}/SFML-2.3.2" ${CMAKE_MODULE_PATH})
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

link_directories(${CMAKE_CURRENT_SOURCE_DIR}/lib)
include_directories(${CMAKE_SOURCE_DIR}/include)

set(SOURCE_FILES include/Ability.hpp
        include/AnimatableObject.hpp
        include/BasicInterface.hpp
        include/Caracteristic.hpp
        include/Character.hpp
        include/Constant.hpp
        include/Game.hpp
        include/GameManager.hpp
        include/InputHandler.hpp
        include/Lobby.hpp
        include/LoginMenu.hpp
        include/Manager.hpp
        include/ManagerGroup.hpp
        include/Monster.hpp
        include/MusicManager.hpp
        include/NButton.hpp
        include/NetworkManager.hpp
        include/NLabel.hpp
        include/NPanel.hpp
        include/NTextField.hpp
        include/OptionManager.hpp
        include/Patch.hpp
        include/Player.hpp
        include/Playlist.hpp
        include/ResourceLoader.hpp
        include/SplashScreen.hpp
        include/Surrounder.hpp
        include/TargetManager.hpp
        include/TextureManager.hpp
        include/TriggerableObject.hpp
        include/Updatable.hpp
        include/VideoParam.hpp
        include/VideoPlayer.hpp
        include/VisualObject.hpp
        include/WarmUp.hpp
        src/Ability.cpp
        src/AnimatableObject.cpp
        src/BasicInterface.cpp
        src/Caracteristic.cpp
        src/Character.cpp
        src/Game.cpp
        src/GameManager.cpp
        src/InputHandler.cpp
        src/Lobby.cpp
        src/LoginMenu.cpp
        src/Manager.cpp
        src/ManagerGroup.cpp
        src/Monster.cpp
        src/MusicManager.cpp
        src/NButton.cpp
        src/Nemesis.cpp
        src/NetworkManager.cpp
        src/NLabel.cpp
        src/NPanel.cpp
        src/OptionManager.cpp
        src/NTextField.cpp
        src/Player.cpp
        src/Playlist.cpp
        src/ResourceLoader.cpp
        src/Surrounder.cpp
        src/SplashScreen.cpp
        src/TargetManager.cpp
        src/TextureManager.cpp
        src/TriggerableObject.cpp
        src/Updatable.cpp
        src/VideoParam.cpp
        src/VideoPlayer.cpp
        src/VisualObject.cpp
        src/WarmUp.cpp)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")

message(WARNING "CMake runtime output Directory : ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")

add_executable(NemesisClient ${SOURCE_FILES})

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})

find_package(SFML 2 REQUIRED system window graphics network audio)

if(SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(NemesisClient ${SFML_LIBRARIES})
endif()