#include <iostream>

#include "expr.hpp"

/*
* Integer literal
*/
void
Integer_literal::print() const
{
	std::cout << m_value << '\n';
}


/*
* Boolean literal
*/
void
Boolean_literal::print() const
{
	std::cout << std::boolalpha << m_value << '\n';
}


/*
 * Unary Expression
*/
Unary_expression::Unary_expression(Expr* expr, char* operation, bool operation_after_operand)
{
	m_operand = expr;
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

bool 
Unary_expression::get_operation_after_operand() const 
{
	return m_operation_after_operand;
}

char* 
Unary_expression::get_operation() const 
{
	return m_operation;
}

Expr* 
Unary_expression::get_operand() const
{
	return m_operand;
}


/*
* Binary Expression
*/
Binary_expr::Binary_expr(Expr* operand0, Expr* operand1, char const* operation)
{
    m_operands[0] = operand0;
    m_operands[1] = operand1;
    m_operation = operation;
}

std::string const
Binary_expr::get_string() const
{
    std::string lhs = "(" + get_lhs()->get_string() + ")";
    std::string rhs = "(" + get_rhs()->get_string() + ")";
    return lhs + " " + get_operation() + " " + rhs + "\n";
}

Expr*
Binary_expr::get_lhs() const
{
    return m_operands[0];
}

Expr* 
Binary_expr::get_rhs() const 
{
    return m_operands[1];
}

char const*
Binary_expr::get_operation() const 
{
    return m_operation;
}