#pragma once

#include "type.hpp"
#include "expr.hpp"
#include "decl.hpp"
#include "name.hpp"
#include "stmt.hpp"
#include "error.hpp"

class Builder
{
public:
    // Types

    Type* get_bool_type() const { return m_bool_type; }
    /// Returns the type `bool`.
    
    Type* get_int_type() const { return m_int_type; }
    /// Returns the type `int`.
    
    Type* get_float_type() const { return m_float_type; }
    /// Returns the type `float`.

    Type* get_ref_type() const { return m_ref_type; }
    /// Returns the type `ref`.

    Type* get_fun_type() const { return m_fun_type; }
    /// Returns the type `fun`.

    // Expression builder

    Expr* make_bool(bool b);
    /// Returns a new boolean literal.

    Expr* make_int(int n);
    /// Returns a new integer literal.

    Expr* make_float(float f);
    /// Returns a new floating point literal.

    Expr* make_id(Decl* d);
    /// Returns a new identifier expression.

    Expr* make_and(Expr* e1, Expr* e2);
    /// Returns a new and expression.

    Expr* make_or(Expr* e1, Expr* e2);
    /// Returns a new or epression.

    Expr* make_not(Expr* e);
    /// Returns a new not expression.

    Expr* make_con(Expr* e1, Expr* e2, Expr* e3);
    /// Returns a new conditional expression.

    Expr* make_eq(Expr* e1, Expr* e2);
    /// Returns a new equality expression.

    Expr* make_ne(Expr* e1, Expr* e2);
    /// Returns a new inequality expression.

    Expr* make_lt(Expr* e1, Expr* e2);
    /// Returns a new less than expression.

    Expr* make_gt(Expr* e1, Expr* e2);
    /// Returns a new greater than or equal expression.

    Expr* make_le(Expr* e1, Expr* e2);
    /// Returns a new less than expression.

    Expr* make_ge(Expr* e1, Expr* e2);
    /// Returns a new greater than or equal expression.

    Expr* make_add(Expr* e1, Expr* e2);
    /// Returns a new addition expression.

    Expr* make_sub(Expr* e1, Expr* e2);
    /// Returns a new subtraction expression.

    Expr* make_mul(Expr* e1, Expr* e2);
    /// Returns a new multiplication expression.

    Expr* make_quo(Expr* e1, Expr* e2);
    /// Returns a new quotient expression.

    Expr* make_rem(Expr* e1, Expr* e2);
    /// Returns a new remainder expression.

    Expr* make_neg(Expr* e1);
    /// Returns a new negation expression.

    Expr* make_rec(Expr* e1);
    /// Returns a new reciprocal expression.
    
    // Declaration builder

    // Typing

    bool is_bool(Expr* e);
    /// Returns true if the expression is of type boolean.

    bool require_bool(Expr* e);
    /// Enforces the expression is a boolean.

    bool require_bools(Expr* e1, Expr* e2);
    /// Enforces the expressions are booleans.

    bool is_number(Expr* e);
    /// Enforces the expression is an `int` or a `bool`.

    bool is_type(Expr* e, Type* t);
    /// Enforces the expression is of the given type.


private:
    Bool_type* m_bool_type;
    /// The type `bool`.

    Int_type* m_int_type;
    /// The type `int`.

    Float_type* m_float_type;
    /// The type `float`.

    Ref_type* m_ref_type;
    /// The type `ref`.

    Fun_type* m_fun_type;
    /// The type `fun`.
};

inline bool 
is_bool(Expr* e) 
{
    return e->get_type()->get_kind() == Type::bool_type;
}

inline bool 
require_bools(Expr* e1, Expr* e2)
{
    if (!is_bool(e1) && !is_bool(e2))
	{
		throw std::logic_error("Both expressions must be boolean.");
	}
}

inline bool 
require_bool(Expr* e)
{
    if (!is_bool(e))
	{
		Type_err("Expression must be a boolean.");
	}  
}

inline bool 
are_same_type(Expr* e1, Expr* e2)
{
    return e1->get_type()->get_kind() == e2->get_type()->get_kind();
}

inline bool 
require_same_type(Expr* e1, Expr* e2)
{
    if (!are_same_type(e1, e2))
    {
        Type_err("Expression must be a boolean.");
    }
}