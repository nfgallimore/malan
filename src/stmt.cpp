#include <iostream>

#include "stmt.hpp"

void Block_stmt::print(std::ostream& os) const {
    os << "foo";
}

void Return_stmt::print(std::ostream& os) const {
    os << "bar";
}

std::ostream& operator<<(std::ostream& os, Stmt const& s) {
    s.print(os);
    return os;
}