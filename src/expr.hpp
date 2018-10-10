#pragma once

#include <iostream>

#include "value.hpp"
#include "type.hpp"
#include "printer.hpp"

class Decl;
class Value;

// Represents the base class of all expressions.
class Expr 
{
public:
    virtual Value evaluate() const = 0;
    /// Evaluates the expression.

    virtual Type* get_type() const = 0;
    /// Gets the type of the expression.

    virtual void print(Printer& p) const = 0;
    /// `Pretty prints` the expression.

    virtual void debug(Printer& p) const = 0;
    /// Prints the expression's associated addresses in memory.

    virtual void to_sexpr(Printer& p) const = 0;
    /// Prints the expression as a symbolic expression.
};


/// Represents the boolean literal expression of the form `true` or `false`.
class Bool_lit : public Expr 
{
public:   
    Bool_lit(bool b, Type* t);
    /// Constructs a boolean literal expression with the given arguments.

    void print(Printer& p) const override;
    /// `Pretty prints` the expression.

    void debug(Printer& p) const override;
    /// Prints the boolean literal expression's associated addresses in memory.

    void to_sexpr(Printer& p) const override;
    /// Prints the boolean literal expression as a symbolic expression.

    Value evaluate() const override;
    /// Evaluates the boolean literal expression.

    bool get_value() { return m_value; }
    /// Returns the boolean value of the boolean literal expression.

    Type* get_type() const override { return m_type; }
    /// Returns the type of the boolean literal expression.

private:
    bool m_value;
    /// The boolean value of the boolean literal expression.

    Type* m_type;
    /// The type of the boolean literal expression.
};

inline
Bool_lit::Bool_lit(bool b, Type* t) 
    : m_value(b), m_type(t) 
{ }

inline
Value Bool_lit::evaluate() const
{
    return Value(m_value);
}


/// Represents the integer literal of the form `1, 2, ..., n`.
class Int_lit : public Expr 
{
public:    
    Int_lit(int i, Type* t);
    /// Constructs an integer literal expression with the given arguments.

    void print(Printer& p) const override;
    /// `Pretty prints` the integer literal expression.

    void debug(Printer& p) const override;
    /// Prints the integer literal expression's associated addresses in memory.

    void to_sexpr(Printer& p) const override;
    /// Prints the integer literal expression as a symbolic expression.

    Value evaluate() const override;
    /// Evaluates the integer literal expression.

    int get_value() { return m_value; }
    /// Returns the integer value of the integer literal expression.

    Type* get_type() const override { return m_type; }
    /// Returns the type of the integer literal expression.

private:
    int m_value;
    /// The integer value of the integer literal expression.

    Type* m_type;
    /// The type of the integer literal expression.
};

inline
Int_lit::Int_lit(int i, Type* t) 
    : m_value(i), m_type(t) 
{ }

inline
Value Int_lit::evaluate() const
{
    return Value(m_value);
}


/// Represents the float literal of the form `1, 1.1, ..., n`.
class Float_lit : public Expr
{
public:    
    Float_lit(float f, Type* t);
    /// Constructs a float literal expression with the given arguments.

    void print(Printer& p) const override;
    /// `Pretty prints` the float literal expression.

    void debug(Printer& p) const override;
    /// Prints the float literal expression's associated addresses in memory.

    void to_sexpr(Printer& p) const override;
    /// Prints the float literal expression as a symbolic expression.

    Value evaluate() const override;
    /// Evaluates the float literal expression.
    
    Type* get_type() const override { return m_type; }
    /// Returns the type of the float literal expression.

    float get_value() { return m_value; }
    /// Returns the float value of the float literal expression.

private:
    float m_value;
    /// The float value of the float literal expression.

    Type* m_type;
    /// The type of the float literal expression.
};

inline
Float_lit::Float_lit(float f, Type* t) 
    : m_value(f), m_type(t) 
{ }

inline
Value Float_lit::evaluate() const
{
    return Value(m_value);
}


/// Represents the identifier expression of the form `x`.
class Id_expr : public Expr
{
public:
    Id_expr(Decl* d, Type* t);
    /// Constructs an identifier expression with the given arguments.

    void print(Printer& p) const override;
    /// `Pretty prints` the identifier expression.

    void debug(Printer& p) const override;
    /// Prints the identifier expression's associated addresses in memory.

    void to_sexpr(Printer& p) const override;
    /// Prints the identifier expression as a symbolic expression.

    Value evaluate() const override;
    /// Evaluates the identifier expression.

    Type* get_type() const override { return m_type; }
    /// Returns the type of the identifier expression.

    Decl* get_decl() { return m_value; }
    /// Gets the declaration of the identifier expression.

private:
    Decl* m_value;
    /// The declaration of the identifier expression.

    Type* m_type;
    /// The type of the identifier expression.
};

inline
Id_expr::Id_expr(Decl* d, Type* t) 
    : m_value(d), m_type(t) 
{ }

inline
Value Id_expr::evaluate() const
{
    throw std::logic_error("Cannot evaluate an identifier.");
}


/// Represents the logical and expression of the form `e1 and e2`.
class And_expr : public Expr 
{
public:
    And_expr(Expr* e1, Expr* e2, Type* t);
    /// Constructs an and expression with the given arguments.

    void print(Printer& p) const override;
    /// `Pretty prints` the and expression.

    void debug(Printer& p) const override;
    /// Prints the and expression's associated addresses in memory.

    void to_sexpr(Printer& p) const override;
    /// Prints the and expression as a symbolic expression.

    Value evaluate() const override;
    /// Evaluates the and expression.

   Type* get_type() const override { return m_type; }
    /// Returns the type of the and expression.

    Expr* get_lhs() { return m_e1; }
    /// Gets the left hand side expression of the and expression.

    Expr* get_rhs() { return m_e2; }
    /// Gets the right hand side expression of the and expression.


private:
    Expr* m_e1;
    /// The left hand side expression of the and expression.

    Expr* m_e2;
    /// The right hand side expression of the and expression.

    Type* m_type;
    /// The type of the and expression.
};

inline
And_expr::And_expr(Expr* e1, Expr* e2, Type* t) 
    : m_e1(e1), m_e2(e2), m_type(t) 
{ }

inline
Value And_expr::evaluate() const
{
    return Value(m_e1->evaluate().get_bool() && m_e2->evaluate().get_bool());
}


/// Represents the logical or expression of the form `e1 or e2`.
class Or_expr : public Expr 
{
public:
    Or_expr(Expr* e1, Expr* e2, Type* t);
    /// Constructs an or expression with the given arguments.

    void print(Printer& p) const override;
    /// `Pretty prints` the or expression.

    void debug(Printer& p) const override;
    /// Prints the or expression's associated addresses in memory.

    void to_sexpr(Printer& p) const override;
    /// Prints the or expression as a symbolic expression.

    Value evaluate() const override;
    /// Evaluates the or expression.
    
    Type* get_type() const override { return m_type; }
    /// Returns the type of the or expression.

    Expr* get_lhs() { return m_e1; }
    /// Gets the left hand side of the or expression.

    Expr* get_rhs() { return m_e2; }
    /// Gets the right hand side of the or expression.

private:
    Expr* m_e1;
    /// The left hand side expression of the or expression.

    Expr* m_e2;
    /// The right hand side expression of the or expression.

    Type* m_type;
    /// The type of the or expression.
};

inline
Or_expr::Or_expr(Expr* e1, Expr* e2, Type* t) 
    : m_e1(e1), m_e2(e2), m_type(t) 
{ }

inline
Value Or_expr::evaluate() const
{
    return Value(m_e1->evaluate().get_bool() || m_e2->evaluate().get_bool());
}


/// Represents the logical not expression of the form `not e1`.
class Not_expr : public Expr
{
public:
    Not_expr(Expr* e, Type* t);
    /// Constructs a not expression with the given arguments.

    void print(Printer& p) const override;
    /// `Pretty prints` the not expression.

    void debug(Printer& p) const override;
    /// Prints the not expression's associated addresses in memory.

    void to_sexpr(Printer& p) const override;
    /// Prints the not expression as a symbolic expression.

    Value evaluate() const override;
    /// Evaluates the not expression.

    Type* get_type() const override { return m_type; }
    /// Returns the type of the not expression.

    Expr* get_exp() { return m_expr; }
    /// Gets the expression not is being applied to.

    Type* get_type() { return m_type; }
    /// Returns the type of the not expression.

private:
    Expr* m_expr;
    /// The expression not is being applied to.

    Type* m_type;
    /// The type of the not expression.
};

inline
Not_expr::Not_expr(Expr* e, Type* t) 
    : m_expr(e), m_type(t) 
{ }

inline
Value Not_expr::evaluate() const
{
    return Value(!m_expr->evaluate().get_bool());
}


/// Represents the conditional expression of the form `if e1 then e2 else e3`.
class Con_expr : public Expr 
{
public:
    Con_expr(Expr* e1, Expr* e2, Expr* e3, Type* t);
    /// Constructs a conditional expression with the given arguments.

    void print(Printer& p) const override;
    /// `Pretty prints` the expression.

    void debug(Printer& p) const override;
    /// Prints the expression's associated addresses in memory.

    void to_sexpr(Printer& p) const override;
    /// Prints the expression as a symbolic expression.

    Value evaluate() const override;
    /// Evalutes the conditional expression.

    Type* get_type() const override { return m_type; }
    /// Returns the type of the conditional expression.

    Expr* get_if() { return m_e1; }
    /// Returns the if expression of the conditional expression.

    Expr* get_then() { return m_e2; }
    /// Returns the then expression of the conditional expression.

    Expr* get_else() { return m_e3; }
    /// Returns the else expression of the conditional expression.

private:
    Expr* m_e1;
    /// The if expression of the conditional expression.

    Expr* const m_e2;
    /// The then expression of the conditional expression.

    Expr* const m_e3;
    /// The else expression of the conditional expression.

    Type* m_type;
    /// The type of the conditional expression.
};

inline
Con_expr::Con_expr(Expr* e1, Expr* e2, Expr* e3, Type* t) 
    : m_e1(e1), m_e2(e2), m_e3(e3), m_type(t) 
{ }

inline
Value Con_expr::evaluate() const
{
    throw std::logic_error("Cannot evaluate a conditional expression.");
}


/// Represents the equality expression of the form `e1 = e2`.
class Eq_expr : public Expr
{
public:
    Eq_expr(Expr* e1, Expr* e2, Type* t);
    /// Constructs an equality expression with the given arguments.

    void print(Printer& p) const override;
    /// `Pretty prints` the equality expression.

    void debug(Printer& p) const override;
    /// Prints the equality expression's associated addresses in memory.

    void to_sexpr(Printer& p) const override;
    /// Prints the equality expression as a symbolic expression.

    Value evaluate() const override;
    /// Evaluates the equality expression.

    Type* get_type() const override { return m_type; }
    /// Returns the type of the equality expression.

    Expr* get_lhs() { return m_e1; }
    /// Gets the left hand side of the equality expression.

    Expr* get_rhs() { return m_e2; }
    /// Gets the right hand side of the equality expression.

private:
    Expr* m_e1;
    /// The left hand side of the equality expression.

    Expr* m_e2;
    /// The right hand side of the equality expression.

    Type* m_type;
    /// The type of the equality expression.
};

inline
Eq_expr::Eq_expr(Expr* e1, Expr* e2, Type* t) 
    : m_e1(e1), m_e2(e2), m_type(t) 
{ }

inline
Value Eq_expr::evaluate() const
{
    throw std::logic_error("Not implemented");
}


/// Represents the inequality expression of the form `e1 != e2`.
class Ne_expr : public Expr
{
public:
    Ne_expr(Expr* e1, Expr* e2, Type* t);
    /// Constructs an inequality expression with the given arguments.

    void print(Printer& p) const override;
    /// `Pretty prints` the inequality expression.

    void debug(Printer& p) const override;
    /// Prints the inequality expression's associated addresses in memory.

    void to_sexpr(Printer& p) const override;
    /// Prints the inequality expression as a symbolic expression.

    Value evaluate() const override;
    /// Evalutes the inequality expression.

    Type* get_type() const override { return m_type; }
    /// Returns the type of the inequality expression.

    Expr* get_lhs() { return m_e1; }
    /// Gets the left hand side of the inequality expression.

    Expr* get_rhs() { return m_e2; }
    /// Gets the right hand side of the inequality expression.

private:
    Expr* m_e1;
    /// The left hand side of the inequality expression.

    Expr* m_e2;
    /// The right hand side of the inequality expression.

    Type* m_type;
    /// The type of the inequality expression.
};

inline
Ne_expr::Ne_expr(Expr* e1, Expr* e2, Type* t) 
    : m_e1(e1), m_e2(e2), m_type(t) 
{ }

inline
Value Ne_expr::evaluate() const
{
    throw std::logic_error("Not implemented");
}


/// Represents the less than expression of the form `e1 < e2`.
class Lt_expr : public Expr
{
public:
    Lt_expr(Expr* e1, Expr* e2, Type* t);
    /// Constructs a less than expression with the given arguments.
     
    void print(Printer& p) const override;
    /// `Pretty prints` the less than expression.

    void debug(Printer& p) const override;
    /// Prints the less than expression's associated addresses in memory.

    void to_sexpr(Printer& p) const override;
    /// Prints the less than expression as a symbolic expression.

    Value evaluate() const override;
    /// Evaluates the less than expression.

    Type* get_type() const override { return m_type; }
    /// Returns the type of the less than expression.

    Expr* get_lhs() { return m_e1; }
    /// Gets the left hand side of the less than expression expression.

    Expr* get_rhs() { return m_e2; }
    /// Gets the right hand side of the less than expression expression.

private:
    Expr* m_e1;
    /// The left hand side expression of the less than expression.

    Expr* m_e2;
    /// The right hand side expression of the less than expression.

    Type* m_type;
    /// The type of the less than expression.
};

inline
Lt_expr::Lt_expr(Expr* e1, Expr* e2, Type* t) 
    : m_e1(e1), m_e2(e2), m_type(t) 
{ }

inline
Value Lt_expr::evaluate() const 
{
    throw std::logic_error("Not implemented");
}


/// Represents the greater than expression of the form `e1 > e2`.
class Gt_expr : public Expr
{
public:
    Gt_expr(Expr* e1, Expr* e2, Type* t);
    /// Constructs a greater than expression with the given arguments.

    void print(Printer& p) const override;
    /// `Pretty prints` the greater than expression.

    void debug(Printer& p) const override;
    /// Prints the greater than expression's associated addresses in memory.

    void to_sexpr(Printer& p) const override;
    /// Prints the greater than expression as a symbolic expression.

    Value evaluate() const override;
    /// Evaluates the greater than expression.

    Type* get_type() const override { return m_type; }
    /// Returns the type of the greater than expression.

    Expr* get_lhs() { return m_e1; }
    /// Gets the left hand side of the greater than expression.

    Expr* get_rhs() { return m_e2; }
    /// Gets the right hand side of the greater than expression.

private:
    Expr* m_e1;
    /// The left hand side expression of the greater than expression.

    Expr* m_e2;
    /// The right hand side expression of the greater than expression.

    Type* m_type;
    /// The type of the greater than expression.
};

inline
Gt_expr::Gt_expr(Expr* e1, Expr* e2, Type* t) 
    : m_e1(e1), m_e2(e2), m_type(t) 
{ }

inline
Value Gt_expr::evaluate() const 
{
    throw std::logic_error("Not implemented");
}


/// Represents the less than or equal expression of the form `e1 <= e2`.
class Le_expr : public Expr
{
public:
    Le_expr(Expr* e1, Expr* e2, Type* t);
    /// Constructs a less than or equal expression with the given arguments.

    void print(Printer& p) const override;
    /// `Pretty prints` the less than or equal expression.

    void debug(Printer& p) const override;
    /// Prints the less than or equal expression's associated addresses in memory.

    void to_sexpr(Printer& p) const override;
    /// Prints the less than or equal expression as a symbolic expression.

    Value evaluate() const override;
    /// Evaluates the less than or equal expression.

    Type* get_type() const override { return m_type; }
    /// Returns the type of the less than or equal  expression.

    Expr* get_lhs() { return m_e1; }
    /// Gets the left hand side of the less than or equal expression.

    Expr* get_rhs() { return m_e2; }
    /// Gets the right hand side of the less than or equal expression.

private:
    Expr* m_e1;
    /// The left hand side expression of the less than or equal expression.

    Expr* m_e2;
    /// The right hand side expression of the less than or equal expression.

    Type* m_type;
    /// The type of the less than or equal expression.
};

inline
Le_expr::Le_expr(Expr* e1, Expr* e2, Type* t) 
    : m_e1(e1), m_e2(e2), m_type(t) 
{ }

inline
Value Le_expr::evaluate() const 
{
    throw std::logic_error("Not implemented");
}


/// Represents the greater than or equal expression of the form `e1 >= e2`.
class Ge_expr : public Expr 
{
public:
    Ge_expr(Expr* e1, Expr* e2, Type* t);
    /// Constructs a greater than or equal expression with the given arguments.

    void print(Printer& p) const override;
    /// `Pretty prints` the greater than or equal expression.

    void debug(Printer& p) const override;
    /// Prints the greater than or equal expression's associated addresses in memory.

    void to_sexpr(Printer& p) const override;
    /// Prints the greater than or equal expression as a symbolic expression.

    Value evaluate() const override;
    /// Evaluates the greater than or equal expression.

    Type* get_type() const override { return m_type; }
    /// Returns the type of the greater than or equal expression.

    Expr* get_lhs() { return m_e1; }
    /// Gets the left hand side of the greater than or equal expression.

    Expr* get_rhs() { return m_e2; }
    /// Gets the right hand side of the greater than or equal expression.

private:
    Expr* m_e1;
    /// The left hand side expression of the greater than or equal expression.

    Expr* m_e2;
    /// The right hand side expression of the greater than or equal expression.

    Type* m_type;
    /// The type of the greater than or equal expression.
};

inline
Ge_expr::Ge_expr(Expr* e1, Expr* e2, Type* t) 
    : m_e1(e1), m_e2(e2), m_type(t) 
{ }

inline
Value Ge_expr::evaluate() const 
{
    throw std::logic_error("Not implemented");
}


/// Represents the addition expression of the form `e1 + e2`.
class Add_expr : public Expr
{
public:
    Add_expr(Expr* e1, Expr* e2, Type* t);
    /// Constructs an addition expression with the given arguments.

    void print(Printer& p) const override;
    /// `Pretty prints` the addition expression.

    void debug(Printer& p) const override;
    /// Prints the addition expression's associated addresses in memory.

    void to_sexpr(Printer& p) const override;
    /// Prints the addition expression as a symbolic expression.

    Value evaluate() const override;
    /// Evaluates the addition expression.

    Type* get_type() const override { return m_type; }
    /// Returns the type of the addition expression.

    Expr* get_lhs() { return m_e1; }
    /// Gets the left hand side of the addition expression.

    Expr* get_rhs() { return m_e2; }
    /// Gets the right hand side of the addition expression.

private:
    Expr* m_e1;
    /// The left hand side expression of the addition expression.

    Expr* m_e2;
    /// The right hand side expression of the addition expression.

    Type* m_type;
    /// The type of the addition expression.
};

inline
Add_expr::Add_expr(Expr* e1, Expr* e2, Type* t) 
    : m_e1(e1), m_e2(e2), m_type(t) 
{ }

inline
Value Add_expr::evaluate() const 
{
    throw std::logic_error("Not implemented");
}


/// Represents the subtraction expression of the form `e1 - e2`.
class Sub_expr : public Expr 
{
public:
    Sub_expr(Expr* e1, Expr* e2, Type* t);
    /// Constructs a subtraction expression with the given arguments.

    void print(Printer& p) const override;
    /// `Pretty prints` the subtraction expression.

    void debug(Printer& p) const override;
    /// Prints the subtraction expression's associated addresses in memory.

    void to_sexpr(Printer& p) const override;
    /// Prints the subtraction expression as a symbolic expression.

    Value evaluate() const override;
    /// Evaluates the subtraction expression.
    
    Type* get_type() const override { return m_type; }
    /// Returns the type of the subtraction expression.

    Expr* get_lhs() { return m_e1; }
    /// Gets the left hand side of the subtraction expression.

    Expr* get_rhs() { return m_e2; }
    /// Gets the right hand side of the subtraction expression.

private:
    Expr* m_e1;
    /// The left hand side expression of the subtraction expression.

    Expr* m_e2;
    /// The right hand side expression of the subtraction expression.

    Type* m_type;
    /// The type of the subtraction expression.
};

inline
Sub_expr::Sub_expr(Expr* e1, Expr* e2, Type* t) 
    : m_e1(e1), m_e2(e2), m_type(t) 
{ }

inline
Value Sub_expr::evaluate() const
{
    throw std::logic_error("Not implemented");
}


/// Represents the multiplication expression of the form `e1 * e2`.
class Mul_expr : public Expr
{
public:
    Mul_expr(Expr* e1, Expr* e2, Type* t);
    /// Constructs a multiplication expression with the given arugments.

    void print(Printer& p) const override;
    /// `Pretty prints` the multiplication expression.

    void debug(Printer& p) const override;
    /// Prints the multiplication expression's associated addresses in memory.

    void to_sexpr(Printer& p) const override;
    /// Prints the multiplication expression as a symbolic expression.

    Value evaluate() const override;
    /// Evaluates the multiplication expression.

    Type* get_type() const override { return m_type; }
    /// Returns the type of the multiplication expression.

    Expr* get_lhs() { return m_e1; }
    /// Gets the left hand side of the multiplication expression.

    Expr* get_rhs() { return m_e2; }
    /// Gets the right hand side of the multiplication expression.

private:
    Expr* m_e1;
    /// The left hand side expression of the multiplication expression.

    Expr* m_e2;
    /// The right hand side expression of the multiplication expression.

    Type* m_type;
    /// The type of the multiplication expression.
};

inline
Mul_expr::Mul_expr(Expr* e1, Expr* e2, Type* t) 
    : m_e1(e1), m_e2(e2), m_type(t) 
{ }

inline
Value Mul_expr::evaluate() const 
{
    throw std::logic_error("Not implemented");
}


/// Represents the quotient expression of the form `e1 / e2`.
class Quo_expr : public Expr
{
public:
    Quo_expr(Expr* e1, Expr* e2, Type* t);
    /// Constructs a quotient expression with the given arguments.

    void print(Printer& p) const override;
    /// `Pretty prints` the quotient expression.

    void debug(Printer& p) const override;
    /// Prints the quotient expression's associated addresses in memory.

    void to_sexpr(Printer& p) const override;
    /// Prints the quotient expression as a symbolic expression.

    Value evaluate() const override;
    /// Evaluates the quotient expression.
    
    Type* get_type() const override { return m_type; }
    /// Returns the type of the quotient expression.

    Expr* get_lhs() { return m_e1; }
    /// Gets the left hand side of the quotient expression.

    Expr* get_rhs() { return m_e2; }
    /// Gets the right hand side of the quotient expression.

private:
    Expr* m_e1;
    /// The left hand side expression of the quotient expression.

    Expr* m_e2;
    /// The right hand side expression of the quotient expression.

    Type* m_type;
    /// The type of the quotient expression.
};

inline
Quo_expr::Quo_expr(Expr* e1, Expr* e2, Type* t) 
    : m_e1(e1), m_e2(e2), m_type(t) 
{ }

inline
Value Quo_expr::evaluate() const 
{
    throw std::logic_error("Not implemented");
}


/// Represents the remainder expression of the form `e1 % e2`.
class Rem_expr : public Expr
{
public:
    Rem_expr(Expr* e1, Expr* e2, Type* t);
    /// Constructs a remainder expression with the given arguments.

    void print(Printer& p) const override;
    /// `Pretty prints` the remainder expression.

    void debug(Printer& p) const override;
    /// Prints the remainder expression's associated addresses in memory.

    void to_sexpr(Printer& p) const override;
    /// Prints the remainder expression as a symbolic expression.

    Value evaluate() const override;
    /// Evaluates the remainder expression.

    Type* get_type() const override { return m_type; }
    /// Returns the type of the remainder expression.

    Expr* get_lhs() { return m_e1; }
    /// Gets the left hand side of the remainder expression.

    Expr* get_rhs() { return m_e2; }
    /// Gets the right hand side of the remainder expression.

private:
    Expr* m_e1;
    /// The left hand side expression of the remainder expression.

    Expr* m_e2;
    /// The right hand side expression of the remainder expression.

    Type* m_type;
    /// The type of the remainder expression.
};

inline
Rem_expr::Rem_expr(Expr* e1, Expr* e2, Type* t) 
    : m_e1(e1), m_e2(e2), m_type(t) 
{ }

inline
Value Rem_expr::evaluate() const 
{
    throw std::logic_error("Not implemented");
}


// Represents the negation expression of the form `-e1`.
class Neg_expr : public Expr
{
public:
    Neg_expr(Expr* e, Type* t);
    /// Constructs a negation expression with the given arguments.

    void print(Printer& p) const override;
    /// `Pretty prints` the negation expression.

    void debug(Printer& p) const override;
    /// Prints the negation expression's associated addresses in memory.

    void to_sexpr(Printer& p) const override;
    /// Prints the negation expression as a symbolic expression.

    Value evaluate() const override;
    /// Evaluates the negation expression.

    Type* get_type() const override { return m_type; }
    /// Returns the type of the negation expression.

    Expr* get_expr() { return m_expr; }
    /// Gets the negated expression.

private:
    Expr* m_expr;
    /// The expression being negated.

    Type* m_type;
    /// The type of the negation expression.
};

inline
Neg_expr::Neg_expr(Expr* e, Type* t) 
    : m_expr(e), m_type(t) 
{ }

inline
Value Neg_expr::evaluate() const 
{
    throw std::logic_error("Not implemented");
}


/// Represents the reciprocal expression of the form `/e1`.
class Rec_expr : public Expr 
{
public:
    Rec_expr(Expr* e, Type* t);
    /// Constructs a reciprocal expression with the given arguments.

    void print(Printer& p) const override;
    /// `Pretty prints` the reciprocal expression.

    void debug(Printer& p) const override;
    /// Prints the reciprocal expression's associated addresses in memory.

    void to_sexpr(Printer& p) const override;
    /// Prints the reciprocal expression as a symbolic expression.

    Value evaluate() const override;
    /// Evaluates the reciprocal expression.

    Type* get_type() const override { return m_type; }
    /// Returns the type of the reciprocal expression.

    Expr* get_expr() { return m_expr; }
    /// Gets the expression the reciprocal is being applied to.

private:
    Expr* m_expr;
    /// The expression the reciprocal is being applied to.

    Type* m_type;
    /// The type of the reciprocal expression.
};

inline
Rec_expr::Rec_expr(Expr* e, Type* t) 
    : m_expr(e), m_type(t) 
{ }

inline
Value Rec_expr::evaluate() const 
{
    throw std::logic_error("Not implemented");
}


/// Represents the assignment expression of the form `e1 <- e2`.
class Ass_expr : public Expr
{
public:
    Ass_expr(Expr* src, Expr* tar, Type* t);
    /// Constructs an assignment expression with the given arguments.
    
    void print(Printer& p) const override;
    /// `Pretty prints` the assignment expression.

    void debug(Printer& p) const override;
    /// Prints the assignment expression's associated addresses in memory.

    void to_sexpr(Printer& p) const override;
    /// Prints the assignment expression as a symbolic expression.

    Value evaluate() const override;
    /// Evaluates the assignment expression.

    Type* get_type() const override { return m_type; }
    /// Returns the type of the assignment expression.

    Expr* get_src() { return m_src; }
    /// Gets the source expression of the assignment expresion.
    
    Expr* get_tar() { return m_tar; }
    /// Gets the target expression of the assignment expression.

private:
    Type* m_type;
    /// The type of the assignment expression.

    Expr* m_src;
    /// The expression source of the assignment expression.

    Expr* m_tar;
    /// The expression target of the assignment expression.
};

inline
Ass_expr::Ass_expr(Expr* src, Expr* tar, Type* t)
    : m_src(src), m_tar(tar), m_type(t)
{ }

inline
Value Ass_expr::evaluate() const 
{
    throw std::logic_error("Cannot evaluate an assignment expression.");
}


/// Represents the function call expression of the form `ef(e1, e2, ..., en)`.
class Call_expr : public Expr
{
public:
    Call_expr(std::vector<Expr*>* exprs, Type* t);
    /// Constructs a function call expression with the given arguments.

    void print(Printer& p) const override;
    /// `Pretty prints` the function call expression.

    void debug(Printer& p) const override;
    /// Prints the function call expression's associated addresses in memory.

    void to_sexpr(Printer& p) const override;
    /// Prints the function call expression as a symbolic expression.

    Value evaluate() const override;
    /// Evaluates the function call expression.

    Type* get_type() const override { return m_type; }
    /// Returns the type of the function call expression.

    std::vector<Expr*>* get_exprs() { return m_exprs; }
    /// Returns the parameters of the function call expression.

private:
    Type* m_type;
    /// Tye type of the function call.

    std::vector<Expr*>* m_exprs;
    /// The parameters of the function call.
};

inline
Call_expr::Call_expr(std::vector<Expr*>* exprs, Type* t)
    : m_exprs(exprs), m_type(t)
{ }

inline
Value Call_expr::evaluate() const 
{
    throw std::logic_error("Cannot evaluate a function call expression.");
}


// Operators

std::ostream& operator<<(std::ostream &os, Expr const& e);
/// Write `e` to the output stream.
