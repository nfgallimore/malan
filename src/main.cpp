#include <iostream>

#include "type.hpp"
#include "expr.hpp"
#include "decl.hpp"
#include "name.hpp"

void types();
void exprs();

int main(int argc, char** argv)
{
    types();
    exprs();
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

    // Logical and operations
    std::cout << "Logical and:\n";
    Logical_and andExp(&bl, &bl, &bt);
    std::cout << "print: " << andExp << '\n';
    andExp.debug(std::cout << "debug: ");
    andExp.to_sexpr(std::cout << "s_expr: ");
    std::cout << "\nevaluate: " << andExp.evaluate().get_bool() << "\n\n";
}