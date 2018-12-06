#include "actions.hpp"
#include "expr.hpp"
#include "stmt.hpp"
#include "type.hpp"

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
        return m_builder.make_true();
    else
        return m_builder.make_false();
}

Expr* 
Actions::on_assignment_expression(Expr* lhs, Expr* rhs)
{
    return m_builder.make_ass(lhs, rhs);
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
Actions::on_reciprocal_expression(Expr* e)
{
    return m_builder.make_rec(e);
}

Expr*
Actions::on_negation_expression(Expr* e)
{
    return m_builder.make_neg(e);
}

Expr*
Actions::on_conditional_expression(Expr* con, Expr* first, Expr* second)
{
    return m_builder.make_con(con, first, second);
}
