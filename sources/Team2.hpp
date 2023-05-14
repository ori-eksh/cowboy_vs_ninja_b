#pragma once
#include "Cowboy.hpp"
#include "Ninja.hpp"
#include "Team.hpp"
#include <vector>

namespace ariel
{
    class Team2 : public Team
    {

    public:
        Team2(Character *chief) : Team(chief) {}
        void attack(Team *otherTeam);
        void print();
    };
}