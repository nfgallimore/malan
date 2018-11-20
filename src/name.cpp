#include "name.hpp"

void 
Name::print(Printer& p) const
{
    p.get_stream() << m_name;
}

std::ostream& operator<<(std::ostream& os, Name const& n) 
{
    Printer p(os);
    n.print(p);
    return p.get_stream();
}
