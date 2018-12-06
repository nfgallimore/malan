#include <vector>

#include "actions.hpp"
#include "token.hpp"
#include "lexer.hpp"

class Expr;
class Symbol_table;

class Parser 
{
public:
    Parser(Symbol_table& syms, std::string const& input);
    /// Constructor for parser.

    Token match(Token::Name n);
    /// Returns the next token.

    Token consume();
    /// Consumes a token advacning the iterator.

    const Token& peek() const { return *m_next; }
    /// Peeks at the next token.

    Token::Name next_name() const { return peek().get_name(); }
    /// Returns the name of the next token.

    bool is_eof() const { return m_next == m_last; }
    /// True if at end of file.

    bool next_token_is(Token::Name n) const { return next_name() == n; }
    /// True if the next is n.

    bool next_token_is_not(Token::Name n) { return next_name() != n; }
    /// True if the next is not n.


    // Parsing

    Expr* parse_expression();
    /// Parses an expression.

    Expr* parse_assignment_expression();
    /// Parse an assignment expression.

    Expr* parse_conditional_expression();
    /// Parse a conditional expression.

    Expr* parse_or_expression();
    /// Parse an or expression.
    
    Expr* parse_and_expression();
    /// Parse an and expression.
    
    Expr* parse_equality_expression();
    /// Parse an equality expression.
    
    Expr* parse_relational_expression();
    /// Parse an relational expression.
    
    Expr* parse_additive_expression();
    /// Parse an additive expression.
    
    Expr* parse_multiplicative_expression();
    /// Parse a multiplicative expression.

    Expr* parse_unary_expression();
    /// Parse a unary expression.

    Expr* parse_postfix_expression();
    /// Parse a postfix expression.

    Expr* parse_primary_expression();
    /// Parse a primary expression.

private:
    Actions m_act;
    /// Semantic actor

    std::vector<Token> m_toks;
    /// Vector of tokens lex'd during construction.

    Token* m_next;
    /// The current token.

    Token* m_last;
    /// The last token.

    Lexer m_lex;
    /// Lexer
};