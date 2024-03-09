cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_COMPILER "/usr/bin/g++")
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(oop_lab3 LANGUAGES CXX)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(lab3 main.cpp point.cpp figure.cpp functions.cpp fcollection.cpp rhombus.cpp hexagon.cpp pentagon.cpp)

enable_testing()
add_executable(tests test.cpp point.cpp figure.cpp functions.cpp fcollection.cpp rhombus.cpp hexagon.cpp pentagon.cpp)
target_link_libraries(tests ${GTEST_LIBRARIES})

add_test(NAME BASIC COMMAND tests)