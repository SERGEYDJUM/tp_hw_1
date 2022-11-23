cmake_minimum_required(VERSION 3.14 FATAL_ERROR)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(CPM.cmake)
CPMAddPackage(
    NAME matplotplusplus
    GITHUB_REPOSITORY alandefreitas/matplotplusplus
    GIT_TAG origin/master
)

project(tp_hw_1)
add_executable(benchmark benchmark.cpp)
target_link_libraries(benchmark PUBLIC matplot)