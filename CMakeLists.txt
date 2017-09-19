cmake_minimum_required(VERSION 3.8)
project(Cliente)

set(CMAKE_CXX_STANDARD 11)
list(APPEND CMAKE_CXX_FLAGS "-pthread -std=c++11 ${CMAKE_CXX_FLAGS} -g -ftest-coverage -fprofile-arcs")
add_executable(main main.cpp)

set(SOURCE_FILES main.cpp cliente.cpp cliente.h)
add_executable(Cliente ${SOURCE_FILES})