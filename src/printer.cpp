#include <iostream>

#include "printer.hpp"

void
Printer::new_line()
{
    m_os << '\n';
}

void
Printer::new_line(int n)
{
    for (int i = 0; i < n; i++)
    {
        m_os << '\n';
    }
}

void
Printer::print_tabs()
{
    for (int i = 0; i < m_tabs; i++)
    {
        m_os << TAB;
    }
}

void
Printer::print_string(char const* str)
{
    m_os << str;
}

void
Printer::print_address(char const* kind, void const* ptr)
{
    print_tabs();
    m_os << kind << ' ' << ptr << '\n';
}
