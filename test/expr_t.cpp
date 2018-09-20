 #define BOOST_TEST_MODULE BinaryExpressionTests
#include <boost/test/unit_test.hpp>

#include "../src/expr.hpp"

BOOST_AUTO_TEST_CASE(pass)
{
    Expr* expr1 = new Expr("1");
    Expr* expr2 = new Expr("2");

    Binary_expr* expr = new Binary_expr(expr1, expr2, "+");
    BOOST_CHECK_EQUAL(expr-> get_lhs()->get_string(), "1");
    BOOST_CHECK_EQUAL(expr-> get_rhs()->get_string(), "2");
    BOOST_CHECK_EQUAL(expr-> get_operation(), "+");
}