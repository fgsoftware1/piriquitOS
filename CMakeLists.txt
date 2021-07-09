cmake_minimum_required(VERSION 3.10.0)
SET(CMAKE_CXX_STANDARD 17)
SET(CMAKE_CXX_STANDARD_REQUIRED ON)

project(fgos VERSION 1.0)
add_executable(fgos src/x86_64/boot/tests/main.cpp)