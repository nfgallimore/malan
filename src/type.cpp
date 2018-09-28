#include "type.hpp"

#include <iostream>

static void
print_str(std::ostream& os, char const* str)
{
  os << str;
}

static void
print_ref(std::ostream& os, Ref_type const* t)
{
  os << "ref " << *t->get_referent_type();
}

static void
print_fun(std::ostream& os, Fun_type const* t)
{
  auto params = t->get_params();
  if (params.empty()) 
    os << "() -> " << *t->get_return_type();

  else 
  {
    os << "(";
    for (int i = 0; i < params.size(); i++) 
    {
      if (i == params.size() - 1) 
        os << *params[i] << ")";
      else 
        os << *params[i] << ",";
    }
    os << " -> " << *t->get_return_type();
  }
}

void
print(std::ostream& os, Type const* t)
{
  switch (t->get_kind()) {
  case Type::bool_type:
    return print_str(os, "bool");
  
  case Type::int_type:
    return print_str(os, "int");
  
  case Type::ref_type:
    return print_ref(os, static_cast<Ref_type const*>(t));

  case Type::fun_type:
    return print_fun(os, static_cast<Fun_type const*>(t));
  }
}

std::ostream&
operator<<(std::ostream& os, Type const& t)
{
  print(os, &t);
  return os;
}

static bool
equal_ref(Ref_type const* a, Ref_type const* b)
{
  return equal(a->get_referent_type(), b->get_referent_type());
}

static bool
equal_fun(Fun_type const* a, Fun_type const* b)
{
  auto a_params = a->get_params();
  auto b_params = b->get_params();

  if (a_params.size() != b_params.size())
    return false;

  for(int i = 0; i < a->get_params().size(); i++) {
    if (!equal(a_params[i], b_params[i]))
      return false;
  }

  return (equal(a->get_return_type(), b->get_return_type()));
}

bool
equal(Type const* a, Type const* b)
{
  // Different kinds of types are not equal.
  if (a->get_kind() != b->get_kind())
    return false;

  // Compare similar types.
  switch (a->get_kind()) {
  case Type::bool_type:
    return true;
  
  case Type::int_type:
    return true;
  
  case Type::ref_type:
    return equal_ref(static_cast<Ref_type const*>(a), 
                     static_cast<Ref_type const*>(b));

  case Type::fun_type:
    return equal_fun(static_cast<Fun_type const*>(a),
                     static_cast<Fun_type const*>(b));
  }
}
