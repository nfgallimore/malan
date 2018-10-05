#include <iostream>

#include "stmt.hpp"


// Break statement printing operations

void Break_stmt::print(std::ostream& os) const {

}

void Break_stmt::debug(std::ostream& os) const {

}

void Break_stmt::to_sexpr(std::ostream& os) const {

}


// Continue statement printing operations

void Cont_stmt::print(std::ostream& os) const {

}

void Cont_stmt::debug(std::ostream& os) const {

}

void Cont_stmt::to_sexpr(std::ostream& os) const {

}


// Block statement printing operations

void Block_stmt::print(std::ostream& os) const {

}

void Block_stmt::debug(std::ostream& os) const {

}

void Block_stmt::to_sexpr(std::ostream& os) const {

}


// While statement printing operations

void While_stmt::print(std::ostream& os) const {

}

void While_stmt::debug(std::ostream& os) const {

}

void While_stmt::to_sexpr(std::ostream& os) const {

}


// If statement printing operations

void If_stmt::print(std::ostream& os) const {

}

void If_stmt::debug(std::ostream& os) const {

}

void If_stmt::to_sexpr(std::ostream& os) const {

}


// Return statement printing operations

void Ret_stmt::print(std::ostream& os) const {

}

void Ret_stmt::debug(std::ostream& os) const {

}

void Ret_stmt::to_sexpr(std::ostream& os) const {

}


// Expression statement printing operations

void Expr_stmt::print(std::ostream& os) const {

}

void Expr_stmt::debug(std::ostream& os) const {

}

void Expr_stmt::to_sexpr(std::ostream& os) const {

}


// Declaration statement printing operations

void Decl_stmt::print(std::ostream& os) const {

}

void Decl_stmt::debug(std::ostream& os) const {

}

void Decl_stmt::to_sexpr(std::ostream& os) const {

}


// Operators

std::ostream& operator<<(std::ostream& os, Stmt const& s) {
    s.print(os);
    return os;
}
