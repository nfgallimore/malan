cmake_minimum_required (VERSION 3.12.1)
project (Malan)
enable_testing()
include(CTest)
set(CMAKE_CXX_FLAGS -std="c++17")

add_executable(main 
src/main.cpp 
src/printer.cpp
src/expr.cpp 
src/type.cpp 
src/decl.cpp 
src/name.cpp
src/stmt.cpp
src/builder.cpp
src/builder.expr.cpp
)

find_package(Boost 1.55 REQUIRED COMPONENTS unit_test_framework)

include_directories (tests ${Boost_INCLUDE_DIRS})

add_definitions (-DBOOST_TEST_DYN_LINK)

add_executable(expr_t
tests/expr_t.cpp
src/printer.cpp
src/expr.cpp 
src/type.cpp 
src/decl.cpp 
src/name.cpp
src/stmt.cpp
src/builder.cpp
src/builder.expr.cpp
)

target_link_libraries (expr_t ${Boost_FILESYSTEM_LIBRARY} ${Boost_SYSTEM_LIBRARY} ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY})

add_test (NAME Expressions COMMAND expr_t)
