#include <iostream>

#include "expr.hpp"

void print(std::ostream& os, Expr const* e) {

}

std::ostream&
operator<<(std::ostream& os, Expr const& e)
{
  print(os, &e);
  return os;
}