#pragma once
#include "Character.hpp"
#include "Ninja.hpp"

using namespace std;

namespace ariel
{
    // the Special ninja
    class YoungNinja : public Ninja
    {
    public:
        YoungNinja(string name, Point const &location) : Ninja(std::move(name), location, HUNDRED, FORTEEN) {}
    };
}