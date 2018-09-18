#include "Expression.hpp"

#include <iostream>
#include <iomanip>

char const* Expression::get_string() const
{
    return string_literal;
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