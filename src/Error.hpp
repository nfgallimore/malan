#include <string>

using std::string;

class Error
{
public:
    Error(string str) : m_str(str) { }
    /// Constructs an error message with the given string

private:
    string m_str;
};

// Throws a logic error exception with the error message
void Type_err(std::string str)
{
    throw std::logic_error(str);
}