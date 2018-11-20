#pragma once

#include <string>
#include <iostream>

#include "printer.hpp"

// Represents the name of a declaration
class Name
{
public:
    Name(std::string name);
    /// Constructs a name from a string

    std::string get_str() { return m_name; }
    /// Gets the string form of the name

    void print(Printer& p) const;
    /// Prints the name to ostream
    
private:
    std::string m_name;
    /// String representation of the name
};

inline
Name::Name(std::string name) 
    : m_name(name) 
{ }


// Operators

std::ostream& operator<<(std::ostream& os, Name const& n);
/// Prints the name using the << operator
