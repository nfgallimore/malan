#pragma once

#include <array>
#include <string>

#include "../Value.hpp"

class Expression
{
public:

	Expression(std::string expr_str)
	{
		m_exp = expr_str;
	}
	
	Expression() 
	{

	}

	// Evaluation
	/// Compute a value from the expression.
	// virtual Value evaluate() const;

	// Debugging
	/// Print a textual representation of the expression tree
	// void dump() const;


	// String representation
	/// Get the expression as a string literal
	virtual std::string const get_string() const 
	{
		return m_exp;
	}

private:
	std::string m_exp;
};