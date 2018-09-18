#include "Expression.hpp"

class Logical_and_expression : Expression
{
public:
	Logical_and_expression(Expression const* left, Expression const* right) 
	{
        m_left = left;
        m_right = right;
    }
	virtual void print() const;

private:
	Expression const* m_left;
    Expression const* m_right;  
};

class Logical_or_expression : Expression
{
public:
	Logical_or_expression(Expression const* left, Expression const* right) 
	{
        m_left = left;
        m_right = right;
    }
	virtual void print() const;

private:
	Expression const* m_left;
    Expression const* m_right;
};

class Logical_not_expression : Expression
{
public:
	Logical_not_expression(Expression const* expr) 
	{
        m_expr = expr;
    }
	virtual void print() const;

private:
	Expression const* m_expr;    
};