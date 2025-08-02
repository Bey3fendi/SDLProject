add_library(food
src/food.cpp)

target_include_directories(food PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_link_libraries(food PUBLIC rendermanager snake)