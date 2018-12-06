#include "parser.hpp"

#include <vector>
#include <iterator>
#include <iostream>
#include <fstream>

int
main(int argc, char* argv[])
{
    std::ifstream ifs("test.c");
    std::istreambuf_iterator<char> first(ifs);
    std::istreambuf_iterator<char> limit;
    std::string input(first, limit);
    input = "1+1";
    Symbol_table syms;

    Parser parse(syms, input);

    parse.parse_expression();
}
