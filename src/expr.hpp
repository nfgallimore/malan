#pragma once

#include <iostream>

class Decl;

class Value
{
public:
    enum Kind {
        int_val,
        float_val,
        bool_val
    };
    
    union Data {
        Data(int d) : z(d) { }
        Data(float d) : f(d) { }
        Data(bool d) : b(d) { }

        int z;
        float f;
        bool b;
    };

    explicit Value(int v) : m_kind(int_val), m_data(v) { }
    explicit Value(float v) : m_kind(float_val), m_data(v) { }
    explicit Value(bool v) : m_kind(bool_val), m_data(v) { }

    Kind get_kind() const { return m_kind; }

    int get_int() const {
        assert(m_kind == int_val);
        return m_data.z;
    }

    float get_float() const {
        assert(m_kind == float_val);
        return m_data.f;
    }

    bool get_bool() const {
        assert(m_kind == bool_val);
        return m_data.b;
    }

private:
    Kind m_kind;
    Data m_data;
};

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
    Bool_literal(bool b) : m_value(b) { }
    void print(std::ostream& os) const override;
    void debug(std::ostream& os) const override;
    void to_sexpr(std::ostream& os) const override;
    Value evaluate() const override { return Value(m_value); }
private:
    bool m_value;
};

class Int_literal : public Expr {
public:    
    Int_literal(int i) : m_value(i) { }
    void print(std::ostream& os) const override;
    void debug(std::ostream& os) const override;
    void to_sexpr(std::ostream& os) const override;
    Value evaluate() const override { return Value(m_value); }
private:
    int m_value;
};

class Identifier : public Expr {
public:
    Identifier(Decl* d) : m_value(d) { }
    void print(std::ostream& os) const override;
    void debug(std::ostream& os) const override;
    void to_sexpr(std::ostream& os) const override;
    Value evaluate() const override { throw std::logic_error("Cannot evaluate an identifier."); }
private:
    Decl* m_value;
};

class Logical_and : public Expr {
public:
    Logical_and(Expr* e1, Expr* e2) : m_e1(e1), m_e2(e2) { }
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
};

std::ostream& operator<<(std::ostream& os, Expr const& e);

inline void
print(std::ostream& os, Expr const& e)
{
    e.print(os);
};