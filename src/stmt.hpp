#pragma once

#include <iostream>

#include "expr.hpp"

class Decl;


// Represents statements in the language
class Stmt
{
public:
    virtual void print(Printer& p) const = 0;
    /// `Pretty prints` the statement as it would appear in code.

    virtual void debug(Printer& p) const = 0;
    /// Prints the address of the statement and all associated addresses in memory.

    virtual void to_sexpr(Printer& p) const = 0;
    /// Prints the statement as a symbolic expression.
};

// Represents a sequence of statements as a vector.
using Stmt_seq = std::vector<Stmt*>;

// Represents the `break` statement
class Break_stmt : public Stmt
{
public:
    Break_stmt() { }
    /// Constructs a block statement.

    void print(Printer& p) const override;
    /// `Pretty prints` the statement as it would appear in code.

    void debug(Printer& p) const override;
    /// Prints the address of the statement and all associated addresses in memory.
    
    void to_sexpr(Printer& p) const override;
    /// Prints the statement as a symbolic expression.
};


// Represents the `continue` statment
class Cont_stmt : public Stmt
{
public:
    Cont_stmt() { }
    /// Constructs a continue statement.

    void print(Printer& p) const override;
    /// `Pretty prints` the statement as it would appear in code.

    void debug(Printer& p) const override;
    /// Prints the address of the statement and all associated addresses in memory.
    
    void to_sexpr(Printer& p) const override;
    /// Prints the statement as a symbolic expression.
};


// Represents statements of the form `{ s1; s2; ... sn; }`
class Block_stmt : public Stmt
{
public:
    Block_stmt(Stmt_seq* seq) : m_stmts(seq) { }
    /// Constructs a block statement with the given arguments.

    void print(Printer& p) const override;
    /// `Pretty prints` the statement as it would appear in code.

    void debug(Printer& p) const override;
    /// Prints the address of the statement and all associated addresses in memory.
    
    void to_sexpr(Printer& p) const override;
    /// Prints the statement as a symbolic expression.

    Stmt_seq* get_stmts() const { return m_stmts; }
    /// Returns the statements inside the block statement.

private:
    Stmt_seq* m_stmts;
    /// Represents the statements inside the block statement.
};


// Represents statements of the form `while (e) s`
class While_stmt : public Stmt
{
public:
    While_stmt(Expr* cond, Stmt* body) 
        : m_cond(cond), m_body(body) 
    { }
    /// Constructs a while statement with the given arguments.

    void print(Printer& p) const override;
    /// `Pretty prints` the statement as it would appear in code.

    void debug(Printer& p) const override;
    /// Prints the address of the statement and all associated addresses in memory.
    
    void to_sexpr(Printer& p) const override;
    /// Prints the statement as a symbolic expression.

    Expr* get_cond() const { return m_cond; }
    /// Returns the condition of the while statement.

    Stmt* get_body() const { return m_body; }
    /// Returns the body of the while statement.

private:
    Expr* m_cond;
    /// Represents the condition of the while statement.

    Stmt* m_body;
    /// Represents the body of the while statement.
};


// Represents statements of the form `if e then s else s`
class If_stmt : public Stmt
{
public:
    If_stmt(Expr* cond, Stmt* then, Stmt* els) 
        : m_cond(cond), m_then(then), m_else(els) 
    { }
    /// Constructs an if statement with the given arguments.

    void print(Printer& p) const override; 
    /// `Pretty prints` the statement as it would appear in code.

    void debug(Printer& p) const override;
    /// Prints the address of the statement and all associated addresses in memory.
    
    void to_sexpr(Printer& p) const override;
    /// Prints the statement as a symbolic expression.

    Expr* get_cond() const { return m_cond; }
    /// Returns the condition of the if statement.

    Stmt* get_then() const { return m_then; }
    /// Returns the then statement of the if statement.

    Stmt* get_else() const { return m_else; }
    /// Returns the else statement of the if statement.

private:
    Expr* m_cond;
    /// Represents the condition of the if statement.

    Stmt* m_then;
    /// Represents the then statement of the if statement.

    Stmt* m_else;
    /// Represents the else statement of the if statement.
};


// Represents statements of the form `return e`
class Ret_stmt : public Stmt
{
public:
    Ret_stmt(Expr* e) 
        : m_expr(e) 
    { }
    /// Constructs a return statement with the given expression.

    void print(Printer& p) const override; 
    /// `Pretty prints` the statement as it would appear in code.

    void debug(Printer& p) const override;
    /// Prints the address of the statement and all associated addresses in memory.
    
    void to_sexpr(Printer& p) const override;
    /// Prints the statement as a symbolic expression.

    Expr* get_expr() { return m_expr; }
    /// Returns the expression that is returned by the return statement.

private:
    Expr* m_expr;
    /// Represents the expression that is returned by the return statement.
};


// Represents a statment of the form `e;`
class Expr_stmt : public Stmt
{
public:
    Expr_stmt(Expr* e) 
        : m_expr(e) 
    { }
    /// Constructs an expression statement with the given expression.

    void print(Printer& p) const override;
    /// `Pretty prints` the statement as it would appear in code.

    void debug(Printer& p) const override;
    /// Prints the address of the statement and all associated addresses in memory.
    
    void to_sexpr(Printer& p) const override;
    /// Prints the statement as a symbolic expression.

    Expr* get_expr() { return m_expr; }
    /// Returns the expression of the expression statement.

private:
    Expr* m_expr;
    /// Represents the expression of the expression statement.
};


// Definition for a local variable
class Decl_stmt : public Stmt
{
public:
    Decl_stmt(Decl* d) 
        : m_decl(d) 
    { }
    /// Constructs a declaration statement with the given declaration.

    void print(Printer& p) const override;
    /// `Pretty prints` the statement as it would appear in code.

    void debug(Printer& p) const override;
    /// Prints the address of the statement and all associated addresses in memory.

    void to_sexpr(Printer& p) const override;
    /// Prints the statement as a symbolic expression.

    Decl* get_decl() { return m_decl; }
    /// Returns the declaration of the declaration statement.

private:
    Decl* m_decl;
    /// Represents the declaration of the declaration statement.
};


// Operators

std::ostream& operator<<(std::ostream& os, Stmt const& s);
/// Prints the statement to ostream.
