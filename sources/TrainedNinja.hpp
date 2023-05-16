#pragma once
#include "Character.hpp"
#include "Ninja.hpp"

using namespace std;

namespace ariel
{
    class TrainedNinja : public Ninja
    {
    public:
        TrainedNinja(string name, Point const &location) : Ninja(std::move(name), location, HUNDRED20, TWELVE) {}
    };
}