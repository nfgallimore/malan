#include "builder.hpp"
#include "type.hpp"
#include "error.hpp"

bool 
Builder::is_bool(Expr* e) 
{
    return e->get_type()->get_kind() == Type::bool_type;
}

void 
Builder::require_bools(Expr* e1, Expr* e2)
{
    if (!is_bool(e1) && !is_bool(e2))
	{
		Error::Type_err("error: expressions must be boolean");
	}
}

void
Builder::require_bool(Expr* e)
{
    if (!is_bool(e))
	{
		Error::Type_err("error: expression must be a boolean");
	}  
}

bool 
Builder::are_same_type(Expr* e1, Expr* e2)
{
    return get_actual_kind(e1) == get_actual_kind(e2);
}

void 
Builder::require_same_type(Expr* e1, Expr* e2)
{
    if (!are_same_type(e1, e2))
    {
        Error::Type_err("error: expressions must be same type");
    }
}

bool
Builder::are_same_type(Decl* d1, Decl* d2)
{
    return get_actual_kind(d1) == get_actual_kind(d2);
}