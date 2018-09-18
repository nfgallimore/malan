#include "UnaryExpression.hpp"
#include <iostream>

Unary_expression::Unary_expression(Expression* expression, char* operation, bool operation_after_operand)
{
	m_operand = expression;
	m_operation = operation;
	m_operation_after_operand = operation_after_operand;
}

void
Unary_expression::print() const
{
	if (get_operation_after_operand()) 
	{
		// print operand first
		std::cout << '(' << get_operand() << ')';
		std::cout << get_operation();
	}
	else 
	{
		// print operator first
		std::cout << get_operation();
		std::cout << '(' << get_operand() << ')';
	}

}

bool Unary_expression::get_operation_after_operand() const 
{
	return m_operation_after_operand;
}

char* Unary_expression::get_operation() const 
{
	return m_operation;
}
