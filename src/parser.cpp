#include <string>

#include "parser.hpp"

Parser::Parser(Symbol_table& syms, std::string const& input) 
    : m_lex(syms, input)
{
    while (Token t = m_lex.get_next_token())
    {
        m_toks.push_back(t);
    }
    m_curr = m_toks.data();
    m_last = m_toks.data() + m_toks.size();
}