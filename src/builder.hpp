#pragma once

#include "type.hpp"
#include "expr.hpp"
#include "decl.hpp"

class Builder
{
public:

    // Types

    Type* get_bool_type() { return &m_bool_type; }
    /// Returns the type `bool`.
    
    Type* get_int_type() { return &m_int_type; }
    /// Returns the type `int`.
    
    Type* get_float_type() { return &m_float_type; }
    /// Returns the type `float`.

    Type* get_reference_type(Type* t);
    /// Returns the type `ref t`.

    Type* get_function_type(std::vector<Type*> const& ts);
    /// Returns the type `(t1, t2, ..., tn) -> tr`.

    // Expression builder

    Expr* make_bool(bool b);
    /// Returns a new boolean literal.

    Expr* make_true();
    /// Returns a new boolean literal with  value of true.

    Expr* make_false();
    /// Returns a new boolean literal with  value of false.

    Expr* make_int(int n);
    /// Returns a new integer literal.

    Expr* make_float(float f);
    /// Returns a new floating point literal.

    Expr* make_id(Decl* d);
    /// Returns a new identifier expression that references a declaration.

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

    Var_decl* make_var(Type* t, Name* n, Expr* init);
    /// Returns a new variable declaration.

    Func_decl* make_func(Name* n, Decl_seq* parms, Type* ret, Stmt* body);
    /// Returns a new function declaration.


    // Typing

    bool is_bool(Expr* e);
    /// Returns true if the expression is of type boolean.

    void require_bool(Expr* e);
    /// Enforces the expression is a boolean.

    void require_bools(Expr* e1, Expr* e2);
    /// Enforces the expressions are booleans.

    bool is_number(Expr* e);
    /// Enforces the expression is an `int` or a `bool`.

    bool is_type(Expr* e, Type* t);
    /// Enforces the expression is of the given type.

    bool are_same_type(Expr* e1, Expr* e2);
    /// Determines if the expressions are of the same type.
    
    bool are_same_type(Decl* d1, Decl* d2);

    void require_same_type(Expr* e1, Expr* e2);
    /// Enforces that the expressions are the same type.

    
    // Conversion

    Type::Kind get_actual_kind(Expr* e1);
    /// Returns the actual kind of the expression, gets type of reference if reference type.


private:
    Bool_type m_bool_type;
    /// The type `bool`.

    Int_type m_int_type;
    /// The type `int`.

    Float_type m_float_type;
    /// The type `float`.
};