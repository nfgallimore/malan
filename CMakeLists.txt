cmake_minimum_required (VERSION 2.6)
project (Malan)

include_directories(malan)
include_directories(malan/expressions)

add_executable(main ./malan/main.cpp ./malan/Expressions/Expression.cpp ./malan/Expressions/BinaryExpression.cpp ./malan/Expressions/LogicalExpression.cpp)