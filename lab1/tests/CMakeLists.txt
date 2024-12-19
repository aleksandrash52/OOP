enable_testing()

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(runTests
    test_main.cpp
    test_is_valid_parentheses.cpp
)

target_link_libraries(runTests ${GTEST_LIBRARIES} pthread ParenthesesProject)
