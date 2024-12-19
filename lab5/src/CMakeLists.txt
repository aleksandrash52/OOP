add_library(MemoryResource
    memory_resource.cpp
    forward_list.cpp
)

target_include_directories(MemoryResource PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
