#include "point.h"

//Constructor
points::Point::Point(int X, int Y, points::Point* closestPoint)
{
    //Using private members from point.h
    x = X;
    y = Y;
    nearestPoint = closestPoint;
}
//Destructor
points::Point::~Point()
{
    delete nearestPoint;
}

//Getters
int points::Point::getX()
{
   // return 0; Something other than 0?
    return x;
}

int points::Point::getY()
{
   // return 0; Something other than 0
    return y;
}

points::Point* points::Point::getNearestPoint()
{
    //return nullptr; Maybe now randomized point
    return nearestPoint;
}

points::Point* points::Point::calcNearestPoint(Point* pointList[], unsigned long arrSize)
{
    //newly modified geekforgeeks brute force for program
    double minDistance = 0.0;
    points::Point* closest = 0; //nullptr

    for (unsigned long i = 0; i < arrSize; i++) {
        double dist = distance(pointList[i]->getX(), pointList[i]->getY());
        if (dist < minDistance) {
            minDistance = dist;
            closest = pointList[i];
        }
    }
    return closest;
}

//Setters
void points::Point::setX(int newVal)
{
    x = newVal;
}

void points::Point::setY(int newVal)
{
    y = newVal;
}

void points::Point::setNearestPoint(Point* newNearestPoint)
{
    nearestPoint = newNearestPoint;
}

double points::Point::distPoints(Point& point)
{
    //Formula using cmath sqrt function and some of the variables
    int xSub2 = x - point.getX();
    int ySub2 = y - point.getY();
    return sqrt((xSub2 * xSub2) + (ySub2 * ySub2));
    return 0.0;
}