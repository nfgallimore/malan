#include <iostream>

#include "expr.hpp"

void Int_literal::print(std::ostream& os, Expr const& e) const {
    os << e.evaluate().get_int();
}

void Int_literal::debug(Expr const& e) const {
    std::cout << "Int_literal " << &e << '\n';
}

void Int_literal::to_sexpr(Expr const& e) const {
    std::cout << "Int(" << e.evaluate().get_int() << ')';
}

void Bool_literal::print(std::ostream& os, Expr const& e) const {
    os << std::boolalpha << e.evaluate().get_bool();
}

void Bool_literal::debug(Expr const& e) const {
    std::cout << "Bool_literal " << &e << '\n';
}

void Bool_literal::to_sexpr(Expr const& e) const {
    std::cout << "Bool(" << e.evaluate().get_bool() << ')';
}

void Identifier::print(std::ostream& os, Expr const& e) const {
    os << e.evaluate().get_str();
}

void Identifier::debug(Expr const& e) const {
    std::cout << "Identifier " << &e << '\n';
}

void Identifier::to_sexpr(Expr const& e) const {
    std::cout << "Identifier(" << e.evaluate().get_str() << ')';
}

std::ostream& operator<<(std::ostream& os, Expr const& e) {
    e.print(os, e);
    return os;
}
