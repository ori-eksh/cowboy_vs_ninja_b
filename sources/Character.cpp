#include "Character.hpp"

using namespace std;

namespace ariel
{

    bool Character::isAlive()
    {
        if (hit_points > 0)
        {
            return true;
        }
        return false;
    }

    double Character::distance(Character *toCheckWith)
    {

        return (location.distance(toCheckWith->getLocation()));
    }

    void Character::hit(int num)
    {
        if (num < 0)
        {
            throw invalid_argument("you cant Sending negative value to hit()git");
        }
        hit_points = (hit_points - num);
        return;
    }

    string Character::getName()
    {
        return name;
    }

    Point Character::getLocation()
    {
        return location;
    }

    int Character::getHitPoints()
    {
        return this->hit_points;
    }
    void Character::setHitPoints(int pointToSet)
    {
        this->hit_points = pointToSet;
    }

}
//