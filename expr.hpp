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
    /// Evaluates the expression.
    virtual Value evaluate() const = 0;

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
    /// Prints the expression's associated addresses in memory.

    void to_sexpr(Printer& p) const override;
    /// Prints the expression as a symbolic expression.

    Value evaluate() const override { return Value(m_value); }
    /// Evaluates the expression.

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


/// Represents the integer literal of the form `1, 2, ..., n`
class Int_lit : public Expr 
{
public:    
    Int_lit(int i, Type* t) 
        : m_value(i), m_type(t) 
    { }

    void print(Printer& p) const override;
    /// `Pretty prints` the expression.

    void debug(Printer& p) const override;
    /// Prints the expression's associated addresses in memory.

    void to_sexpr(Printer& p) const override;
    /// Prints the expression as a symbolic expression.

    Value evaluate() const override { return Value(m_value); }
    /// Evaluates the expression.

private:
    int m_value;
    Type* m_type;
};


/// Represents the float literal of the form `1, 1.1, ..., n`.
class Float_lit : public Expr
{
public:    
    Float_lit(float f, Type* t) 
        : m_value(f), m_type(t) 
    { }

    void print(Printer& p) const override;
    /// `Pretty prints` the expression.

    void debug(Printer& p) const override;
    /// Prints the expression's associated addresses in memory.

    void to_sexpr(Printer& p) const override;
    /// Prints the expression as a symbolic expression.

    Value evaluate() const override { return Value(m_value); }
    /// Evaluates the expression.

private:
    float m_value;
    Type* m_type;
};


/// Represents the identifier expression of the form `x`.
class Id_expr : public Expr
{
public:
    Id_expr(Decl* d, Type* t) 
        : m_value(d), m_type(t) 
    { }

    void print(Printer& p) const override;
    /// `Pretty prints` the expression.

    void debug(Printer& p) const override;
    /// Prints the expression's associated addresses in memory.

    void to_sexpr(Printer& p) const override;
    /// Prints the expression as a symbolic expression.

    Value evaluate() const override { throw std::logic_error("Cannot evaluate an identifier."); }
    /// Evaluates the expression.

private:
    Decl* m_value;
    Type* m_type;
};


/// Represents the logical AND expression of the form `e1 and e2`.
class And_expr : public Expr 
{
public:
    And_expr(Expr* e1, Expr* e2, Type* t) : m_e1(e1), m_e2(e2), m_type(t) { }

    void print(Printer& p) const override;
    /// `Pretty prints` the expression.

    void debug(Printer& p) const override;
    /// Prints the expression's associated addresses in memory.

    void to_sexpr(Printer& p) const override;
    /// Prints the expression as a symbolic expression.

    Value evaluate() const override {
        return Value(m_e1->evaluate().get_bool() && m_e2->evaluate().get_bool());
    }
    /// Evaluates the expression.

    Expr* get_lhs() { return m_e1; }
    Expr* get_rhs() { return m_e2; }
private:
    Expr* m_e1;
    Expr* m_e2;
    Type* m_type;
};


/// Represents the logical OR expression of the form `e1 or e2`.
class Or_expr : public Expr 
{
public:
    Or_expr(Expr* e1, Expr* e2, Type* t) 
        : m_e1(e1), m_e2(e2), m_type(t) 
    { }

    void print(Printer& p) const override;
    /// `Pretty prints` the expression.

    void debug(Printer& p) const override;
    /// Prints the expression's associated addresses in memory.

    void to_sexpr(Printer& p) const override;
    /// Prints the expression as a symbolic expression.

    Value evaluate() const override {
        return Value(m_e1->evaluate().get_bool() || m_e2->evaluate().get_bool());
    }
    Expr* get_lhs() { return m_e1; }
    Expr* get_rhs() { return m_e2; }
private:
    Expr* m_e1;
    Expr* m_e2;
    Type* m_type;
};


/// Represents the logical NOT expression of the form `not e1`.
class Not_expr : public Expr {
public:
    Not_expr(Expr* e, Type* t) 
        : m_expr(e), m_type(t) 
    { }

    void print(Printer& p) const override;
    /// `Pretty prints` the expression.

    void debug(Printer& p) const override;
    /// Prints the expression's associated addresses in memory.

    void to_sexpr(Printer& p) const override;
    /// Prints the expression as a symbolic expression.

    Value evaluate() const override {
        return Value(!m_expr->evaluate().get_bool());
    }
    Expr* get_exp() { return m_expr; }
private:
    Expr* m_expr;
    Type* m_type;
};


/// Represents the conditional expression of the form `if e1 then e2 else e3`.
class Con_expr : public Expr 
{
public:
    Con_expr(Expr* e1, Expr* e2, Expr* e3, Type* t) 
        : m_e1(e1), m_e2(e2), m_e3(e3), m_type(t) 
    { }

    void print(Printer& p) const override;
    /// `Pretty prints` the expression.

    void debug(Printer& p) const override;
    /// Prints the expression's associated addresses in memory.

    void to_sexpr(Printer& p) const override;
    /// Prints the expression as a symbolic expression.

    Value evaluate() const override {
        throw std::logic_error("Cannot evaluate ternary expression.");
    }
private:
    Expr* m_e1;
    Expr* const m_e2;
    Expr* const m_e3;
    Type* m_type;
};


/// Represents the equality expression of the form `e1 = e2`.
class Eq_expr : public Expr
{
public:
    Eq_expr(Expr* e1, Expr* e2, Type* t) 
        : m_e1(e1), m_e2(e2), m_type(t) 
    { }
    void print(Printer& p) const override;
    /// `Pretty prints` the expression.

    void debug(Printer& p) const override;
    /// Prints the expression's associated addresses in memory.

    void to_sexpr(Printer& p) const override;
    /// Prints the expression as a symbolic expression.

    Value evaluate() const override {
        throw std::logic_error("Not implemented");
    }
private:
    Expr* m_e1;
    Expr* m_e2;
    Type* m_type;
};


/// Represents the not equal expression of the form `e1 != e2`.
class Ne_expr : public Expr
{
public:
    Ne_expr(Expr* e1, Expr* e2, Type* t) 
        : m_e1(e1), m_e2(e2), m_type(t) 
    { }

    void print(Printer& p) const override;
    /// `Pretty prints` the expression.

    void debug(Printer& p) const override;
    /// Prints the expression's associated addresses in memory.

    void to_sexpr(Printer& p) const override;
    /// Prints the expression as a symbolic expression.

    Value evaluate() const override {
        throw std::logic_error("Not implemented");
    }
private:
    Expr* m_e1;
    Expr* m_e2;
    Type* m_type;
};


/// Represents the less than expression of the form `e1 < e2`.
class Lt_expr : public Expr
{
public:
    Lt_expr(Expr* e1, Expr* e2, Type* t) 
        : m_e1(e1), m_e2(e2), m_type(t) 
    { }

    void print(Printer& p) const override;
    /// `Pretty prints` the expression.

    void debug(Printer& p) const override;
    /// Prints the expression's associated addresses in memory.

    void to_sexpr(Printer& p) const override;
    /// Prints the expression as a symbolic expression.

    Value evaluate() const override {
        throw std::logic_error("Not implemented");
    }
private:
    Expr* m_e1;
    Expr* m_e2;
    Type* m_type;
};


/// Represents the greater than expression of the form `e1 > e2`.
class Gt_expr : public Expr
{
public:
    Gt_expr(Expr* e1, Expr* e2, Type* t) 
        : m_e1(e1), m_e2(e2), m_type(t) 
    { }

    void print(Printer& p) const override;
    /// `Pretty prints` the expression.

    void debug(Printer& p) const override;
    /// Prints the expression's associated addresses in memory.

    void to_sexpr(Printer& p) const override;
    /// Prints the expression as a symbolic expression.

    Value evaluate() const override {
        throw std::logic_error("Not implemented");
    }
private:
    Expr* m_e1;
    Expr* m_e2;
    Type* m_type;
};

/// Represents the less than or equal expression of the form `e1 <= e2`.
class Le_expr : public Expr
{
public:
    Le_expr(Expr* e1, Expr* e2, Type* t) 
        : m_e1(e1), m_e2(e2), m_type(t) 
    { }

    void print(Printer& p) const override;
    /// `Pretty prints` the expression.

    void debug(Printer& p) const override;
    /// Prints the expression's associated addresses in memory.

    void to_sexpr(Printer& p) const override;
    /// Prints the expression as a symbolic expression.

    Value evaluate() const override {
        throw std::logic_error("Not implemented");
    }
private:
    Expr* m_e1;
    Expr* m_e2;
    Type* m_type;
};


/// Represents the greater than or equal expression of the form `e1 >= e2`.
class Ge_expr : public Expr 
{
public:
    Ge_expr(Expr* e1, Expr* e2, Type* t) 
        : m_e1(e1), m_e2(e2), m_type(t) 
    { }

    void print(Printer& p) const override;
    /// `Pretty prints` the expression.

    void debug(Printer& p) const override;
    /// Prints the expression's associated addresses in memory.

    void to_sexpr(Printer& p) const override;
    /// Prints the expression as a symbolic expression.

    Value evaluate() const override {
        throw std::logic_error("Not implemented");
    }
private:
    Expr* m_e1;
    Expr* m_e2;
    Type* m_type;
};


/// Represents the addition expression of the form `e1 + e2`.
class Add_expr : public Expr
{
public:
    Add_expr(Expr* e1, Expr* e2, Type* t) 
        : m_e1(e1), m_e2(e2), m_type(t) 
    { }

    void print(Printer& p) const override;
    /// `Pretty prints` the expression.

    void debug(Printer& p) const override;
    /// Prints the expression's associated addresses in memory.

    void to_sexpr(Printer& p) const override;
    /// Prints the expression as a symbolic expression.

    Value evaluate() const override {
        throw std::logic_error("Not implemented");
    }
private:
    Expr* m_e1;
    Expr* m_e2;
    Type* m_type;
};


/// Represents the subtraction expression of the form `e1 - e2`.
class Sub_expr : public Expr 
{
public:
    Sub_expr(Expr* e1, Expr* e2, Type* t) 
        : m_e1(e1), m_e2(e2), m_type(t) 
    { }

    void print(Printer& p) const override;
    /// `Pretty prints` the expression.

    void debug(Printer& p) const override;
    /// Prints the expression's associated addresses in memory.

    void to_sexpr(Printer& p) const override;
    /// Prints the expression as a symbolic expression.

    Value evaluate() const override {
        throw std::logic_error("Not implemented");
    }
private:
    Expr* m_e1;
    Expr* m_e2;
    Type* m_type;
};


/// Represents the multiplication expression of the form `e1 * e2`.
class Mul_expr : public Expr
{
public:
    Mul_expr(Expr* e1, Expr* e2, Type* t) 
        : m_e1(e1), m_e2(e2), m_type(t) 
    { }

    void print(Printer& p) const override;
    /// `Pretty prints` the expression.

    void debug(Printer& p) const override;
    /// Prints the expression's associated addresses in memory.

    void to_sexpr(Printer& p) const override;
    /// Prints the expression as a symbolic expression.

    Value evaluate() const override {
        throw std::logic_error("Not implemented");
    }
private:
    Expr* m_e1;
    Expr* m_e2;
    Type* m_type;
};


/// Represents the quotient expression of the form `e1 / e2`.
class Quo_expr : public Expr
{
public:
    Quo_expr(Expr* e1, Expr* e2, Type* t) 
        : m_e1(e1), m_e2(e2), m_type(t) 
    { }

    void print(Printer& p) const override;
    /// `Pretty prints` the expression.

    void debug(Printer& p) const override;
    /// Prints the expression's associated addresses in memory.

    void to_sexpr(Printer& p) const override;
    /// Prints the expression as a symbolic expression.

    Value evaluate() const override {
        throw std::logic_error("Not implemented");
    }
private:
    Expr* m_e1;
    Expr* m_e2;
    Type* m_type;
};


/// Represents the remainder expression of the form `e1 % e2`.
class Rem_expr : public Expr
{
public:
    Rem_expr(Expr* e1, Expr* e2, Type* t) 
        : m_e1(e1), m_e2(e2), m_type(t) 
    { }

    void print(Printer& p) const override;
    /// `Pretty prints` the expression.

    void debug(Printer& p) const override;
    /// Prints the expression's associated addresses in memory.

    void to_sexpr(Printer& p) const override;
    /// Prints the expression as a symbolic expression.

    Value evaluate() const override {
        throw std::logic_error("Not implemented");
    }
private:
    Expr* m_e1;
    Expr* m_e2;
    Type* m_type;
};


// Represents the negation expression of the form `-e1`.
class Neg_expr : public Expr
{
public:
    Neg_expr(Expr* e, Type* t) 
        : m_expr(e), m_type(t) 
    { }

    void print(Printer& p) const override;
    /// `Pretty prints` the expression.

    void debug(Printer& p) const override;
    /// Prints the expression's associated addresses in memory.

    void to_sexpr(Printer& p) const override;
    /// Prints the expression as a symbolic expression.

    Value evaluate() const override {
        throw std::logic_error("Not implemented");
    }
private:
    Expr* m_expr;
    Type* m_type;
};


/// Represents the reciprocal expression of the form `/e1`.
class Rec_expr : public Expr 
{
public:
    Rec_expr(Expr* e, Type* t) 
        : m_expr(e), m_type(t) 
    { }

    void print(Printer& p) const override;
    /// `Pretty prints` the expression.

    void debug(Printer& p) const override;
    /// Prints the expression's associated addresses in memory.

    void to_sexpr(Printer& p) const override;
    /// Prints the expression as a symbolic expression.

    Value evaluate() const override {
        throw std::logic_error("Not implemented");
    }
private:
    Expr* m_expr;
    Type* m_type;
};


/// Represents the assignment expression of the form `e1 <- e2`.
class Ass_expr : public Expr
{
public:
    Ass_expr(Expr* src, Expr* tar, Type* t)
        : m_src(src), m_tar(tar), m_type(t)
    { }
    
    void print(Printer& p) const override;
    /// `Pretty prints` the expression.

    void debug(Printer& p) const override;
    /// Prints the expression's associated addresses in memory.

    void to_sexpr(Printer& p) const override;
    /// Prints the expression as a symbolic expression.

    Value evaluate() const override {
        throw std::logic_error("Not implemented");
    }
private:
    Type* m_type;
    Expr* m_src;
    Expr* m_tar;
};

/// Represents the function call expression of the form `ef(e1, e2, ..., en)`.
class Call_expr : public Expr
{
public:
    Call_expr(std::vector<Expr*>* exprs, Type* t)
        : m_exprs(exprs), m_type(t)
    { }

    void print(Printer& p) const override;
    /// `Pretty prints` the expression.

    void debug(Printer& p) const override;
    /// Prints the expression's associated addresses in memory.

    void to_sexpr(Printer& p) const override;
    /// Prints the expression as a symbolic expression.

    Value evaluate() const override {
        throw std::logic_error("Not implemented");
    }
private:
    Type* m_type;
    std::vector<Expr*>* m_exprs;
};


// Operators

std::ostream& operator<<(std::ostream &os, Expr const& e);