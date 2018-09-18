#include "Expression.hpp"
#include <string>

class Binary_expression : public Expression 
{
public:
	Binary_expression(Expression* operand0, Expression* operand1, char const* operation);

	Expression* get_lhs() const;

	Expression* get_rhs() const;

	char const* get_operation() const;

	virtual std::string const get_string() const;

private:
	std::array<Expression*, 2> m_operands;
	char const* m_operation;
};
