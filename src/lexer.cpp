#include "lexer.hpp"

Lexer::Lexer(Symbol_table& syms,
char const* first,
char const* limit)
    : m_syms(&syms)
{

}

Token
Lexer::get_next_token()
{
	start:
	switch(peek()) {
		case ' ':
			consume();
			goto start;
		case '\t':
			consume();
			goto start;
		case '\n':
            consume();
            m_line++;

		case '{':
			return match(Token::lbrace, 1);

		case '<':
			if (peek(1) == '=')
				return match(Token::less_equal, 2);
			return match(Token::less, 1);
		case '>':
			if (peek(1) == '=')
				return match(Token::greater_equal, 2);
			return match(Token::greater, 1);
		case '!':
			if (peek(1) == '=')
				return match(Token::bang_equal, 1);

			// Consume the invalid input and then restart
			// processing.
			consume();
			std::cerr << "error: " << m_line << "expected '=' after '!' at line\n";

		default:
			if (is_nondigit(*m_first))
				return match_word();
			if (is_digit(*m_first))
				return match_number();

			// Consume the invalid input and then restart
			// processing.

			consume();
			std::cerr << "error: " << m_line << "Invalid character.\n";
			goto start;
	}
}

Token
Lexer::match(Token::Name n, int len)
{
	std::string str(m_first, m_first + len);
	Symbol sym = m_syms->get(str);
	Token tok = Token(n, sym);
	// FIXME: Add source info./
	
	// Update the lexer.
	m_first += len;

	return tok;
}

static bool
is_digit(char c)
{
    return std::isdigit(c);
}

static bool
is_nondigit(char c)
{
	return !std::isdigit(c);
}

static bool
is_nondigit_or_digit(char c)
{
    return is_nondigit(c) || is_digit(c);
}

static bool
is_hexdigit(char c)
{
    return std::isxdigit(c);
}

Token
Lexer::match_word()
{
    char const* iter = m_first + 1;
    while (!is_eof() && is_nondigit_or_digit(*iter))
        ++iter;

    std::string id(m_first, iter);

    // Advance the lexer
    m_first = iter;

    // Build the token.

    return Token(Token::identifier, "hello", nullptr);
}