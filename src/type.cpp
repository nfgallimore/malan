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
    p.print_tabs();
    p.print_string("Bool_type ");
    p.print_address(this);
    p.new_line();
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
    p.print_tabs();
    p.print_string("Int_type ");
    p.print_address(this);
    p.new_line();
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
    p.print_tabs();
    p.print_string("Float_type ");
    p.print_address(this);
    p.new_line();
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
    p.print_tabs();
    p.print_string("Ref_type ");
    p.print_address(this);
    p.new_line();
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
    p.print_tabs();
    p.print_string("Fun_type ");
    p.print_address(this);
    p.new_line();
    p.indent();

    if (!m_params.empty())
    {
        for (int i = 0; i < m_params.size(); i++)
        {
            p.print_tabs();
            m_params[i]->debug(p);
        }
    }
    p.print_tabs();
    p.print_string("Ret_type: ");
    
    p.indent();
    m_ret_type->debug(p);
    p.undent();

    p.undent();
    p.new_line();
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

/// Prints `t` to the output stream.
void
print(std::ostream& os, Type const* t)
{
    Printer p(os);
    t->print(p);
}

/// Prints the kind of type `t` and its address to output stream
void
debug(std::ostream& os, Type const* t)
{
    Printer p(os);
    t->debug(p);
}

/// Prints `t` as a symbolic expression to output stream
void
to_sexpr(std::ostream& os, Type const* t)
{
    Printer p(os);
    t->print(p);
}

/// Returns true when `a` and `b` denote the same type.
bool
equal(Type const* a, Type const* b)
{
    throw std::logic_error("Not implemented");
}
