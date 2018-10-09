#pragma once

#include <vector>

#include "printer.hpp"

class Name;
class Type;
class Expr;
class Stmt;
class Decl;

/// Represents the base class of all declarations
class Decl
{
public:

    // Printer operations

    virtual void print(Printer& p) const = 0;
    /// Prints the declaration in `pretty print`

    virtual void debug(Printer& p) const = 0;
    /// Prints the declaration's associated addresses in memory.

    virtual void to_sexpr(Printer& p) const = 0;
    /// Prints the declaration as a symbolic expression.

    // Queries

    virtual Name* get_name() const = 0;
    /// Returns the name of the declaration, if any.

    virtual Type* get_type() const = 0;
    /// Returns the type of the declaration, if any.
};

using Decl_seq = std::vector<Decl*>;

/// Represents object declarations
class Var_decl : public Decl
{
public:
    Var_decl(Name* name, Type* type, Expr* init);
    /// Constructs the variable with the given arguments.

    void print(Printer& p) const override;
    /// Prints the declaration in `pretty print`

    void debug(Printer& p) const override;
    /// Prints the declaration's associated addresses in memory.

    void to_sexpr(Printer& p) const override;
    /// Prints the declaration as a symbolic expression.

    Name* get_name() const override { return m_name; }
    /// Returns the name of the declaration, if any.

    Type* get_type() const override { return m_type; }
    /// Returns the type of the declaration, if any.

private:
    Name* m_name;
    Type* m_type;
    Expr* m_init;
};

inline 
Var_decl::Var_decl(Name* name, Type* type, Expr* init) 
    : m_name(name), m_type(type), m_init(init) 
{ }


class Ref_decl : public Decl
{
public:
    Ref_decl(Name* name, Type* type, Expr* init) 
        : m_name(name), m_type(type), m_init(init) 
    { }
    /// Constructs the reference with the given arguments.

    void print(Printer& p) const override;
    /// Prints the declaration in `pretty print`

    void debug(Printer& p) const override;
    /// Prints the declaration's associated addresses in memory.

    void to_sexpr(Printer& p) const override;
    /// Prints the declaration as a symbolic expression.

    Name* get_name() const override { return m_name; }
    /// Returns the name of the declaration, if any.

    Type* get_type() const override { return m_type; }
    /// Returns the type of the declaration, if any.

private:
    Name* m_name;
    /// The name of the declaration

    Type* m_type;
    /// The type of the declaration

    Expr* m_init;
    /// The initial value of the declaration
};

struct Func_decl : public Decl
{
public:

    Func_decl(Name* name, Decl_seq* parms, Type* ret, Stmt* body) 
        : m_name(name), m_parms(parms), m_ret(ret), m_body(body)
    { }

    void print(Printer& p) const override;
    /// Prints the declaration in `pretty print`

    void debug(Printer& p) const override;
    /// Prints the declaration's associated addresses in memory.

    void to_sexpr(Printer& p) const override;
    /// Prints the declaration as a symbolic expression.

    Name* get_name() const override { return m_name; }
    /// Returns the name of the declaration, if any.

    Type* get_type() const override { return m_ret; }
    /// Returns the type of the declaration, if any.

    Stmt* get_body() const { return m_body; }
    /// Returns the body of the declaration, if any.

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