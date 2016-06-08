cmake_minimum_required(VERSION 3.5)
project(hw4)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp SymbolTable.hpp Var.h Var.cpp SymbolTable.cpp output.cpp output.hpp  SymbolTableTest.cpp simple_test.hpp SymbolTableTest.hpp)
add_executable(hw4 ${SOURCE_FILES})