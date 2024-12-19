cmake_minimum_required(VERSION 3.10)

project(FiguresProject)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(FiguresProject src/main.cpp src/Figure.cpp src/Trapezoid.cpp src/Rhombus.cpp src/Pentagon.cpp)
