cmake_minimum_required (VERSION 3.12.1)
project (Malan)

add_subdirectory(src)
add_subdirectory(test)
add_test (NAME Test COMMAND test/Test)