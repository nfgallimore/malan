#include "builder.hpp"
#include "decl.hpp"

Var_decl*
Builder::make_var(Type* t, Name* n, Expr* init)
{
  return new Var_decl(n, t, init);
}

Func_decl*
Builder::make_func(Name* n, Decl_seq* parms, Type* ret, Stmt* body)
{
  return new Func_decl(n, parms, ret, body);
}
