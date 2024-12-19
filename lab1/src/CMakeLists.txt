add_executable(ParenthesesProject
    main.cpp
    is_valid_parentheses.cpp
)

target_include_directories(ParenthesesProject PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
