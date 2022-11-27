cmake_minimum_required(VERSION 3.14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 20)

project(tp_hw_1)
find_package(Matplot++ REQUIRED)
add_executable(benchmark benchmark.cpp)
set_property(TARGET benchmark PROPERTY CXX_STANDARD 20)
target_link_libraries(benchmark PUBLIC Matplot++::matplot)