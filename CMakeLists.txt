cmake_minimum_required (VERSION 2.6)
project (Malan)

include_directories(malan)
include_directories(malan/expressions)

add_executable(main ${PROJECT_SOURCE_DIR}/malan/main.cpp)