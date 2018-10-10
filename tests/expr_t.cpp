#define BOOST_TEST_MODULE ExprTests

#include <boost/test/unit_test.hpp>
#include <boost/test/output_test_stream.hpp>
#include <iostream>

#include "../expr.hpp"
#include "../printer.hpp"
#include "../type.hpp"
#include "../decl.hpp"
#include "../name.hpp"
#include "../stmt.hpp"

using boost::test_tools::output_test_stream;

// Integer literal expression unit tests

/// Tests that a integer literal expression `pretty prints` correctly.
BOOST_AUTO_TEST_CASE(Int_lit_prints)
{
    // Arrange
    output_test_stream os;   
    Printer p(os);
    Int_lit* il = new Int_lit(1, new Int_type());

    // Act
    il->print(p);

    // Assert
    BOOST_TEST( os.is_equal( "1" ) );
}

/// Tests that a integer literal expression converts to a symbolic expression correctly.
BOOST_AUTO_TEST_CASE(Int_lit_to_sexpr)
{
    // Arrange
    output_test_stream os;
    Printer p(os);
    Int_lit* il = new Int_lit(1, new Int_type());

    // Act
    il->to_sexpr(p);

    // Assert
    BOOST_TEST( os.is_equal( "(1)" ) );
}

/// Tests that a integer literal expression debugs correctly.
BOOST_AUTO_TEST_CASE(Int_lit_debugs)
{
    // Arrange
    output_test_stream os;
    Printer p(os);
    Int_lit* il = new Int_lit(1, new Int_type());

    std::stringstream ss;
    ss << il;
    std::string expectedResult = "Int_lit " + ss.str() + '\n';

    // Act
    il->debug(p);

    // Assert
    BOOST_TEST( os.is_equal( expectedResult ) );
}


// Boolean literal expression unit tests

/// Tests that a boolean literal expression `pretty prints` correctly.
BOOST_AUTO_TEST_CASE(Bool_lit_prints)
{
    // Arrange
    output_test_stream os;   
    Printer p(os);
    Bool_lit* il = new Bool_lit(false, new Bool_type());

    // Act
    il->print(p);

    // Assert
    BOOST_TEST( os.is_equal( "false" ) );
}

/// Tests that a boolean literal expression converts to symbolic expression correctly.
BOOST_AUTO_TEST_CASE(Bool_lit_to_sexprs)
{
    // Arrange
    output_test_stream os;
    Printer p(os);
    Bool_lit* il = new Bool_lit(false, new Bool_type());

    // Act
    il->to_sexpr(p);

    // Assert
    BOOST_TEST( os.is_equal( "(false)" ) );
}

/// Tests that a boolean literal expression debugs correctly.
BOOST_AUTO_TEST_CASE(Bool_lit_debugs)
{
    // Arrange
    output_test_stream os;
    Printer p(os);
    Bool_lit* il = new Bool_lit(1, new Bool_type());

    std::stringstream ss;
    ss << il;
    std::string expectedResult = "Bool_lit " + ss.str() + '\n';

    // Act
    il->debug(p);

    // Assert
    BOOST_TEST( os.is_equal( expectedResult ) );
}


// Float literal expression unit tests.

/// Tests that a float literal expression `pretty prints` correctly.
BOOST_AUTO_TEST_CASE(Float_lit_prints)
{
    // Arrange
    output_test_stream os;   
    Printer p(os);
    Float_lit* il = new Float_lit(1.1, new Float_type());

    // Act
    il->print(p);

    // Assert
    BOOST_TEST( os.is_equal( "1.1" ) );
}

/// Tests that a float literal expression converts to a symbolic expression correctly.
BOOST_AUTO_TEST_CASE(Float_lit_to_sexprs)
{
    // Arrange
    output_test_stream os;
    Printer p(os);
    Float_lit* il = new Float_lit(1.1, new Float_type());

    // Act
    il->to_sexpr(p);

    // Assert
    BOOST_TEST( os.is_equal( "(1.1)" ) );
}

/// Tests that a float literal expression debugs correctly.
BOOST_AUTO_TEST_CASE(Float_lit_debugs)
{
    // Arrange
    output_test_stream os;
    Printer p(os);
    Float_lit* il = new Float_lit(1.1, new Float_type());

    std::stringstream ss;
    ss << il;
    std::string expectedResult = "Float_lit " + ss.str() + '\n';

    // Act
    il->debug(p);

    // Assert
    BOOST_TEST( os.is_equal( expectedResult ) );
}


// // Identifier expression unit tests.

// /// Tests that a identifier expression `pretty prints` correctly.
// BOOST_AUTO_TEST_CASE(Id_expr_prints)
// {
//     // Arrange
//     output_test_stream os;   
//     Printer p(os);

//     Name* name = new Name("x");
//     Type* it = new Int_type();
//     Int_lit* il = new Int_lit(1, it);
//     Var_decl* decl = new Var_decl(name, it, il);

//     Id_expr* il = new Id_expr(decl, it);

//     // Act
//     il->print(p);

//     // Assert
//     BOOST_TEST( os.is_equal( "x" ) );
// }

// /// Tests that a identifier expression converts to a symbolic expression correctly.
// BOOST_AUTO_TEST_CASE(Id_expr_to_sexprs)
// {
//     // Arrange
//     output_test_stream os;
//     Printer p(os);
//     Id_expr* il = new Id_expr(1.1, new Id_expr_type());

//     // Act
//     il->to_sexpr(p);

//     // Assert
//     BOOST_TEST( os.is_equal( "(1.1)" ) );
// }

// /// Tests that a identifier expression debugs correctly.
// BOOST_AUTO_TEST_CASE(Id_expr_debugs)
// {
//     // Arrange
//     output_test_stream os;
//     Printer p(os);

//     Name* name = new Name("x");
//     Type* it = new Int_type();
//     Int_lit* il = new Int_lit(1, it);
//     Var_decl* decl = new Var_decl(name, it, il);

//     Id_expr* id = new Id_expr(decl, it);

//     std::stringstream ss;
//     ss << id;
    
//     std::string expectedResult = "Id_expr " + ss.str() + '\n';

//     // Act
//     il->debug(p);

//     // Assert
//     BOOST_TEST( os.is_equal( expectedResult ) );
// }