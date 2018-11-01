#include "builder.hpp"

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
		throw std::logic_error("Both expressions must be boolean.");
	}
}

void
Builder::require_bool(Expr* e)
{
    if (!is_bool(e))
	{
		throw std::logic_error("Expression must be a boolean.");
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
        throw std::logic_error("Expression must be a boolean.");
    }
}

bool
Builder::are_same_type(Decl* d1, Decl* d2)
{
    return d1->get_type()->get_kind() == d2->get_type()->get_kind();
}