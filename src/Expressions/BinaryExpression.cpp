#include "BinaryExpression.hpp"
#include <iostream>
#include <string>
Binary_expression::Binary_expression(Expression* operand0, Expression* operand1, char const* operation)
{
    m_operands[0] = operand0;
    m_operands[1] = operand1;
    m_operation = operation;
}

std::string const
Binary_expression::get_string() const
{
    std::string lhs = "(" + get_lhs()->get_string() + ")";
    std::string rhs = "(" + get_rhs()->get_string() + ")";
    return lhs + " " + get_operation() + " " + rhs + "\n";
}

Expression*
Binary_expression::get_lhs() const
{
    return m_operands[0];
}

Expression* 
Binary_expression::get_rhs() const 
{
    return m_operands[1];
}

char const*
Binary_expression::get_operation() const 
{
    return m_operation;
}