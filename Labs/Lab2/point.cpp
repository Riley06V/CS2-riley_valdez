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
    return 0;
}

int points::Point::getY()
{
    return 0;
}

points::Point* points::Point::getNearestPoint()
{
    return nullptr;
}

points::Point* points::Point::calcNearestPoint(Point* pointList[], unsigned long arrSize)
{
    return nullptr;
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