#include "Expression.hpp"

class Binary_expression : public Expression 
{
public:
	Binary_expression(Expression* operand0, Expression* operand1, char const* operation);

	Expression* get_lhs() const;

	Expression* get_rhs() const;

	char const* get_operation() const;

	virtual void print();

private:
	std::array<Expression*, 2> m_operands;
	char const* m_operation;
};
