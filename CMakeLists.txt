cmake_minimum_required(VERSION 3.20)
project(StringLearning)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -m64")

add_executable(StringLearning main.cpp String.cpp String.hpp)
