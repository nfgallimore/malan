#define BOOST_TEST_MODULE LexTests

#include "../src/token.hpp"
#include "../src/lexer.hpp"

#include <boost/test/unit_test.hpp>
#include <boost/test/output_test_stream.hpp>
#include <vector>
#include <iterator>
#include <iostream>
#include <fstream>

using boost::test_tools::output_test_stream;


BOOST_AUTO_TEST_CASE(LexsAddExpr)
{
    std::ifstream ifs("../programs/add_expr.dm");
    std::istreambuf_iterator<char> first(ifs);
    std::istreambuf_iterator<char> limit;
    std::string input(first, limit);

    output_test_stream os;

    Lexer lexer(input);
    while (Token tok = lexer.get_next_token()) {
        os << tok << '\n';
    }

    BOOST_TEST(os.is_equal("<integer_literal>\n<plus>\n<integer_literal>\n<semicolon>\n"));
}
