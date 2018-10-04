#include <iostream>

#include "type.hpp"
#include "expr.hpp"
#include "decl.hpp"
#include "name.hpp"

void types();
void exprs();
void complex_expressions();

int main(int argc, char** argv)
{
    types();
    exprs();
    complex_decl();
    if_stmt();
}

void types()
{
    Bool_type b;
    Int_type i;
    Float_type f;
    Ref_type rb(&b);
    Ref_type ri(&i);
    Ref_type rri(&ri);

    std::vector<Type*> params;
    params.push_back(&b);
    params.push_back(&i);

    Fun_type fun_p(params, &i);
    Fun_type fun_np(&i);
    
    std::cout << b << '\n';
    std::cout << i << '\n';
    std::cout << f << '\n';
    std::cout << rb << '\n';
    std::cout << ri << '\n';
    std::cout << rri << '\n';
    std::cout << fun_p << '\n';
    std::cout << fun_np << '\n';
    std::cout << '\n';

    std::cout << b << " == " << b << " -> " << equal(&b, &b) << '\n';
    std::cout << b << " == " << i << " -> " << equal(&b, &i) << '\n';
    std::cout << b << " == " << f << " -> " << equal(&b, &f) << '\n';
    std::cout << b << " == " << rb << " -> " << equal(&b, &rb) << '\n';
    std::cout << b << " == " << ri << " -> " << equal(&b, &ri) << '\n';
    std::cout << b << " == " << fun_p << " -> " << equal(&b, &fun_p) << '\n';
    std::cout << b << " == " << fun_p << " -> " << equal(&b, &fun_np) << '\n';
    std::cout << '\n';

    std::cout << i << " == " << b << " -> " << equal(&i, &b) << '\n';
    std::cout << i << " == " << i << " -> " << equal(&i, &i) << '\n';
    std::cout << i << " == " << f << " -> " << equal(&i, &f) << '\n';
    std::cout << i << " == " << rb << " -> " << equal(&i, &rb) << '\n';
    std::cout << i << " == " << ri << " -> " << equal(&i, &ri) << '\n';
    std::cout << i << " == " << fun_p << " -> " << equal(&i, &fun_p) << '\n';
    std::cout << i << " == " << fun_np << " -> " << equal(&i, &fun_np) << '\n';
    std::cout << '\n';

    std::cout << f << " == " << b << " -> " << equal(&f, &b) << '\n';
    std::cout << f << " == " << f << " -> " << equal(&f, &i) << '\n';
    std::cout << f << " == " << f << " -> " << equal(&f, &f) << '\n';
    std::cout << f << " == " << rb << " -> " << equal(&f, &rb) << '\n';
    std::cout << f << " == " << ri << " -> " << equal(&f, &ri) << '\n';
    std::cout << f << " == " << fun_p << " -> " << equal(&f, &fun_p) << '\n';
    std::cout << f << " == " << fun_np << " -> " << equal(&f, &fun_np) << '\n';
    std::cout << '\n';

    std::cout << rb << " == " << b << " -> " << equal(&rb, &b) << '\n';
    std::cout << rb << " == " << i << " -> " << equal(&rb, &i) << '\n';
    std::cout << rb << " == " << f << " -> " << equal(&rb, &f) << '\n';
    std::cout << rb << " == " << rb << " -> " << equal(&rb, &rb) << '\n';
    std::cout << rb << " == " << ri << " -> " << equal(&rb, &ri) << '\n';
    std::cout << rb << " == " << fun_p << " -> " << equal(&rb, &fun_p) << '\n';
    std::cout << rb << " == " << fun_np << " -> " << equal(&rb, &fun_np) << '\n';
    std::cout << '\n';

    std::cout << ri << " == " << b << " -> " << equal(&ri, &b) << '\n';
    std::cout << ri << " == " << i << " -> " << equal(&ri, &i) << '\n';
    std::cout << ri << " == " << f << " -> " << equal(&ri, &f) << '\n';
    std::cout << ri << " == " << rb << " -> " << equal(&ri, &rb) << '\n';
    std::cout << ri << " == " << ri << " -> " << equal(&ri, &ri) << '\n';
    std::cout << ri << " == " << fun_p << " -> " << equal(&ri, &fun_p) << '\n';
    std::cout << ri << " == " << fun_np << " -> " << equal(&ri, &fun_np) << '\n';
    std::cout << '\n';

    std::cout << fun_p << " == " << b << " -> " << equal(&fun_p, &b) << '\n';
    std::cout << fun_p << " == " << i << " -> " << equal(&fun_p, &i) << '\n';
    std::cout << fun_p << " == " << f << " -> " << equal(&fun_p, &f) << '\n';
    std::cout << fun_p << " == " << rb << " -> " << equal(&fun_p, &rb) << '\n';
    std::cout << fun_p << " == " << ri << " -> " << equal(&fun_p, &ri) << '\n';
    std::cout << fun_p << " == " << fun_p << " -> " << equal(&fun_p, &fun_p) << '\n';
    std::cout << fun_p << " == " << fun_np << " -> " << equal(&fun_p, &fun_np) << '\n';
    std::cout << '\n';

    std::cout << fun_np << " == " << b << " -> " << equal(&fun_np, &b) << '\n';
    std::cout << fun_np << " == " << i << " -> " << equal(&fun_np, &i) << '\n';
    std::cout << fun_np << " == " << f << " -> " << equal(&fun_np, &f) << '\n';
    std::cout << fun_np << " == " << rb << " -> " << equal(&fun_np, &rb) << '\n';
    std::cout << fun_np << " == " << ri << " -> " << equal(&fun_np, &ri) << '\n';
    std::cout << fun_np << " == " << fun_p << " -> " << equal(&fun_np, &fun_p) << '\n';
    std::cout << fun_np << " == " << fun_np << " -> " << equal(&fun_np, &fun_np) << '\n';
    std::cout << '\n';

    std::cout << "Debugging types:\n";
    debug(std::cout, &b);
    debug(std::cout, &i);
    debug(std::cout, &f);
    debug(std::cout, &rb);
    debug(std::cout, &ri);
    debug(std::cout, &fun_p);
    debug(std::cout, &fun_np);
    std::cout << "\n\n";

    std::cout << "Converting types to s_expr:\n";
    to_sexpr(std::cout, &b);
    std::cout << '\n';
    to_sexpr(std::cout, &i);
    std::cout << '\n';
    to_sexpr(std::cout, &f);
    std::cout << '\n';
    to_sexpr(std::cout, &rb);
    std::cout << '\n';
    to_sexpr(std::cout, &ri);
    std::cout << '\n';
    to_sexpr(std::cout, &fun_p);
    std::cout << '\n';
    to_sexpr(std::cout, &fun_np);
    std::cout << "\n\n";
}


void exprs()
{    
    Type it = Int_type();
    Type bt = Bool_type();

    // Int literal operations
    std::cout << "Integer literal:\n";
    Int_literal il(1, &it);
    std::cout << "print: " << il << '\n';
    il.debug(std::cout << "debug: ");
    il.to_sexpr(std::cout << "s_expr: ");
    std::cout << "\n\n";

    // Bool literal operations
    std::cout << "Boolean literal:\n";
    Bool_literal bl(false, &bt);
    std::cout << "print: " << bl << '\n';
    bl.debug(std::cout << "debug: ");
    bl.to_sexpr(std::cout << "s_expr: ");
    std::cout << "\n\n";

    // Identifier operations
    Name n("x");
    Var_decl vdecl(&n, &it, &il);
    
    std::cout << "Identifier:\n";
    Identifier id(&vdecl, &it);
    std::cout << "print: " << id << '\n';
    id.debug(std::cout << "debug: ");
    id.to_sexpr(std::cout << "s_expr: ");
    std::cout << "\n\n";

    // Logical AND operations
    std::cout << "Logical AND:\n";
    Logical_and andExp(&bl, &bl, &bt);
    std::cout << "print: " << andExp << '\n';
    andExp.debug(std::cout << "debug: ");
    andExp.to_sexpr(std::cout << "s_expr: ");
    std::cout << "\nevaluate: " << andExp.evaluate().get_bool() << "\n\n";

    // Logical OR operations
    std::cout << "Logical OR:\n";
    Logical_or orExp(&bl, &bl, &bt);
    std::cout << "print: " << orExp << '\n';
    orExp.debug(std::cout << "debug: ");
    orExp.to_sexpr(std::cout << "s_expr: ");
    std::cout << "\nevaluate: " << orExp.evaluate().get_bool() << "\n\n";
    
    // Logical NOT operations
    std::cout << "Logical NOT:\n";
    Logical_not notExp(&bl, &bt);
    std::cout << "print: " << notExp << '\n';
    notExp.debug(std::cout << "debug: ");
    notExp.to_sexpr(std::cout << "s_expr: ");
    std::cout << "\nevaluate: " << notExp.evaluate().get_bool() << "\n\n";

    // Ternary expression operations
    std::cout << "Ternary expression:\n";
    Ternary_expr ternaryExpr(&bl, &bl, &bl, &bt);
    std::cout << "print: " << ternaryExpr << '\n';
    ternaryExpr.debug(std::cout << "debug: ");
    ternaryExpr.to_sexpr(std::cout << "s_expr: ");
    std::cout << "\n\n";

    // Equal expression operations
    std::cout << "Equal expression:\n";
    Equal_expr equalExpr(&bl, &bl, &bt);
    std::cout << "print: " << equalExpr << '\n';
    equalExpr.debug(std::cout << "debug: ");
    equalExpr.to_sexpr(std::cout << "s_expr: ");
    std::cout << "\n\n";

    // Not equal expression operations
    std::cout << "Not equal expression:\n";
    Not_equal_expr notEqExpr(&bl, &bl, &bt);
    std::cout << "print: " << notEqExpr << '\n';
    notEqExpr.debug(std::cout << "debug: ");
    notEqExpr.to_sexpr(std::cout << "s_expr: ");
    std::cout << "\n\n";

    // Less than expression operations
    std::cout << "Less than expression:\n";
    Less_than_expr lessExpr(&bl, &bl, &bt);
    std::cout << "print: " << lessExpr << '\n';
    lessExpr.debug(std::cout << "debug: ");
    lessExpr.to_sexpr(std::cout << "s_expr: ");
    std::cout << "\n\n";

    // Greater than expression operations
    std::cout << "Greater than expression:\n";
    Greater_than_expr greaterExpr(&bl, &bl, &bt);
    std::cout << "print: " << greaterExpr << '\n';
    greaterExpr.debug(std::cout << "debug: ");
    greaterExpr.to_sexpr(std::cout << "s_expr: ");
    std::cout << "\n\n";

    // Less than or equal expression operations
    std::cout << "Less than or equal expression:\n";
    Less_than_or_equal_expr lessOrEqExpr(&bl, &bl, &bt);
    std::cout << "print: " << lessOrEqExpr << '\n';
    lessOrEqExpr.debug(std::cout << "debug: ");
    lessOrEqExpr.to_sexpr(std::cout << "s_expr: ");
    std::cout << "\n\n";

    // Greater than or equal expression operations
    std::cout << "Greater than or equal expression:\n";
    Greater_than_or_equal_expr greaterOrEqExpr(&bl, &bl, &bt);
    std::cout << "print: " << greaterOrEqExpr << '\n';
    greaterOrEqExpr.debug(std::cout << "debug: ");
    greaterOrEqExpr.to_sexpr(std::cout << "s_expr: ");
    std::cout << "\n\n";

    // Addition expression operations
    std::cout << "Addition expression:\n";
    Add_expr addExpr(&il, &il, &it);
    std::cout << "print: " << addExpr << '\n';
    addExpr.debug(std::cout << "debug: ");
    addExpr.to_sexpr(std::cout << "s_expr: ");
    std::cout << "\n\n";

    // Subtraction expression operations
    std::cout << "Subtraction expression:\n";
    Sub_expr subExpr(&il, &il, &it);
    std::cout << "print: " << subExpr << '\n';
    subExpr.debug(std::cout << "debug: ");
    subExpr.to_sexpr(std::cout << "s_expr: ");
    std::cout << "\n\n";

    // Multiplication expression operations
    std::cout << "Multiplication expression:\n";
    Mult_expr multExpr(&il, &il, &it);
    std::cout << "print: " << multExpr << '\n';
    multExpr.debug(std::cout << "debug: ");
    multExpr.to_sexpr(std::cout << "s_expr: ");
    std::cout << "\n\n";

    // Quotient expression operations
    std::cout << "Quotient expression:\n";
    Quot_expr quotExpr(&il, &il, &it);
    std::cout << "print: " << quotExpr << '\n';
    quotExpr.debug(std::cout << "debug: ");
    quotExpr.to_sexpr(std::cout << "s_expr: ");
    std::cout << "\n\n";

    // Remainder expression operations
    std::cout << "Remainder expression:\n";
    Rem_expr remExpr(&il, &il, &it);
    std::cout << "print: " << remExpr << '\n';
    remExpr.debug(std::cout << "debug: ");
    remExpr.to_sexpr(std::cout << "s_expr: ");
    std::cout << "\n\n";

    // Negate expression operations
    std::cout << "Negate expression:\n";
    Negate_expr negExpr(&il, &it);
    std::cout << "print: " << negExpr << '\n';
    negExpr.debug(std::cout << "debug: ");
    negExpr.to_sexpr(std::cout << "s_expr: ");
    std::cout << "\n\n";

    // Reciprocal expression operations
    std::cout << "Reciprocal expression:\n";
    Reciprocal_expr recipExpr(&il, &it);
    std::cout << "print: " << recipExpr << '\n';
    recipExpr.debug(std::cout << "debug: ");
    recipExpr.to_sexpr(std::cout << "s_expr: ");
    std::cout << "\n\n";

}

// Complex expression operations
void complex_decl()
{
    // var x = 2 + 2;
    Name name("x");
    Type type = Int_type();

    Int_literal operand1(2, &type);
    Int_literal operand2(2, &type);

    Add_expr add_expr(&operand1, &operand2, &type);
    Sub_expr sub_expr(&operand1, &operand2, &type);

    Mult_expr mult_expr(&add_expr, &sub_expr, &type);

    Var_decl decl(&name, &type, &mult_expr);
    std::cout << "print: " << decl << '\n';
    decl.to_sexpr(std::cout << "s_expr: ");
        
}

void if_stmt()
{
    
}