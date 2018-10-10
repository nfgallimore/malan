#pragma once

#include "type.hpp"
#include "expr.hpp"
#include "decl.hpp"
#include "name.hpp"
#include "stmt.hpp"

class Ast_builder
{
public:
    // Types

    Type* get_bool_type() const { return m_bool_type; }
    /// Returns the type `bool`.
    
    Type* get_int_type() const { return m_int_type; }
    /// Returns the type `int`.
    
    Type* get_ref_type() const { return m_ref_type; }
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

    Expr* make_float(double n);
    /// Returns a new floating point literal.

    Expr* make_id(Name* n, Decl* d, Type* t);
    /// Returns a new identifier expression.

    Expr* make_and(Expr* e1, Expr* e2);
    /// Returns a new and expression.

    Expr* make_or(Expr* e1, Expr* e2);
    /// Returns a new or epression.

    Expr* make_not(Expr* e);
    /// Returns a new not expression.

    Expr* make_con(Expr* e1, Expr* e2, Expr* e3, Type* t);
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

    Expr* make_add(Expr* e1, Expr* e2, Type* t);
    /// Returns a new addition expression.

    Expr* make_sub(Expr* e1, Expr* e2, Type* t);
    /// Returns a new subtraction expression.

    Expr* make_mul(Expr* e1, Expr* e2, Type* t);
    /// Returns a new multiplication expression.

    Expr* make_quo(Expr* e1, Expr* e2, Type* t);
    /// Returns a new quotient expression.

    Expr* make_rem(Expr* e1, Expr* e2, Type* t);
    /// Returns a new remainder expression.

    Expr* make_neg(Expr* e1);
    /// Returns a new negation expression.

    Expr* make_rec(Expr* e1);
    /// Returns a new reciprocal expression.
    
    // Declaration builder



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
