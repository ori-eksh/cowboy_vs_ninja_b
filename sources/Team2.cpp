#include "Team2.hpp"
namespace ariel
{
    void Team2::attack(Team *otherTeam)
    {
        if (otherTeam == nullptr)
        {
            throw invalid_argument("you cant sending nullptr to the attack() method");
        }
        return;
    }

    void Team2::print()
    {
        return;
    }
}