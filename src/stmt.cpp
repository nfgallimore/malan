#include <iostream>

#include "stmt.hpp"
#include "decl.hpp"

// Break statement printing operations

void 
Break_stmt::print(Printer& p) const
{
    p.print_string("break;");
}

void 
Break_stmt::debug(Printer& p) const
{
    p.print_address("Break_stmt", this);
}

void 
Break_stmt::to_sexpr(Printer& p) const
{
    p.print_string("(break)");
}


// Continue statement printing operations

void 
Cont_stmt::print(Printer& p) const
{
    p.print_string("continue;");
}

void 
Cont_stmt::debug(Printer& p) const
{
    p.print_address("Cont_stmt", this);
}

void 
Cont_stmt::to_sexpr(Printer& p) const
{
    p.print_string("(continue)");
}


// Skip statement printing operations

void 
Skip_stmt::print(Printer& p) const
{
    p.print_string(";");
}

void 
Skip_stmt::debug(Printer& p) const
{
    p.print_address("Skip_stmt", this);
}

void 
Skip_stmt::to_sexpr(Printer& p) const
{
    p.print_string("(skip)");
}
 

// Block statement printing operations

void 
Block_stmt::print(Printer& p) const
{
    for(int i = 0, len = m_stmts->size(); i < len; i++)
    {
        p.print_string("\n{\n");
        p.indent();
        p.print_tabs();
        (*m_stmts)[i]->print(p);
        p.undent();
        p.print_string("\n}");
    }
}

void 
Block_stmt::debug(Printer& p) const
{
    p.print_address("Block_stmt", this);
    p.indent();
    for (int i = 0, len = m_stmts->size(); i < len; i++)
    {
        (*m_stmts)[i]->debug(p);
    }
    p.undent();
}

void 
Block_stmt::to_sexpr(Printer& p) const
{
    p.print_string("(Block_stmt ");
    for(int i = 0, len = m_stmts->size(); i < len; i++)
    {
        (*m_stmts)[i]->to_sexpr(p);
    }
    p.print_string(")");
}


// While statement printing operations

void 
While_stmt::print(Printer& p) const
{
    p.get_stream() << "while (" << *get_cond() << ")" << *get_body();
}

void 
While_stmt::debug(Printer& p) const
{
    p.print_address("While_stmt", this);
    p.indent();
    m_cond->debug(p);
    m_body->debug(p);
    p.undent();
}

void 
While_stmt::to_sexpr(Printer& p) const
{
    p.get_stream() << "(While_stmt ";
    m_cond->to_sexpr(p);
    m_body->to_sexpr(p);
    p.print_string(")");
}


// If statement printing operations

void 
If_stmt::print(Printer& p) const
{
    p.get_stream() << "if " << *m_cond << " then";
    p.new_line();

    p.print_tabs();
    p.print_string("{");
    p.new_line();

    p.indent();
    p.print_tabs();
    p.get_stream() << *m_then;
    p.new_line();
    
    p.undent();
    p.print_tabs();
    p.get_stream() << "}";
    p.new_line();

    p.print_tabs();
    p.get_stream() << "else";
    p.new_line();
    
    p.print_tabs();
    p.print_string("{");
    p.new_line();

    p.indent();
    p.print_tabs();
    p.get_stream() << *m_else;
    p.new_line();

    p.undent();
    p.print_tabs();
    p.print_string("}");
    p.undent();
}

void 
If_stmt::debug(Printer& p) const
{
    p.print_address("If_stmt", this);
    p.indent();
    m_cond->debug(p);
    m_then->debug(p);
    m_else->debug(p);
    p.undent();
}

void 
If_stmt::to_sexpr(Printer& p) const
{
    p.get_stream() << "(If_stmt ";
    m_cond->to_sexpr(p);
    p.get_stream() << " (then ";
    m_then->to_sexpr(p);
    p.get_stream() << ") (else ";
    m_else->to_sexpr(p);
    p.get_stream() << "))";
}


// Return statement printing operations

void 
Ret_stmt::print(Printer& p) const
{
    p.get_stream() << "return " << *m_expr << ";";
}

void 
Ret_stmt::debug(Printer& p) const
{
    p.print_address("Ret_stmt", this);
    p.indent();
    m_expr->debug(p);
    p.undent();
}

void 
Ret_stmt::to_sexpr(Printer& p) const
{
    p.print_string("(Return_stmt ");
    m_expr->to_sexpr(p);
    p.print_string(")");
}


// Expression statement printing operations

void 
Expr_stmt::print(Printer& p) const
{
    p.get_stream() << *m_expr << ";";
}

void 
Expr_stmt::debug(Printer& p) const
{
    p.print_address("Expr_stmt", this);
    p.indent();
    m_expr->debug(p);
    p.undent();
}

void 
Expr_stmt::to_sexpr(Printer& p) const
{
    p.print_string("(Expr_stmt ");
    m_expr->to_sexpr(p);
    p.print_string(")");
}


// Declaration statement printing operations

void 
Decl_stmt::print(Printer& p) const
{
    p.get_stream() << m_decl << ";";
}

void 
Decl_stmt::debug(Printer& p) const
{
    p.print_address("Decl_stmt", this);
    p.indent();
    m_decl->debug(p);
    p.undent();
}

void 
Decl_stmt::to_sexpr(Printer& p) const
{
    p.print_string("(Decl_stmt ");
    m_decl->to_sexpr(p);
    p.print_string(")");
}


// Operators

std::ostream& 
operator<<(std::ostream& os, Stmt const& s)
{
    Printer p(os);
    s.print(p);
    return p.get_stream();
}
