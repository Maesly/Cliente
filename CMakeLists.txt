cmake_minimum_required(VERSION 3.8)
project(Cliente)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp cliente.cpp cliente.h)
add_executable(Cliente ${SOURCE_FILES})