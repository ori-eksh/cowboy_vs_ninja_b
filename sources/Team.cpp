#include "Team.hpp"

namespace ariel
{
    void Team::add(Character *toAdd)
    {
        if (participants >= 10)
        {
            throw runtime_error("A team can have at most 10 teammates");
        }
        if (toAdd->getIfPlayed() == true)
        {
            throw runtime_error("you cant Appointing the same captain to different teams");
        }
        if (participants < 10 && toAdd->isAlive() == true)
        {
            Members.emplace_back(toAdd);
            this->participants++;
            toAdd->startPlay();
        }
        return;
    }

    void Team::attack(Team *otherTeam)
    {

        return;
    }

    int Team::stillAlive()
    {
        int countAlive = 0;
        for (auto member : Members)
        {
            if (member->isAlive() == true)
                countAlive++;
        }
        return countAlive;
    }

    void Team::print()
    {
        for (auto member : Members)
        {
            member->print();
        }
        return;
    }

}