#pragma once

#include "symbol.hpp"
#include "location.hpp"

#include <iostream>

/// A token is a name and an attribute
/// A token (in the language) is a name and a set of attributes including its lexeme and its source location. The name of a token is the name of hte abstract symbol.
class Token
{
public:
	enum Name
	{
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
		or_kw,
		ref_kw,
		return_kw,
		true_kw,
		var_kw,
		while_kw,

		// literals
		integer_literal,
		float_literal,
		identifier
	};

	Token(Name n, Symbol sym, Location = {})
		: m_name(n), m_lex(sym), m_loc()
	{ }

	Name get_name() const { return m_name; }
	/// Returns the name of the token.

	Symbol get_lexeme() const { return m_lex; }
	/// Returns the lexeme of the token.

	Location get_location() const { return m_loc; }

private:
	Name m_name;
	Symbol m_lex;
	Location m_loc;
};

std::ostream& operator<<(std::ostream& os, Token const& t);
