#include <iostream>

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
