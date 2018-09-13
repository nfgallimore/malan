#include "Expression.hpp"

class Unary_expression : Expression {
public:

	/// Construct a unary expression
	Unary_expression(Expression*, char*, bool);

	/// Gets the expression operand
	Expression* get_operand() const;

	/// Gets the name of the operation performed
	char* get_operation() const;
	
	/// Determines whether the operator is before or after the operand
	bool get_operation_after_operand() const;

	/// Prints the unary expression
	virtual void print() const;

private:
	Expression* m_operand;
	char* m_operation; 
	bool m_operation_after_operand;
};
