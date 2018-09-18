#include "Expressions/BinaryExpression.hpp"
#include <iostream>

int main(int argc, char** argv)
{
    Expression* expression1 = new Expression("1");
    Expression* expression2 = new Expression("2");

    Binary_expression* addition_expr = new Binary_expression(expression1, expression2, "+");
    std::cout << addition_expr->get_string();

    Binary_expression* and_expr = new Binary_expression(expression1, expression2, "and");
    std::cout << and_expr->get_string();
}