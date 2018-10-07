#pragma once

#include <iostream>

class Expr;

class Printer 
{
public:
    Printer(std::ostream& os) 
        : m_os(os), m_tabs() 
    { }
    std::ostream& get_stream() { return m_os; }
    void indent() { m_tabs++; }
    void undent() { m_tabs--; }
    void new_line();
    void new_line(int n);
    void print_tabs();
    void print_string(char const* str);
    void print_address(void const* ptr);
private:
    int m_tabs;
    std::ostream& m_os;
};