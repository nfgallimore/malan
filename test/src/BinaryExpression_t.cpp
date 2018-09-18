#define BOOST_TEST_MODULE BinaryExpressionTests
#include <boost/test/unit_test.hpp>

#include "../../src/Expressions/BinaryExpression.hpp"

BOOST_AUTO_TEST_CASE(pass)
{
    Expression* expression1 = new Expression("1");
    Expression* expression2 = new Expression("2");

    Binary_expression* expr = new Binary_expression(expression1, expression2, "+");
    BOOST_CHECK_EQUAL(expr-> get_lhs()->get_string(), "1");
    BOOST_CHECK_EQUAL(expr-> get_rhs()->get_string(), "2");
    BOOST_CHECK_EQUAL(expr-> get_operation(), "+");
}