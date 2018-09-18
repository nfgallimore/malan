# https://stackoverflow.com/questions/14446495/cmake-project-structure-with-unit-tests

find_package(Boost 1.55 REQUIRED COMPONENTS unit_test_framework)

include_directories (./src
                     ${Boost_INCLUDE_DIRS}
                     ./../src/Expressions
                     )
add_definitions (-DBOOST_TEST_DYN_LINK)

add_executable (test 
                    src/BinaryExpression_t.cpp 
                    ../src/Expressions/BinaryExpression.cpp
                )

target_link_libraries (Test
                        ${Boost_FILESYSTEM_LIBRARY}
                        ${Boost_SYSTEM_LIBRARY}
                        ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
                        )