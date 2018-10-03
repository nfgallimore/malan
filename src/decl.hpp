#pragma once

#include <iostream>
#include <iosfwd>
#include <vector>

class Name;
class Type;
class Expr;
class Stmt;
class Decl;

class Decl
{
public:
    enum Kind
    {
        var,
        ref,
        func
    };

protected:
    Decl(Kind k) : m_kind(k) { }

public:
    Kind get_kind() const { return m_kind; }
    virtual void print(std::ostream& os) const = 0;
    virtual void debug(std::ostream& os) const = 0;
    virtual void to_sexpr(std::ostream& os) const = 0;
    virtual Name* get_name() const = 0;
private:
    Kind m_kind;
};

using Decl_seq = std::vector<Decl*>;
using Stmt_seq = std::vector<Stmt*>;

class Var_decl : public Decl
{
public:
    Var_decl(Name* name, Type* type, Expr* init) 
        : Decl(var), m_name(name), m_type(type), m_init(init) 
    { }
    void print(std::ostream& os) const override;
    void debug(std::ostream& os) const override;
    void to_sexpr(std::ostream& os) const override;
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
        :  Decl(ref), m_name(name), m_type(type), m_init(init) 
    { }
    void print(std::ostream& os) const override;
    void debug(std::ostream& os) const override;
    void to_sexpr(std::ostream& os) const override;
    Name* get_name() const override { return m_name; }

private:
    Name* m_name;
    Type* m_type;
    Expr* m_init;
};

struct Func_decl : public Decl
{
public:
    Func_decl(Name* name, Decl_seq* parms, Type* ret, Stmt_seq* body) 
        :  Decl(func), m_name(name), m_parms(parms), m_ret(ret), m_body(body)
    { }
    void print(std::ostream& os) const override;
    void debug(std::ostream& os) const override;
    void to_sexpr(std::ostream& os) const override;
    Name* get_name() const override { return m_name; }

private:
    Name* m_name;
    Decl_seq* m_parms;
    Type* m_ret;
    Stmt_seq* m_body;
};

std::ostream& operator<<(std::ostream& os, Decl const& d);

inline void
print(std::ostream& os, Decl const& d)
{
    d.print(os);
};