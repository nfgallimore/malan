#include <iostream>

#include "stmt.hpp"


// Break statement printing operations

void Break_stmt::print(Printer& p) const {
    p.print_string("break;");
}

void Break_stmt::debug(Printer& p) const {
    p.print_address(this);
}

void Break_stmt::to_sexpr(Printer& p) const {
    p.print_string("(break)");
}


// Continue statement printing operations

void Cont_stmt::print(Printer& p) const {
    p.print_string("continue;");
}

void Cont_stmt::debug(Printer& p) const {
    p.print_address(this);
}

void Cont_stmt::to_sexpr(Printer& p) const {
    p.print_string("(continue)");
}


// Block statement printing operations

void Block_stmt::print(Printer& p) const {
    for(int i = 0, len = m_stmts->size(); i < len; i++) {
        (*m_stmts)[i]->print(p);
        // TODO stream is printing address
        // p.get_stream() << stmt;
    }
}

void Block_stmt::debug(Printer& p) const {
    p.print_string("Block_stmt ");
    p.print_address(this);
    for(int i = 0, len = m_stmts->size(); i < len; i++) {
        (*m_stmts)[i]->debug(p);
    }
}

void Block_stmt::to_sexpr(Printer& p) const {
    p.print_string("(Block_stmt)");
    p.print_address(this);
    for(int i = 0, len = m_stmts->size(); i < len; i++) {
        (*m_stmts)[i]->to_sexpr(p);
    }
}


// While statement printing operations

void While_stmt::print(Printer& p) const {
    p.get_stream() << "while (" << *get_cond() << ")" << *get_body();
}

void While_stmt::debug(Printer& p) const {

}

void While_stmt::to_sexpr(Printer& p) const {

}


// If statement printing operations

void If_stmt::print(Printer& p) const {

}

void If_stmt::debug(Printer& p) const {

}

void If_stmt::to_sexpr(Printer& p) const {

}


// Return statement printing operations

void Ret_stmt::print(Printer& p) const {
    p.get_stream() << "return " << *m_expr << ";";
}

void Ret_stmt::debug(Printer& p) const {
    p.get_stream() << "return ";
    p.print_address(this);
}

void Ret_stmt::to_sexpr(Printer& p) const {

}


// Expression statement printing operations

void Expr_stmt::print(Printer& p) const {

}

void Expr_stmt::debug(Printer& p) const {

}

void Expr_stmt::to_sexpr(Printer& p) const {

}


// Declaration statement printing operations

void Decl_stmt::print(Printer& p) const {

}

void Decl_stmt::debug(Printer& p) const {

}

void Decl_stmt::to_sexpr(Printer& p) const {

}


// Operators

std::ostream& operator<<(std::ostream& os, Stmt const& s) {
    Printer p(os);
    s.print(p);
    return p.get_stream();
}
