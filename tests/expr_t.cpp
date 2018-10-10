#define BOOST_TEST_MODULE ExprTests

#include <boost/test/unit_test.hpp>
#include <boost/test/output_test_stream.hpp>

#include "../expr.hpp"
#include "../printer.hpp"
#include "../type.hpp"


using boost::test_tools::output_test_stream;

BOOST_AUTO_TEST_CASE(test)
{
  output_test_stream output;
  int i=2;
  output << "i=" << i;
  BOOST_TEST( !output.is_empty( false ) );
  BOOST_TEST( output.check_length( 3, false ) );
  BOOST_TEST( output.is_equal( "i=3" ) );
}