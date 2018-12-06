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
    Expr* or_expr = parse_or_expression();
    Expr* and_expr = parse_and_expression();
    if (match(Token::or_kw))
    {
        return m_act.on_or_expression(or_expr, and_expr);
    }
    return and_expr;
}

/// Parse an and expression.
///
///   and-expression -> and-expression 'and' equality-expression
///                   | equality-expression
Expr*
Parser::parse_and_expression()
{
    Expr* and_expr = parse_and_expression();
    Expr* eq_expr = parse_equality_expression();
    if (match(Token::and_kw))
    {
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
    Expr* eq_expr = parse_equality_expression();
    Expr* rel_expr = parse_relational_expression();
    if (match(Token::equal_equal))
    {
        return m_act.on_equality_expression(eq_expr, rel_expr);
    }
    if (match(Token::bang_equal))
    {
        return m_act.on_inequality_expression(eq_expr, rel_expr);
    }
    
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
    Expr* rel_epr = parse_relational_expression();


}

/// Parse an additive expression.
///
///   additive-expression -> additive-expression '+' multiplicative-expression
///                        | additive-expression '-' multiplicative-expression
///                        | multiplicative-expression
Expr* 
Parser::parse_additive_expression()
{

}

/// Parse a multiplicative expression.
///
///   multiplicative-expression -> multiplicative-expression '*' unary-expression
///                              | multiplicative-expression '/' unary-expression
///                              | unary-expression
Expr* 
Parser::parse_multiplicative_expression()
{

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

}

/// Parse a postfix expression.
///
///   postfix-expression -> postfix-expression ( argument-list? )
///                       | primary-expression
///        argument-list -> argument-list ',' argument
///                       | argument
///             argument -> expression
Expr*
Parser::parse_postfix_expression()
{

}

/// Parse a primary expression.
///
///   primary-expression -> literal
///                     | identifier
///                     | ( expression )
Expr*
Parser::parse_primary_expression()
{

}
