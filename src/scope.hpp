#pragma once

#include "decl.hpp"
#include "name.hpp"

#include <string>
#include <vector>
#include <unordered_map>

struct Scope : public std::unordered_map<std::string, Decl*>
{
    Decl* lookup(Name name)
    {
        auto iter = find(name.get_str());
        if (iter == end())
        {
            return nullptr;
        }
        return iter->second;
    }

    void declare(Decl* d)
    {
        assert(!already_declared(d));
        emplace(d->get_name()->get_str(), d);
    }

    bool already_declared(Decl* d)
    {
        return d->get_name() != nullptr;
    }
};

struct Scope_stack : public std::vector<Scope>
{
    Decl* lookup(Name name)
    {
        for (auto iter = rbegin(); iter != rend(); ++iter)
        {
            if (Decl * d = iter->lookup(name.get_str()))
            {
                return d;
            }
        }
        return nullptr;
    }
};
