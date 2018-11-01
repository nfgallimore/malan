#pragma once

#include "type.hpp"
#include "expr.hpp"

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

    Bool_lit* make_bool(bool b);
    /// Returns a new boolean literal.

    Bool_lit* make_true();
    /// Returns a new boolean literal with  value of true.

    Bool_lit* make_false();
    /// Returns a new boolean literal with  value of false.

    Int_lit* make_int(int n);
    /// Returns a new integer literal.

    Float_lit* make_float(float f);
    /// Returns a new floating point literal.

    Id_expr* make_id(Decl* d);
    /// Returns a new identifier expression.

    And_expr* make_and(Expr* e1, Expr* e2);
    /// Returns a new and expression.

    Or_expr* make_or(Expr* e1, Expr* e2);
    /// Returns a new or epression.

    Not_expr* make_not(Expr* e);
    /// Returns a new not expression.

    Con_expr* make_con(Expr* e1, Expr* e2, Expr* e3);
    /// Returns a new conditional expression.

    Eq_expr* make_eq(Expr* e1, Expr* e2);
    /// Returns a new equality expression.

    Ne_expr* make_ne(Expr* e1, Expr* e2);
    /// Returns a new inequality expression.

    Lt_expr* make_lt(Expr* e1, Expr* e2);
    /// Returns a new less than expression.

    Gt_expr* make_gt(Expr* e1, Expr* e2);
    /// Returns a new greater than or equal expression.

    Le_expr* make_le(Expr* e1, Expr* e2);
    /// Returns a new less than expression.

    Ge_expr* make_ge(Expr* e1, Expr* e2);
    /// Returns a new greater than or equal expression.

    Add_expr* make_add(Expr* e1, Expr* e2);
    /// Returns a new addition expression.

    Sub_expr* make_sub(Expr* e1, Expr* e2);
    /// Returns a new subtraction expression.

    Mul_expr* make_mul(Expr* e1, Expr* e2);
    /// Returns a new multiplication expression.

    Quo_expr* make_quo(Expr* e1, Expr* e2);
    /// Returns a new quotient expression.

    Rem_expr* make_rem(Expr* e1, Expr* e2);
    /// Returns a new remainder expression.

    Neg_expr* make_neg(Expr* e1);
    /// Returns a new negation expression.

    Rec_expr* make_rec(Expr* e1);
    /// Returns a new reciprocal expression.
    
    // Declaration builder

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
    
    void require_same_type(Expr* e1, Expr* e2);
    /// Enforces that the expressions are the same type.

private:
    Bool_type m_bool_type;
    /// The type `bool`.

    Int_type m_int_type;
    /// The type `int`.

    Float_type m_float_type;
    /// The type `float`.
};