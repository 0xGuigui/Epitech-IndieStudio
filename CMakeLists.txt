cmake_minimum_required(VERSION 3.17)

set(CMAKE_PROJECT_NAME bomberman)

project(${CMAKE_PROJECT_NAME})

set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR})

include(Findraylib.cmake)

find_package(raylib 3.0 REQUIRED) # Requires at least version 3.0

include_directories(_deps/raylib-src/src/ include)

#@TODO: Try to get all .cpp files for the compilation via cmake and Makefile
add_executable(${CMAKE_PROJECT_NAME}
        src/main.cpp
        src/indie.cpp
        src/Menus/MainMenu.cpp
        src/Menus/MultiplayerMenu.cpp
        src/Menus/OptionMenu.cpp
        src/Menus/SinglePlayerMenu.cpp
        src/Menus/SplashScreen.cpp
        src/Game.cpp
        src/IncludeDefinitions/Player.cpp
        src/IncludeDefinitions/Bomb.cpp
        src/components/environmentHandler.cpp)

target_link_libraries(${CMAKE_PROJECT_NAME} raylib)

# Checks if OSX and links appropriate frameworks (only required on MacOS)
if (APPLE)
    target_link_libraries(${CMAKE_PROJECT_NAME} "-framework IOKit")
    target_link_libraries(${CMAKE_PROJECT_NAME} "-framework Cocoa")
    target_link_libraries(${CMAKE_PROJECT_NAME} "-framework OpenGL")
endif()
