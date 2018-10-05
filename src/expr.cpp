#include <iostream>

#include "expr.hpp"
#include "decl.hpp"
#include "name.hpp"


/* Programming style:

Always have std::ostream as first argument if included.

*/

// TODO add more generalized cases like defined 
// in printer.hpp for unary, binary, k-ary expressions



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
    // TODO use get_name() like in to_sexpr
    os << m_value->get_name()->get_str();
}

void Identifier::debug(std::ostream& os) const {
    os << "Identifier " << this << '\n';
} 

void Identifier::to_sexpr(std::ostream& os) const {
    os << '(' << *m_value->get_name() << ')';
}

// Logical And Operations

void Logical_and::print(std::ostream& os) const {
    os << *m_e1 << " AND " << *m_e2;
}

void Logical_and::debug(std::ostream& os) const {
    os << "Logical_and " << this;
    os << "\n    ";
    debugexpr(os, *m_e1);
    os << "    ";
    debugexpr(os, *m_e2);
}

void Logical_and::to_sexpr(std::ostream& os) const {
    os << "(AND ";
    sexpr(os, *m_e1);
    os << " ";
    sexpr(os, *m_e2);
    os << ')';
}

// Logical Or Operations

void Logical_or::print(std::ostream& os) const {
    os << *m_e1 << " OR " << *m_e2;
}

void Logical_or::debug(std::ostream& os) const {
    os << "Logical_or " << this;
    os << "\n    ";
    debugexpr(os, *m_e1);
    os << "    ";
    debugexpr(os, *m_e2);
}

void Logical_or::to_sexpr(std::ostream& os) const {
    os << "(OR ";
    sexpr(os, *m_e1);
    os << " ";
    sexpr(os, *m_e2);
    os << ')';
}

// Logical Not Operations

void Logical_not::print(std::ostream& os) const {
    os << " NOT " << *m_expr;
}

void Logical_not::debug(std::ostream& os) const {
    os << "Logical_not " << this << '\n';
    debugexpr(os, *m_expr);
}

void Logical_not::to_sexpr(std::ostream& os) const {
    os << "(NOT " << *m_expr << ')';
}

// Ternary Expression Operations

void Ternary_expr::print(std::ostream& os) const {
    os << "if (" << *m_e1 << ") then " << *m_e2 << " else " << *m_e3;
}

void Ternary_expr::debug(std::ostream& os) const {
    os << "Ternary_expr " << this << '\n';
}

void Ternary_expr::to_sexpr(std::ostream& os) const {
    os << "(if-expr ";
    sexpr(os, *m_e1);
    os << " (then ";
    sexpr(os, *m_e2);
    os << ") (else ";
    sexpr(os, *m_e3);
    os << "))";
}

// Equal Expression Operations

void Equal_expr::print(std::ostream& os) const {
    os << *m_e1 << " == " << *m_e2;
}

void Equal_expr::debug(std::ostream& os) const {
    os << "Equal_expr " << this << '\n';
}

void Equal_expr::to_sexpr(std::ostream& os) const {
    os << "(== " << *m_e1 << " " << *m_e2 << ')';
}

// Not Equal Expression Operations

void Not_equal_expr::print(std::ostream& os) const {
    os << *m_e1 << " != " << *m_e2;
}

void Not_equal_expr::debug(std::ostream& os) const {
    os << "Not_equal_expr " << this << '\n';
}

void Not_equal_expr::to_sexpr(std::ostream& os) const {
    os << "(!= " << *m_e1 << " " << *m_e2 << ')';
}

// Less Than Expression Operations

void Less_than_expr::print(std::ostream& os) const {
    os << *m_e1 << " < " << *m_e2;
}

void Less_than_expr::debug(std::ostream& os) const {
    os << "Less_than_expr " << this << '\n';
}

void Less_than_expr::to_sexpr(std::ostream& os) const {
    os << "(< " << *m_e1 << " " << *m_e2 << ')';
}

// Greater Than Expression Operations

void Greater_than_expr::print(std::ostream& os) const {
    os << *m_e1 << " > " << *m_e2;
}

void Greater_than_expr::debug(std::ostream& os) const {
    os << "Greater_than_expr " << this << '\n';
}

void Greater_than_expr::to_sexpr(std::ostream& os) const {
    os << "(> " << *m_e1 << " " << *m_e2 << ')';
}

// Less Than Or Equal Expression Operations

void Less_than_or_equal_expr::print(std::ostream& os) const {
    os << *m_e1 << " <= " << *m_e2;
}

void Less_than_or_equal_expr::debug(std::ostream& os) const {
    os << "Less_than_or_equal_expr " << this << '\n';
}

void Less_than_or_equal_expr::to_sexpr(std::ostream& os) const {
    os << "(<= " << *m_e1 << " " << *m_e2 << ')';
}

// Greater Than Or Equal Expression Operations

void Greater_than_or_equal_expr::print(std::ostream& os) const {
    os << *m_e1 << " >= " << *m_e2;
}

void Greater_than_or_equal_expr::debug(std::ostream& os) const {
    os << "Greater_than_or_equal_expr " << this << '\n';
}

void Greater_than_or_equal_expr::to_sexpr(std::ostream& os) const {
    os << "(>= " << *m_e1 << " " << *m_e2 << ')';
}

// Addition Expression Operations

void Add_expr::print(std::ostream& os) const {
    os << *m_e1 << " + " << *m_e2;
}

void Add_expr::debug(std::ostream& os) const {
    os << "Add_expr " << this << '\n';
}

void Add_expr::to_sexpr(std::ostream& os) const {
    os << "(+ " << *m_e1 << " " << *m_e2 << ')';
}

// Subtraction Expression Operations

void Sub_expr::print(std::ostream& os) const {
    os << *m_e1 << " - " << *m_e2;
}

void Sub_expr::debug(std::ostream& os) const {
    os << "Sub_expr " << this << '\n';
}

void Sub_expr::to_sexpr(std::ostream& os) const {
    os << "(- " << *m_e1 << " " << *m_e2 << ')';
}

// Multiplication Expression Operations

void Mult_expr::print(std::ostream& os) const {
    os << *m_e1 << " * " << *m_e2;
}

void Mult_expr::debug(std::ostream& os) const {
    os << "Mult_expr " << this << '\n';
}

void Mult_expr::to_sexpr(std::ostream& os) const {
    os << "(* " << *m_e1 << " " << *m_e2 << ')';
}

// Quotient Expression Operations

void Quot_expr::print(std::ostream& os) const {
    os << *m_e1 << " / " << *m_e2;
}

void Quot_expr::debug(std::ostream& os) const {
    os << "Quot_expr " << this << '\n';
}

void Quot_expr::to_sexpr(std::ostream& os) const {
    os << "(/ " << *m_e1 << " " << *m_e2 << ')';
}

// Remainder Expression Operations

void Rem_expr::print(std::ostream& os) const {
    os << *m_e1 << " % " << *m_e2;
}

void Rem_expr::debug(std::ostream& os) const {
    os << "Rem_expr " << this << '\n';
}

void Rem_expr::to_sexpr(std::ostream& os) const {
    os << "(% " << *m_e1 << " " << *m_e2 << ')';
}

// Negate Expression Operations

void Negate_expr::print(std::ostream& os) const {
    os << '-' <<  *m_expr;
}

void Negate_expr::debug(std::ostream& os) const {
    os << "Negate_expr " << this << '\n';
}

void Negate_expr::to_sexpr(std::ostream& os) const {
    os << "(Negate " << *m_expr << ')';
}

// Reciprocal Expression Operations

void Reciprocal_expr::print(std::ostream& os) const {
    os << "/ " <<  *m_expr;
}

void Reciprocal_expr::debug(std::ostream& os) const {
    os << "Reciprocal_expr " << this << '\n';
}

void Reciprocal_expr::to_sexpr(std::ostream& os) const {
    os << "(Recip " << *m_expr << ')';
}

std::ostream& operator<<(std::ostream& os, Expr const& e) {
    e.print(os);
    return os;
}