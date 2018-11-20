#include "builder.hpp"
#include "decl.hpp"
#include "error.hpp"

Expr* Builder::make_bool(bool b)
{
    return new Bool_lit(Value(b), get_bool_type());
}

Expr* Builder::make_true()
{
      return make_bool(true);
}

Expr* Builder::make_false()
{
      return make_bool(false);
}

Expr* Builder::make_int(int n)
{
    return new Int_lit(Value(n), get_int_type());
}

Expr* Builder::make_float(float f)
{
    return new Float_lit(Value(f), get_float_type());
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
      require_same_type(e1, e2);
      return new Eq_expr(e1, e2, get_bool_type());
}

Expr* Builder::make_ne(Expr* e1, Expr* e2)
{
    require_same_type(e1, e2);
      return new Ne_expr(e1, e2, get_bool_type());
}

Expr* Builder::make_lt(Expr* e1, Expr* e2)
{
    require_same_type(e1, e2);
      return new Lt_expr(e1, e2, get_bool_type());
}

Expr* Builder::make_gt(Expr* e1, Expr* e2)
{
    require_same_type(e1, e2);
      return new Gt_expr(e1, e2, get_bool_type());
}

Expr* Builder::make_le(Expr* e1, Expr* e2)
{
    require_same_type(e1, e2);
      return new Le_expr(e1, e2, get_bool_type());
}

Expr* Builder::make_ge(Expr* e1, Expr* e2)
{
    require_same_type(e1, e2);
      return new Ge_expr(e1, e2, get_bool_type());
}

Expr* Builder::make_add(Expr* e1, Expr* e2)
{
    require_numbers(e1, e2);
      return new Add_expr(e1, e2, get_dominant_type(e1, e2));	
}

Expr* Builder::make_sub(Expr* e1, Expr* e2)
{
    require_numbers(e1, e2);
      return new Sub_expr(e1, e2, get_dominant_type(e1, e2));		
}

Expr* Builder::make_mul(Expr* e1, Expr* e2)
{
    require_numbers(e1, e2);
      return new Mul_expr(e1, e2, get_dominant_type(e1, e2));		
}

Expr* Builder::make_quo(Expr* e1, Expr* e2)
{
    require_numbers(e1, e2);
      return new Quo_expr(e1, e2, get_dominant_type(e1, e2));		
}

Expr* Builder::make_rem(Expr* e1, Expr* e2)
{
    require_numbers(e1, e2);
      return new Rem_expr(e1, e2, get_dominant_type(e1, e2));		
}

Expr* Builder::make_neg(Expr* e)
{
    require_number(e);
    return new Neg_expr(e, e->get_type());
}

Expr* Builder::make_rec(Expr* e)
{
    require_number(e);
    return new Rec_expr(e, e->get_type());
}

Expr* Builder::make_ass(Expr* e1, Expr* e2)
{
    require_type(e2, e1->get_type());
    return new Ass_expr(e1, e2, e1->get_type());
}

Expr* Builder::make_call(std::vector<Expr*>* exprs)
{
    std::vector<Type*> types;
    std::vector<Expr*> es = *exprs;
    
    for(Expr* e : *exprs)
    {
        types.push_back(e->get_type());
    }
    require_type(es[0], get_function_type(types));
    return new Call_expr(exprs, es[0]->get_type());
}
