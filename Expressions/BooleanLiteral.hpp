#include "Expression.hpp"

class Boolean_literal : Expression
{
public:
	Boolean_literal(bool v) 
		: m_value(v)
	{}
	virtual void print() const;

private:
	int m_value;

};
