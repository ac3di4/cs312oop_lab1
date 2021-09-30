cmake_minimum_required(VERSION 3.21)
project(cs312oop_lab1)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "-Wall -Wextra")

add_subdirectory(task1)
add_executable(task2 task2/main.cpp)