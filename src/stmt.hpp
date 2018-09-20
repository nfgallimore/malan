#pragma Once

#include <iostream>

struct Expr;

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

