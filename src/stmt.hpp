#pragma once

#include <iostream>

#include "expr.hpp"

class Decl;


// Represents statements in the language
class Stmt
{
public:
    virtual void print(Printer& p) const = 0;
    virtual void debug(Printer& p) const = 0;
    virtual void to_sexpr(Printer& p) const = 0;
};

using Stmt_seq = std::vector<Stmt*>;


// Represents the `break` statement
class Break_stmt : public Stmt
{
public:
    Break_stmt() { }
    void print(Printer& p) const override;
    void debug(Printer& p) const override;
    void to_sexpr(Printer& p) const override;
};


// Represents the `continue` statment
class Cont_stmt : public Stmt
{
public:
    Cont_stmt() { }
    void print(Printer& p) const override;
    void debug(Printer& p) const override;
    void to_sexpr(Printer& p) const override;
};


// Represents statements of the form `{ s1; s2; ... sn; }`
class Block_stmt : public Stmt
{
public:
    Block_stmt(Stmt_seq* seq) : m_stmts(seq) { }
    void print(Printer& p) const override;
    void debug(Printer& p) const override;
    void to_sexpr(Printer& p) const override;
    Stmt_seq* get_stmts() const { return m_stmts; }
private:
    Stmt_seq* m_stmts;
};


// Represents statements of the form `while (e) s`
class While_stmt : public Stmt
{
public:
    While_stmt(Expr* cond, Stmt* body) 
        : m_cond(cond), m_body(body) 
    { }
    void print(Printer& p) const override; 
    void debug(Printer& p) const override;
    void to_sexpr(Printer& p) const override;
    Expr* get_cond() const { return m_cond; }
    Stmt* get_body() const { return m_body; }
private:
    Expr* m_cond;
    Stmt* m_body;
};


// Represents statements of the form `if e then s else s`
class If_stmt : public Stmt
{
public:
    If_stmt(Expr* cond, Stmt* then, Stmt* els) 
        : m_cond(cond), m_then(then), m_else(els) 
    { }
    void print(Printer& p) const override; 
    void debug(Printer& p) const override;
    void to_sexpr(Printer& p) const override;
    Expr* get_cond() const { return m_cond; }
    Stmt* get_then() const { return m_then; }
    Stmt* get_else() const { return m_else; }
private:
    Expr* m_cond;
    Stmt* m_then;
    Stmt* m_else;
};


// Represents statements of the form `return e`
class Ret_stmt : public Stmt
{
public:
    Ret_stmt(Expr* e) : m_expr(e) { }
    void print(Printer& p) const override; 
    void debug(Printer& p) const override;
    void to_sexpr(Printer& p) const override;
    Expr* get_expr() { return m_expr; }
private:
    Expr* m_expr;
};


// Represents a statment of the form `e;`
class Expr_stmt : public Stmt
{
public:
    Expr* expr;
    void print(Printer& p) const override;
    void debug(Printer& p) const override;
    void to_sexpr(Printer& p) const override;
};


// Definition for a local variable
class Decl_stmt : public Stmt
{
public:
    Decl_stmt(Decl* d) : m_decl(d) { }
    void print(Printer& p) const override;
    void debug(Printer& p) const override;
    void to_sexpr(Printer& p) const override;
private:
    Decl* m_decl;
};


// Operators

std::ostream& operator<<(std::ostream& os, Stmt const& s);


// Operations

inline void
print(Printer& p, Stmt const& s)
{
    s.print(p);
};

inline void
debug(Printer& p, Stmt const& s)
{
    s.debug(p);
};

inline void
to_sexpr(Printer& p, Stmt const& s)
{
    s.to_sexpr(p);
};
