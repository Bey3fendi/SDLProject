cmake_minimum_required(VERSION 3.10)

project(SDLProject VERSION 1.0.0)

add_executable(SDLProject main.cpp) # Add your source files here

target_include_directories(SDLProject PRIVATE /usr/include/SDL2)
target_link_libraries(SDLProject PRIVATE SDL2)