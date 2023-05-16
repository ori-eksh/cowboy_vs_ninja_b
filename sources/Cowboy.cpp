#include "Cowboy.hpp"

using namespace std;
// ori
namespace ariel
{
    void Cowboy::shoot(Character *target)
    {
        if (target->isAlive() == false || this->isAlive() == false)
        {
            throw runtime_error("Dead characters cannot attack and characters cannot attack a dead enemy");
        }

        if (this == target)
        {
            throw runtime_error("No self harm");
        }

        if (amountOfBalls > 0)
        {
            target->hit(10);
            amountOfBalls -= 1;
        }
        return;
    }

    bool Cowboy::hasboolets()
    {
        if (amountOfBalls > 0)
        {
            return true;
        }
        return false;
    }

    void Cowboy::reload()
    {
        if (this->isAlive() == false)
        {
            throw runtime_error("Dead cowboy can not reload");
        }
        amountOfBalls = 6;
        return;
    }

    string Cowboy::print()
    {
        if (this->isAlive() == true)
        {

            string toStringAlive = "C: " + this->getName() + "\n" +
                                   "HitPoints: " + to_string(this->getHitPoints()) +
                                   "\n" + "location: " + this->getLocation().print();
            return toStringAlive;
        }

        string toStringDead = "C: (" + this->getName() + ")\n" +
                              "location: " + this->getLocation().print();
        return toStringDead;
    }
    int Cowboy::getAmountOfBalls() { return amountOfBalls; }

}