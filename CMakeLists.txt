cmake_minimum_required(VERSION 3.28)
project(untitled)

set(CMAKE_CXX_STANDARD 26)

add_executable(untitled source/main/main.cpp
        source/main/main.h
        source/debugging/debug.cpp
        source/debugging/debug.h
        source/interface/user_interface.cpp
        source/interface/user_interface.h
        source/input_manager/input.cpp
        source/input_manager/input.h)
