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

class Logical_or : public Expr {
public:
    Logical_or(Expr* e1, Expr* e2, Type* t) : m_e1(e1), m_e2(e2), m_type(t) { }
    void print(std::ostream& os) const override;
    void debug(std::ostream& os) const override;
    void to_sexpr(std::ostream& os) const override;
    Value evaluate() const override {
        return Value(m_e1->evaluate().get_bool() || m_e2->evaluate().get_bool());
    }
    Expr* get_lhs() { return m_e1; }
    Expr* get_rhs() { return m_e2; }
private:
    Expr* m_e1;
    Expr* m_e2;
    Type* m_type;
};

class Logical_not : public Expr {
public:
    Logical_not(Expr* e, Type* t) : m_expr(e), m_type(t) { }
    void print(std::ostream& os) const override;
    void debug(std::ostream& os) const override;
    void to_sexpr(std::ostream& os) const override;
    Value evaluate() const override {
        return Value(!m_expr->evaluate().get_bool());
    }
    Expr* get_exp() { return m_expr; }
private:
    Expr* m_expr;
    Type* m_type;
};

class Ternary_expr : public Expr {
public:
    Ternary_expr(Expr* e1, Expr* e2, Expr* e3, Type* t) 
        : m_e1(e1), m_e2(e2), m_e3(e3), m_type(t) 
    { }
    void print(std::ostream& os) const override;
    void debug(std::ostream& os) const override;
    void to_sexpr(std::ostream& os) const override;
    Value evaluate() const override {
        throw std::logic_error("Cannot evaluate ternary expression.");
    }
private:
    Expr* m_e1;
    Expr* m_e2;
    Expr* m_e3;
    Type* m_type;
};

class Equal_expr : public Expr {
public:
    Equal_expr(Expr* e1, Expr* e2, Type* t) 
        : m_e1(e1), m_e2(e2), m_type(t) 
    { }
    void print(std::ostream& os) const override;
    void debug(std::ostream& os) const override;
    void to_sexpr(std::ostream& os) const override;
    Value evaluate() const override {
        throw std::logic_error("Not implemented");
    }
private:
    Expr* m_e1;
    Expr* m_e2;
    Type* m_type;
};

class Not_equal_expr : public Expr {
public:
    Not_equal_expr(Expr* e1, Expr* e2, Type* t) 
        : m_e1(e1), m_e2(e2), m_type(t) 
    { }
    void print(std::ostream& os) const override;
    void debug(std::ostream& os) const override;
    void to_sexpr(std::ostream& os) const override;
    Value evaluate() const override {
        throw std::logic_error("Not implemented");
    }
private:
    Expr* m_e1;
    Expr* m_e2;
    Type* m_type;
};

class Less_than_expr : public Expr {
public:
    Less_than_expr(Expr* e1, Expr* e2, Type* t) 
        : m_e1(e1), m_e2(e2), m_type(t) 
    { }
    void print(std::ostream& os) const override;
    void debug(std::ostream& os) const override;
    void to_sexpr(std::ostream& os) const override;
    Value evaluate() const override {
        throw std::logic_error("Not implemented");
    }
private:
    Expr* m_e1;
    Expr* m_e2;
    Type* m_type;
};

class Greater_than_expr : public Expr {
public:
    Greater_than_expr(Expr* e1, Expr* e2, Type* t) 
        : m_e1(e1), m_e2(e2), m_type(t) 
    { }
    void print(std::ostream& os) const override;
    void debug(std::ostream& os) const override;
    void to_sexpr(std::ostream& os) const override;
    Value evaluate() const override {
        throw std::logic_error("Not implemented");
    }
private:
    Expr* m_e1;
    Expr* m_e2;
    Type* m_type;
};

class Less_than_or_equal_expr : public Expr {
public:
    Less_than_or_equal_expr(Expr* e1, Expr* e2, Type* t) 
        : m_e1(e1), m_e2(e2), m_type(t) 
    { }
    void print(std::ostream& os) const override;
    void debug(std::ostream& os) const override;
    void to_sexpr(std::ostream& os) const override;
    Value evaluate() const override {
        throw std::logic_error("Not implemented");
    }
private:
    Expr* m_e1;
    Expr* m_e2;
    Type* m_type;
};

class Greater_than_or_equal_expr : public Expr {
public:
    Greater_than_or_equal_expr(Expr* e1, Expr* e2, Type* t) 
        : m_e1(e1), m_e2(e2), m_type(t) 
    { }
    void print(std::ostream& os) const override;
    void debug(std::ostream& os) const override;
    void to_sexpr(std::ostream& os) const override;
    Value evaluate() const override {
        throw std::logic_error("Not implemented");
    }
private:
    Expr* m_e1;
    Expr* m_e2;
    Type* m_type;
};

class Add_expr : public Expr {
public:
    Add_expr(Expr* e1, Expr* e2, Type* t) 
        : m_e1(e1), m_e2(e2), m_type(t) 
    { }
    void print(std::ostream& os) const override;
    void debug(std::ostream& os) const override;
    void to_sexpr(std::ostream& os) const override;
    Value evaluate() const override {
        throw std::logic_error("Not implemented");
    }
private:
    Expr* m_e1;
    Expr* m_e2;
    Type* m_type;
};

class Sub_expr : public Expr {
public:
    Sub_expr(Expr* e1, Expr* e2, Type* t) 
        : m_e1(e1), m_e2(e2), m_type(t) 
    { }
    void print(std::ostream& os) const override;
    void debug(std::ostream& os) const override;
    void to_sexpr(std::ostream& os) const override;
    Value evaluate() const override {
        throw std::logic_error("Not implemented");
    }
private:
    Expr* m_e1;
    Expr* m_e2;
    Type* m_type;
};

class Mult_expr : public Expr {
public:
    Mult_expr(Expr* e1, Expr* e2, Type* t) 
        : m_e1(e1), m_e2(e2), m_type(t) 
    { }
    void print(std::ostream& os) const override;
    void debug(std::ostream& os) const override;
    void to_sexpr(std::ostream& os) const override;
    Value evaluate() const override {
        throw std::logic_error("Not implemented");
    }
private:
    Expr* m_e1;
    Expr* m_e2;
    Type* m_type;
};

class Quot_expr : public Expr {
public:
    Quot_expr(Expr* e1, Expr* e2, Type* t) 
        : m_e1(e1), m_e2(e2), m_type(t) 
    { }
    void print(std::ostream& os) const override;
    void debug(std::ostream& os) const override;
    void to_sexpr(std::ostream& os) const override;
    Value evaluate() const override {
        throw std::logic_error("Not implemented");
    }
private:
    Expr* m_e1;
    Expr* m_e2;
    Type* m_type;
};

class Rem_expr : public Expr {
public:
    Rem_expr(Expr* e1, Expr* e2, Type* t) 
        : m_e1(e1), m_e2(e2), m_type(t) 
    { }
    void print(std::ostream& os) const override;
    void debug(std::ostream& os) const override;
    void to_sexpr(std::ostream& os) const override;
    Value evaluate() const override {
        throw std::logic_error("Not implemented");
    }
private:
    Expr* m_e1;
    Expr* m_e2;
    Type* m_type;
};

class Negate_expr : public Expr {
public:
    Negate_expr(Expr* e, Type* t) 
        : m_expr(e), m_type(t) 
    { }
    void print(std::ostream& os) const override;
    void debug(std::ostream& os) const override;
    void to_sexpr(std::ostream& os) const override;
    Value evaluate() const override {
        throw std::logic_error("Not implemented");
    }
private:
    Expr* m_expr;
    Type* m_type;
};

class Reciprocal_expr : public Expr {
public:
    Reciprocal_expr(Expr* e, Type* t) 
        : m_expr(e), m_type(t) 
    { }
    void print(std::ostream& os) const override;
    void debug(std::ostream& os) const override;
    void to_sexpr(std::ostream& os) const override;
    Value evaluate() const override {
        throw std::logic_error("Not implemented");
    }
private:
    Expr* m_expr;
    Type* m_type;
};


std::ostream& operator<<(std::ostream& os, Expr const& e);

inline void
print(std::ostream& os, Expr const& e)
{
    e.print(os);
};