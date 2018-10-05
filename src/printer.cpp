#include <iostream>

#include "printer.hpp"
#include "expr.hpp"

// Nullary operations

template <typename T>
void print_nullary(std::ostream& os, T value) {
    os << value;
}

void debug_nullary(std::ostream& os, char const* str, Expr const* expr) {
    os << str << " " << expr << '\n';
}

template <typename T>
void sexpr_nullary(std::ostream& os, T value) {
    os << '(' << value << ')';
}

// Unary operations

void print_unary(std::ostream& os, Expr const* expr, char const* str) {
    os << str << " " << *expr;
}

void debug_unary(std::ostream& os, char const* str, Expr const* expr, Expr const* child) {
    os << str << " " << expr << '\n';
    debugexpr(os, *child);
}

/*
template <typename T>
void sexpr_unary(std::ostream& os, char const* str, Expr const* expr, Expr const* child) {
    os << '(' << str;
    sexpr(child)')';
}
*/