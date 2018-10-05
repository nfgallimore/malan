#include <iostream>

#include "decl.hpp"
#include "type.hpp"
#include "name.hpp"
#include "expr.hpp"
#include "stmt.hpp"
#include "printer.hpp"

// Variable declaration printing operations

void Var_decl::print(Printer& p) const {
    p.get_stream() << *m_type << " " << m_name->get_str() << " = " << *m_init;
}

void Var_decl::debug(Printer& p) const {
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
    p.print_string("Expr ");
    p.print_address(m_init);
    m_init->debug(p);
    p.new_line();

    p.undent();
}

void Var_decl::to_sexpr(Printer& p) const {

}


// Function declaration printing operations

void Func_decl::print(Printer& p) const {

}

void Func_decl::debug(Printer& p) const {

}

void Func_decl::to_sexpr(Printer& p) const {

}


// Reference declaration printing operations

void Ref_decl::print(Printer& p) const {

}

void Ref_decl::debug(Printer& p) const {

}

void Ref_decl::to_sexpr(Printer& p) const {

}

std::ostream& operator<<(std::ostream& os, Decl const& d) {
    Printer p(os);
    d.print(p);
    return p.get_stream();
}
