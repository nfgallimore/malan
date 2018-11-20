#include <iostream>

#include "expr.hpp"
#include "decl.hpp"
#include "name.hpp"

// Integer literal expressions

void
Int_lit::print(Printer& p) const
{
    p.get_stream() << m_value.get_int();
}

void
Int_lit::debug(Printer& p) const
{
    p.print_address("Int_lit", this);
    p.indent();
    m_type->debug(p);
    p.undent();
}

void
Int_lit::to_sexpr(Printer& p) const
{
    p.get_stream() << '(' << m_value.get_int() << ')';
}


// Boolean literal expression operations

void
Bool_lit::print(Printer& p) const
{
    p.get_stream() << std::boolalpha << m_value.get_bool();
}

void
Bool_lit::debug(Printer& p) const
{
    p.print_address("Bool_lit", this);
    p.indent();
    m_type->debug(p);
    p.undent();
}

void
Bool_lit::to_sexpr(Printer& p) const
{
    p.get_stream() << '(' << std::boolalpha << m_value.get_bool() << ')';
}


// Float literal expressions

void
Float_lit::print(Printer& p) const
{
    p.get_stream() << m_value.get_float();
}

void
Float_lit::debug(Printer& p) const
{
    p.print_address("Float_lit", this);
    p.indent();
    m_type->debug(p);
    p.undent();
}

void
Float_lit::to_sexpr(Printer& p) const
{
    p.get_stream() << '(' << m_value.get_float() << ')';
}


// Identifier operations

void
Id_expr::print(Printer& p) const
{
    p.get_stream() << m_decl->get_name()->get_str();
}

void
Id_expr::debug(Printer& p) const
{
    p.print_address("Id_expr", this);
    p.indent();
    m_decl->debug(p);
    m_type->debug(p);
    p.undent();
}

void
Id_expr::to_sexpr(Printer& p) const
{
    p.get_stream() << '(' << m_decl->get_name()->get_str() << ')';
}


// Logical And Operations

void
And_expr::print(Printer& p) const
{
    p.get_stream() << "(" << *m_e1 << " AND " << *m_e2 << ")";
}

void
And_expr::debug(Printer& p) const
{
    p.print_address("And_expr", this);    
    p.indent();
    m_e1->debug(p);
    m_e2->debug(p);
    m_type->debug(p);
    p.undent();
}

void
And_expr::to_sexpr(Printer& p) const
{
    p.print_string("(AND ");
    m_e1->to_sexpr(p);
    p.print_string(" ");
    m_e2->to_sexpr(p);
    p.print_string(")");
}


// Logical Or Operations

void
Or_expr::print(Printer& p) const
{
    p.get_stream() << "(" << *m_e1 << " OR " << *m_e2 << ")";
}

void
Or_expr::debug(Printer& p) const
{
    p.print_address("Or_expr", this);    
    p.indent();
    m_e1->debug(p);
    m_e2->debug(p);
    m_type->debug(p);
    p.undent();
}

void
Or_expr::to_sexpr(Printer& p) const
{
    p.print_string("(OR ");
    m_e1->to_sexpr(p);
    p.print_string(" ");
    m_e2->to_sexpr(p);
    p.print_string(")");
}


// Logical Not Operations

void
Not_expr::print(Printer& p) const
{
    p.get_stream() << "(NOT " << *m_expr << ")";
}

void
Not_expr::debug(Printer& p) const
{
    p.print_address("Not_expr", this);    
    p.indent();
    m_expr->debug(p);
    m_type->debug(p);
    p.undent();
}

void
Not_expr::to_sexpr(Printer& p) const
{
    p.print_string("(NOT ");
    m_expr->to_sexpr(p);
    p.print_string(")");
}


// Conditional Expression Operations

void
Con_expr::print(Printer& p) const
{
    p.get_stream() << "if (" << *m_e1 << ") then " << *m_e2 << " else " << *m_e3;
}

void
Con_expr::debug(Printer& p) const
{
    p.print_address("Con_expr", this);
    p.indent();
    m_e1->debug(p);
    m_e2->debug(p);
    m_e3->debug(p);
    m_type->debug(p);
    p.undent();
}

void
Con_expr::to_sexpr(Printer& p) const
{
    p.print_string("(If ");
    m_e1->to_sexpr(p);
    p.print_string(" (then ");
    m_e2->to_sexpr(p);
    p.print_string(") (else ");
    m_e3->to_sexpr(p);
    p.print_string("))");
}


// Equal Expression Operations

void
Eq_expr::print(Printer& p) const
{
    p.get_stream() << "(" << *m_e1 << " == " << *m_e2 << ")";
}

void
Eq_expr::debug(Printer& p) const
{
    p.print_address("Eq_expr", this);
    p.indent();
    m_e1->debug(p);
    m_e2->debug(p);
    m_type->debug(p);
    p.undent();
}

void
Eq_expr::to_sexpr(Printer& p) const
{
    p.print_string("(== ");
    m_e1->to_sexpr(p);
    p.print_string(" ");
    m_e2->to_sexpr(p);
    p.print_string(")");
}


// Not Equal Expression Operations

void
Ne_expr::print(Printer& p) const
{
    p.get_stream() << "(" << *m_e1 << " != " << *m_e2 << ")";
}

void
Ne_expr::debug(Printer& p) const
{
    p.print_address("Ne_expr", this);
    p.indent();
    m_e1->debug(p);
    m_e2->debug(p);
    m_type->debug(p);
    p.undent();
}

void
Ne_expr::to_sexpr(Printer& p) const
{
    p.print_string("(!= ");
    m_e1->to_sexpr(p);
    p.print_string(" ");
    m_e2->to_sexpr(p);
    p.print_string(")");
}


// Less Than Expression Operations

void
Lt_expr::print(Printer& p) const
{
    p.get_stream() << "(" << *m_e1 << " < " << *m_e2 << ")";
}

void
Lt_expr::debug(Printer& p) const
{
    p.print_address("Lt_expr", this);
    p.indent();
    m_e1->debug(p);
    m_e2->debug(p);
    m_type->debug(p);
    p.undent();
}

void
Lt_expr::to_sexpr(Printer& p) const
{
    p.get_stream() << "(< ";

    m_e1->to_sexpr(p);
    p.print_string(" ");

    m_e2->to_sexpr(p);
    p.print_string(")");
}


// Greater Than Expression Operations

void
Gt_expr::print(Printer& p) const
{
    p.get_stream() << "(" << *m_e1 << " > " << *m_e2 << ")";
}

void
Gt_expr::debug(Printer& p) const
{
    p.print_address("Gt_expr", this);
    p.indent();
    m_e1->debug(p);
    m_e2->debug(p);
    m_type->debug(p);
    p.undent();
}

void
Gt_expr::to_sexpr(Printer& p) const
{
    p.print_string("(> ");
    m_e1->to_sexpr(p);
    p.print_string(" ");
    m_e2->to_sexpr(p);
    p.print_string(")");
}


// Less Than Or Equal Expression Operations

void
Le_expr::print(Printer& p) const
{
    p.get_stream() << "(" << *m_e1 << " <= " << *m_e2 << ")";
}

void
Le_expr::debug(Printer& p) const
{
    p.print_address("Le_expr", this);
    p.indent();
    m_e1->debug(p);
    m_e2->debug(p);
    m_type->debug(p);
    p.undent();
}

void
Le_expr::to_sexpr(Printer& p) const
{
    p.print_string("(<= ");
    m_e1->to_sexpr(p);
    p.print_string(" ");
    m_e2->to_sexpr(p);
    p.print_string(")");
}


// Greater Than Or Equal Expression Operations

void
Ge_expr::print(Printer& p) const
{
    p.get_stream() << "(" << *m_e1 << " >= " << *m_e2 << ")";
}

void
Ge_expr::debug(Printer& p) const
{
    p.print_address("Ge_expr", this);
    p.indent();
    m_e1->debug(p);
    m_e2->debug(p);
    m_type->debug(p);
    p.undent();
}

void
Ge_expr::to_sexpr(Printer& p) const
{
    p.print_string("(>= ");
    m_e1->to_sexpr(p);
    p.print_string(" ");
    m_e2->to_sexpr(p);
    p.print_string(")");
}


// Addition Expression Operations

void
Add_expr::print(Printer& p) const
{
    p.get_stream() << "(" << *m_e1 << " + " << *m_e2 << ")";
}

void
Add_expr::debug(Printer& p) const
{
    p.print_address("Add_expr", this);
    p.indent();
    m_e1->debug(p);
    m_e2->debug(p);
    m_type->debug(p);
    p.undent();
}

void
Add_expr::to_sexpr(Printer& p) const
{
    p.print_string("(+ ");
    m_e1->to_sexpr(p);
    p.print_string(" ");
    m_e2->to_sexpr(p);
    p.print_string(")");
}


// Subtraction Expression Operations

void
Sub_expr::print(Printer& p) const
{
    p.get_stream() << "(" << *m_e1 << " - " << *m_e2 << ")";
}

void
Sub_expr::debug(Printer& p) const
{
    p.print_address("Sub_expr", this);
    p.indent();
    m_e1->debug(p);
    m_e2->debug(p);
    m_type->debug(p);
    p.undent();
}

void
Sub_expr::to_sexpr(Printer& p) const
{
    p.print_string("(- ");
    m_e1->to_sexpr(p);
    p.print_string(" ");
    m_e2->to_sexpr(p);
    p.print_string(")");
}


// Multiplication Expression Operations

void
Mul_expr::print(Printer& p) const
{
    p.get_stream() << "(" << *m_e1 << " * " << *m_e2 << ")";
}

void
Mul_expr::debug(Printer& p) const
{
    p.print_address("Mul_expr", this);
    p.indent();
    m_e1->debug(p);
    m_e2->debug(p);
    m_type->debug(p);
    p.undent();
}

void
Mul_expr::to_sexpr(Printer& p) const
{
    p.print_string("(* ");
    m_e1->to_sexpr(p);
    p.print_string(" ");
    m_e2->to_sexpr(p);
    p.print_string(")");
}


// Quotient Expression Operations

void
Quo_expr::print(Printer& p) const
{
    p.get_stream() << "(" << *m_e1 << " / " << *m_e2 << ")";
}

void
Quo_expr::debug(Printer& p) const
{
    p.print_address("Quo_expr", this);
    p.indent();
    m_e1->debug(p);
    m_e2->debug(p);
    m_type->debug(p);
    p.undent();
}

void
Quo_expr::to_sexpr(Printer& p) const
{
    p.print_string("(/ ");
    m_e1->to_sexpr(p);
    p.print_string(" ");
    m_e2->to_sexpr(p);
    p.print_string(")");
}


// Remainder Expression Operations

void
Rem_expr::print(Printer& p) const
{
    p.get_stream() << "(" << *m_e1 << " % " << *m_e2 << ")";
}

void
Rem_expr::debug(Printer& p) const
{
    p.print_address("Rem_expr", this);
    p.indent();
    m_e1->debug(p);
    m_e2->debug(p);
    m_type->debug(p);
    p.undent();
}

void
Rem_expr::to_sexpr(Printer& p) const
{
    p.print_string("(% ");
    m_e1->to_sexpr(p);
    p.print_string(" ");
    m_e2->to_sexpr(p);
    p.print_string(")");
}


// Negate Expression Operations

void
Neg_expr::print(Printer& p) const
{
    p.get_stream() << "(-" <<  *m_expr << ")";
}

void
Neg_expr::debug(Printer& p) const
{
    p.print_address("Neg_expr", this);
    p.indent();
    m_expr->debug(p);
    m_type->debug(p);
    p.undent();
}

void
Neg_expr::to_sexpr(Printer& p) const
{
    p.print_string("(NEG ");
    m_expr->to_sexpr(p);
    p.print_string(")");
}


// Reciprocal Expression Operations

void
Rec_expr::print(Printer& p) const
{
    p.get_stream() << "(1 / " <<  *m_expr << ")";
}

void
Rec_expr::debug(Printer& p) const
{
    p.print_address("Rec_expr", this);
    p.indent();
    m_expr->debug(p);
    m_type->debug(p);
    p.undent();
}

void
Rec_expr::to_sexpr(Printer& p) const
{
    p.print_string("(REC ");
    m_expr->to_sexpr(p);
    p.print_string(")");
}


// Call Expression Operations

void
Call_expr::print(Printer& p) const
{
    for (int i = 0, len = m_exprs->size(); i < len; i++)
    {
        (*m_exprs)[i]->print(p);
    }
}

void
Call_expr::debug(Printer& p) const
{
    p.print_address("Call_expr", this);
    p.indent();
    for (int i = 0, len = m_exprs->size(); i < len; i++)
    {
        (*m_exprs)[i]->debug(p);
    }
    m_type->debug(p);
    p.undent();
}

void
Call_expr::to_sexpr(Printer& p) const
{
    p.print_string("(Call_expr ");
    for (int i = 0, len = m_exprs->size(); i < len; i++)
    {
        (*m_exprs)[i]->to_sexpr(p);
    }
    p.print_string(")");
}


// Assignment Expression Operations

void
Ass_expr::print(Printer& p) const
{
    p.get_stream() << *m_tar << " = " << *m_src;
}

void
Ass_expr::debug(Printer& p) const
{
    p.print_address("Ass_expr", this);
    p.indent();
    m_src->debug(p);
    m_tar->debug(p);
    m_type->debug(p);
    p.undent();
}

void
Ass_expr::to_sexpr(Printer& p) const
{
    p.print_string("(Ass_expr ");
    m_src->to_sexpr(p);
    m_tar->to_sexpr(p);
    p.print_string(")");
}


// Operators

std::ostream& operator<<(std::ostream& os, Expr const& e)
{
    Printer p(os);
    e.print(p);
    return p.get_stream();
}
