#pragma once

#include <array>
#include <string>

#include "../Value.hpp"

class Expression
{
public:

	// Evaluation
	/// Compute a value from the expression.
	// virtual Value evaluate() const;


	// Printing
	/// Print a representation of the expression
	//virtual void print();


	// Debugging
	/// Print a textual representation of the expression tree
	// void dump() const;

	char const* string_literal;

};

// class Nullary_expression : Expression 
// {

// };