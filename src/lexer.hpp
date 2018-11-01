#pragma once

#include "token.hpp"
#include "symbol.hpp"
#include <unordered_map>

class Lexer
{
public:

	Lexer::Lexer(Symbol_table& syms, char const* first, char const* limit);

	Token get_next_token();
	/// Give you one token after another.


private:
	bool is_eof() const { return m_first == m_limit; } 
	/// True if we've consumed all input.

	char peek() const 
	{ 
		if (is_eof())
			return 0;

		return *m_first;
	}
	// Peek at the first character.

	char peek(int n) const 
	{ 
		if (m_limit - m_first <= n)
			return 0;

		if (is_eof())
			return 0;

		return *(m_first + n);
	}
	// Peek at the first character.


	char consume() { return *m_first++; }
	// Returns the current characfter, increments
	// the current input charafter (lookahead).

	Token match(Token::Name n, int len);

	Token match_word();

	Token match_number();

private:
	char* m_first;
	char* m_limit;

	Symbol_table* m_syms;

	int m_line;

	std::unordered_map<std::string, Token::Name> map;
};