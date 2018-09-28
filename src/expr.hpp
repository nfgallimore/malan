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

struct Expr
{
public:
    enum Kind
    {
        literal,
        unary,
        binary
    };

    virtual Value evaluate() const = 0;

    friend std::ostream& operator<<(std::ostream& os, Expr const& t);

    void print(std::ostream& os, Expr const* e);
};


// Helper functions

/// Checks if the values are different from each other and throws an exception if they are
void check_if_different_types(Value* v1, Value* v2) 
{
    if (v1->get_kind() != v2->get_kind()) 
    {
        throw std::logic_error("Cannot evaluate two expressions of different kinds of values.");
    }
}

// Checks if the value is a boolean and throws an exception if it is
void check_if_bool(Value* v) 
{
    if (v->get_kind() == Value::bool_val)
    {
        throw std::logic_error("Cannot perform operation on boolean values");
    }
}



/// Class to represent a unary expression
class Unary_expr : public Expr
{
public:
    /// Construct a unary expression
    Unary_expr(Expr* expr, char* op) 
        : m_expr(expr), m_op(op)
    { }

    /// Gets the expression operand
    Expr* get_operand() const 
    {
        return m_expr;
    }

    /// Prints the unary expression
    virtual void print(std::ostream& str);

private:
    Expr* m_expr;
    char* m_op;
};



class Binary_expr : public Expr 
{
public:
    Expr* get_lhs() const
    {
 ;       return m_e1;
    }
    
    Expr* get_rhs() const 
    {
        return m_e2;
    }

    Binary_expr(Expr* left, Expr* right, char* op) 
        : m_e1(left), m_e2(right), m_op(op)
    { }

private:
    Expr* m_e1;
    Expr* m_e2;
    char* m_op;
};



class Bool_expr : Expr
{
public:
    Value evaluate() const override 
    {
        return Value(value); 
    }

private:
    bool value;
};



class Int_expr : Expr
{
public:
    Value evaluate() const override
    {
        return Value(value); 
    }

private:
    int value;
};



class Float_expr : Expr
{
public:
    Value evaluate() const override 
    {
        return Value(value); 
    }

private:
    float value;
};



class Add_expr : Binary_expr
{
public:
    Value evaluate() const override
    {
        Value v1 = get_lhs()->evaluate();
        Value v2 = get_rhs()->evaluate();

        check_if_bool(&v1);

        check_if_different_types(&v1, &v2);

        switch(v1.get_kind())
        {
            case Value::int_val:
                return Value(v1.get_int() + v2.get_int());

            case Value::float_val:
                return Value(v1.get_float() + v2.get_float());
        }

        throw std::logic_error("Unknown kind of value");
    }
};



class Sub_expr : Binary_expr
{
public:
    Value evaluate() const override
    {
        Value v1 = get_lhs()->evaluate();
        Value v2 = get_rhs()->evaluate();

        check_if_bool(&v1);
        
        check_if_different_types(&v1, &v2);


        switch(v1.get_kind())
        {
            case Value::int_val:
                return Value(v1.get_int() - v2.get_int());

            case Value::float_val:
                return Value(v1.get_float() - v2.get_float());
        }

        throw std::logic_error("Unknown kind of value");
    }
};



class Mult_expr : Binary_expr
{
public:
    Value evaluate() const override
    {
        Value v1 = get_lhs()->evaluate();
        Value v2 = get_rhs()->evaluate();

        check_if_bool(&v1);

        check_if_different_types(&v1, &v2);


        switch(v1.get_kind())
        {
            case Value::int_val:
                return Value(v1.get_int() * v2.get_int());

            case Value::float_val:
                return Value(v1.get_float() * v2.get_float());
        }

        throw std::logic_error("Unknown kind of value");
    }
};



class Div_expr : Binary_expr
{
public:
    Value evaluate() const override
    {
        Value v1 = get_lhs()->evaluate();
        Value v2 = get_rhs()->evaluate();

        check_if_bool(&v1);

        check_if_different_types(&v1, &v2);

        switch(v1.get_kind())
        {
            case Value::int_val:
                return Value(v1.get_int() / v2.get_int());

            case Value::float_val:
                return Value(v1.get_float() / v2.get_float());
        }

        throw std::logic_error("Unknown kind of value");
    }
};


// Comparison expressions

/// Equality expression
class Eq_expr : Binary_expr
{
public:
    Value evaluate() const override
    {
        Value v1 = get_lhs()->evaluate();
        Value v2 = get_rhs()->evaluate();

        check_if_different_types(&v1, &v2);

        switch(v1.get_kind())
        {
            case Value::int_val:
                return Value(v1.get_int() == v2.get_int());

            case Value::float_val:
                return Value(v1.get_float() == v2.get_float());

            case Value::bool_val:
                return Value(v1.get_bool() == v2.get_bool());
        }

        throw std::logic_error("Unknown kind of value");
    }
};


/// Not equal expression
class Not_eq_expr : Binary_expr
{
public:
    Value evaluate() const override
    {
        Value v1 = get_lhs()->evaluate();
        Value v2 = get_rhs()->evaluate();

        check_if_different_types(&v1, &v2);

        switch(v1.get_kind())
        {
            case Value::int_val:
                return Value(v1.get_int() != v2.get_int());

            case Value::float_val:
                return Value(v1.get_float() != v2.get_float());

            case Value::bool_val:
                return Value(v1.get_bool() != v2.get_bool());
        }

        throw std::logic_error("Unknown kind of value");
    }
};



class Lt_expr : Binary_expr
{
public:
    Value evaluate() const override
    {
        Value v1 = get_lhs()->evaluate();
        Value v2 = get_rhs()->evaluate();

        check_if_bool(&v1);

        check_if_different_types(&v1, &v2);

        switch(v1.get_kind())
        {
            case Value::int_val:
                return Value(v1.get_int() < v2.get_int());

            case Value::float_val:
                return Value(v1.get_float() < v2.get_float());
        }

        throw std::logic_error("Unknown kind of value");
    }
};



class Gt_expr : Binary_expr
{
public:
    Value evaluate() const override
    {
        Value v1 = get_lhs()->evaluate();
        Value v2 = get_rhs()->evaluate();

        check_if_bool(&v1);

        check_if_different_types(&v1, &v2);

        switch(v1.get_kind())
        {
            case Value::int_val:
                return Value(v1.get_int() > v2.get_int());

            case Value::float_val:
                return Value(v1.get_float() > v2.get_float());
        }

        throw std::logic_error("Unknown kind of value");
    }
};



class Lt_or_eq_expr : Binary_expr
{
public:
    Value evaluate() const override
    {
        Value v1 = get_lhs()->evaluate();
        Value v2 = get_rhs()->evaluate();

        check_if_bool(&v1);

        check_if_different_types(&v1, &v2);

        switch(v1.get_kind())
        {
            case Value::int_val:
                return Value(v1.get_int() <= v2.get_int());

            case Value::float_val:
                return Value(v1.get_float() <= v2.get_float());
        }

        throw std::logic_error("Unknown kind of value");
    }
};



class Gt_or_eq_expr : Binary_expr
{
public:
    Value evaluate() const override
    {
        Value v1 = get_lhs()->evaluate();
        Value v2 = get_rhs()->evaluate();

        check_if_bool(&v1);

        check_if_different_types(&v1, &v2);

        switch(v1.get_kind())
        {
            case Value::int_val:
                return Value(v1.get_int() <= v2.get_int());

            case Value::float_val:
                return Value(v1.get_float() <= v2.get_float());
        }

        throw std::logic_error("Unknown kind of value");
    }
};



class Or_expr : Binary_expr
{
public:
    Value evaluate() const override
    {
        Value v1 = get_lhs()->evaluate();
        Value v2 = get_rhs()->evaluate();
        
        if (v1.get_kind() != Value::bool_val && v2.get_kind() != Value::bool_val)
        {
            throw std::logic_error("Logical operations can only be performed on boolean values.");
        }

        return Value(v1.get_bool() || v2.get_bool());
    }
};



class And_expr : Binary_expr
{
public:
    Value evaluate() const override
    {
        Value v1 = get_lhs()->evaluate();
        Value v2 = get_rhs()->evaluate();
        
        if (v1.get_kind() != Value::bool_val && v2.get_kind() != Value::bool_val)
        {
            throw std::logic_error("Logical operations can only be performed on boolean values.");
        }

        return Value(v1.get_bool() && v2.get_bool());
    }

    And_expr(Expr* e1, Expr* e2) 
        : Binary_expr(e1, e2, "AND")
    { }

    Expr* print();
};

class Not_expr : Unary_expr
{
public:
    Not_expr(Expr* e)
        : Unary_expr(e, "NOT")
    { }
    Expr* print();
};