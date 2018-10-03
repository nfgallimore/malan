#pragma once

#include <iostream>

class Value
{
public:
    enum Kind {
        int_val,
        float_val,
        bool_val,
        str_val
    };
    
    union Data {
        Data(int d) : z(d) { }
        Data(float d) : f(d) { }
        Data(bool d) : b(d) { }
        Data(char* d) : s(d) { }

        int z;
        float f;
        bool b;
        char* s;
    };

    explicit Value(int v) : m_kind(int_val), m_data(v) { }
    explicit Value(float v) : m_kind(float_val), m_data(v) { }
    explicit Value(bool v) : m_kind(bool_val), m_data(v) { }
    explicit Value(char* v) : m_kind(str_val), m_data(v) { } 

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

    std::string get_str() const {
        assert(m_kind == str_val);
        return m_data.s;
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
    Bool_literal(bool b) : m_value(b) { }
    void print(std::ostream& os, Expr const& e) const override;
    void debug(Expr const& e) const override;
    void to_sexpr(Expr const& e) const override;
    Value evaluate() const override { return Value(m_value); }
private:
    bool m_value;
};

class Int_literal : public Expr {
public:    
    Int_literal(int i) : m_value(i) { }
    void print(std::ostream& os, Expr const& e) const override;
    void debug(Expr const& e) const override;
    void to_sexpr(Expr const& e) const override;
    Value evaluate() const override { return Value(m_value); }
private:
    int m_value;
};

class Identifier : public Expr {
public:
    Identifier(char* s) : m_value(s) { }
    void print(std::ostream& os, Expr const& e) const override;
    void debug(Expr const& e) const override;
    void to_sexpr(Expr const& e) const override;
    Value evaluate() const override { return Value(m_value); }
private:
    char* m_value;
};

class Logical_and : public Expr {
public:
    Logical_and(Expr const* e1, Expr const* e2) : m_e1(e1), m_e2(e2) { }
    void print(std::ostream& os, Expr const& e) const override;
    void debug(Expr const& e) const override;
    void to_sexpr(Expr const& e) const override;
    Value evaluate() const override;
private:
    Expr const* m_e1;
    Expr const* m_e2;
};

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