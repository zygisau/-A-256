cmake_minimum_required(VERSION 3.14)
project(hash)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(gtests)
add_executable(hash src/main.cpp src/ZA256/ZA256.h)