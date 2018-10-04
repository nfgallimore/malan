#pragma once

#include <iostream>
#include "expr.hpp"

class Decl;

// Represents statements in the language
class Stmt
{
public:
    virtual void print(std::ostream& os) const = 0;
};

using Stmt_seq = std::vector<Stmt*>;

// Represents the `break` statement
class Break_stmt : public Stmt
{
public:
    Break_stmt() { }
    void print(std::ostream& os) const;
};

// Represents the `continue` statment
class Cont_stmt : public Stmt
{
public:
    Cont_stmt() { }
    void print(std::ostream& os) const;
};

// Represents statements of the form `{ s1; s2; ... sn; }`
class Block_stmt : public Stmt
{
public:
    Block_stmt(Stmt_seq* seq) : m_stmts(seq) { }
    void print(std::ostream& os) const;
    Stmt_seq* get_stmts() const { return m_stmts; }
private:
    Stmt_seq* m_stmts;
};

// Represents statements of the form `while (e) s`
class While_stmt : public Stmt
{
public:
    While_stmt(Expr* cond, Stmt* body) : m_cond(cond), m_body(body) { }
    Expr* get_cond() const { return m_cond; }
    Stmt* get_body() const { return m_body; }
private:
    Expr* m_cond;
    Stmt* m_body;
};

// Represents statements of the form `if e then s else s`
class Ternary_stmt : public Stmt
{
public:
    Ternary_stmt(Expr* cond, Stmt* then, Stmt* els) : m_cond(cond), m_then(then), m_else(els) { }
    Expr* get_cond() const { return m_cond; }
    Stmt* get_then() const { return m_then; }
    Stmt* get_else() const { return m_else; }
private:
    Expr* m_cond;
    Stmt* m_then;
    Stmt* m_else;
};

// Represents statements of the form `return e`
class Return_stmt : public Stmt
{
public:
    Return_stmt(Stmt* stmt) : m_stmt(stmt) { }
    Stmt* get_stmt() { return m_stmt; }
private:
    Stmt* m_stmt;
};

class Expression_stmt : public Stmt
{
public:
    Expr* expr;
};

// Definition for a local variable
class Local_defn_stmt : public Stmt
{
public:
    Block_stmt* block;
    Decl* decl;
};

std::ostream& operator<<(std::ostream& os, Stmt const& s);

inline void
print(std::ostream& os, Stmt const& s)
{
    s.print(os);
};