#include <iostream>

#include "decl.hpp"
#include "type.hpp"
#include "name.hpp"
#include "expr.hpp"
#include "stmt.hpp"


// Variable declaration printing operations

void Var_decl::print(std::ostream& os) const {

}

void Var_decl::debug(std::ostream& os) const {

}

void Var_decl::to_sexpr(std::ostream& os) const {

}


// Function declaration printing operations

void Func_decl::print(std::ostream& os) const {

}

void Func_decl::debug(std::ostream& os) const {

}

void Func_decl::to_sexpr(std::ostream& os) const {

}


// Reference declaration printing operations

void Ref_decl::print(std::ostream& os) const {

}

void Ref_decl::debug(std::ostream& os) const {

}

void Ref_decl::to_sexpr(std::ostream& os) const {

}

std::ostream& operator<<(std::ostream& os, Decl const& d) {
    d.print(os);
    return os;
}
