#include "BooleanLiteral.hpp"
#include <iostream>

void
Boolean_literal::print() const
{
	std::cout << std::boolalpha << m_value << '\n';
}
