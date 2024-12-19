add_library(ElevenLib
    Array.cpp
    Eleven.cpp
)

target_include_directories(ElevenLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
