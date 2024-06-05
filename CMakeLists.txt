cmake_minimum_required(VERSION 3.28)
project(untitled)

set(CMAKE_CXX_STANDARD 17)

add_executable(untitled source/main/main.cpp
        source/main/main.h
        source/debug/printing.cpp
        source/debug/printing.h)
