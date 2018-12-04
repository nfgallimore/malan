#include "parser.hpp"
#include "token.hpp"

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
    Expr* expr = parse_conditional_expression();
    if (match(Token::equal))
        return parse_assignment_expression();
    return expr;        
}

/// Parse a conditional expression.
///
///   conditional-expression -> logical-or-expression ? expression : conditional-expression
///                           | logical-or-expression
Expr*
Parser::parse_conditional_expression()
{
    Expr* orExpr = parse_or_expression();
    if (match(Token::question))
    {
        Expr* expr = parse_expression(); // FIXME

        if (match(Token::colon))
            return parse_conditional_expression();
    }
    return orExpr;
}

/// Parse an or expression.
///
///   or-expression -> and-expression 'or' or-expression
///                  | and-expression
Expr*
Parser::parse_or_expression()
{
    Expr* expr = parse_and_expression();
    if (match(Token::or_kw))
        return parse_or_expression();
    return expr;
}

/// Parse an and expression.
///
///   and-expression -> and-expression 'and' equality-expression
///                   | equality-expression
Expr*
Parser::parse_and_expression()
{
    Expr* expr = parse_and_expression();
    if (match(Token::and_kw))
        return parse_equality_expression();
    
}

/// Parse an equality expression.
///
///   equality-expression -> equality-expression '==' relational-expression
///                        | equality-expression '!=' relational-expression
///                        | relational-expression
Expr* Parser::parse_equality_expression()
{

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
