#include "Expression.hpp"

class Integer_literal : Expression
{
public:
	Integer_literal(int v) 
		: m_value(v)
	{}
	virtual void print() const;

private:
	int m_value;
};
