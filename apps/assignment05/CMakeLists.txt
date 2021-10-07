cmake_minimum_required(VERSION 2.4)

#set the project name
project(assignment05)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(../../include)

#add the executable
add_executable(assignment05 assignment05.cpp)

