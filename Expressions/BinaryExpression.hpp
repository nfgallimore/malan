#include "Expression.hpp"

class Binary_expression : Expression 
{
public:
	Binary_expression(Expression* operand0, Expression* operand1, char* operation);

	Expression* get_lhs() const;

	Expression* get_rhs() const;

	char* get_operation() const;

	virtual void print() const;

private:
	std::array<Expression*, 2> m_operands;
	char* m_operation;
};
