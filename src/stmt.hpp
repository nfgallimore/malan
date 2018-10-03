#pragma once

#include <iostream>

struct Expr;
struct Decl;

struct Stmt
{

};

using Stmt_seq = std::vector<Stmt*>;

struct Break_stmt : Stmt
{

};

struct Cont_stmt : Stmt
{

};

struct Block_stmt : Stmt
{
    Stmt_seq* stmts;
};

struct While_stmt : Stmt
{
    Expr* cond;
    Stmt* body;
};

struct Ternary_stmt : Stmt
{
    Expr* cond;
    Stmt* then;
    Stmt* els;
};


// (if Sexpr(e)
// )
struct Return_stmt : Stmt
{
    Stmt* stmt;
};

struct Expression_stmt : Stmt
{
    Expr* expr;
};


// Local variables
struct Local_defn_stmt : Stmt
{
    Block_stmt* block;
    Decl* decl;
};