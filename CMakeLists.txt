cmake_minimum_required(VERSION 3.17)

set(CMAKE_PROJECT_NAME bomberman)

project(${CMAKE_PROJECT_NAME})

set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR})

include(Findraylib.cmake)

find_package(raylib 3.0 REQUIRED) # Requires at least version 3.0

include_directories(_deps/raylib-src/src/ include)

add_executable(${CMAKE_PROJECT_NAME}
        src/main.cpp
        src/indie.cpp
        src/Menus/ControlsMenu.cpp
        src/Menus/MainMenu.cpp
        src/Menus/OptionsMenu.cpp
        src/Menus/PlayMenu.cpp
        src/Menus/SplashScreen.cpp
        src/Menus/PlayerControlsMenu.cpp
        src/game.cpp
        src/Menus/HelpMenu.cpp
        src/components/player.cpp
        src/components/bomb.cpp
        src/components/powerUp.cpp
        src/components/mapController.cpp
        src/components/environmentHandler.cpp)

target_link_libraries(${CMAKE_PROJECT_NAME} raylib)

# Checks if OSX and links appropriate frameworks (only required on MacOS)
if (APPLE)
    target_link_libraries(${CMAKE_PROJECT_NAME} "-framework IOKit")
    target_link_libraries(${CMAKE_PROJECT_NAME} "-framework Cocoa")
    target_link_libraries(${CMAKE_PROJECT_NAME} "-framework OpenGL")
endif()
