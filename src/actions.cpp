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
Actions::on_bool_literal(Token const& tok)
{
    if (tok.is(Token::true_kw))
        return m_builder.make_true();
    else
        return m_builder.make_false();
}

Expr*
Actions::on_reciprocal_expr(Expr* e)
{
    return m_builder.make_rec(e);
}

Expr*
Actions::on_negation_expr(Expr* e)
{
    return m_builder.make_neg(e);
}


