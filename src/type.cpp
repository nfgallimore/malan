#include <iostream>

#include "type.hpp"
#include "printer.hpp"


// Bool type printing operations

void
Bool_type::print(Printer& p) const
{
    p.print_string("bool");
}

void
Bool_type::debug(Printer& p) const
{
    p.print_address("Bool_type", this);
}

void
Bool_type::to_sexpr(Printer& p) const
{
    p.print_string("(bool)");
}


// Integer type printing operations

void
Int_type::print(Printer& p) const
{
    p.print_string("int");
}

void
Int_type::debug(Printer& p) const
{
    p.print_address("Int_type", this);
}

void
Int_type::to_sexpr(Printer& p) const
{
    p.print_string("(int)");
}


// Float type printing operations

void
Float_type::print(Printer& p) const
{
    p.print_string("float");
}

void
Float_type::debug(Printer& p) const
{
    p.print_address("Float_type", this);
}

void
Float_type::to_sexpr(Printer& p) const
{
    p.print_string("(float)");
}


// Reference type printing operations

void
Ref_type::print(Printer& p) const
{
    p.get_stream() << "ref " << *get_ref_type();
}

void
Ref_type::debug(Printer& p) const
{
    p.print_address("Ref_type", this);
}

void
Ref_type::to_sexpr(Printer& p) const
{
    p.get_stream() << "(Ref_type " << *this << ')';
}

// Function type printing operations

void
Fun_type::print(Printer& p) const
{
    std::vector<Type*> params = get_params();
    if (params.empty())
        p.get_stream() << "() -> " << *get_return_type();
    else
    {
        p.get_stream() << "(";
        for (int i = 0; i < params.size(); i++)
        {
            if (i == params.size() - 1) 
                p.get_stream() << (*params[i]) << ")";
            else
                p.get_stream() << *params[i] << ",";
        }
        p.get_stream() << " -> " << *get_return_type();
    }
}

void
Fun_type::debug(Printer& p) const
{
    p.print_address("Fun_type", this);

    p.indent();
    for (int i = 0; i < m_params.size(); i++)
    {
        p.print_tabs();
        m_params[i]->debug(p);
    }
    m_ret_type->debug(p);
    p.undent();
}

void
Fun_type::to_sexpr(Printer& p) const
{
    p.print_string("(Fun");
    if (!m_params.empty())
    {
        p.print_string(" Params(");
        for (int i = 0; i < m_params.size(); i++)
        {
            m_params[i]->to_sexpr(p);
        }
        p.print_string(")");
    }
    p.print_string(" Ret");
    m_ret_type->to_sexpr(p);
    p.print_string(")");
}


// Operators

std::ostream& operator<<(std::ostream& os, Type const& t)
{
    Printer p(os);
    t.print(p);
    return p.get_stream();
}


// Operations

/// Returns true when `a` and `b` denote the same type.
bool
equal(Type const* a, Type const* b)
{
    throw std::logic_error("Not implemented");
}
