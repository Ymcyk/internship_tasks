cmake_minimum_required(VERSION 3.5)

project(functors)

include_directories(includes)
file(GLOB SOURCES src/*.cpp)
add_executable(functors ${SOURCES})

add_definitions(-std=c++11)
