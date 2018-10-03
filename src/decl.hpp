#pragma once

#include <iostream>

struct Name;
struct Type;
struct Expr;
struct Stmt;

struct Decl
{
    virtual Type* check() const = 0;
};

using Decl_seq = std::vector<Decl*>;

struct Var_decl : Decl
{
    Name* name;
    Type* type;
    Expr* init;
    
    virtual Type* check() const override {
        return new Ref_type(type);
    }
};

struct Ref_decl : Decl
{
    Name* name;
    Type* type;
    Expr* init;

    Type* check() const override {
        return type;
    }
};

struct Func_decl : Decl
{
    Name* name;
    Decl_seq* parms;
    Type* ret;
    Stmt* body;

    Type* check() const override {
        return ret;
    }
};
