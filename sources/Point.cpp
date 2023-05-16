
#include "Point.hpp"

using namespace std;

namespace ariel
{
    double Point::distance(Point point2) const
    {
        double dx = x - point2.x;
        double dy = y - point2.y;
        return sqrt(dx * dx + dy * dy);
    }

    string Point::print()
    {
        return "(" + to_string(x) + ", " + to_string(y) + ")";
    }

}