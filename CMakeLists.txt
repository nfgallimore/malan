cmake_minimum_required (VERSION 3.12.1)
project (Malan)
enable_testing()
include(CTest)
set(CMAKE_CXX_FLAGS -std="c++17")

add_executable(main 
main.cpp 
printer.cpp
expr.cpp 
type.cpp 
decl.cpp 
name.cpp
stmt.cpp)

find_package(Boost 1.55 REQUIRED COMPONENTS unit_test_framework)

include_directories (tests ${Boost_INCLUDE_DIRS})

add_definitions (-DBOOST_TEST_DYN_LINK)

add_executable(expr_t
tests/expr_t.cpp
printer.cpp
expr.cpp 
type.cpp 
decl.cpp 
name.cpp
stmt.cpp)

target_link_libraries (expr_t ${Boost_FILESYSTEM_LIBRARY} ${Boost_SYSTEM_LIBRARY} ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY})

add_test (NAME Expressions COMMAND expr_t)
