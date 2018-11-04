#include <iostream>

#include "decl.hpp"
#include "type.hpp"
#include "name.hpp"
#include "expr.hpp"
#include "stmt.hpp"
#include "printer.hpp"

// Variable declaration printing operations

void 
Var_decl::print(Printer& p) const 
{
    p.get_stream() << *m_type << " " << m_name->get_str();
    if (is_initialized())
    {
        p.get_stream() << " = " << *m_init;
    }
}

void 
Var_decl::debug(Printer& p) const 
{
    p.print_address("Var_decl", this);
    p.indent();
    m_type->debug(p);
    p.print_address("Name", m_name);
    if (is_initialized())
    {
        m_init->debug(p);
    }
    p.undent();
}

void 
Var_decl::to_sexpr(Printer& p) const 
{
    p.print_string("(Var_decl (");
    m_type->to_sexpr(p);
    p.get_stream() << " " << m_name->get_str();
    if (is_initialized())
    {
        p.get_stream() << " " << m_init;
    }
    p.print_string(")");
}


// Function declaration printing operations

/// Prints like the following:
    // func f : (x : int, y : int) -> bool {
    //     return x < y;
    // }
void 
Func_decl::print(Printer& p) const 
{
    p.print_string("func ");
    p.get_stream() << m_name->get_str() << " : (";
    for (int i = 0, len = m_parms->size(); i < len; i++) 
    {
        Decl* d = (*m_parms)[i];
        p.get_stream() << d->get_name()->get_str() << " : " << *d->get_type();
    
        // print `,` if not the last param
        if (i != len - 1) 
        {
            p.print_string(", ");
        }
    }

    // prints return type
    p.get_stream() << ") -> " << *m_ret;

    // begin statements
    m_body->print(p);
}

void 
Func_decl::debug(Printer& p) const 
{
    p.print_address("Func_decl", this);
    p.print_address("Name", m_name);

    // Print the parameters' addresses
    p.indent();
    for (int i = 0, len = m_parms->size(); i < len; i++) 
    {
        (*m_parms)[i]->debug(p);
    }
    p.undent();

    // Print the return type's address
    m_ret->debug(p);

    // Debugs the statement body
    m_body->debug(p);
}

void 
Func_decl::to_sexpr(Printer& p) const 
{
    p.get_stream() << "(Func " << m_name->get_str() << " ";
    if (!m_parms->empty()) {
        p.print_string(" Params(");
        for (int i = 0, len = m_parms->size(); i < len; i++) 
        {
            Decl* parm = (*m_parms)[i];
            parm->to_sexpr(p);
            if (i != len - 1)
                p.print_string(" ");
        }
        p.print_string(")");
    }
    p.print_string(" Ret (");
    m_ret->to_sexpr(p);
    p.print_string(")");

    p.print_string(" Body (");
    m_body->to_sexpr(p);
    p.print_string(")");
}


// Operators

std::ostream& operator<<(std::ostream& os, Decl const& d) 
{
    Printer p(os);
    d.print(p);
    return p.get_stream();
}
