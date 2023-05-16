#include "Cowboy.hpp"

using namespace std;
// ori
namespace ariel
{
    void Cowboy::shoot(Character *target)
    {
        if (target->isAlive() == true && this->isAlive() == true && amountOfBalls > 0)
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