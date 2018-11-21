#include "builder.hpp"
#include "stmt.hpp"


Stmt* 
Builder::make_break()
{
    return new Break_stmt();
}

Stmt* 
Builder::make_cont()
{
    return new Cont_stmt();
}

Stmt*
Builder::make_block(Stmt_seq* seq)
{
    return new Block_stmt(seq);
}

Stmt* 
Builder::make_if(Expr* cond, Stmt* then_stmt, Stmt* else_stmt)
{
    require_bool(cond);
    return new If_stmt(cond, then_stmt, else_stmt);
}

Stmt* 
Builder::make_ret(Expr* ret)
{
    return new Ret_stmt(ret);
}

Stmt*
Builder::make_while(Expr* cond, Stmt* stmt)
{
    require_bool(cond);
    return new While_stmt(cond, stmt);
}

Stmt*
Builder::make_expr_stmt(Expr* expr)
{
    return new Expr_stmt(expr);
}

Stmt* 
Builder::make_decl_stmt(Decl* decl)
{
    return new Decl_stmt(decl);
}

Stmt*
Builder::make_skip_stmt()
{
    return new Skip_stmt();
}
