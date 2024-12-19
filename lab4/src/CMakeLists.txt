add_library(Figures
    Figure.cpp
    Trapezoid.cpp
    Rhombus.cpp
    Pentagon.cpp
    Point.cpp
    Array.cpp
)

target_include_directories(Figures PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
