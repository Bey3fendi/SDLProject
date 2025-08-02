add_library(snake
src/Snake.cpp)

target_include_directories(snake PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_link_libraries(snake PUBLIC rendermanager)