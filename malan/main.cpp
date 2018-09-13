#include "Expressions/BinaryExpression.hpp"

int main(int argc, char** argv)
{
    char const* expression_as_string = "1 + 2";

    Expression* expression1 = new Expression();
    Expression* expression2 = new Expression();
    expression1->string_literal = "1";
    expression2->string_literal = "2";

    Binary_expression* binary_expression = new Binary_expression(expression1, expression2, "+");
}