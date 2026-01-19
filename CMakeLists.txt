cmake_minimum_required(VERSION 4.1)
project(daily_cpp)
set(CMAKE_CXX_STANDARD 23)

add_executable(daily_cpp main.cpp window.cpp string_fun.cpp)

target_link_libraries(daily_cpp PRIVATE stdc++exp)