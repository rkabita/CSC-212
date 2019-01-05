cmake_minimum_required(VERSION 3.12)
project(Assignment6)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Assignment6
        bagexam.cpp
        bagtest.cpp
        bintree.h
        bstbag.h
        main.cpp)
