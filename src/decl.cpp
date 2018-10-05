#include <iostream>

#include "decl.hpp"
#include "type.hpp"
#include "name.hpp"
#include "expr.hpp"
#include "stmt.hpp"

void Var_decl::print(std::ostream& os) const {
    os << "var " << *m_name << " = " << *m_init;
}

void Var_decl::debug(std::ostream& os) const {
    os << "Var_decl " << this << '\n';
}

void Var_decl::to_sexpr(std::ostream& os) const {
    os << "(Var_decl " << *m_type << " " << *m_name << " " << *m_init << ")";
}

void Func_decl::print(std::ostream& os) const {
    os << "var " << *m_name << " = " << *m_body;
}

void Func_decl::debug(std::ostream& os) const {
    os << "Func_decl " << this << '\n';
}

void Func_decl::to_sexpr(std::ostream& os) const {
    os << "(Func_decl " << *m_ret << " " << *m_name << " " << m_body << ")";
}

std::ostream& operator<<(std::ostream& os, Decl const& d) {
    d.print(os);
    return os;
}
