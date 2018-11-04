#include "builder.hpp"
#include "decl.hpp"
#include "error.hpp"

Var_decl*
Builder::make_var(Type* t, Name* n, Expr* init)
{
    require_not_fun_type(t);
    Var_decl* var = new Var_decl(n, t);
    var->set_initializer(init);
    return var;
}

Var_decl*
Builder::make_var(Type* t, Name* n)
{
    require_not_fun_type(t);
    return new Var_decl(n, t);
}

Func_decl*
Builder::make_func(Name* n, Decl_seq* parms, Type* ret, Stmt* body)
{
    require_not_fun_type(ret);

    std::vector<Type*> parm_types;
    for (Decl* d : *parms)
    {
        require_not_fun_type(d->get_type());
        parm_types.push_back(d->get_type());
    }

    Fun_type* type = new Fun_type(parm_types, ret);
    return new Func_decl(n, parms, ret, body);
}
