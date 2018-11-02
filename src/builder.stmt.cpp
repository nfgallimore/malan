#include "builder.hpp"
#include "stmt.hpp"

Stmt*
Builder::make_block(Stmt_seq* seq)
{
    return new Block_stmt(seq);
}

Stmt*
Builder::make_while(Expr* cond, Stmt* stmt)
{
    return new While_stmt(cond, stmt);
}

Stmt*
Builder::make_expr_stmt(Expr* expr)
{
    return new Expr_stmt(expr);
}
