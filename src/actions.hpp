#pragma once

#include "token.hpp"
#include "builder.hpp"

class Expr;
class Stmt;
class Decl;
class Type;

/// Defines and implements semantic/parsing actions
class Actions
{
public:
    Expr* on_integer_literal(Token const& tok);
    /// Returns an integer expression.

    Expr* on_bool_literal(Token const& tok);
    /// Returns a boolean expression.

    Expr* on_id_expr(Token const& tok);
    /// Returns an id-expression.

    Expr* on_negation_expr(Expr* e);
    /// Returns a negation expression.

    Expr* on_reciprocal_expr(Expr* e);
    /// Returns a reciprocal expression.
    
    Expr* on_multiplication_expresion(Expr* lhs, Expr* rhs);
    /// Returns a multiplication expression.
    
private:
    Builder m_builder;
};
