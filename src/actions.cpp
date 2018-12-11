#include "actions.hpp"
#include "expr.hpp"
#include "stmt.hpp"
#include "type.hpp"

Expr* 
Actions::on_assignment_expression(Expr* lhs, Expr* rhs)
{
    return m_builder.make_ass(lhs, rhs);
}

Expr*
Actions::on_conditional_expression(Expr* con, Expr* first, Expr* second)
{
    return m_builder.make_con(con, first, second);
}

Expr* 
Actions::on_or_expression(Expr* lhs, Expr* rhs)
{
    return m_builder.make_or(lhs, rhs);
}

Expr*
Actions::on_and_expression(Expr* lhs, Expr* rhs)
{
    return m_builder.make_and(lhs, rhs);
}

Expr*
Actions::on_equality_expression(Expr* lhs, Expr* rhs)
{
    return m_builder.make_eq(lhs, rhs);
}

Expr*
Actions::on_inequality_expression(Expr* lhs, Expr* rhs)
{
    return m_builder.make_ne(lhs, rhs);
}

Expr*
Actions::on_less_than_expression(Expr* lhs, Expr* rhs)
{
    return m_builder.make_lt(lhs, rhs);
}

Expr*    
Actions::on_greater_than_expression(Expr* lhs, Expr* rhs)
{
    return m_builder.make_gt(lhs, rhs);
}

Expr*
Actions::on_less_than_or_equal_expression(Expr* lhs, Expr* rhs)
{
    return m_builder.make_le(lhs, rhs);
}

Expr*    
Actions::on_greater_than_or_equal_expression(Expr* lhs, Expr* rhs)
{
    return m_builder.make_ge(lhs, rhs);
}

Expr*    
Actions::on_addition_expression(Expr* lhs, Expr* rhs)
{
    return m_builder.make_add(lhs, rhs);
}

Expr*   
Actions::on_subtraction_expression(Expr* lhs, Expr* rhs)
{
    return m_builder.make_sub(lhs, rhs);
}

Expr*
Actions::on_multiplication_expression(Expr* lhs, Expr* rhs)
{
    return m_builder.make_mul(lhs, rhs);
}

Expr*    
Actions::on_division_expression(Expr* lhs, Expr* rhs)
{
    return m_builder.make_quo(lhs, rhs);
}

Expr*    
Actions::on_remainder_expression(Expr* lhs, Expr* rhs)
{
    return m_builder.make_rem(lhs, rhs);
}

Expr*    
Actions::on_identifier_expression(Token const& tok)
{
    Name name(tok.get_lexeme().str());
    Decl* decl = m_stack.lookup(name);
    if (!decl)
    {
        throw std::runtime_error("no matching declaration");
    }
    return m_builder.make_id(decl);
}

Expr*
Actions::on_negation_expression(Expr* e)
{
    return m_builder.make_neg(e);
}

Expr*
Actions::on_reciprocal_expression(Expr* e)
{
    return m_builder.make_rec(e);
}

Expr*
Actions::on_not_expression(Expr* e)
{
    return m_builder.make_not(e);
}

Expr*
Actions::on_call_expression(std::vector<Expr*>* exprs)
{
    return m_builder.make_call(exprs);
}

Expr*
Actions::on_integer_literal(Token const& tok)
{
    int n = std::stoi(tok.get_lexeme().str());
    return m_builder.make_int(n);
}

Expr*
Actions::on_float_literal(Token const& tok)
{
    float f = std::stof(tok.get_lexeme().str());
    return m_builder.make_float(f);
}

Expr*
Actions::on_bool_literal(Token const& tok)
{
    if (tok.is(Token::true_kw))
    {
        return m_builder.make_true();
    }
    else
    {
        return m_builder.make_false();
    }
}


Decl*
Actions::on_object_declaration(Token id, Type* type)
{
    Scope* scope = get_current_scope();

    // Check for redefinition errors.
    if (scope->lookup(id))
        throw std::runtime_error("redefinition error"); 

    // Partially create the declaration.
    Name* name = m_builder.make_name(id.get_lexeme());
    Decl *var = m_builder.make_variable(name, type);

    // Emit the declaration.
    scope->declare(var);

    return var;
}

void
Actions::finish_object_declaration(Decl* d, Expr* init)
{
    Var_decl* var = static_cast<Var_decl*>(d);

    // Perform copy initialization.
    m_builder.copy_initialize(d, init);
}

Decl*
Actions::on_function_declaration(Token id, std::vector<Decl*> const& parms, Type* type)
{
    Scope* scope = get_current_scope();

    // Check for redefinition errors.
    if (scope->lookup(id))
        throw std::runtime_error("redefinition error"); 

    // Build the function type. For example, if I declare:
    //
    //        fun f(a : int, b : int) -> bool { ... }
    //
    // The function type becomes:
    //
    //        (int, int) -> bool
    Type* ft = m_builder.get_function_type(parms, type);

    // Build the function
    // FIXME: Implement me.
    Fn_decl* fn = nullptr;

    // Emit the declaration.
    scope->declare(var);

    return fn;
}

Decl*
Actions::start_function_declaration(Decl* d)
{
    m_fn = static_cast<Fn_decl*>(d);
}

Decl*
Actions::finish_function_declaration(Decl* d, Stmt* s)
{
    Fn_decl* fn = static_cast<Fn_decl*>(d);

    // Set the body of the function.
    fn->set_body(s);

    m_fn = nullptr;
}


