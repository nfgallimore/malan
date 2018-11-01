#include "builder.hpp"
#include "expr.hpp"
#include "type.hpp"

Type::Kind 
Builder::get_actual_kind(Expr* e1)
{
    if (e1->get_type()->get_kind() == Type::ref_type)
    {
        Ref_type* ref = static_cast<Ref_type*>(e1->get_type());
        return ref->get_ref_type()->get_kind();
    }
    return e1->get_type()->get_kind();
}