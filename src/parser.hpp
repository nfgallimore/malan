#include <vector>

#include "actions.hpp"
#include "token.hpp"
#include "lexer.hpp"

class Expr;
class Symbol_table;
class Type;
class Stmt;
class Decl;

class Parser 
{
public:
    Parser(Symbol_table& syms, std::string const& input);
    /// Constructor for parser.

    Token expect(Token::Name n);
    /// Expect a token.

     Token require(Token::Name n);
    /// Assert next_name is n, consume.

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

    void parse_program();
    /// Parses a program.

    // Expression Parsing

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

    std::vector<Expr*>* parse_argument_list();
    /// Parse a function argument list.

    Expr* parse_argument();
    /// Parse an argument.

    Expr* parse_primary_expression();
    /// Parse a primary expression.

    // Statement parsing

    Stmt* parse_statement();
    /// Parse a statement.

    Stmt* parse_empty_statement();
    /// Parse an empty statement.

    Stmt* parse_block_statement();
    /// Parse a block statement.

    Stmt* parse_if_statement();
    /// Parse an if statement.

    Stmt* parse_while_statement();
    /// Parse a while statement.

    Stmt* parse_break_statement();
    /// Parse a break statement.

    Stmt* parse_continue_statement();
    /// Parse a continue statement.

    Stmt* parse_return_statement();
    /// Parse a return statement.

    Stmt* parse_declaration_statement();
    /// Parse a declaration statement.

    Stmt* parse_expression_statement();
    /// Parse an expression statement.

    // Types

    Type* parse_type();

    // Declarations

    Decl_seq* parse_declaration_seq();
    /// Parse a declaration sequence.

    Decl* parse_declaration();
    /// Parse a declaration.

    Decl* parse_local_declaration();
    /// Parse a local declaration.

    Decl* parse_function_definition();
    /// Parse a function declaration.

    Decl* parse_object_definition();
    /// Parse an object definition.

    std::vector<Decl*> parse_parameter_declarations();
    /// Parse parameter declarations.

private:
    Actions m_act;
    /// Semantic actor.

    std::vector<Token> m_toks;
    /// Vector of tokens lex'd during parser construction.

    Token* m_next;
    /// The current token.

    Token* m_last;
    /// The last token.

    Lexer m_lex;
    /// Lexer.

    Decl_seq* m_prog;
    /// The program parsed.
};