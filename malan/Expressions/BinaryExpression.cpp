#include "BinaryExpression.hpp"
#include <iostream>

Binary_expression::Binary_expression(Expression* operand0, Expression* operand1, char const* operation)
{
    m_operands[0] = operand0;
    m_operands[1] = operand1;
    m_operation = operation;
}

void
Binary_expression::print()
{
	std::cout << '(' << get_lhs() << ')';
	std::cout << ' ' << get_operation() << ' ';
	std::cout << ' ' << '(' << get_rhs() << ')';
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