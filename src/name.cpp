#include "name.hpp"

void 
Name::print(std::ostream& os) const
{
    os << m_name;
}

std::ostream& 
operator<<(std::ostream& os, Name const& n) 
{
    n.print(os);
    return os;
}
