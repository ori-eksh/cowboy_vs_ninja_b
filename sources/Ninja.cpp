#include "Ninja.hpp"

namespace ariel
{
    void Ninja::slash(Character *target)
    {
        if (target->isAlive() == false)
        {
            throw runtime_error("characters cannot attack a dead enemy");
        }
        if (this->isAlive() == false)
        {
            throw runtime_error("Dead characters cannot attack ");
        }
        if (this == target)
        {
            throw runtime_error("No self harm");
        }
        if ((this->getLocation().distance(target->getLocation())) <= 1)
        {
            target->hit(40);
        }
        return;
    }

    void Ninja::move(Character *target)
    {
        Point moveTo = Point::moveTowards(this->getLocation(), target->getLocation(), speed);
        this->setLocation(moveTo);
        return;
    }

    std::string Ninja::print()
    {

        if (this->isAlive() == true)
        {

            string toStringAlive = "N: " + this->getName() + "\n" +
                                   "HitPoints: " + to_string(this->getHitPoints()) +
                                   "\n" + "location: " + this->getLocation().print();
            return toStringAlive;
        }

        string toStringDead = "N: (" + this->getName() + ")\n" +
                              "location: " + this->getLocation().print();
        return toStringDead;
    }
    int Ninja::getSpeed() { return speed; }

}