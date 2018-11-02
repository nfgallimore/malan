#include "builder.hpp"
#include "name.hpp"

Name*
Builder::make_name(std::string name)
{
    return new Name(name);
}
