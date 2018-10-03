#include <iostream>

#include "expr.hpp"
#include "decl.hpp"
#include "name.hpp"

// Integer literal expressions

void Int_literal::print(std::ostream& os) const {
    os << m_value;
}

void Int_literal::debug(std::ostream& os) const {
    os << "Int_literal " << this << '\n';
}

void Int_literal::to_sexpr(std::ostream& os) const {
    os << '(' << m_value << ')';
}

// Boolean literal operations

void Bool_literal::print(std::ostream& os) const {
    os << std::boolalpha << m_value;
}

void Bool_literal::debug(std::ostream& os) const {
    os << "Bool_literal " << this << '\n';
}

void Bool_literal::to_sexpr(std::ostream& os) const {
    os << '(' << m_value << ')';
}

// Identifier operations

void Identifier::print(std::ostream& os) const {
    os << m_value->get_name()->get_str();
}

void Identifier::debug(std::ostream& os) const {
    os << "Identifier " << this << '\n';
}

void Identifier::to_sexpr(std::ostream& os) const {
    os << '(' << m_value->get_name()->get_str() << ')';
}

// Logical And Operations

void Logical_and::print(std::ostream& os) const {
    os << *m_e1 << " AND " << *m_e2;
}

void Logical_and::debug(std::ostream& os) const {
    std::cout << "Logical_and " << this << '\n';
}

void Logical_and::to_sexpr(std::ostream& os) const {
    std::cout << "(AND " << *m_e1 << " " << *m_e2 << ")";
}

// Logical Or Operations

void Logical_or::print(std::ostream& os) const {
    os << *m_e1 << " OR " << *m_e2;
}

void Logical_or::debug(std::ostream& os) const {
    std::cout << "Logical_or " << this << '\n';
}

void Logical_or::to_sexpr(std::ostream& os) const {
    std::cout << "(OR " << *m_e1 << " " << *m_e2 << ")";
}

// Logical Not Operations

void Logical_not::print(std::ostream& os) const {
    os << " NOT " << *m_expr;
}

void Logical_not::debug(std::ostream& os) const {
    std::cout << "Logical_not " << this << '\n';
}

void Logical_not::to_sexpr(std::ostream& os) const {
    std::cout << "(NOT " << *m_expr << ")";
}

// Ternary Expression Operations

void Ternary_expr::print(std::ostream& os) const {
    os << "if (" << *m_e1 << ") then " << *m_e2 << " else " << *m_e3;
}

void Ternary_expr::debug(std::ostream& os) const {
    std::cout << "Ternary_expr " << this << '\n';
}

void Ternary_expr::to_sexpr(std::ostream& os) const {
    std::cout << "(Ternary_expr " << *m_e1 << " " << *m_e2 << " " << *m_e3 << ")";
}

// Equal Expression Operations

void Equal_expr::print(std::ostream& os) const {
    os << *m_e1 << " == " << *m_e2;
}

void Equal_expr::debug(std::ostream& os) const {
    std::cout << "Equal_expr " << this << '\n';
}

void Equal_expr::to_sexpr(std::ostream& os) const {
    std::cout << "(Equal_expr " << *m_e1 << " " << *m_e2 << ")";
}

// Not Equal Expression Operations

void Not_equal_expr::print(std::ostream& os) const {
    os << *m_e1 << " != " << *m_e2;
}

void Not_equal_expr::debug(std::ostream& os) const {
    std::cout << "Not_equal_expr " << this << '\n';
}

void Not_equal_expr::to_sexpr(std::ostream& os) const {
    std::cout << "(Not_equal_expr " << *m_e1 << " " << *m_e2 << ")";
}

// Less Than Expression Operations

void Less_than_expr::print(std::ostream& os) const {
    os << *m_e1 << " < " << *m_e2;
}

void Less_than_expr::debug(std::ostream& os) const {
    std::cout << "Less_than_expr " << this << '\n';
}

void Less_than_expr::to_sexpr(std::ostream& os) const {
    std::cout << "(Less_than_expr " << *m_e1 << " " << *m_e2 << ")";
}

// Greater Than Expression Operations

void Greater_than_expr::print(std::ostream& os) const {
    os << *m_e1 << " > " << *m_e2;
}

void Greater_than_expr::debug(std::ostream& os) const {
    std::cout << "Greater_than_expr " << this << '\n';
}

void Greater_than_expr::to_sexpr(std::ostream& os) const {
    std::cout << "(Greater_than_expr " << *m_e1 << " " << *m_e2 << ")";
}

// Less Than Or Equal Expression Operations

void Less_than_or_equal_expr::print(std::ostream& os) const {
    os << *m_e1 << " <= " << *m_e2;
}

void Less_than_or_equal_expr::debug(std::ostream& os) const {
    std::cout << "Less_than_or_equal_expr " << this << '\n';
}

void Less_than_or_equal_expr::to_sexpr(std::ostream& os) const {
    std::cout << "(Less_than_or_equal_expr " << *m_e1 << " " << *m_e2 << ")";
}

// Greater Than Or Equal Expression Operations

void Greater_than_or_equal_expr::print(std::ostream& os) const {
    os << *m_e1 << " >= " << *m_e2;
}

void Greater_than_or_equal_expr::debug(std::ostream& os) const {
    std::cout << "Greater_than_or_equal_expr " << this << '\n';
}

void Greater_than_or_equal_expr::to_sexpr(std::ostream& os) const {
    std::cout << "(Greater_than_or_equal_expr " << *m_e1 << " " << *m_e2 << ")";
}

std::ostream& operator<<(std::ostream& os, Expr const& e) {
    e.print(os);
    return os;
}
