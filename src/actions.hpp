#pragma once

#include "token.hpp"
#include "builder.hpp"
#include "scope.hpp"

class Expr;
class Stmt;
class Decl;
class Type;

/// Defines and implements semantic/parsing actions
class Actions
{
public:
    Expr* on_assignment_expression(Expr* lhs, Expr* rhs);
    /// Returns an assignment expression.

    Expr* on_conditional_expression(Expr* con, Expr* first, Expr* second);
    /// Returns a conditional expression.

    Expr* on_or_expression(Expr* lhs, Expr* rhs);
    /// Returns an or expression.

    Expr* on_and_expression(Expr* lhs, Expr* rhs);
    /// Returns an and expression.

    Expr* on_equality_expression(Expr* lhs, Expr* rhs);
    /// Returns an equality expression.

    Expr* on_inequality_expression(Expr* lhs, Expr* rhs);
    /// Returns an inequality expression.

    Expr* on_less_than_expression(Expr* lhs, Expr* rhs);
    /// Returns a less than expression.
    
    Expr* on_greater_than_expression(Expr* lhs, Expr* rhs);
    /// Returns a greater than expression.

    Expr* on_less_than_or_equal_expression(Expr* lhs, Expr* rhs);
    /// Returns a less than or equa expression.
    
    Expr* on_greater_than_or_equal_expression(Expr* lhs, Expr* rhs);
    /// Returns a greater than or equal expression.
    
    Expr* on_addition_expression(Expr* lhs, Expr* rhs);
    /// Returns an addition expression.
   
    Expr* on_subtraction_expression(Expr* lhs, Expr* rhs);
    /// Returns a subtraction expression.
     
    Expr* on_multiplication_expression(Expr* lhs, Expr* rhs);
    /// Returns a multiplication expression.
    
    Expr* on_division_expression(Expr* lhs, Expr* rhs);
    /// Returns a division expression.
    
    Expr* on_remainder_expression(Expr* lhs, Expr* rhs);
    /// Returns a remainder expression.
    
    Expr* on_identifier_expression(Token const& tok);
    /// Returns an identifier-expression.

    Expr* on_negation_expression(Expr* e);
    /// Returns a negation expression.

    Expr* on_reciprocal_expression(Expr* e);
    /// Returns a reciprocal expression.

    Expr* on_integer_literal(Token const& tok);
    /// Returns an integer expression.

    Expr* on_float_literal(Token const& tok);
    /// Returns a float expression.

    Expr* on_bool_literal(Token const& tok);
    /// Returns a boolean expression.

    // Scope stuff

    void enter_scope() { m_stack.emplace_back(); }
    /// Enter a new scope.
  
    void leave_scope() { m_stack.pop_back(); }
    /// Leave the current scope.
  
    Scope* get_current_scope() { return &m_stack.back(); }
    /// Return the current scope.

private:
    Builder m_builder;

    Scope_stack m_stack;
};
