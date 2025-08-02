add_library(rendermanager
src/render_manager.cpp)

target_include_directories(rendermanager PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_link_libraries(rendermanager PUBLIC logger)