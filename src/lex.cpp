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
    input = "1+1;";
    Lexer lexer(input);
    while (Token tok = lexer.get_next_token()) {
        std::cout << tok << '\n';
    }
}
