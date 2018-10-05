#pragma once

#include <iostream>
#include <vector>

#include "printer.hpp"

class Name;
class Type;
class Expr;
class Stmt;
class Decl;

class Decl
{
public:
    virtual void print(Printer& p) const = 0;
    virtual void debug(Printer& p) const = 0;
    virtual void to_sexpr(Printer& p) const = 0;
    virtual Name* get_name() const = 0;
};

using Decl_seq = std::vector<Decl*>;

class Var_decl : public Decl
{
public:
    Var_decl(Name* name, Type* type, Expr* init) 
        : m_name(name), m_type(type), m_init(init) 
    { }
    void print(Printer& p) const override;
    void debug(Printer& p) const override;
    void to_sexpr(Printer& p) const override;
    Name* get_name() const override { return m_name; }
private:
    Name* m_name;
    Type* m_type;
    Expr* m_init;
};

class Ref_decl : public Decl
{
public:
    Ref_decl(Name* name, Type* type, Expr* init) 
        : m_name(name), m_type(type), m_init(init) 
    { }
    void print(Printer& p) const override;
    void debug(Printer& p) const override;
    void to_sexpr(Printer& p) const override;
    Name* get_name() const override { return m_name; }

private:
    Name* m_name;
    Type* m_type;
    Expr* m_init;
};

struct Func_decl : public Decl
{
public:
    Func_decl(Name* name, Decl_seq* parms, Type* ret, Stmt* body) 
        : m_name(name), m_parms(parms), m_ret(ret), m_body(body)
    { }
    void print(Printer& p) const override;
    void debug(Printer& p) const override;
    void to_sexpr(Printer& p) const override;
    Name* get_name() const override { return m_name; }

private:
    Name* m_name;
    Decl_seq* m_parms;
    Type* m_ret;
    Stmt* m_body;
};


// Operators

std::ostream& operator<<(std::ostream& os, Decl const& d);


// Operations

inline void
print(Printer& p, Decl const& d)
{
    p.get_stream() << d;
};

inline void
to_sexpr(Printer& p, Decl const& d)
{
    d.to_sexpr(p);
}

inline void
debug(Printer& p, Decl const& d)
{
    d.debug(p);
}