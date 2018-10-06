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
    p.get_stream() << "(var ";
    m_type->to_sexpr(p);
    p.get_stream() << " " << m_name->get_str() << " ";
    p.get_stream() << m_init;
}


// Function declaration printing operations
// Prints like the following:
    // func f : (x : int, y : int) -> bool {
    //     return x < y;
    // }
void Func_decl::print(Printer& p) const {
    p.print_string("func ");
    p.get_stream() << m_name->get_str() << " : (";
    if (m_parms->empty()) {
        p.print_string(")");
    }
    else {
        for (int i = 0, len = m_parms->size(); i < len; i++) {

            Decl* d = (*m_parms)[i];
            p.get_stream() << d->get_name()->get_str() << " : " << *d->get_type();
        
            // print `,` if not the last param
            if (i != len - 1) {
                p.print_string(", ");
            }
        }
        p.print_string(") -> ");
        
        // :O
        p.get_stream() << *static_cast<Fun_type const*>(m_ret)->get_return_type();

        // begin statements
        p.print_string(" {\n");
        p.indent();
        p.print_tabs();
        m_body->print(p);
        p.undent();
        p.print_string("\n}");

    }
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
