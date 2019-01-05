cmake_minimum_required(VERSION 3.12)
project(problem3)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(problem3
        exam.cpp
        hashfunctions.cpp
        hashfunctions.h
        hashfunctiontest.h)
