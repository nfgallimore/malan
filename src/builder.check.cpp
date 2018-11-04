#include "builder.hpp"
#include "type.hpp"
#include "error.hpp"

bool 
Builder::is_bool(Expr* e) 
{
    return e->get_type()->get_kind() == Type::bool_type;
}

bool
Builder::is_number(Expr* e)
{
    Type::Kind k = e->get_type()->get_kind();
    return k == Type::int_type ||  k == Type::float_type;
}

bool
Builder::is_type(Expr* e, Type* t)
{
    return e->get_type()->get_kind() != t->get_kind();
}

bool 
Builder::are_same_type(Expr* e1, Expr* e2)
{
    return get_actual_kind(e1) == get_actual_kind(e2);
}

bool
Builder::are_same_type(Decl* d1, Decl* d2)
{
    return get_actual_kind(d1) == get_actual_kind(d2);
}

Type* 
Builder::get_dominant_type(Expr* e1, Expr* e2)
{
    require_numbers(e1, e2);
    if (is_type(e1, get_float_type()) || is_type(e2, get_float_type()))
    {
        return get_float_type();
    }
    else
    {
        return get_int_type();
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

void
Builder::require_bools(Expr* e1, Expr* e2)
{
    if (!is_bool(e1) && !is_bool(e2))
	{
		Error::Type_err("error: expressions must be boolean");
	}
}

void Builder::require_number(Expr* e)
{
    if (!is_number(e))
    {
        Error::Type_err("error: expression must be a number");
    }
}

void Builder::require_numbers(Expr* e1, Expr* e2)
{
    if (!is_number(e1) || !is_number(e2))
    {
        Error::Type_err("error: expressions must be numbers");
    }
}

void Builder::require_type(Expr* e, Type* t)
{
    if (!is_type(e, t))
    {
        Error::Type_err("error: expression is invalid type");
    }
}

void 
Builder::require_same_type(Expr* e1, Expr* e2)
{
    if (!are_same_type(e1, e2))
    {
        Error::Type_err("error: expressions must be same type");
    }
}

void 
Builder::require_same_type(Decl* d1, Decl* d2)
{
    if (!are_same_type(d1, d2))
    {
        Error::Type_err("error: expressions must be same type");
    }
}

Type::Kind 
Builder::get_actual_kind(Expr* expr)
{
    if (expr->get_type()->get_kind() == Type::ref_type)
    {
        Ref_type* ref = static_cast<Ref_type*>(expr->get_type());
        return ref->get_ref_type()->get_kind();
    }
    return expr->get_type()->get_kind();
}

Type::Kind
Builder::get_actual_kind(Decl* decl)
{
    if (decl->get_type()->get_kind() == Type::ref_type)
    {
        Ref_type* ref = static_cast<Ref_type*>(decl->get_type());
        return ref->get_ref_type()->get_kind();
    }
    return decl->get_type()->get_kind();
}

void
Builder::require_not_fun_type(Type* t)
{
    if (t->get_kind() == Type::fun_type)
    {
        Error::Type_err("error: type cannot be function type");
    }
}