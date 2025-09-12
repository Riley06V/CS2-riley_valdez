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
    //return nullptr; Something other than null
    return nearestPoint;
}

points::Point* points::Point::calcNearestPoint(Point* pointList[], unsigned long arrSize)
{
    //PsuedoCode in plain english: In order to figure out which coordinate pair is, we have to go through
    //every index in the array of pointList[], use the distPoints on every single one, whichever is smallest is returned
    points::Point* closest = nullptr;
    closest = pointList[0];
    for (unsigned long i = 0; i < arrSize; i++) {
        distPoints(*pointList[i]);
        if(pointList[i]->nearestPoint > closest) {
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
}