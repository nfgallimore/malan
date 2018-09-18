#include "Expressions/BinaryExpression.hpp"
#include "Expressions/LogicalExpression.hpp"

int main(int argc, char** argv)
{
    Expression* expression1 = new Expression();
    Expression* expression2 = new Expression();
    expression1->string_literal = "1";
    expression2->string_literal = "2";

    Binary_expression* binary_expression = new Binary_expression(expression1, expression2, "+");
    binary_expression->print();

    Logical_and_expression* logical_and_expression = new Logical_and_expression(expression1, expression2);
    logical_and_expression->print();
}