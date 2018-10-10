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

find_package(Boost 1.55 REQUIRED COMPONENTS unit_test_framework)

include_directories (${Boost_INCLUDE_DIRS})

add_definitions (-DBOOST_TEST_DYN_LINK)

add_executable(ExprTests
tests/expr_t.cpp
printer.cpp
expr.cpp 
type.cpp 
decl.cpp 
name.cpp
stmt.cpp)

target_link_libraries (ExprTests ${Boost_FILESYSTEM_LIBRARY} ${Boost_SYSTEM_LIBRARY} ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY})

add_test (NAME ExprTests COMMAND tests/ExprTests)
