#pragma once

#include <iostream>

struct Name;
struct Type;
struct Expr;
struct Stmt;

struct Decl
{

};

using Decl_seq = std::vector<Decl*>;

struct Var_decl : Decl
{
    Name* name;
    Type* type;
    Expr* init;
};

struct Ref_decl : Decl
{
    Name* name;
    Type* type;
    Expr* init;
};

struct Func_decl : Decl
{
    Name* name;
    Decl_seq* parms;
    Type* ret;
    Stmt* body;
};
