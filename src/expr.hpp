#pragma Once

#include <array>
#include <string>

class Value
{

};

class Expr
{
public:

	Expr(std::string expr_str)
	{
		m_exp = expr_str;
	}
	
	Expr() 
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



class Integer_literal : Expr
{
public:
	Integer_literal(int v) 
		: m_value(v)
	{}
	virtual void print() const;

private:
	int m_value;
};


class Boolean_literal : Expr
{
public:
	Boolean_literal(bool v) 
		: m_value(v)
	{}
	virtual void print() const;

private:
	int m_value;

};


class Unary_expression : Expr {
public:

	/// Construct a unary expression
	Unary_expression(Expr*, char*, bool);

	/// Gets the expression operand
	Expr* get_operand() const;

	/// Gets the name of the operation performed
	char* get_operation() const;
	
	/// Determines whether the operator is before or after the operand
	bool get_operation_after_operand() const;

	/// Prints the unary expression
	virtual void print() const;

private:
	Expr* m_operand;
	char* m_operation; 
	bool m_operation_after_operand;
};


class Binary_expression : public Expr 
{
public:
	Binary_expression(Expr* operand0, Expr* operand1, char const* operation);

	Expr* get_lhs() const;

	Expr* get_rhs() const;

	char const* get_operation() const;

	virtual std::string const get_string() const;

private:
	std::array<Expr*, 2> m_operands;
	char const* m_operation;
};

