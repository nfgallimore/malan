#include <iostream>

#include "expr.hpp"
#include "decl.hpp"
#include "name.hpp"

/// Rules:
/// Print tabs as first statement in debug.
/// Print new line after printing address in debug.

// Integer literal expressions

void
Int_lit::print(Printer& p) const
{
    p.get_stream() << m_value;
}

void
Int_lit::debug(Printer& p) const
{
    p.debug_address(this, "Int_lit");

    p.indent();
    m_type->debug(p);
    p.undent();
}

void
Int_lit::to_sexpr(Printer& p) const
{
    p.get_stream() << '(' << m_value << ')';
}


// Boolean literal expression operations

void
Bool_lit::print(Printer& p) const
{
    p.get_stream() << std::boolalpha << m_value;
}

void
Bool_lit::debug(Printer& p) const
{
    p.debug_address(this, "Bool_lit");

    p.indent();
    m_type->debug(p);
    p.undent();
}

void
Bool_lit::to_sexpr(Printer& p) const
{
    p.get_stream() << '(' << std::boolalpha << m_value << ')';
}


// Float literal expressions

void
Float_lit::print(Printer& p) const
{
    p.get_stream() << m_value;
}

void
Float_lit::debug(Printer& p) const
{
    p.debug_address(this, "Float_lit");

    p.indent();
    m_type->debug(p);
    p.undent();
}

void
Float_lit::to_sexpr(Printer& p) const
{
    p.get_stream() << '(' << m_value << ')';
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
    p.debug_address(this, "Id_expr");

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
    p.get_stream() << "And_expr ";
    p.print_address(this);
    p.new_line();
    
    p.indent();

    p.print_tabs();
    m_e1->debug(p);

    p.print_tabs();
    m_e2->debug(p);
  
    p.undent();
}

void
And_expr::to_sexpr(Printer& p) const
{
    p.get_stream() << "(AND ";

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
    p.get_stream() << "Or_expr ";
    p.print_address(this);
    p.new_line();

    p.indent();

    p.print_tabs();
    m_e1->debug(p);

    p.print_tabs();
    m_e2->debug(p);
 
    p.undent();
}

void
Or_expr::to_sexpr(Printer& p) const
{
    p.get_stream() << "(OR ";

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
    p.get_stream() << "Not_expr ";
    p.print_address(this);
    p.new_line();

    p.indent();

    p.print_tabs();
    m_expr->debug(p);

    p.undent();
}

void
Not_expr::to_sexpr(Printer& p) const
{
    p.get_stream() << "(NOT ";
    m_expr->to_sexpr(p);
    p.get_stream() << ')';
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
    p.get_stream() << "Con_expr ";
    p.print_address(this);
    p.new_line();
    p.indent();

    p.print_tabs();
    m_e1->debug(p);

    p.print_tabs();
    m_e2->debug(p);

    p.print_tabs();
    m_e3->debug(p);
    p.new_line();

    p.undent();
}

void
Con_expr::to_sexpr(Printer& p) const
{
    p.get_stream() << "(If ";
    m_e1->to_sexpr(p);
    p.get_stream() << " (then ";
    m_e2->to_sexpr(p);
    p.get_stream() << ") (else ";
    m_e3->to_sexpr(p);
    p.get_stream() << "))";
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
    p.get_stream() << "Eq_expr ";
    p.print_address(this);
    p.new_line();

    p.indent();

    p.print_tabs();
    m_e1->debug(p);

    p.print_tabs();
    m_e2->debug(p);

    p.undent();
}

void
Eq_expr::to_sexpr(Printer& p) const
{
    p.get_stream() << "(== ";

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
    p.get_stream() << "Ne_expr ";
    p.print_address(this);
    p.new_line();

    p.indent();

    p.print_tabs();
    m_e1->debug(p);

    p.print_tabs();
    m_e2->debug(p);

    p.undent();
}

void
Ne_expr::to_sexpr(Printer& p) const
{
    p.get_stream() << "(!= ";

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
    p.get_stream() << "Lt_expr ";
    p.print_address(this);
    p.new_line();

    p.indent();

    p.print_tabs();
    m_e1->debug(p);

    p.print_tabs();
    m_e2->debug(p);
 
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
    p.get_stream() << "Gt_expr ";
    p.print_address(this);
    p.new_line();

    p.indent();

    p.print_tabs();
    m_e1->debug(p);

    p.print_tabs();
    m_e2->debug(p);

    p.undent();
}

void
Gt_expr::to_sexpr(Printer& p) const
{
    p.get_stream() << "(> ";

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
    p.get_stream() << "Le_expr ";
    p.print_address(this);
    p.new_line();

    p.indent();

    p.print_tabs();
    m_e1->debug(p);

    p.print_tabs();
    m_e2->debug(p);

    p.undent();
}

void
Le_expr::to_sexpr(Printer& p) const
{
    p.get_stream() << "(<= ";

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
    p.get_stream() << "Ge_expr ";
    p.print_address(this);
    p.new_line();

    p.indent();

    p.print_tabs();
    m_e1->debug(p);

    p.print_tabs();
    m_e2->debug(p);

    p.undent();
}

void
Ge_expr::to_sexpr(Printer& p) const
{
    p.get_stream() << "(>= ";

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
    p.print_tabs();
    p.get_stream() << "Add_expr ";
    p.print_address(this);
    p.new_line();

    p.indent();

    p.print_tabs();
    m_e1->debug(p);

    p.print_tabs();
    m_e2->debug(p);

    p.undent();
}

void
Add_expr::to_sexpr(Printer& p) const
{
    p.get_stream() << "(+ ";

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
    p.print_tabs();
    p.get_stream() << "Sub_expr ";
    p.print_address(this);
    p.new_line();

    p.indent();

    p.print_tabs();
    m_e1->debug(p);

    p.print_tabs();
    m_e2->debug(p);

    p.undent();
}

void
Sub_expr::to_sexpr(Printer& p) const
{
    p.get_stream() << "(- ";

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
    p.get_stream() << "Mul_expr ";
    p.print_address(this);
    p.new_line();

    p.indent();

    p.print_tabs();
    m_e1->debug(p);

    p.print_tabs();
    m_e2->debug(p);

    p.undent();
}

void
Mul_expr::to_sexpr(Printer& p) const
{
    p.get_stream() << "(* ";

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
    p.get_stream() << "Quo_expr ";
    p.print_address(this);
    p.new_line();

    p.indent();

    p.print_tabs();
    m_e1->debug(p);

    p.print_tabs();
    m_e2->debug(p);

    p.undent();
}

void
Quo_expr::to_sexpr(Printer& p) const
{
    p.get_stream() << "(/ ";

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
    p.get_stream() << "Rem_expr ";
    p.print_address(this);
    p.new_line();

    p.indent();

    p.print_tabs();
    m_e1->debug(p);

    p.print_tabs();
    m_e2->debug(p);

    p.undent();
}

void
Rem_expr::to_sexpr(Printer& p) const
{
    p.get_stream() << "(% ";

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
    p.get_stream() << "Neg_expr ";
    p.print_address(this);
    p.new_line();

    p.indent();

    p.print_tabs();
    m_expr->debug(p);

    p.undent();
}

void
Neg_expr::to_sexpr(Printer& p) const
{
    p.get_stream() << "(NEG ";
    m_expr->to_sexpr(p);
    p.get_stream() << ')';
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
    p.get_stream() << "Rec_expr ";
    p.print_address(this);
    p.new_line();

    p.indent();

    p.print_tabs();
    m_expr->debug(p);

    p.undent();
}

void
Rec_expr::to_sexpr(Printer& p) const
{
    p.get_stream() << "(REC ";
    m_expr->to_sexpr(p);
    p.get_stream() << ')';
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
    p.get_stream() << "Call_expr ";
    p.print_address(this);
    p.new_line();

    p.indent();
    p.print_tabs();
    for (int i = 0, len = m_exprs->size(); i < len; i++)
    {
        (*m_exprs)[i]->debug(p);
    }
    
    p.undent();
}

void
Call_expr::to_sexpr(Printer& p) const
{
    p.get_stream() << "(Call_expr ";
    for (int i = 0, len = m_exprs->size(); i < len; i++)
    {
        (*m_exprs)[i]->to_sexpr(p);
    }
    p.get_stream() << ')';
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
    p.get_stream() << "Ass_expr ";
    p.print_address(this);
    p.new_line();

    p.indent();
    p.print_tabs();
    m_src->debug(p);
    m_tar->debug(p);
    
    p.undent();
}

void
Ass_expr::to_sexpr(Printer& p) const
{
    p.get_stream() << "(Ass_expr ";
    m_src->to_sexpr(p);
    m_tar->to_sexpr(p);
    p.get_stream() << ')';
}


// Operators

std::ostream& operator<<(std::ostream& os, Expr const& e)
{
    Printer p(os);
    e.print(p);
    return p.get_stream();
}