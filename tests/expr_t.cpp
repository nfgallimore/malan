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
#include "../src/value.hpp"
#include "../src/builder.hpp"

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
    Builder b;
    Expr* il = b.make_int(1);

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
    Builder b;
    Expr* il = b.make_int(1);

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
    Builder b;
    Expr* il = b.make_int(1);

    std::string expectedResult = 
        "Int_lit " + expr_addr(il) + '\n' 
            + TAB + "Int_type " + type_addr(il->get_type()) + '\n';

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
    Builder b;
    Expr* bl = b.make_false();

    // Act
    bl->print(p);

    // Assert
    BOOST_TEST( os.is_equal( "false" ) );
}

/// Tests that a boolean literal expression converts to symbolic expression correctly.
BOOST_AUTO_TEST_CASE(Bool_lit_converts_to_sexprs)
{
    // Arrange
    output_test_stream os;
    Printer p(os);
    Builder b;
    Expr* bl = b.make_false();

    // Act
    bl->to_sexpr(p);

    // Assert
    BOOST_TEST( os.is_equal( "(false)" ) );
}

/// Tests that a boolean literal expression debugs correctly.
BOOST_AUTO_TEST_CASE(Bool_lit_debugs)
{
    // Arrange
    output_test_stream os;
    Printer p(os);
    Builder b;
    Expr* bl = b.make_false();

    std::string expectedResult = 
        "Bool_lit " + expr_addr(bl) + '\n' 
            + TAB + "Bool_type " + type_addr(bl->get_type()) + '\n';

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
    Builder b;
    Expr* fl = b.make_float(1.1f);

    // Act
    fl->print(p);

    // Assert
    BOOST_TEST( os.is_equal( "1.1" ) );
}

/// Tests that a float literal expression converts to a symbolic expression correctly.
BOOST_AUTO_TEST_CASE(Float_lit_converts_to_sexprs)
{
    // Arrange
    output_test_stream os;
    Printer p(os);
    Builder b;
    Expr* fl = b.make_float(1.1f);

    // Act
    fl->to_sexpr(p);

    // Assert
    BOOST_TEST( os.is_equal( "(1.1)" ) );
}

/// Tests that a float literal expression debugs correctly.
BOOST_AUTO_TEST_CASE(Float_lit_debugs)
{
    // Arrange
    output_test_stream os;
    Printer p(os);
    Builder b;
    Expr* fl = b.make_float(1.1);

    std::string expectedResult = 
        "Float_lit " + expr_addr(fl) + '\n' 
            + TAB + "Float_type " + type_addr(fl->get_type()) + '\n';

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
    Builder b;

    Name* name = new Name("x");
    Expr* il = b.make_int(1);

    Var_decl* var = b.make_var(b.get_int_type(), name, il);
    Expr* id = b.make_id(var);

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
    Builder b;

    Name* name = new Name("x");
    Expr* il = b.make_int(1);

    Var_decl* var = b.make_var(b.get_int_type(), name, il);
    Expr* id = b.make_id(var);

    // Act
    id->to_sexpr(p);

    // Assert
    BOOST_TEST( os.is_equal( "(x)" ) );
}

/// Tests that a identifier expression debugs correctly.
BOOST_AUTO_TEST_CASE(Id_expr_debugs)
{
    // Arrange
    output_test_stream os;   
    Printer p(os);
    Builder b;

    Name* name = new Name("x");
    Expr* il = b.make_int(1);

    Var_decl* var = b.make_var(b.get_int_type(), name, il);
    Expr* id = b.make_id(var);

    std::string expected_result = 
        "Id_expr " + expr_addr(id) + '\n' +
        TAB + "Var_decl " + decl_addr(var) + '\n' +
        TAB + TAB + "Int_type " + type_addr(b.get_int_type()) + '\n' +
        TAB + TAB + "Name " + name_addr(name) + '\n' +
        TAB + TAB + "Int_lit " + expr_addr(il) + '\n' +
        TAB + TAB + TAB + "Int_type " + type_addr(b.get_int_type()) + '\n' +
        TAB + "Int_type " + type_addr(b.get_int_type()) + '\n';

    // Act
    id->debug(p);

    // Assert
    BOOST_TEST( os.is_equal( expected_result ) );
}


// And expression unit tests.

/// Tests that an And expression `pretty prints` correctly.
BOOST_AUTO_TEST_CASE(And_expr_prints)
{
    // Arrange
    output_test_stream os;   
    Printer p(os);
    Builder b;

    Expr* expr = b.make_and(b.make_true(), b.make_true());
 
    // Act
    expr->print(p);

    // Assert
    BOOST_TEST( os.is_equal( "(true AND true)" ) );
}

/// Tests that an And expression converts to a symbolic expression correctly.
BOOST_AUTO_TEST_CASE(And_expr_converts_to_sexpr)
{
    // Arrange
    output_test_stream os;   
    Printer p(os);
    Builder b;

    Expr* expr = b.make_and(b.make_true(), b.make_true());

    // Act
    expr->to_sexpr(p);

    // Assert
    BOOST_TEST( os.is_equal( "(AND (true) (true))" ) );
}

/// Tests that an And expression debugs correctly.
BOOST_AUTO_TEST_CASE(And_expr_debugs)
{
    // Arrange
    output_test_stream os;   
    Printer p(os);
    Builder b;

    Expr* e1 = b.make_true();
    Expr* e2 = b.make_true();
    Expr* expr = b.make_and(e1, e2);

    std::string expected_result = 
        "And_expr " + expr_addr(expr) + '\n' +
        TAB + "Bool_lit " + expr_addr(e1) + '\n' +
        TAB + TAB "Bool_type " + type_addr(e1->get_type()) + '\n' +
        TAB + "Bool_lit " + expr_addr(e2) + '\n' +
        TAB + TAB "Bool_type " + type_addr(e2->get_type()) + '\n' +
        TAB + "Bool_type " + type_addr(expr->get_type()) + '\n';

    // Act
    expr->debug(p);

    // Assert
    BOOST_TEST( os.is_equal( expected_result ) );
}


// Or expression unit tests.

/// Tests that an Or expression `pretty prints` correctly.
BOOST_AUTO_TEST_CASE(Or_expr_prints)
{
    // Arrange
    output_test_stream os;   
    Printer p(os);
    Builder b;

    Expr* expr = b.make_or(b.make_true(), b.make_true());

    // Act
    expr->print(p);

    // Assert
    BOOST_TEST( os.is_equal( "(true OR true)" ) );
}

/// Tests that an Or expression converts to a symbolic expression correctly.
BOOST_AUTO_TEST_CASE(Or_expr_converts_to_sexpr)
{
    // Arrange
    output_test_stream os;   
    Printer p(os);
    Builder b;

    Expr* expr = b.make_or(b.make_true(), b.make_true());

    // Act
    expr->to_sexpr(p);

    // Assert
    BOOST_TEST( os.is_equal( "(OR (true) (true))" ) );
}

/// Tests that an Or expression debugs correctly.
BOOST_AUTO_TEST_CASE(Or_expr_debugs)
{
    // Arrange
    output_test_stream os;   
    Printer p(os);
    Builder b;

    Expr* e1 = b.make_true();
    Expr* e2 = b.make_true();
    Expr* expr = b.make_or(e1, e2);

    std::string expected_result = 
        "Or_expr " + expr_addr(expr) + '\n' +
        TAB + "Bool_lit " + expr_addr(e1) + '\n' +
        TAB + TAB "Bool_type " + type_addr(e1->get_type()) + '\n' +
        TAB + "Bool_lit " + expr_addr(e2) + '\n' +
        TAB + TAB "Bool_type " + type_addr(e2->get_type()) + '\n' +
        TAB + "Bool_type " + type_addr(expr->get_type()) + '\n';

    // Act
    expr->debug(p);

    // Assert
    BOOST_TEST( os.is_equal( expected_result ) );
}


// Eq expression unit tests.

/// Tests that an Eq expression `pretty prints` correctly.
BOOST_AUTO_TEST_CASE(Eq_expr_prints)
{
    // Arrange
    output_test_stream os;   
    Printer p(os);
    Builder b;

    Expr* expr = b.make_eq(b.make_true(), b.make_true());

    // Act
    expr->print(p);

    // Assert
    BOOST_TEST( os.is_equal( "(true == true)" ) );
}

/// Tests that an Eq expression converts to a symbolic expression correctly.
BOOST_AUTO_TEST_CASE(Eq_expr_converts_to_sexpr)
{
    // Arrange
    output_test_stream os;   
    Printer p(os);
    Builder b;

    Expr* expr = b.make_eq(b.make_true(), b.make_true());

    // Act
    expr->to_sexpr(p);

    // Assert
    BOOST_TEST( os.is_equal( "(== (true) (true))" ) );
}

/// Tests that an Eq expression debugs correctly.
BOOST_AUTO_TEST_CASE(Eq_expr_debugs)
{
    // Arrange
    output_test_stream os;   
    Printer p(os);
    Builder b;

    Expr* e1 = b.make_true();
    Expr* e2 = b.make_true();
    Expr* expr = b.make_eq(e1, e2);

    std::string expected_result = 
        "Eq_expr " + expr_addr(expr) + '\n' +
        TAB + "Bool_lit " + expr_addr(e1) + '\n' +
        TAB + TAB "Bool_type " + type_addr(e1->get_type()) + '\n' +
        TAB + "Bool_lit " + expr_addr(e2) + '\n' +
        TAB + TAB "Bool_type " + type_addr(e2->get_type()) + '\n' +
        TAB + "Bool_type " + type_addr(expr->get_type()) + '\n';

    // Act
    expr->debug(p);

    // Assert
    BOOST_TEST( os.is_equal( expected_result ) );
}


// Ne expression unit tests.

/// Tests that an Ne expression `pretty prints` correctly.
BOOST_AUTO_TEST_CASE(Ne_expr_prints)
{
    // Arrange
    output_test_stream os;   
    Printer p(os);
    Builder b;

    Expr* expr = b.make_ne(b.make_true(), b.make_true());

    // Act
    expr->print(p);

    // Assert
    BOOST_TEST( os.is_equal( "(true != true)" ) );
}

/// Tests that an Ne expression converts to a symbolic expression correctly.
BOOST_AUTO_TEST_CASE(Ne_expr_converts_to_sexpr)
{
    // Arrange
    output_test_stream os;   
    Printer p(os);
    Builder b;

    Expr* expr = b.make_ne(b.make_true(), b.make_true());

    // Act
    expr->to_sexpr(p);

    // Assert
    BOOST_TEST( os.is_equal( "(!= (true) (true))" ) );
}

/// Tests that an Ne expression debugs correctly.
BOOST_AUTO_TEST_CASE(Ne_expr_debugs)
{
    // Arrange
    output_test_stream os;   
    Printer p(os);
    Builder b;

    Expr* e1 = b.make_true();
    Expr* e2 = b.make_true();
    Expr* expr = b.make_ne(e1, e2);

    std::string expected_result = 
        "Ne_expr " + expr_addr(expr) + '\n' +
        TAB + "Bool_lit " + expr_addr(e1) + '\n' +
        TAB + TAB "Bool_type " + type_addr(e1->get_type()) + '\n' +
        TAB + "Bool_lit " + expr_addr(e2) + '\n' +
        TAB + TAB "Bool_type " + type_addr(e2->get_type()) + '\n' +
        TAB + "Bool_type " + type_addr(expr->get_type()) + '\n';

    // Act
    expr->debug(p);

    // Assert
    BOOST_TEST( os.is_equal( expected_result ) );
}
