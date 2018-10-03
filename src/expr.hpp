#pragma once

#include <iostream>

class Value
{
public:
    enum Kind
    {
        int_val,
        float_val,
        bool_val
    };
    
    union Data 
    {
        Data(int d) : z(d) { }
        Data(float d) : f(d) { }
        Data(bool d) : b(d) { }

        int z;
        float f;
        bool b;
    };

    explicit Value(int v)
        : m_kind(int_val), m_data(v)
    { }

    explicit Value(float v)
        : m_kind(float_val), m_data(v)
    { }

    explicit Value(bool v)
        : m_kind(bool_val), m_data(v)
    { }

    Kind get_kind() const 
    {
        return m_kind;
    }

    int get_int() const 
    {
        assert(m_kind == int_val);
        return m_data.z;
    }

    float get_float() const 
    {
        assert(m_kind == float_val);
        return m_data.f;
    }

    bool get_bool() const 
    {
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
    virtual void print(std::ostream& os, Expr const& e) const = 0;

    // debugs an expression with the name of class and memory address
    virtual void debug(Expr const& e) const = 0;

    // converts to sexpr
    virtual void to_sexpr(Expr const& e) const = 0;
};

class Bool_literal : public Expr {
public:    
    void print(std::ostream& os, Expr const& e) const override;
    void debug(Expr const& e) const override;
    void to_sexpr(Expr const& e) const override;
    Bool_literal(bool b) : m_value(b) { }
    Value evaluate() const override { return Value(m_value); }

private:
    bool m_value;
};

class Int_literal : public Expr {
public:    
    void print(std::ostream& os, Expr const& e) const override;
    void debug(Expr const& e) const override;
    void to_sexpr(Expr const& e) const override;
    Int_literal(int i) : m_value(i) { }
    Value evaluate() const override { return Value(m_value); }

private:
    int m_value;
};

class Identifier : public Expr {
public:
    void print(std::ostream& os, Expr const& e) const override;
    void debug(Expr const& e) const override;
    void to_sexpr(Expr const& e) const override;
    Identifier(Value v) : m_value(v) { }
    Value evaluate() const override { return m_value; }

private:
    Value m_value;
};

class Logical_and : public Expr {
    void print(std::ostream& os, Expr const& e) const override;
    void debug(Expr const& e) const override;
    void to_sexpr(Expr const& e) const override;
    Identifier(Value v) : m_value(v) { }
    Value evaluate() const override { return m_value; }
}

std::ostream& operator<<(std::ostream& os, Expr const& e);

inline void
print(std::ostream& os, Expr const& e)
{
    e.print(os, e);
};

inline void
debug (Expr const& e)
{
    e.debug(e);
}

inline void
to_sexpr(Expr const& e)
{
    e.to_sexpr(e);
}