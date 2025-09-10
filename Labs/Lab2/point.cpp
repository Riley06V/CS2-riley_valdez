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
    //Brute force method to find nearestpoint on geeksforgeeks.org
    float min;
    for (int i = 0; i < arrSize; ++i) {
        for (int j = i + 1; j < arrSize; ++j) {
            if (distPoints(pointList[i]) < min) {
                min = distPoints(pointList[i]);
                return min;
            }
            else {
                return nullptr;
            }
        }
    }
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