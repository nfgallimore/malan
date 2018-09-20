#include "expr.hpp"

#include <iostream>

int main(int argc, char** argv)
{
    Expr* expr1 = new Expr("1");
    Expr* expr2 = new Expr("2");

    Binary_expression* addition_expr = new Binary_expression(expr1, expr2, "+");
    std::cout << addition_expr->get_string();

    Binary_expression* and_expr = new Binary_expression(expr2, expr2, "and");
    std::cout << and_expr->get_string();
}
