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
    /// Handles the type checking error with provided error message.

    void static Eval_err(string str);
    /// Handles the evaluation error with provided error message.

private:
    string m_str;
};

inline void 
Error::Type_err(std::string str)
{
    throw std::runtime_error(str);
}

inline void
Error::Eval_err(std::string str)
{
    throw std::logic_error(str);
}
