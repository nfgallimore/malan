#include <iostream>

#include "expr.hpp"
#include "decl.hpp"
#include "name.hpp"

void Int_literal::print(std::ostream& os) const {
    os << m_value;
}

void Int_literal::debug(std::ostream& os) const {
    os << "Int_literal " << this << '\n';
}

void Int_literal::to_sexpr(std::ostream& os) const {
    os << '(' << m_value << ')';
}

void Bool_literal::print(std::ostream& os) const {
    os << std::boolalpha << m_value;
}

void Bool_literal::debug(std::ostream& os) const {
    os << "Bool_literal " << this << '\n';
}

void Bool_literal::to_sexpr(std::ostream& os) const {
    os << '(' << m_value << ')';
}

void Identifier::print(std::ostream& os) const {
    os << m_value->get_name()->get_str();
}

void Identifier::debug(std::ostream& os) const {
    os << "Identifier " << this << '\n';
}

void Identifier::to_sexpr(std::ostream& os) const {
    os << '(' << m_value->get_name()->get_str() << ')';
}

void Logical_and::print(std::ostream& os) const {
    os << *m_e1 << " AND " << *m_e2;
}

void Logical_and::debug(std::ostream& os) const {
    std::cout << "Logical_and " << this << '\n';
}

void Logical_and::to_sexpr(std::ostream& os) const {
    std::cout << "(AND " << *m_e1 << " " << *m_e2 << ")";
}

std::ostream& operator<<(std::ostream& os, Expr const& e) {
    e.print(os);
    return os;
}
