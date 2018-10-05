#pragma once

#include <iostream>

#include "value.hpp"
#include "type.hpp"
#include "printer.hpp"

class Decl;
class Value;

class Expr {
public:
    // evaluates an expression
    virtual Value evaluate() const = 0;

    // prints an expression
    virtual void print(Printer &p) const = 0;

    // debugs an expression with the name of class and memory address
    virtual void debug(Printer &p) const = 0;

    // converts to sexpr
    virtual void to_sexpr(Printer &p) const = 0;
};

class Bool_lit : public Expr {
public:    
    Bool_lit(bool b, Type* t) 
        : m_value(b), m_type(t) 
    { }
    void print(Printer &p) const override;
    void debug(Printer &p) const override;
    void to_sexpr(Printer &p) const override;
    Value evaluate() const override { return Value(m_value); }
private:
    bool m_value;
    Type* m_type;
};

class Int_lit : public Expr {
public:    
    Int_lit(int i, Type* t) 
        : m_value(i), m_type(t) 
    { }
    void print(Printer &p) const override;
    void debug(Printer &p) const override;
    void to_sexpr(Printer &p) const override;
    Value evaluate() const override { return Value(m_value); }
private:
    int m_value;
    Type* m_type;
};

class Id_expr : public Expr {
public:
    Id_expr(Decl* d, Type* t) 
        : m_value(d), m_type(t) 
    { }
    void print(Printer &p) const override;
    void debug(Printer &p) const override;
    void to_sexpr(Printer &p) const override;
    Value evaluate() const override { throw std::logic_error("Cannot evaluate an identifier."); }
private:
    Decl* m_value;
    Type* m_type;
};

class And_expr : public Expr {
public:
    And_expr(Expr* e1, Expr* e2, Type* t) : m_e1(e1), m_e2(e2), m_type(t) { }
    void print(Printer &p) const override;
    void debug(Printer &p) const override;
    void to_sexpr(Printer &p) const override;
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

class Or_expr : public Expr {
public:
    Or_expr(Expr* e1, Expr* e2, Type* t) 
        : m_e1(e1), m_e2(e2), m_type(t) 
    { }
    void print(Printer &p) const override;
    void debug(Printer &p) const override;
    void to_sexpr(Printer &p) const override;
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

class Not_expr : public Expr {
public:
    Not_expr(Expr* e, Type* t) 
        : m_expr(e), m_type(t) 
    { }
    void print(Printer &p) const override;
    void debug(Printer &p) const override;
    void to_sexpr(Printer &p) const override;
    Value evaluate() const override {
        return Value(!m_expr->evaluate().get_bool());
    }
    Expr* get_exp() { return m_expr; }
private:
    Expr* m_expr;
    Type* m_type;
};

class Con_expr : public Expr {
public:
    Con_expr(Expr* e1, Expr* e2, Expr* e3, Type* t) 
        : m_e1(e1), m_e2(e2), m_e3(e3), m_type(t) 
    { }
    void print(Printer &p) const override;
    void debug(Printer &p) const override;
    void to_sexpr(Printer &p) const override;
    Value evaluate() const override {
        throw std::logic_error("Cannot evaluate ternary expression.");
    }
private:
    Expr* m_e1;
    Expr* const m_e2;
    Expr* const m_e3;
    Type* m_type;
};

class Eq_expr : public Expr {
public:
    Eq_expr(Expr* e1, Expr* e2, Type* t) 
        : m_e1(e1), m_e2(e2), m_type(t) 
    { }
    void print(Printer &p) const override;
    void debug(Printer &p) const override;
    void to_sexpr(Printer &p) const override;
    Value evaluate() const override {
        throw std::logic_error("Not implemented");
    }
private:
    Expr* m_e1;
    Expr* m_e2;
    Type* m_type;
};

class Ne_expr : public Expr {
public:
    Ne_expr(Expr* e1, Expr* e2, Type* t) 
        : m_e1(e1), m_e2(e2), m_type(t) 
    { }
    void print(Printer &p) const override;
    void debug(Printer &p) const override;
    void to_sexpr(Printer &p) const override;
    Value evaluate() const override {
        throw std::logic_error("Not implemented");
    }
private:
    Expr* m_e1;
    Expr* m_e2;
    Type* m_type;
};

class Lt_expr : public Expr {
public:
    Lt_expr(Expr* e1, Expr* e2, Type* t) 
        : m_e1(e1), m_e2(e2), m_type(t) 
    { }
    void print(Printer &p) const override;
    void debug(Printer &p) const override;
    void to_sexpr(Printer &p) const override;
    Value evaluate() const override {
        throw std::logic_error("Not implemented");
    }
private:
    Expr* m_e1;
    Expr* m_e2;
    Type* m_type;
};

class Gt_expr : public Expr {
public:
    Gt_expr(Expr* e1, Expr* e2, Type* t) 
        : m_e1(e1), m_e2(e2), m_type(t) 
    { }
    void print(Printer &p) const override;
    void debug(Printer &p) const override;
    void to_sexpr(Printer &p) const override;
    Value evaluate() const override {
        throw std::logic_error("Not implemented");
    }
private:
    Expr* m_e1;
    Expr* m_e2;
    Type* m_type;
};

class Le_expr : public Expr {
public:
    Le_expr(Expr* e1, Expr* e2, Type* t) 
        : m_e1(e1), m_e2(e2), m_type(t) 
    { }
    void print(Printer &p) const override;
    void debug(Printer &p) const override;
    void to_sexpr(Printer &p) const override;
    Value evaluate() const override {
        throw std::logic_error("Not implemented");
    }
private:
    Expr* m_e1;
    Expr* m_e2;
    Type* m_type;
};

class Ge_expr : public Expr {
public:
    Ge_expr(Expr* e1, Expr* e2, Type* t) 
        : m_e1(e1), m_e2(e2), m_type(t) 
    { }
    void print(Printer &p) const override;
    void debug(Printer &p) const override;
    void to_sexpr(Printer &p) const override;
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
    void print(Printer &p) const override;
    void debug(Printer &p) const override;
    void to_sexpr(Printer &p) const override;
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
    void print(Printer &p) const override;
    void debug(Printer &p) const override;
    void to_sexpr(Printer &p) const override;
    Value evaluate() const override {
        throw std::logic_error("Not implemented");
    }
private:
    Expr* m_e1;
    Expr* m_e2;
    Type* m_type;
};

class Mul_expr : public Expr {
public:
    Mul_expr(Expr* e1, Expr* e2, Type* t) 
        : m_e1(e1), m_e2(e2), m_type(t) 
    { }
    void print(Printer &p) const override;
    void debug(Printer &p) const override;
    void to_sexpr(Printer &p) const override;
    Value evaluate() const override {
        throw std::logic_error("Not implemented");
    }
private:
    Expr* m_e1;
    Expr* m_e2;
    Type* m_type;
};

class Quo_expr : public Expr {
public:
    Quo_expr(Expr* e1, Expr* e2, Type* t) 
        : m_e1(e1), m_e2(e2), m_type(t) 
    { }
    void print(Printer &p) const override;
    void debug(Printer &p) const override;
    void to_sexpr(Printer &p) const override;
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
    void print(Printer &p) const override;
    void debug(Printer &p) const override;
    void to_sexpr(Printer &p) const override;
    Value evaluate() const override {
        throw std::logic_error("Not implemented");
    }
private:
    Expr* m_e1;
    Expr* m_e2;
    Type* m_type;
};

class Neg_expr : public Expr {
public:
    Neg_expr(Expr* e, Type* t) 
        : m_expr(e), m_type(t) 
    { }
    void print(Printer &p) const override;
    void debug(Printer &p) const override;
    void to_sexpr(Printer &p) const override;
    Value evaluate() const override {
        throw std::logic_error("Not implemented");
    }
private:
    Expr* m_expr;
    Type* m_type;
};

class Rec_expr : public Expr {
public:
    Rec_expr(Expr* e, Type* t) 
        : m_expr(e), m_type(t) 
    { }
    void print(Printer &p) const override;
    void debug(Printer &p) const override;
    void to_sexpr(Printer &p) const override;
    Value evaluate() const override {
        throw std::logic_error("Not implemented");
    }
private:
    Expr* m_expr;
    Type* m_type;
};


// Operators

std::ostream& operator<<(std::ostream &os, Expr const& e);