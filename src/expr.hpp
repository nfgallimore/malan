#pragma once

#include <iostream>

#include "value.hpp"
#include "type.hpp"

class Decl;
class Value;

class Expr {
public:
    // evaluates an expression
    virtual Value evaluate() const = 0;

    // prints an expression
    virtual void print(std::ostream& os) const = 0;

    // debugs an expression with the name of class and memory address
    virtual void debug(std::ostream& o) const = 0;

    // converts to sexpr
    virtual void to_sexpr(std::ostream& o) const = 0;
};

class Bool_literal : public Expr {
public:    
    Bool_literal(bool b, Type* t) : m_value(b), m_type(t) { }
    void print(std::ostream& os) const override;
    void debug(std::ostream& os) const override;
    void to_sexpr(std::ostream& os) const override;
    Value evaluate() const override { return Value(m_value); }
private:
    bool m_value;
    Type* m_type;
};

class Int_literal : public Expr {
public:    
    Int_literal(int i, Type* t) : m_value(i), m_type(t) { }
    void print(std::ostream& os) const override;
    void debug(std::ostream& os) const override;
    void to_sexpr(std::ostream& os) const override;
    Value evaluate() const override { return Value(m_value); }
private:
    int m_value;
    Type* m_type;
};

class Identifier : public Expr {
public:
    Identifier(Decl* d, Type* t) : m_value(d), m_type(t) { }
    void print(std::ostream& os) const override;
    void debug(std::ostream& os) const override;
    void to_sexpr(std::ostream& os) const override;
    Value evaluate() const override { throw std::logic_error("Cannot evaluate an identifier."); }
private:
    Decl* m_value;
    Type* m_type;
};

class Logical_and : public Expr {
public:
    Logical_and(Expr* e1, Expr* e2, Type* t) : m_e1(e1), m_e2(e2), m_type(t) { }
    void print(std::ostream& os) const override;
    void debug(std::ostream& os) const override;
    void to_sexpr(std::ostream& os) const override;
    Value evaluate() const override {
        return Value(m_e1->evaluate().get_bool() && m_e2->evaluate().get_bool());
    }
    Expr* get_lhs() { return m_e1; }
    Expr* get_rhs() { return m_e2; }
private:
    Expr* m_e1;
    Expr* m_e2;
    Type* m_type;
};

std::ostream& operator<<(std::ostream& os, Expr const& e);

inline void
print(std::ostream& os, Expr const& e)
{
    e.print(os);
};