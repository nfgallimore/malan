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
