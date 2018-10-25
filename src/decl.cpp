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
    assert(m_init != nullptr);
    p.get_stream() << " = " << *m_init;
}

void 
Var_decl::debug(Printer& p) const 
{
    p.print_string("Var_decl ");
    p.print_address(this);
    p.new_line();
    p.indent();
    
    p.print_tabs();
    p.print_string("Type ");
    p.print_address(m_type);
    p.new_line();

    p.print_tabs();
    p.print_string("Name ");
    p.print_address(m_name);
    p.new_line();

    p.print_tabs();
    m_init->debug(p);
    p.undent();
}

void 
Var_decl::to_sexpr(Printer& p) const 
{
    p.get_stream() << "(Var_decl (";
    m_type->to_sexpr(p);
    p.get_stream() << " " << m_name->get_str();
    if (m_init != nullptr) {
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
    if (!m_parms->empty()) {
        for (int i = 0, len = m_parms->size(); i < len; i++) {

            Decl* d = (*m_parms)[i];
            p.get_stream() << d->get_name()->get_str() << " : " << *d->get_type();
        
            // print `,` if not the last param
            if (i != len - 1) {
                p.print_string(", ");
            }
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
    // Print Func_decl's address
    p.print_string("Func_decl ");
    p.print_address(this);
    p.new_line();

    // Print name of function's address
    p.indent();
    p.print_tabs();
    p.print_string("Name ");
    p.print_address(m_name);
    p.new_line();

    // Print parameters' address
    p.print_tabs();
    p.print_string("Parameters ");
    p.print_address(m_parms);
    p.new_line();

    // Print the parameters' addresses
    p.indent();
    for (int i = 0, len = m_parms->size(); i < len; i++) {
        p.print_tabs();
        (*m_parms)[i]->debug(p);
    }
    p.undent();

    // Print the return type's address
    p.print_tabs();
    p.print_string("Return Type ");
    p.print_address(m_ret);
    p.new_line();

    // Debugs the statement body
    p.print_tabs();
    m_body->debug(p);
}

void 
Func_decl::to_sexpr(Printer& p) const 
{
    p.get_stream() << "(Func " << m_name->get_str() << " ";
    if (!m_parms->empty()) {
        p.print_string(" Params(");
        for (int i = 0, len = m_parms->size(); i < len; i++) {
            auto x = (*m_parms)[i];
            (*m_parms)[i]->to_sexpr(p);
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


// Reference declaration printing operations

void 
Ref_decl::print(Printer& p) const 
{
    p.get_stream() << "Ref " << *m_type << " " << m_name->get_str();
    if (m_init != nullptr)
        p.get_stream() << " = " << *m_init;
    p.print_string(";");
}

void 
Ref_decl::debug(Printer& p) const 
{
    p.print_string("Ref ");
    p.print_address(this);
    p.indent();
    p.new_line();

    p.print_tabs();
    p.print_string("Type ");
    m_type->debug(p);

    p.print_tabs();
    p.print_string("Name ");
    p.print_address(m_name);
    p.new_line();

    p.print_tabs();
    p.print_string("Expr ");
    m_init->debug(p);
    p.new_line();

    p.undent();
}

void 
Ref_decl::to_sexpr(Printer& p) const 
{
    p.print_string("(Ref ");
    m_type->to_sexpr(p);
    p.get_stream() << " " << m_name->get_str() << " ";
    if (m_init != nullptr)
        m_init->to_sexpr(p);
    p.print_string(")");
}


// Operators

std::ostream& operator<<(std::ostream& os, Decl const& d) 
{
    Printer p(os);
    d.print(p);
    return p.get_stream();
}
