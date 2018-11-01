#pragma once

#include <string>
#include <iostream>

using std::string;

// Class that represents all kinds of errors.
class Error
{
public:
    Error(string str) : m_str(str) { }
    /// Constructs an error message with the given string

    void static Type_err(string str);
    /// Prints an error to cerr with the error message.

private:
    string m_str;
};

inline void 
Error::Type_err(std::string str)
{
     std::cerr << str;
}
