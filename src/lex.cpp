#include "token.hpp"
#include "lexer.hpp"

#include <vector>
#include <iterator>
#include <iostream>
#include <fstream>

int
main(int argc, char* argv[])
{
    std::ifstream ifs(argv[1]);
    std::istreambuf_iterator<char> first(ifs);
    std::istreambuf_iterator<char> limit;
    std::string input(first, limit);

    Symbol_table syms;

#if 1
    std::vector<Token> toks {
        Token(Token::if_kw, syms.get("if")),
        Token(Token::lparen, syms.get("(")),
        Token(Token::true_kw, syms.get("true")),
        Token(Token::rparen, syms.get(")")),
        Token(Token::semicolon, syms.get(";"))
    };

    for (Token tok : toks)
        std::cout << tok << '\n';
#endif

    Lexer lexer(syms, input);

    while (Token tok = lexer.get_next_token()) {
        std::cout << tok << '\n';
    }
}
