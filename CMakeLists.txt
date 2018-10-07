cmake_minimum_required (VERSION 3.12.1)

set(CMAKE_CXX_FLAGS -std="c++17")

project (Malan)

add_executable(main 
main.cpp 
printer.cpp
expr.cpp 
type.cpp 
decl.cpp 
name.cpp
stmt.cpp)