cmake_minimum_required(VERSION 3.16)

project(AdventOfCode)
set(CMAKE_CXX_STANDARD 17)

# Copy input data to build dir
set(input_data
    "day1/input1"
    "day1/test_input1"
    "day2/input2"
    "day2/test_input2"
    "day3/input3"
    "day3/test_input3"
    "day4/input4"
    "day4/test_input4"
    "day5/input5"
    "day5/test_input5"
    "day6/input6"
    "day6/test_input6"
    "day7/input7"
    "day7/test_input7"
    "day8/input8"
    "day8/test_input8"
    "day25/input25"
    "day25/test_input25"
)

message(STATUS "Copying input data to: ${CMAKE_BINARY_DIR}")

foreach(input ${input_data})
    message(STATUS "copying ${input}")
    file(COPY ${input} DESTINATION ${CMAKE_BINARY_DIR})
endforeach()

add_executable(d1 day1/day1.cpp)
add_executable(d2 day2/day2.cpp)
add_executable(d3 day3/day3.cpp)
add_executable(d4 day4/day4.cpp)
add_executable(d5 day5/day5.cpp)
add_executable(d6 day6/day6.cpp)
add_executable(d7 day7/day7.cpp)
add_executable(d8 day8/day8.cpp)
add_executable(d25 day25/day25.cpp)
