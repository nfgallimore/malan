#include "builder.hpp"
#include "expr.hpp"
#include "type.hpp"

Type::Kind 
Builder::get_actual_kind(Expr* expr)
{
    if (expr->get_type()->get_kind() == Type::ref_type)
    {
        Ref_type* ref = static_cast<Ref_type*>(expr->get_type());
        return ref->get_ref_type()->get_kind();
    }
    return expr->get_type()->get_kind();
}

Type::Kind
Builder::get_actual_kind(Decl* decl)
{
    if (decl->get_type()->get_kind() == Type::ref_type)
    {
        Ref_type* ref = static_cast<Ref_type*>(decl->get_type());
        return ref->get_ref_type()->get_kind();
    }
    return decl->get_type()->get_kind();
}
