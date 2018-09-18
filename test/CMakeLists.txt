# https://stackoverflow.com/questions/14446495/cmake-project-structure-with-unit-tests

find_package (Boost COMPONENTS system filesystem unit_test_framework REQUIRED)
include_directories (${TEST_SOURCE_DIR}/src
                     ${Boost_INCLUDE_DIRS}
                     ../src/Expressions
                     )
add_definitions (-DBOOST_TEST_DYN_LINK)
add_executable (Test src/BinaryExpression_t.cpp ../src/Expressions/BinaryExpression.cpp)
target_link_libraries (Test
                        ../src/Expressions/BinaryExpression.hpp
                        ../src/Expressions/Expression.hpp
                        ${Boost_FILESYSTEM_LIBRARY}
                        ${Boost_SYSTEM_LIBRARY}
                        ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
                        )