cmake_minimum_required(VERSION 3.10)

project(SDLProject VERSION 1.0.0)

find_package(PkgConfig REQUIRED)

pkg_check_modules(SDL2 REQUIRED sdl2)
pkg_check_modules(SDL2_TTF REQUIRED SDL2_ttf)

message(STATUS "Current build type: ${CMAKE_BUILD_TYPE}")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_BUILD_TYPE}/bin)

include_directories(src/util/include)

add_subdirectory(util)
add_subdirectory(src/RenderManager)
add_subdirectory(src/Snake)
add_subdirectory(src/Food)

set(MY_PROJECT_LIBS
    ${SDL2_LIBRARIES}
    ${SDL2_TTF_LIBRARIES}
    logger
    rendermanager
    snake
    food
)

add_executable(${PROJECT_NAME} main.cpp)

target_include_directories(${PROJECT_NAME} PRIVATE ${SDL2_INCLUDE_DIRS} ${SDL2_TTF_INCLUDE_DIRS})

target_link_libraries(${PROJECT_NAME} PRIVATE  ${MY_PROJECT_LIBS})
