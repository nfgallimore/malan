#pragma once

#include <string>

class Name
{
public:
    Name(std::string name) : m_name(name) { }
    std::string get_str() const { return m_name; }
    void print(std::ostream& os) const;
    
private:
    std::string m_name;
};

std::ostream& operator<<(std::ostream& os, Name const& n);

inline void
print(std::ostream& os, Name const& n)
{
    n.print(os);
};