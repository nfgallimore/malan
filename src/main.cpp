#include <iostream>

#include "type.hpp"
#include "expr.hpp"
#include "decl.hpp"
#include "name.hpp"
#include "stmt.hpp"
#include "printer.hpp"
#include "builder.hpp"

void make_min();
void factorial();

int main(int argc, char** argv)
{
    factorial();
}

void factorial()
{
    Builder b;
    Printer p(std::cout);
    /*
        int n = 9;
        int result = 10;

        while (n > 1)
        {
            result = result * n;
            n = n - 1;
        }

    */
    Decl* n_decl = b.make_var(b.get_int_type(), b.make_name("n"), b.make_int(9));
    Decl* result_decl = b.make_var(b.get_int_type(), b.make_name("result"), b.make_int(10));

    Expr* n = b.make_id(n_decl);
    Expr* result = b.make_id(result_decl);

    Stmt* while_stmt = b.make_while(b.make_gt(n, b.make_int(1)),
        b.make_block(new Stmt_seq {
            b.make_expr_stmt(b.make_ass(result, b.make_mul(result, n))),
            b.make_expr_stmt(
                b.make_ass(n,
                b.make_sub(n, b.make_int(1)))
            )
        })
    );
    n_decl->print(p);
    p.new_line();
    result_decl->print(p);
    p.new_line(2);
    while_stmt->print(p);
    p.new_line(2);
}
