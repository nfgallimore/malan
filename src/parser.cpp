#include <string>
#include <cassert>

#include "parser.hpp"

Parser::Parser(Symbol_table& syms, std::string const& input) 
    : m_lex(syms, input)
{
    while (Token t = m_lex.get_next_token())
    {
        m_toks.push_back(t);
    }
    m_next = m_toks.data();
    m_last = m_toks.data() + m_toks.size();
}

Token 
Parser::consume()
{
    assert(!is_eof());
    Token curr = *m_next;
    ++m_next;
    return curr;
}

Token 
Parser::expect(Token::Name n)
{
    if (next_token_is(n))
        return consume();

    throw std::runtime_error("syntax error");
    return Token();
}

Token 
Parser::require(Token::Name n)
{
    assert(next_token_is(n));
    return consume();
}

Token 
Parser::match(Token::Name n)
{
    if (next_token_is(n))
        return consume();
    return Token();
}
