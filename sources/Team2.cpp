#include "Team2.hpp"

namespace ariel
{
    void Team2::attack(Team *otherTeam)
    {

        if (otherTeam == nullptr)
        {
            throw invalid_argument("you cant sending nullptr to the attack() method");
        }

        if (otherTeam->stillAlive() <= 0 || stillAlive() <= 0) // if everyone in this team tead
        {
            return;
        }

        if (Character::this->getChief().isAlive() == false) // if the chief is dead
        {
            double min_dis = 99999;
            for (auto member : Members)
            {
                if (chief->distance(member) < min_dis && member->isAlive() == true)
                {
                    chief = member;
                    min_dis = chief->distance(member);
                }
            }
        }

        double min_victim = 99999;
        Character *victim;
        for (auto member : otherTeam->Members) // choos victim
        {
            if ((chief->distance(member) < min_victim) && (member->isAlive() == true))
            {
                victim = member;
                min_victim = chief->distance(member);
            }
        }

        for (auto member : Members) // the attack
        {
            Cowboy *cowPtr = dynamic_cast<Cowboy *>(member); // its cowboy

            if (cowPtr != nullptr && cowPtr->isAlive() == true)
            {
                if (cowPtr->getAmountOfBalls() > 0)
                {
                    cowPtr->shoot(victim);
                }
                else
                {
                    cowPtr->reload();
                }
            }

            Ninja *Ninjaptr = dynamic_cast<Ninja *>(member); // its ninja
            if (Ninjaptr != nullptr && Ninjaptr->isAlive() == true)
            {
                if (Ninjaptr->distance(victim) > 1)
                {
                    Ninjaptr->move(victim);
                }
                else
                {
                    Ninjaptr->slash(victim);
                }
            }

            if (victim->isAlive() == false)
            {
                if (otherTeam->stillAlive() == 0)
                {
                    return;
                }
                for (auto member : otherTeam->Members) // choos new victim
                {
                    min_victim = 99999;
                    if ((chief->distance(member) < min_victim) && (member->isAlive() == true))
                    {
                        victim = member;
                        min_victim = chief->distance(member);
                    }
                }
            }
        }
    }

    void Team2::print()
    {
        return;
    }
}