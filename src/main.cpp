#include <iostream>

#include "type.hpp"
#include "expr.hpp"
#include "decl.hpp"
#include "name.hpp"
#include "stmt.hpp"
#include "printer.hpp"

void types();
void exprs();
void complex_decl();
void nested_debug_printing();
void make_min();
void print_ref_decl();
void if_stmt();
void while_stmt();
void test();
void identifier_if_stmt();
void factorial();

/* This main file contains constructions of the abstract syntax tree
to test the classes blow up when instantiated. Ideally these would be unit tests
asserting that the proper value is being printed. But due to lack of time, and more of a focus on features,
unit tests have been excluded and will need to be re-added.
 */

int main(int argc, char** argv)
{
    // types();
    // exprs();
    // complex_decl();
    // nested_debug_printing();
    // make_min();
    // print_ref_decl();
    // if_stmt();
    // while_stmt();
    // identifier_if_stmt();
    // factorial();
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
    (params).push_back(&b);
    (params).push_back(&i);

    Fun_type fun_p(params, &i);
    Fun_type fun_np(&i);
    
    Printer p(std::cout);

    p.get_stream() << b << '\n';
    p.get_stream() << i << '\n';
    p.get_stream() << f << '\n';
    p.get_stream() << rb << '\n';
    p.get_stream() << ri << '\n';
    p.get_stream() << rri << '\n';
    p.get_stream() << fun_p << '\n';
    p.get_stream() << fun_np << '\n';
    p.get_stream() << '\n';

    // p.get_stream() << b << " == " << b << " -> " << equal(&b, &b) << '\n';
    // p.get_stream() << b << " == " << i << " -> " << equal(&b, &i) << '\n';
    // p.get_stream() << b << " == " << f << " -> " << equal(&b, &f) << '\n';
    // p.get_stream() << b << " == " << rb << " -> " << equal(&b, &rb) << '\n';
    // p.get_stream() << b << " == " << ri << " -> " << equal(&b, &ri) << '\n';
    // p.get_stream() << b << " == " << fun_p << " -> " << equal(&b, &fun_p) << '\n';
    // p.get_stream() << b << " == " << fun_p << " -> " << equal(&b, &fun_np) << '\n';
    // p.get_stream() << '\n';

    // p.get_stream() << i << " == " << b << " -> " << equal(&i, &b) << '\n';
    // p.get_stream() << i << " == " << i << " -> " << equal(&i, &i) << '\n';
    // p.get_stream() << i << " == " << f << " -> " << equal(&i, &f) << '\n';
    // p.get_stream() << i << " == " << rb << " -> " << equal(&i, &rb) << '\n';
    // p.get_stream() << i << " == " << ri << " -> " << equal(&i, &ri) << '\n';
    // p.get_stream() << i << " == " << fun_p << " -> " << equal(&i, &fun_p) << '\n';
    // p.get_stream() << i << " == " << fun_np << " -> " << equal(&i, &fun_np) << '\n';
    // p.get_stream() << '\n';

    // p.get_stream() << f << " == " << b << " -> " << equal(&f, &b) << '\n';
    // p.get_stream() << f << " == " << f << " -> " << equal(&f, &i) << '\n';
    // p.get_stream() << f << " == " << f << " -> " << equal(&f, &f) << '\n';
    // p.get_stream() << f << " == " << rb << " -> " << equal(&f, &rb) << '\n';
    // p.get_stream() << f << " == " << ri << " -> " << equal(&f, &ri) << '\n';
    // p.get_stream() << f << " == " << fun_p << " -> " << equal(&f, &fun_p) << '\n';
    // p.get_stream() << f << " == " << fun_np << " -> " << equal(&f, &fun_np) << '\n';
    // p.get_stream() << '\n';

    // p.get_stream() << rb << " == " << b << " -> " << equal(&rb, &b) << '\n';
    // p.get_stream() << rb << " == " << i << " -> " << equal(&rb, &i) << '\n';
    // p.get_stream() << rb << " == " << f << " -> " << equal(&rb, &f) << '\n';
    // p.get_stream() << rb << " == " << rb << " -> " << equal(&rb, &rb) << '\n';
    // p.get_stream() << rb << " == " << ri << " -> " << equal(&rb, &ri) << '\n';
    // p.get_stream() << rb << " == " << fun_p << " -> " << equal(&rb, &fun_p) << '\n';
    // p.get_stream() << rb << " == " << fun_np << " -> " << equal(&rb, &fun_np) << '\n';
    // p.get_stream() << '\n';

    // p.get_stream() << ri << " == " << b << " -> " << equal(&ri, &b) << '\n';
    // p.get_stream() << ri << " == " << i << " -> " << equal(&ri, &i) << '\n';
    // p.get_stream() << ri << " == " << f << " -> " << equal(&ri, &f) << '\n';
    // p.get_stream() << ri << " == " << rb << " -> " << equal(&ri, &rb) << '\n';
    // p.get_stream() << ri << " == " << ri << " -> " << equal(&ri, &ri) << '\n';
    // p.get_stream() << ri << " == " << fun_p << " -> " << equal(&ri, &fun_p) << '\n';
    // p.get_stream() << ri << " == " << fun_np << " -> " << equal(&ri, &fun_np) << '\n';
    // p.get_stream() << '\n';

    // p.get_stream() << fun_p << " == " << b << " -> " << equal(&fun_p, &b) << '\n';
    // p.get_stream() << fun_p << " == " << i << " -> " << equal(&fun_p, &i) << '\n';
    // p.get_stream() << fun_p << " == " << f << " -> " << equal(&fun_p, &f) << '\n';
    // p.get_stream() << fun_p << " == " << rb << " -> " << equal(&fun_p, &rb) << '\n';
    // p.get_stream() << fun_p << " == " << ri << " -> " << equal(&fun_p, &ri) << '\n';
    // p.get_stream() << fun_p << " == " << fun_p << " -> " << equal(&fun_p, &fun_p) << '\n';
    // p.get_stream() << fun_p << " == " << fun_np << " -> " << equal(&fun_p, &fun_np) << '\n';
    // p.get_stream() << '\n';

    // p.get_stream() << fun_np << " == " << b << " -> " << equal(&fun_np, &b) << '\n';
    // p.get_stream() << fun_np << " == " << i << " -> " << equal(&fun_np, &i) << '\n';
    // p.get_stream() << fun_np << " == " << f << " -> " << equal(&fun_np, &f) << '\n';
    // p.get_stream() << fun_np << " == " << rb << " -> " << equal(&fun_np, &rb) << '\n';
    // p.get_stream() << fun_np << " == " << ri << " -> " << equal(&fun_np, &ri) << '\n';
    // p.get_stream() << fun_np << " == " << fun_p << " -> " << equal(&fun_np, &fun_p) << '\n';
    // p.get_stream() << fun_np << " == " << fun_np << " -> " << equal(&fun_np, &fun_np) << '\n';
    // p.get_stream() << '\n';

    p.get_stream() << "Debugging types:\n";
    debug(p.get_stream(), &b);
    debug(p.get_stream(), &i);
    debug(p.get_stream(), &f);
    debug(p.get_stream(), &rb);
    debug(p.get_stream(), &ri);
    debug(p.get_stream(), &fun_p);
    debug(p.get_stream(), &fun_np);
    p.get_stream() << "\n\n";

    p.get_stream() << "Converting types to s_expr:\n";
    to_sexpr(p.get_stream(), &b);
    p.get_stream() << '\n';
    to_sexpr(p.get_stream(), &i);
    p.get_stream() << '\n';
    to_sexpr(p.get_stream(), &f);
    p.get_stream() << '\n';
    to_sexpr(p.get_stream(), &rb);
    p.get_stream() << '\n';
    to_sexpr(p.get_stream(), &ri);
    p.get_stream() << '\n';
    to_sexpr(p.get_stream(), &fun_p);
    p.get_stream() << '\n';
    to_sexpr(p.get_stream(), &fun_np);
    p.get_stream() << "\n\n";
}


void exprs()
{    
    Int_type it;
    Bool_type bt;

    Printer p(std::cout);
    // Int literal operations
    p.get_stream() << "Integer literal:\n";
    Int_lit il(1, &it);
    p.get_stream() << "print: " << il << '\n';
    p.get_stream() << "debug: \n";
    il.debug(p);
    p.get_stream() << "s_expr: ";
    il.to_sexpr(p);
    p.new_line(2);

    // Bool literal operations
    p.get_stream() << "Boolean literal:\n";
    Bool_lit bl(false, &bt);
    p.get_stream() << "print: " << bl << '\n';
    p.get_stream() << "debug: \n";
    bl.debug(p);
    p.get_stream() << "s_expr: ";
    bl.to_sexpr(p);
    p.new_line(2);

    // Float literal operations
    p.get_stream() << "Boolean literal:\n";
    Float_lit fl(1.3f, &bt);
    p.get_stream() << "print: " << fl << '\n';
    p.get_stream() << "debug: \n";
    fl.debug(p);
    p.get_stream() << "s_expr: ";
    fl.to_sexpr(p);
    p.new_line(2);

    // Identifier operations
    Name n("x");
    Var_decl vdecl(&n, &it, &il);
    
    p.get_stream() << "Identifier:\n";
    Id_expr id(&vdecl, &it);
    p.get_stream() << "print: " << id << '\n';
    p.get_stream() << "debug: \n";
    id.debug(p);
    p.get_stream() << "s_expr: ";
    id.to_sexpr(p);
    p.new_line(2);

    // Logical AND operations
    p.get_stream() << "Logical AND:\n";
    And_expr andExp(&bl, &bl, &bt);
    p.get_stream() << "print: " << andExp << '\n';
    p.get_stream() << "debug: \n";
    andExp.debug(p);
    p.get_stream() << "s_expr: ";
    andExp.to_sexpr(p);
    p.new_line();
    p.get_stream() << "\nevaluate: " << andExp.evaluate().get_bool() << "\n\n";

    // Logical OR operations
    p.get_stream() << "Logical OR:\n";
    Or_expr orExp(&bl, &bl, &bt);
    p.get_stream() << "print: " << orExp << '\n';
    p.get_stream() << "debug: \n";
    orExp.debug(p);
    p.get_stream() << "s_expr: ";
    orExp.to_sexpr(p);
    p.new_line();
    p.get_stream() << "\nevaluate: " << orExp.evaluate().get_bool() << "\n\n";
    
    // Logical NOT operations
    p.get_stream() << "Logical NOT:\n";
    Not_expr notExp(&bl, &bt);
    p.get_stream() << "print: " << notExp << '\n';
    p.get_stream() << "debug: \n";
    notExp.debug(p);
    p.get_stream() << "s_expr: ";
    notExp.to_sexpr(p);
    p.new_line();
    p.get_stream() << "\nevaluate: " << notExp.evaluate().get_bool() << "\n\n";

    // Ternary expression operations
    p.get_stream() << "Ternary expression:\n";
    Con_expr conExpr(&bl, &bl, &bl, &bt);
    p.get_stream() << "print: " << conExpr << '\n';
    p.get_stream() << "debug: \n";
    conExpr.debug(p);
    p.get_stream() << "s_expr: ";
    conExpr.to_sexpr(p);
    p.new_line(2);

    // Equal expression operations
    p.get_stream() << "Equal expression:\n";
    Eq_expr eqExpr(&il, &il, &bt);
    p.get_stream() << "print: " << eqExpr << '\n';
    p.get_stream() << "debug: \n";
    eqExpr.debug(p);
    p.get_stream() << "s_expr: ";
    eqExpr.to_sexpr(p);
    p.new_line(2);

    // Not equal expression operations
    p.get_stream() << "Not equal expression:\n";
    Ne_expr neExpr(&il, &il, &bt);
    p.get_stream() << "print: " << neExpr << '\n';
    p.get_stream() << "debug: \n";
    neExpr.debug(p);
    p.get_stream() << "s_expr: ";
    neExpr.to_sexpr(p);
    p.new_line(2);

    // Less than expression operations
    p.get_stream() << "Less than expression:\n";
    Lt_expr ltExpr(&il, &il, &bt);
    p.get_stream() << "print: " << ltExpr << '\n';
    p.get_stream() << "debug: \n";
    ltExpr.debug(p);
    p.get_stream() << "s_expr: ";
    ltExpr.to_sexpr(p);
    p.new_line(2);

    // Greater than expression operations
    p.get_stream() << "Greater than expression:\n";
    Gt_expr gtExpr(&il, &il, &bt);
    p.get_stream() << "print: " << gtExpr << '\n';
    p.get_stream() << "debug: \n";
    gtExpr.debug(p);
    p.get_stream() << "s_expr: ";
    gtExpr.to_sexpr(p);
    p.new_line(2);

    // Less than or equal expression operations
    p.get_stream() << "Less than or equal expression:\n";
    Le_expr leExpr(&il, &il, &bt);
    p.get_stream() << "print: " << leExpr << '\n';
    p.get_stream() << "debug: \n";
    leExpr.debug(p);
    p.get_stream() << "s_expr: ";
    leExpr.to_sexpr(p);
    p.new_line(2);

    // Greater than or equal expression operations
    p.get_stream() << "Greater than or equal expression:\n";
    Ge_expr geExpr(&il, &il, &bt);
    p.get_stream() << "print: " << geExpr << '\n';
    p.get_stream() << "debug: \n";
    geExpr.debug(p);
    p.get_stream() << "s_expr: ";
    geExpr.to_sexpr(p);
    p.new_line(2);

    // Addition expression operations
    p.get_stream() << "Addition expression:\n";
    Add_expr addExpr(&il, &il, &it);
    p.get_stream() << "print: " << addExpr << '\n';
    p.get_stream() << "debug: \n";
    addExpr.debug(p);
    p.get_stream() << "s_expr: ";
    addExpr.to_sexpr(p);
    p.new_line(2);

    // Subtraction expression operations
    p.get_stream() << "Subtraction expression:\n";
    Sub_expr subExpr(&il, &il, &it);
    p.get_stream() << "print: " << subExpr << '\n';
    p.get_stream() << "debug: \n";
    subExpr.debug(p);
    p.get_stream() << "s_expr: ";
    subExpr.to_sexpr(p);
    p.new_line(2);

    // Multiplication expression operations
    p.get_stream() << "Multiplication expression:\n";
    Mul_expr mulExpr(&il, &il, &it);
    p.get_stream() << "print: " << mulExpr << '\n';
    p.get_stream() << "debug: \n";
    mulExpr.debug(p);
    p.get_stream() << "s_expr: ";
    mulExpr.to_sexpr(p);
    p.new_line(2);

    // Quotient expression operations
    p.get_stream() << "Quotient expression:\n";
    Quo_expr quoExpr(&il, &il, &it);
    p.get_stream() << "print: " << quoExpr << '\n';
    p.get_stream() << "debug: \n";
    quoExpr.debug(p);
    p.get_stream() << "s_expr: ";
    quoExpr.to_sexpr(p);
    p.new_line(2);

    // Remainder expression operations
    p.get_stream() << "Remainder expression:\n";
    Rem_expr remExpr(&il, &il, &it);
    p.get_stream() << "print: " << remExpr << '\n';
    p.get_stream() << "debug: \n";
    remExpr.debug(p);
    p.get_stream() << "s_expr: ";
    remExpr.to_sexpr(p);
    p.new_line(2);

    // Negate expression operations
    p.get_stream() << "Negate expression:\n";
    Neg_expr negExpr(&il, &it);
    p.get_stream() << "print: " << negExpr << '\n';
    p.get_stream() << "debug: \n";
    negExpr.debug(p);
    p.get_stream() << "s_expr: ";
    negExpr.to_sexpr(p);
    p.new_line(2);

    // Reciprocal expression operations
    p.get_stream() << "Reciprocal expression:\n";
    Rec_expr recExpr(&il, &it);
    p.get_stream() << "print: " << recExpr << '\n';
    p.get_stream() << "debug: \n";
    recExpr.debug(p);
    p.get_stream() << "s_expr: ";
    recExpr.to_sexpr(p);
    p.new_line(2);
}

// Complex expression operations
void complex_decl()
{
    Printer p(std::cout);

    p.get_stream() << "Printing complex declaration:\n";

    Name name("x");
    Int_type type;

    Int_lit operand1(2, &type);
    Int_lit operand2(2, &type);

    // 2 + 2;
    Add_expr add_expr(&operand1, &operand2, &type);

    // 2 - 2;
    Sub_expr sub_expr(&operand1, &operand2, &type);

    //(2 + 2) * (2 - 2)
    Mul_expr mult_expr(&add_expr, &sub_expr, &type);

    // var x = (2 + 2) * (2 - 2)
    Var_decl decl(&name, &type, &mult_expr);
    p.get_stream() << "print: " << decl << "\ns_expr: ";
    decl.to_sexpr(p);
    p.new_line();
    decl.debug(p);
}

void nested_debug_printing()
{
    Bool_type bt;

    Bool_lit cierto(true, &bt);
    Bool_lit falso(false, &bt);

    And_expr andExpr(&cierto, &cierto, &bt);;

    // Create an OR expression
    Or_expr orExp(&andExpr, new Or_expr(&cierto, &falso, &bt), &bt);

    And_expr hardAnd(&orExp, new And_expr(&orExp, &cierto, &bt), &bt);

    Printer p(std::cout);

    // 2 levels deep
    p.get_stream() << "print: " << orExp;
    p.get_stream() << "\nsexpr: ";
    orExp.to_sexpr(p);
    p.get_stream() << "\ndebug:\n";
    orExp.debug(p);

    // 3 levels deep
    p.get_stream() << "\n\nprint: " << hardAnd;
    p.get_stream() << "\nsexpr: ";
    hardAnd.to_sexpr(p);
    p.get_stream() << "\ndebug:\n";
    hardAnd.debug(p);
}

void make_min()
{
    Type* b = new Bool_type();
    Type* z = new Int_type();
    Decl* p1 = new Var_decl(new Name("a"), z, new Int_lit(1, z));
    Decl* p2 = new Var_decl(new Name("b"), z, new Int_lit(2, z));

      // p1 < p2 ? p1 : p2
    Expr* expr = new Con_expr(
        new Lt_expr(new Id_expr(p1, z), new Id_expr(p2, z), b),
        new Id_expr(p1, z),
        new Id_expr(p2, z),
        z
    );

    std::vector<Stmt*> stmts;
    stmts.push_back(new Ret_stmt(expr));
    Stmt* body = new Block_stmt(&stmts);

    // Build the function type.
    std::vector<Type*> params;
    params.push_back(z);
    params.push_back(z);
    Type* f = new Fun_type(params, z);

    std::vector<Decl*> func_decl_parms;
    func_decl_parms.push_back(p1);
    func_decl_parms.push_back(p2);
    Func_decl* fundecl =  new Func_decl(new Name("min"), &func_decl_parms, f, body);

    Printer p(std::cout);
    p.new_line(2);
    p.get_stream() << "Printing function:\n\n" << *fundecl;
    p.new_line();
    p.print_string("\nPrinting function sexpr:\n\n");
    fundecl->to_sexpr(p);
    p.print_string("\n\nPrinting function debugging:\n\n");
    p.new_line();
    fundecl->debug(p);
}

void print_ref_decl()
{
    Printer p(std::cout);
    p.new_line(2);
    Int_type it = Int_type();
    Ref_decl* refDecl = new Ref_decl(new Name("foo"), new Int_type(), new Int_lit(1, &it));
    p.get_stream() << *refDecl;
    p.new_line(2);
    refDecl->to_sexpr(p);
    p.new_line(2);
    refDecl->debug(p);
}

void if_stmt()
{
    Printer p(std::cout);
    p.new_line(2);
    Int_type it = Int_type();

    If_stmt* ifstmt = new If_stmt(
        new Lt_expr(new Int_lit(2, &it), new Int_lit(3, &it), &it),
        new Expr_stmt(new Int_lit(1, &it)),
        new Expr_stmt(new Int_lit(1, &it))
    );

    p.get_stream() << *ifstmt;
    p.new_line(2);
    ifstmt->debug(p);
    p.new_line(2);
    ifstmt->to_sexpr(p);
}

void while_stmt()
{
    Printer p(std::cout);
    p.new_line(2);
    Bool_type bt = Bool_type();

    While_stmt* whilestmt = new While_stmt(
        new Bool_lit(true, &bt),
        new Expr_stmt(new Bool_lit(false, &bt))
    );
    
    p.get_stream() << *whilestmt;
    p.new_line(2);
    whilestmt->debug(p);
    p.new_line(2);
    whilestmt->to_sexpr(p);
    p.new_line(2);
}


void identifier_if_stmt()
{
    Int_type it = Int_type();
    Bool_type bt = Bool_type();

    Decl_stmt* x = new Decl_stmt(new Var_decl(
        new Name("x"),
        &it,
        new Add_expr(
            new Int_lit(1, &it),
            new Int_lit(1, &it),
            &it
        )
    ));
    // if (x < 2) then true; else false;

    If_stmt* ifstmt = new If_stmt(
        new Lt_expr(
            new Id_expr(
                x->get_decl(),
                &it
            ),
            new Int_lit(2, &it),
            &it
        ),
        new Expr_stmt(new Bool_lit(false, &bt)),
        new Expr_stmt(new Bool_lit(true, &bt))
    );

    Printer p(std::cout);
    p.new_line(2);
    x->debug(p);
    p.new_line(2);
    x->print(p);
    p.new_line(2);
    x->to_sexpr(p);
    p.new_line();
    p.new_line(2);
    ifstmt->debug(p);
    p.new_line(2);
    ifstmt->print(p);
    p.new_line(2);
    ifstmt->to_sexpr(p);
    p.new_line();
}

// Recursive implementation
void factorial()
{
    Printer p(std::cout);
    p.new_line(2);
    Int_type* it = new Int_type();

    int factSize = 10;

    Var_decl* n = new Var_decl(
        new Name("n"), 
        it, 
        new Int_lit(10, it)
    );

    Func_decl* fact = new Func_decl(new Name("fact"), nullptr, nullptr, nullptr);

    fact = new Func_decl(
        new Name("fact"),
        new std::vector<Decl*> { new Var_decl(new Name("n"), it, new Int_lit(10, it))},
        it,
        new Block_stmt(
            new std::vector<Stmt*>{
                new If_stmt(
                    new Gt_expr(
                        new Id_expr(n, it),
                        new Int_lit(0, it),
                        it
                    ),
                    new Ret_stmt(
                        new Mul_expr(
                            new Id_expr(n, it),
                            new Call_expr(
                                new std::vector<Expr*>{
                                    new Id_expr(fact, it),
                                    new Sub_expr(
                                        new Id_expr(n, it),
                                        new Int_lit(1, it),
                                        it
                                    )
                                },
                                it
                            ),
                            it
                        )
                    ),
                    new Ret_stmt(
                        new Int_lit(1, it)
                    )
                )
            }
        )
    );
    p.new_line(2);
    fact->print(p);;
    p.new_line(2);
    fact->debug(p);
    p.new_line(2);
    fact->to_sexpr(p);
}
