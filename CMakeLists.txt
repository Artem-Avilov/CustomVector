cmake_minimum_required(VERSION 3.29.6)

project(CustomVector)

set(CMAKE CXX STANDARD 11)
set(CMAKE CXX STANDARD_REQUIRED True)

add_executable(CustomVector src/main.cpp)

include_directories(src)