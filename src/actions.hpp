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

    Expr* on_float_literal(Token const& tok);
    /// Returns a float expression.

    Expr* on_bool_literal(Token const& tok);
    /// Returns a boolean expression.

    Expr* on_assignment_expression(Expr* lhs, Expr* rhs);
    /// Returns an assignment expression.

    Expr* on_or_expression(Expr* lhs, Expr* rhs);
    /// Returns an or expression.

    Expr* on_and_expression(Expr* lhs, Expr* rhs);
    /// Returns an and expression.

    Expr* on_identifier_expression(Token const& tok);
    /// Returns an identifier-expression.

    Expr* on_negation_expression(Expr* e);
    /// Returns a negation expression.

    Expr* on_reciprocal_expression(Expr* e);
    /// Returns a reciprocal expression.
    
    Expr* on_multiplication_expression(Expr* lhs, Expr* rhs);
    /// Returns a multiplication expression.
    
    Expr* on_conditional_expression(Expr* con, Expr* first, Expr* second);
    /// Returns a conditional expression.

private:
    Builder m_builder;
};
