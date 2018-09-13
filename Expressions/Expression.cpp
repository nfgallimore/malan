#include "Expression.hpp"

#include <iostream>
#include <iomanip>

void
Boolean_literal::print() const
{
	std::cout << std::boolalpha << m_value << '\n';
}

void
Integer_literal::print() const
{
	std::cout << m_value << '\n';
}


Binary_expression::Binary_expression(Binary_expression const* expr, char const* op)
{
	std::cout << '(' << expr->get_lhs() << ' ';
	std::cout << op << ' ';
	expr->get_rhs();
	std::cout << ' ' << ')';
}

/// Prints '(+ e1 e2)'
// void
// Add_expression::to_sexpr() const
// {
// 	cout << "(+ "
// 	<< get_operand(0) << ' '
// 	cout << std::boolalpha << m_value << '\n';

// }

// void
// Sub_expression::to_sexpr() const
// {
// 	cout << std::boolalpha << m_value << '\n';
// }

// void
// Mul_expression::to_sexpr() const
// {
// 	cout << std::boolalpha << m_value << '\n';
// }

// void
// Quo_expression::to_sexpr() const
// {
// 	cout << std::boolalpha << m_value << '\n';
// }

// void
// Rem_expression::to_sexpr() const
// {
// 	cout << std::boolalpha << m_value << '\n';
// }