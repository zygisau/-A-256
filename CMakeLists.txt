cmake_minimum_required(VERSION 3.14)
project(hash)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "../build")
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS -O3)

add_executable(hash src/main.cpp src/ZA256/ZA256.h src/functions.cpp src/functions.h)
add_executable(test-hash src/test-hash.cpp)