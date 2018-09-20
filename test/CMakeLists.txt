# https://stackoverflow.com/questions/14446495/cmake-project-structure-with-unit-tests

find_package(Boost 1.55 REQUIRED COMPONENTS unit_test_framework)

include_directories (${Boost_INCLUDE_DIRS})
add_definitions (-DBOOST_TEST_DYN_LINK)

set(SrcDirectory "../src/")

add_executable (test Expr_t.cpp ./${SrcDirectory}/expr.cpp)

target_link_libraries (test
                        ${Boost_FILESYSTEM_LIBRARY}
                        ${Boost_SYSTEM_LIBRARY}
                        ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
                        )