#include "builder.hpp"
#include "decl.hpp"

Var_decl*
Builder::make_var(Type* t, Name* n, Expr* init)
{
    Var_decl* var = new Var_decl(n, t);
    var->set_initializer(init);
    return var;
}

Var_decl*
Builder::make_var(Type* t, Name* n)
{
  return new Var_decl(n, t);
}

Func_decl*
Builder::make_func(Name* n, Decl_seq* parms, Type* ret, Stmt* body)
{
  return new Func_decl(n, parms, ret, body);
}
