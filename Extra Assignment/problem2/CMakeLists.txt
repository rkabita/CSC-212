cmake_minimum_required(VERSION 3.12)
project(problem2)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(problem2
        exam.cpp
        node.cpp
        node.h)
