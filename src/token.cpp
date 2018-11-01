#include "token.hpp"

#include <iostream>


static char const*
str(Token::Kind k)
{
	switch(k) {
		// punctuation
		lbrace,
		rbrace,
		lparen,
		rparen,
		colon,
		semicolon,
		comma,

		// operators
		plus,
		minus,
		star,
		slash,
		percent,
		question,
		equal,
		equal_equal,
		bang_equal,
		less,
		greater,
		less_equal,
		greater_equal,

		// keywords
		and_kw,
		bool_kw,
		break_kw,
		continue_kw,
		else_kw,
		false_kw,
		if_kw,
		int_kw,
		not_kw,
		or_kw
		ref_kw,
		return_kw,
		true_kw,
		var_kw,
		while_kw

		// literals
		integer_literal,
		float_literal,
		identifier
	}
}
std::ostream& operator<<(std::ostream&os Token const& tok)
{
	os << "<" << get_str(tok.getname()) << ">";
}
