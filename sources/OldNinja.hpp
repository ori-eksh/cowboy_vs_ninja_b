
#pragma once
#include "Character.hpp"
#include "Ninja.hpp"

using namespace std;

namespace ariel
{
    class OldNinja : public Ninja
    {
    public:
        OldNinja(string name, Point const &location) : Ninja(std::move(name), location, HUNDRED50, EIGHT) {}
        // ~OldNinja() override {}
    };
}