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
    /************************************************************************************************************************/
    void Team::attack(Team *otherTeam)
    {
        if (otherTeam == nullptr)
        {
            throw invalid_argument("you cant sending nullptr to the attack() method");
        }

        if (otherTeam->stillAlive() <= 0 || stillAlive() <= 0) // if everyone in this team tead
        {
            throw runtime_error("cant fight with dead people");
        }

        if (chief->isAlive() == false) // if the chief is dead
        {
            double min_dis = 999999;
            Character *firs_chief = chief;
            for (auto member : Members)
            {
                if (firs_chief->distance(member) < min_dis && member->isAlive() == true)
                {
                    chief = member;
                    min_dis = firs_chief->distance(member);
                }
            }
        }

        double min_victim = 999999;
        Character *victim;
        for (auto member : otherTeam->Members) // choos victim
        {
            if ((chief->distance(member) < min_victim) && (member->isAlive() == true))
            {
                victim = member;
                min_victim = chief->distance(member);
            }
        }

        for (auto member : Members) // the attack of cowboy
        {
            Cowboy *cowPtr = dynamic_cast<Cowboy *>(member); // its cowboy

            if (cowPtr != nullptr && cowPtr->isAlive() == true && victim->isAlive() == true)
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

            if (victim->isAlive() == false)
            {
                if (otherTeam->stillAlive() == 0 || stillAlive() == 0)
                {
                    return;
                }
                double min_victim2 = 999999;

                for (auto member : otherTeam->Members) // choos new victim
                {
                    if ((chief->distance(member) < min_victim2) && (member->isAlive() == true))
                    {
                        victim = member;
                        min_victim2 = chief->distance(member);
                    }
                }
            }
        }

        for (auto member : Members) // the attack of ninja
        {
            Ninja *Ninjaptr = dynamic_cast<Ninja *>(member); // its ninja
            if (Ninjaptr != nullptr && Ninjaptr->isAlive() == true && victim->isAlive() == true)
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
                if (otherTeam->stillAlive() == 0 || stillAlive() == 0)
                {
                    return;
                }
                double min_victim3 = 999999;

                for (auto member : otherTeam->Members) // choos new victim
                {
                    if ((chief->distance(member) < min_victim3) && (member->isAlive() == true))
                    {
                        victim = member;
                        min_victim3 = chief->distance(member);
                    }
                }
            }
        }
    }
    /************************************************************************************************************************/
    int Team::stillAlive()
    {
        int countAlive = 0;
        for (auto member : Members)
        {
            if (member->isAlive() == true)
            {
                countAlive++;
            }
        }
        return countAlive;
    }

    void Team::print()
    {

        for (auto member : Members)
        {
            Ninja *Ninjaptr = dynamic_cast<Ninja *>(member);
            if (Ninjaptr != nullptr)
            {
                member->print();
            }
        }

        for (auto member : Members)
        {
            Character *Charatptr = dynamic_cast<Character *>(member);
            if (Charatptr != nullptr)
            {
                member->print();
            }
        }
        return;
    }

}