cmake_minimum_required (VERSION 3.12.1)
project (Malan)
enable_testing()
include(CTest)
set(CMAKE_CXX_FLAGS -std="c++17")

find_package(Boost 1.55 REQUIRED COMPONENTS unit_test_framework)
include_directories (tests ${Boost_INCLUDE_DIRS})
add_definitions (-DBOOST_TEST_DYN_LINK)

add_library(libmalan
    src/printer.cpp
    src/expr.cpp 
    src/type.cpp 
    src/decl.cpp 
    src/name.cpp
    src/stmt.cpp
    src/builder.expr.cpp
    src/builder.decl.cpp
    src/builder.stmt.cpp
    src/builder.check.cpp
    src/builder.type.cpp
    src/builder.name.cpp
    src/builder.init.cpp
    src/lexer.cpp
    src/token.cpp
    src/parser-expr.cpp
    src/parser.cpp
    src/actions.cpp
)

add_executable(main src/main.cpp)
target_link_libraries(main libmalan)

add_executable(lex src/lex.cpp)
target_link_libraries(lex libmalan)

add_executable(parse src/parse.cpp)
target_link_libraries(parse libmalan)

add_executable(expr_t tests/expr_t.cpp)
target_link_libraries (expr_t libmalan ${Boost_FILESYSTEM_LIBRARY} ${Boost_SYSTEM_LIBRARY} ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY})
add_test (NAME Expressions COMMAND expr_t)

add_executable(lex_t tests/lex_t.cpp)
target_link_libraries (lex_t libmalan ${Boost_FILESYSTEM_LIBRARY} ${Boost_SYSTEM_LIBRARY} ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY})
add_test (NAME Lexing COMMAND lex_t)