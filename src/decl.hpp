#pragma once

#include <vector>

#include "printer.hpp"

class Name;
class Type;
class Expr;
class Stmt;

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

    virtual bool is_object() const = 0;

    virtual bool is_variable() const = 0;
    /// Returns true if this is a variable (i.e., an object or reference).

    virtual bool is_reference() const = 0;
    /// Returns true if this declares a reference.
};


/// Represents object declarations of the form `var x : t = e`
class Var_decl : public Decl
{
public:
    Var_decl(Name* name, Type* type);
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

    void set_initializer(Expr* e) { m_init = e; }
    /// Sets the initial value of the variable declaration.

    Expr* get_initializer() const { return m_init; }
    /// Returns the initial value of the function if set.
    
    bool is_initialized() const { return m_init != nullptr; }
    /// Returns whether the declaration was initialized

    bool is_object() const override { return true; }
    /// Determines whether the declaration is an object.

    bool is_reference() const override;
    /// Determines whether the declaration is a reference.

    bool is_variable() const override { return true; }
    /// Determines whether the declaration is a variable.

private:
    Name* m_name;
    /// The name of the variable declaration.

    Type* m_type;
    /// The type of the variable declaration.

    Expr* m_init;
    /// The initial value of the variable declaration.
};

inline 
Var_decl::Var_decl(Name* name, Type* type) 
    : m_name(name), m_type(type)
{ }

using Decl_seq = std::vector<Decl*>;
/// Represents a sequence of declarations as a vector.

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

    Type* get_type() const override { return m_type; }
    /// Returns the type of the function, if any.

    Stmt* get_body() const { return m_body; }
    /// Returns the body of the declaration, if any.

    bool is_object() const override { return false; }
    /// Determines whether the declaration is an object.

    void set_type(Type* t) { m_type = t; }
    /// Sets the type of the function declaration.

    bool is_reference() const override { return false; }
    /// Determines whether the declaration is a reference.

    bool is_variable() const override { return false; }
    /// Determines whether the declaration is a variable.

    void set_body(Stmt* body) { m_body = body; }
    
private:
    Name* m_name;
    /// The name of the function declaration.

    Decl_seq* m_parms;
    /// The parameters of the function declaration.

    Type* m_ret;
    /// The return type of the function declaration.

    Stmt* m_body;
    /// The body of the function declaration.

    Type* m_type;
    /// The type of the function.
};

inline
Func_decl::Func_decl(Name* name, Decl_seq* parms, Type* ret, Stmt* body)
    : m_name(name), m_parms(parms), m_ret(ret), m_body(body)
{ }


// Operators

std::ostream& operator<<(std::ostream& os, Decl const& d);
/// Write `d` to the output stream.
