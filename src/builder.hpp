#pragma once

#include "type.hpp"
#include "expr.hpp"
#include "decl.hpp"
#include "stmt.hpp"

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
    /// Returns the type `(t1, t2, ..., tn) -> tr`. First parameter in list is ret type.

    Type* get_function_type(std::vector<Decl*> const& parms, Type* ret_type);
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

    Expr* make_neg(Expr* e);
    /// Returns a new negation expression.

    Expr* make_rec(Expr* e);
    /// Returns a new reciprocal expression.
    
    Expr* make_ass(Expr* e1, Expr* e2);
    /// Returns a new assignment expression.

    Expr* make_call(std::vector<Expr*>* exprs);
    /// Returns a new function call expression.


    // Declaration builder

    Var_decl* make_var(Type* t, Name* n, Expr* init);
    /// Returns a new variable declaration that is initializedl

    Var_decl* make_var(Type* t, Name* n);
    /// Returns a new uninitialized variable declaration.

    Func_decl* make_func(Name* n, Decl_seq* parms, Type* ret, Stmt* body);
    /// Returns a new function declaration.


    // Stmt builder

    Stmt* make_break();
    /// Construct a break statement.

    Stmt* make_cont();
    /// Construct a continue statement.

    Stmt* make_block(Stmt_seq* seq);
    /// Construct a block statement.

    Stmt* make_while(Expr* cond, Stmt* body);
    /// Constructs a while statement.

    Stmt* make_if(Expr* cond, Stmt* then_stmt, Stmt* else_stmt);
    /// Constructs an if statement.

    Stmt* make_ret(Expr* ret);
    /// Constructs a return statement.

    Stmt* make_expr_stmt(Expr* expr);
    /// Constructs an expression statement.

    Stmt* make_decl_stmt(Decl* decl);
    /// Constructs a declaration statement.
    
    Stmt* make_skip_stmt();
    /// Constructs a skip statement.

    // Name builder

    Name* make_name(std::string);

    // Typing Helpers

    bool is_bool(Expr* e);
    /// Returns true if the expression is of type boolean.

    bool is_number(Expr* e);
    /// Determines if the expression is an `int` or a `float`.

    bool is_type(Expr* e, Type* t);
    /// Determines if the expression is of the given type.

    bool is_type(Decl* d, Type* t);
    /// Determine if the declaration is of the given type.

    bool are_same_type(Expr* e1, Expr* e2);
    /// Determines if the expressions are the same type.
    
    bool are_same_type(Decl* d1, Decl* d2);
    /// Determines if the declarations are the same type.

    Type* get_dominant_type(Expr* e1, Expr* e2);
    /// Enforces e1 and e2 are numbers.
    /// Returns float if either are float, else returns int.


    // Type Enforcing

    void require_bool(Expr* e);
    /// Enforces the expression is a boolean.
    
    void require_bools(Expr* e1, Expr* e2);
    /// Enforces the expressions are booleans.
    
    void require_number(Expr* e);
    /// Enforces that the expression is an `int` or a `float`.

    void require_numbers(Expr* e1, Expr* e2);
    /// Enforces that the expressions are either `int` or `float`.

    Expr* require_type(Expr* e, Type* t);
    /// Enforces that the expression is the provided type.

    Decl* require_type(Decl* d, Type* t);
    /// Enforces that the expression is the provided type.

    void require_same_type(Expr* e1, Expr* e2);
    /// Enforces that the expressions are the same type.

    void require_same_type(Decl* d1, Decl* d2);
    /// Determines that the declarations are the same type.

    void require_not_fun_type(Type* t);
    /// Requries the type to not be a function.

    // Conversion

    Type::Kind get_actual_kind(Expr* e);
    /// Returns the actual kind of the expression, gets type of reference if reference type.

    Type::Kind get_actual_kind(Decl* d);
    /// Returns the actual kind of the declaration, gets type of reference if reference type.

    // Initialization

    void copy_initialize(Decl* d, Expr* e);
    /// Copy expression into declaration.

    void reference_initialize(Decl* d, Expr* e);
    /// Initilize the reference.

private:
    Bool_type m_bool_type;
    /// The type `bool`.

    Int_type m_int_type;
    /// The type `int`.

    Float_type m_float_type;
    /// The type `float`.
};
