#pragma once

#include <array>
#include "../Value.hpp"

class Expression
{
public:

	// Evaluation
	/// Compute a value from the expression.
	virtual Value evaluate() const = 0;


	// Printing
	/// Print a representation of the expression
	virtual void print();


	// Debugging
	/// Print a textual representation of the expression tree
	void dump() const;
};

class Nullary_expression : Expression 
{

};