cmake_minimum_required(VERSION 3.5 FATAL_ERROR)
project(saarcor LANGUAGES CXX)
find_package(Eigen3 3.3 REQUIRED NO_MODULE)
add_executable(rayTriangleIntersect rayTriangleIntersect.cpp)
target_link_libraries(rayTriangleIntersect Eigen3::Eigen)

