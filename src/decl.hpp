#pragma once

#include <vector>

#include "printer.hpp"

class Name;
class Type;
class Expr;
class Stmt;
class Decl;

/// Represents the base class of all declarations.
class Decl
{
public:

    // Printer operations

    virtual void print(Printer& p) const = 0;
    /// `Pretty prints` the declaration.

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


/// Represents object declarations of the form `var x : t = e`
class Var_decl : public Decl
{
public:
    Var_decl(Name* name, Type* type, Expr* init);
    /// Constructs the variable with the given arguments.

    void print(Printer& p) const override;
    /// `Pretty prints` the declaration.

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
    /// The name of the variable declaration.

    Type* m_type;
    /// The type of the variable declaration.

    Expr* m_init;
    /// The initial value of the variable declaration.
};

inline 
Var_decl::Var_decl(Name* name, Type* type, Expr* init) 
    : m_name(name), m_type(type), m_init(init) 
{ 
    assert(init != nullptr);
}


/// Represents reference declarations of the type: `ref x : t = e`
class Ref_decl : public Decl
{
public:
    Ref_decl(Name* name, Type* type, Expr* init);
    /// Constructs the reference with the given arguments.

    void print(Printer& p) const override;
    /// `Pretty prints` the declaration.

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
    /// The name of the reference declaration.

    Type* m_type;
    /// The type of the reference declaration.

    Expr* m_init;
    /// The initial value of the reference declaration.
};

inline
Ref_decl::Ref_decl(Name* name, Type* type, Expr* init) 
    : m_name(name), m_type(type), m_init(init) 
{ }


/// Represents a declaration sequence
using Decl_seq = std::vector<Decl*>;


/// Represents function declaration of the type: `fun x (decl-seq) -> t s`
class Func_decl : public Decl
{
public:

    Func_decl(Name* name, Decl_seq* parms, Type* ret, Stmt* body);
    /// Constructs the function with the given arguments.

    void print(Printer& p) const override;
    /// `Pretty prints` the declaration.

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
    /// The name of the function declaration.

    Decl_seq* m_parms;
    /// The parameters of the function declaration.

    Type* m_ret;
    /// The return type of the function declaration.

    Stmt* m_body;
    /// The body of the function declaration.
};

inline
Func_decl::Func_decl(Name* name, Decl_seq* parms, Type* ret, Stmt* body)
    : m_name(name), m_parms(parms), m_ret(ret), m_body(body)
{ }


// Operators

std::ostream& operator<<(std::ostream& os, Decl const& d);
/// Write `d` to the output stream.


// Operations

/// `Pretty prints` the declaration.
inline void
print(Printer& p, Decl const& d)
{
    p.get_stream() << d;
};

/// Prints the declaration as a symbolic expression.
inline void
to_sexpr(Printer& p, Decl const& d)
{
    d.to_sexpr(p);
}

/// Prints the declaration's associated addresses in memory.
inline void
debug(Printer& p, Decl const& d)
{
    d.debug(p);
}