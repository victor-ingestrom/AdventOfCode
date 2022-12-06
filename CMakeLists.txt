cmake_minimum_required(VERSION 3.16)

project(AdventOfCode)
set(CMAKE_CXX_STANDARD 17)

# Copy input data to build dir
set(test_data
    "day4/input4"
    "day4/test_input4"
    "day5/input5"
    "day5/test_input5"
    "day6/input6"
    "day6/test_input6"
)

message(STATUS "Copying input data to: ${CMAKE_BINARY_DIR}")

foreach(input ${test_data})
    message(STATUS "copying ${input}")
    file(COPY ${input} DESTINATION ${CMAKE_BINARY_DIR})
endforeach()

add_executable(d4 day4/day4.cpp)
add_executable(d5 day5/day5.cpp)
add_executable(d6 day6/day6.cpp)
