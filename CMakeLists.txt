cmake_minimum_required(VERSION 3.19)
project(indie)

include(Findraylib.cmake)
include_directories(_deps/raylib-src/src/)
add_executable(indie src/main.cpp)
target_link_libraries(${PROJECT_NAME} raylib)