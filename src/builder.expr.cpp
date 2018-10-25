#include "builder.hpp"

Expr* Builder::make_bool(bool b)
{
	return new Bool_lit(b, get_bool_type());
}

Expr* Builder::make_int(int n)
{
	return new Int_lit(n, get_int_type());
}

Expr* Builder::make_float(float f)
{
	return new Float_lit(f, get_float_type());
}

Expr* Builder::make_id(Decl* d)
{
	return new Id_expr(d, d->get_type());
}

Expr* Builder::make_and(Expr* e1, Expr* e2)
{
	require_bools(e1, e2);
	return new And_expr(e1, e2, get_bool_type());
}

Expr* Builder::make_or(Expr* e1, Expr* e2)
{
	require_bools(e1, e2);
	return new Or_expr(e1, e2, get_bool_type());
}

Expr* Builder::make_not(Expr* e)
{
	require_bool(e);
	return new Not_expr(e, get_bool_type());
}

Expr* Builder::make_con(Expr* e1, Expr* e2, Expr* e3)
{
	require_bool(e1);
	require_same_type(e2, e3);
	return new Con_expr(e1, e2, e3, e2->get_type());
}

Expr* Builder::make_eq(Expr* e1, Expr* e2)
{
	// If different types
	if (!is_type(e1, e2->get_type()))
	{
		if (!is_number(e1) || !is_number(e2))
		{
			Type_err("Expressions cannot be different types unless they are numbers.");
		}
		else if (is_type(e1, get_int_type()))
		{
			return new Eq_expr(convert_to_float(e1), e2, get_bool_type());
		}
		else 
		{
			return new Eq_expr(e1, convert_to_float(e2), get_bool_type());
		}
	}
	return new Eq_expr(e1, e2, get_bool_type());
}

Expr* Builder::make_ne(Expr* e1, Expr* e2)
{
	
}

Expr* Builder::make_lt(Expr* e1, Expr* e2)
{
	
}

Expr* Builder::make_gt(Expr* e1, Expr* e2)
{
	
}

Expr* Builder::make_le(Expr* e1, Expr* e2)
{
	
}

Expr* Builder::make_ge(Expr* e1, Expr* e2)
{
	
}

Expr* Builder::make_add(Expr* e1, Expr* e2)
{
	
}

Expr* Builder::make_sub(Expr* e1, Expr* e2)
{
	
}

Expr* Builder::make_mul(Expr* e1, Expr* e2)
{
	
}

Expr* Builder::make_quo(Expr* e1, Expr* e2)
{
	
}

Expr* Builder::make_rem(Expr* e1, Expr* e2)
{
	
}

Expr* Builder::make_neg(Expr* e1)
{
	
}
