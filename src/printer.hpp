#include <iostream>

#include "expr.hpp"

class Printer 
{
public:
    // Pretty printing operations
    template <typename T>
    void print_nullary(T value, std::ostream& os, Expr const* expr);

    // Debug printing operations
    static void debug_nullary(std::ostream& os, char const* str, Expr const* expr);

    // Converting to symbolic expression operations
    template <typename T>
    static void sexpr_nullary(T value, std::ostream& os, Expr const* expr);
};