#include "builder.hpp"
#include "decl.hpp"

Bool_lit* Builder::make_bool(bool b)
{
	return new Bool_lit(Value(b), get_bool_type());
}

Bool_lit* Builder::make_true()
{
  	return make_bool(true);
}

Bool_lit* Builder::make_false()
{
  	return make_bool(false);
}

Int_lit* Builder::make_int(int n)
{
	return new Int_lit(Value(n), get_int_type());
}

Float_lit* Builder::make_float(float f)
{
	return new Float_lit(Value(f), get_float_type());
}

Id_expr* Builder::make_id(Decl* d)
{
	return new Id_expr(d, d->get_type());
}

And_expr* Builder::make_and(Expr* e1, Expr* e2)
{
	require_bools(e1, e2);
	return new And_expr(e1, e2, get_bool_type());
}

Or_expr* Builder::make_or(Expr* e1, Expr* e2)
{
	require_bools(e1, e2);
	return new Or_expr(e1, e2, get_bool_type());
}

Not_expr* Builder::make_not(Expr* e)
{
	require_bool(e);
	return new Not_expr(e, get_bool_type());
}

Con_expr* Builder::make_con(Expr* e1, Expr* e2, Expr* e3)
{
	require_bool(e1);
	require_same_type(e2, e3);
	return new Con_expr(e1, e2, e3, e2->get_type());
}

// Expr* Builder::make_eq(Expr* e1, Expr* e2)
// {
// 	// If different types

// }

// Expr* Builder::make_ne(Expr* e1, Expr* e2)
// {
	
// }

// Expr* Builder::make_lt(Expr* e1, Expr* e2)
// {
	
// }

// Expr* Builder::make_gt(Expr* e1, Expr* e2)
// {
	
// }

// Expr* Builder::make_le(Expr* e1, Expr* e2)
// {
	
// }

// Expr* Builder::make_ge(Expr* e1, Expr* e2)
// {
	
// }

// Expr* Builder::make_add(Expr* e1, Expr* e2)
// {
	
// }

// Expr* Builder::make_sub(Expr* e1, Expr* e2)
// {
	
// }

// Expr* Builder::make_mul(Expr* e1, Expr* e2)
// {
	
// }

// Expr* Builder::make_quo(Expr* e1, Expr* e2)
// {
	
// }

// Expr* Builder::make_rem(Expr* e1, Expr* e2)
// {
	
// }

// Expr* Builder::make_neg(Expr* e1)
// {
	
// }
