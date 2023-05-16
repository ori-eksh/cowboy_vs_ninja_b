#pragma once
#include <string>
#include <cmath>
namespace ariel
{
    class Point
    {
    private:
        double x;
        double y;

    public:
        Point(double x_toInsert, double y_toInsert) : x(x_toInsert), y(y_toInsert) {}
        Point() : x(0.0), y(0.0) {}
        Point(const Point &other) : x(other.x), y(other.y) {}
        Point(Point &&other) noexcept : x((other.x)), y((other.y)) {}

        Point &operator=(const Point &other)
        {
            if (this != &other)
            {
                x = other.x;
                y = other.y;
            }
            return *this;
        }

        Point &operator=(Point &&other) noexcept
        {
            if (this != &other)
            {
                x = (other.x);
                y = (other.y);
            }
            return *this;
        }

        double distance(Point point2) const;

        double getX() const { return x; }
        double getY() const { return y; }

        std::string print();

        static Point moveTowards(const Point &from, const Point &target, double distance)
        {
            double dist = target.distance(from);

            if (dist <= distance)
            {
                // If the distance is already less than or equal to the given distance, return the target point
                return target;
            }

            // Calculate the ratio of the distance we want to move to the total distance between the points
            double ratio = distance / dist;

            // Calculate the new x and y coordinates of the point that is distance units away from the source point
            double newX = from.getX() + (target.getX() - from.getX()) * ratio;
            double newY = from.getY() + (target.getY() - from.getY()) * ratio;

            // Return a new Point object with the calculated coordinates
            return Point(newX, newY);
        }
        ~Point() {}
    };
}
