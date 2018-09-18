#include "LogicalExpression.hpp"
#include <iostream>

void Logical_and_expression::print() const
{
    std::cout << m_left << " and " << m_right;
}

void Logical_or_expression::print() const
{
    std::cout << m_left << " or " << m_right;
}

void Logical_not_expression::print() const
{
    std::cout << "not " << m_expr;
}