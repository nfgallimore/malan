#define BOOST_TEST_MODULE ExprTests

#include <boost/test/unit_test.hpp>
#include <boost/test/output_test_stream.hpp>
#include <iostream>

#include "../src/expr.hpp"
#include "../src/printer.hpp"
#include "../src/type.hpp"
#include "../src/decl.hpp"
#include "../src/name.hpp"
#include "../src/stmt.hpp"

using boost::test_tools::output_test_stream;

// Helper functions

std::string expr_addr(Expr const* expr)
{
    std::stringstream ss;
    ss << expr;
    return ss.str();
}

std::string decl_addr(Decl const* decl)
{
    std::stringstream ss;
    ss << decl;
    return ss.str();
}

std::string type_addr(Type const* type)
{
    std::stringstream ss;
    ss << type;
    return ss.str();
}

std::string stmt_addr(Stmt const* stmt)
{
    std::stringstream ss;
    ss << stmt;
    return ss.str();
}

std::string name_addr(Name const* name)
{
    std::stringstream ss;
    ss << name;
    return ss.str();
}

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
BOOST_AUTO_TEST_CASE(Int_lit_converts_to_sexpr)
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
    Int_type* it = new Int_type();
    Int_lit* il = new Int_lit(1, it);

    std::string expectedResult = 
        "Int_lit " + expr_addr(il) + '\n' 
            + TAB + "Int_type " + type_addr(it) + '\n';

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
BOOST_AUTO_TEST_CASE(Bool_lit_converts_to_sexprs)
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
    Bool_type* bt = new Bool_type();
    Bool_lit* bl = new Bool_lit(false, bt);

    std::string expectedResult = 
        "Bool_lit " + expr_addr(bl) + '\n' 
            + TAB + "Bool_type " + type_addr(bt) + '\n';

    // Act
    bl->debug(p);

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
BOOST_AUTO_TEST_CASE(Float_lit_converts_to_sexprs)
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
    Float_type* ft = new Float_type();
    Float_lit* fl = new Float_lit(1.0, ft);

    std::string expectedResult = 
        "Float_lit " + expr_addr(fl) + '\n' 
            + TAB + "Float_type " + type_addr(ft) + '\n';

    // Act
    fl->debug(p);

    // Assert
    BOOST_TEST( os.is_equal( expectedResult ) );
}


// Identifier expression unit tests.

/// Tests that a identifier expression `pretty prints` correctly.
BOOST_AUTO_TEST_CASE(Id_expr_prints)
{
    // Arrange
    output_test_stream os;   
    Printer p(os);

    Name* name = new Name("x");
    Type* it = new Int_type();
    Int_lit* il = new Int_lit(1, it);
    Var_decl* decl = new Var_decl(name, it, il);

    Id_expr* id = new Id_expr(decl, it);

    // Act
    id->print(p);

    // Assert
    BOOST_TEST( os.is_equal( "x" ) );
}

/// Tests that a identifier expression converts to a symbolic expression correctly.
BOOST_AUTO_TEST_CASE(Id_expr_converts_to_sexpr)
{
    // Arrange
    output_test_stream os;   
    Printer p(os);

    Name* name = new Name("x");
    Type* it = new Int_type();
    Int_lit* il = new Int_lit(1, it);
    Var_decl* decl = new Var_decl(name, it, il);

    Id_expr* id = new Id_expr(decl, it);

    // Act
    id->print(p);

    // Assert
    BOOST_TEST( os.is_equal( "x" ) );
}

/// Tests that a identifier expression debugs correctly.
BOOST_AUTO_TEST_CASE(Id_expr_debugs)
{
    // Arrange
    output_test_stream os;   
    Printer p(os);

    Name* name = new Name("x");
    Type* it = new Int_type();
    Int_lit* il = new Int_lit(1, it);
    Var_decl* decl = new Var_decl(name, it, il);

    Id_expr* id = new Id_expr(decl, it);

    std::string expected_result = 
        "Id_expr " + expr_addr(id) + '\n' +
        TAB + "Var_decl " + decl_addr(decl) + '\n' +
        TAB + TAB + "Int_type " + type_addr(it) + '\n' +
        TAB + TAB + "Name " + name_addr(name) + '\n' +
        TAB + TAB + "Int_lit " + expr_addr(il) + '\n' +
        TAB + TAB + TAB + "Int_type " + type_addr(it) + '\n' +
        TAB + "Int_type " + type_addr(it) + '\n';
    std::cout << expected_result;

    // Act
    id->debug(p);

    // Assert
    BOOST_TEST( os.is_equal( expected_result ) );
}