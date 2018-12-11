#include "builder.hpp"
#include "type.hpp"

Type*
Builder::get_reference_type(Type* t)
{
    return new Ref_type(t);
}

Type*
Builder::get_function_type(std::vector<Type*> const& ts)
{
    return new Fun_type(ts, ts[0]);
}

Type*
Builder::get_function_type(std::vector<Decl*> const& parms, Type* ret_type)
{
    std::vector<Type*> ts;
    for (auto parm : parms)
    {
        ts.push_back(parm->get_type());
    }
    return new Fun_type(ts, ret_type);
}
