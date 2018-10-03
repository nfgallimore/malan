#pragma once

#include <string>

class Name
{
public:
    Name(std::string name) : m_name(name) { }
    std::string get_str() const { return m_name; }
private:
    std::string m_name;
};