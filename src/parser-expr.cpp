#include "parser.hpp"
#include "token.hpp"
#include "actions.hpp"

Expr*
Parser::parse_expression()
{
    return parse_assignment_expression();
}

/// Parse an assignment expression.
///
///   assignment-expression -> conditional-expression '=' assignment-expression
///                          | conditional-expression
Expr*
Parser::parse_assignment_expression()
{
    Expr* cond = parse_conditional_expression();
    if (match(Token::equal))
    {
        Expr* asst = parse_assignment_expression();
        return m_act.on_assignment_expression(cond, asst);
    }
    return cond;
}

/// Parse a conditional expression.
///
///   conditional-expression -> logical-or-expression ? expression : conditional-expression
///                           | logical-or-expression
Expr*
Parser::parse_conditional_expression()
{
    Expr* or_expr = parse_or_expression();
    if (match(Token::question))
    {
        Expr* expr = parse_expression();
        if (match(Token::colon))
        {
            Expr* cond_expr = parse_conditional_expression();
            return m_act.on_conditional_expression(or_expr, expr, cond_expr);
        }
    }
    return or_expr;
}

/// Parse an or expression.
///
///   or-expression -> or-expression 'or' and-expression
///                  | and-expression
Expr*
Parser::parse_or_expression()
{
    Expr* and_expr = parse_and_expression();
    if (match(Token::or_kw))
    {
        Expr* or_expr = parse_or_expression();
        return m_act.on_or_expression(or_expr, and_expr);
    }
    return parse_and_expression();
}

/// Parse an and expression.
///
///   and-expression -> and-expression 'and' equality-expression
///                   | equality-expression
Expr*
Parser::parse_and_expression()
{
    Expr* eq_expr = parse_equality_expression();
    if (match(Token::and_kw))
    {
        Expr* and_expr = parse_and_expression();
        return m_act.on_and_expression(and_expr, eq_expr);
    }
    return eq_expr;
}

/// Parse an equality expression.
///
///   equality-expression -> equality-expression '==' relational-expression
///                        | equality-expression '!=' relational-expression
///                        | relational-expression
Expr* Parser::parse_equality_expression()
{
    Expr* rel_expr = parse_relational_expression();
    if (match(Token::equal_equal))
    {
        Expr* eq_expr = parse_equality_expression();
        return m_act.on_equality_expression(eq_expr, rel_expr);
    }
    if (match(Token::bang_equal))
    {
        Expr* eq_expr = parse_equality_expression();
        return m_act.on_inequality_expression(eq_expr, rel_expr);
    }
    return rel_expr;
}

/// Parse a relational expression.
///
///   relational-expression -> relational-expression '<' additive-expression
///                          | relational-expression '>' additive-expression
///                          | relational-expression '<=' additive-expression
///                          | relational-expression '>=' additive-expression
///                          | additive-expression
Expr* Parser::parse_relational_expression()
{
    Expr* add_expr = parse_additive_expression();
    if (match(Token::less))
    {
        Expr* rel_expr = parse_relational_expression();
        return m_act.on_less_than_expression(rel_expr, add_expr);
    }
    if (match(Token::greater))
    {
        Expr* rel_expr = parse_relational_expression();
        return m_act.on_greater_than_expression(rel_expr, add_expr);
    }
    if (match(Token::less_equal))
    {
        Expr* rel_expr = parse_relational_expression();
        return m_act.on_less_than_or_equal_expression(rel_expr, add_expr);
    }
    if (match(Token::greater_equal))
    {
        Expr* rel_expr = parse_relational_expression();
        return m_act.on_greater_than_or_equal_expression(rel_expr, add_expr);
    }
    return add_expr;
}

/// Parse an additive expression.
///
///   additive-expression -> additive-expression '+' multiplicative-expression
///                        | additive-expression '-' multiplicative-expression
///                        | multiplicative-expression
Expr* 
Parser::parse_additive_expression()
{
    Expr* mul_expr = parse_multiplicative_expression();
    if (match(Token::plus))
    {
        Expr* add_expr = parse_additive_expression();
        return m_act.on_addition_expression(add_expr, mul_expr);
    }
    if (match(Token::minus))
    {
        Expr* add_expr = parse_additive_expression();
        return m_act.on_subtraction_expression(add_expr, mul_expr);
    }
    return mul_expr;
}

/// Parse a multiplicative expression.
///
///   multiplicative-expression -> multiplicative-expression '*' unary-expression
///                              | multiplicative-expression '/' unary-expression
///                              | multiplicative-expression '%' unary-expression
///                              | unary-expression
Expr* 
Parser::parse_multiplicative_expression()
{
    Expr* unary_expr = parse_unary_expression();
    if (match(Token::star))
    {
        Expr* mul_expr = parse_multiplicative_expression();
        return m_act.on_multiplication_expression(mul_expr, unary_expr);
    }
    if (match(Token::slash))
    {
        Expr* mul_expr = parse_multiplicative_expression();
        return m_act.on_division_expression(mul_expr, unary_expr);
    }
    if (match(Token::percent))
    {
        Expr* mul_expr = parse_multiplicative_expression();
        return m_act.on_remainder_expression(mul_expr, unary_expr);
    }
    return unary_expr;
}

/// Parse a unary expression.
///
///   unary-expression -> unary-expression '-' postfix-expression
///                     | unary-expression '/' postfix-expression
///                     | unary-expression '!' postfix-expression
///                     | postfix-expression
Expr*
Parser::parse_unary_expression()
{
    if (match(Token::minus))
    {
        Expr* unary_expr = parse_unary_expression();
        return m_act.on_negation_expression(unary_expr);
    }
    if (match(Token::slash))
    {
        Expr* unary_expr = parse_unary_expression();
        return m_act.on_reciprocal_expression(unary_expr);
    }
    if (match(Token::not_kw))
    {
        Expr* unary_expr = parse_unary_expression();
        return m_act.on_not_expression(unary_expr);
    }
    return parse_postfix_expression();
}

/// Parse a postfix expression.
///
///   postfix-expression -> postfix-expression ( argument-list? )
///                       | primary-expression

Expr*
Parser::parse_postfix_expression()
{
    if (match(Token::lparen)) {
        std::vector<Expr*>* arg_list = parse_argument_list();
        expect(Token::rparen);
        return m_act.on_call_expression(arg_list);
    }
    return parse_primary_expression();
}

///   argument-list -> argument-list ',' argument
///                   | argument
std::vector<Expr*>*
Parser::parse_argument_list()
{
    std::vector<Expr*>* argument_list;
    while (match(Token::comma)) {
        argument_list->push_back(parse_argument());
    }
    argument_list->push_back(parse_argument());
    return argument_list;
}

///   argument -> expression
Expr*
Parser::parse_argument()
{
    return parse_expression();
}

/// Parse a primary expression.
///
///   primary-expression -> literal
///                     | identifier
///                     | ( expression )
Expr*
Parser::parse_primary_expression()
{
    if (Token tok = match(Token::integer_literal))
        return m_act.on_integer_literal(tok);

    if (Token tok = match(Token::identifier))
        return m_act.on_identifier_expression(tok);

    if (match(Token::lparen)) 
    {
        Expr* expr = parse_expression();
        expect(Token::rparen);
        return expr;
    }

    throw std::runtime_error("expected factor");
}
