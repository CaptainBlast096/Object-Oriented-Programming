#include "Jaleel_Rogers_Circle2D.h"
#include <cmath>



int Jaleel_Rogers_Circle2D::numberOfCircles = 0; // Initialized number of circles

// 1)-3)
 double const Jaleel_Rogers_Circle2D::getX()
{
    return x;
}

 double const Jaleel_Rogers_Circle2D::getY()
{
    return y;
}

 double const Jaleel_Rogers_Circle2D::getRadius()
{
    return radius;
}

 int Jaleel_Rogers_Circle2D::getNumberOfCircles() //Don't use static, simply need to provide the variable name
{
    return numberOfCircles;
}


// double Jaleel_Rogers_Circle2D::Jaleel_Rogers_Circle2D(double get_x, double get_y, double get_Radius); Don't reference constructor but make one


Jaleel_Rogers_Circle2D::Jaleel_Rogers_Circle2D(double newX, double newY, double newRadius) // Constructor
{
    x = newX;
    y = newY;
    radius = newRadius;
    numberOfCircles++;
}
//The dot (.) operator is used for direct member selection via object name. In other words, it is used to access the child object.
Jaleel_Rogers_Circle2D::Jaleel_Rogers_Circle2D(const Jaleel_Rogers_Circle2D &circle) // This would be an example of dynamic memory allocation | Copy Constructor
{
    x = circle.x;
    y = circle.y;
    radius = circle.radius;
    numberOfCircles++;
}
Jaleel_Rogers_Circle2D::~Jaleel_Rogers_Circle2D()
{
   numberOfCircles--;
}
 bool const Jaleel_Rogers_Circle2D::overlaps(const Jaleel_Rogers_Circle2D &circle)
{
    return  (sqrt(pow((x - circle.x),2) + pow(y - circle.y, 2))) < (radius + circle.radius); // Equation for position
    // Compares the position with the sum of both radii
}


