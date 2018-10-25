#pragma once

#include <iostream>

class Expr;

#define TAB "    " // 4 Spaces

// Class that handles printing to ostream.
class Printer 
{
public:
    Printer(std::ostream& os);
    /// Constructs a printer from the ostream.

    std::ostream& get_stream() { return m_os; }
    /// Returns the underlying ostream.

    void indent() { m_tabs++; }
    /// Increases the amount of tabs.

    void undent() { m_tabs--; }
    /// Reduces the amount of tabs.

    void new_line();
    /// Prints a new line.

    void new_line(int n);
    /// Prints n amount of lines.

    void print_tabs();
    /// Prints as many tabs as the value of m_tabs.

    void print_string(char const* str);
    /// Prints the given string.

    void print_address(void const* ptr);
    /// Prints the given arguments address.

    void debug_address(Expr const* e, char const* kind);

private:
    int m_tabs;
    /// Represents the current number of indentation.

    std::ostream& m_os;
    /// The underlying ostream that the printer prints to.
};

inline
Printer::Printer(std::ostream& os) 
    : m_os(os), m_tabs() 
{ }