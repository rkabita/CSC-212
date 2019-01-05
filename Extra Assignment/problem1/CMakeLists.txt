cmake_minimum_required(VERSION 3.12)
project(problem1)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(problem1
        bag.cpp
        bag.h
        exam.cpp)
