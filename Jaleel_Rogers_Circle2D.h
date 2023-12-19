/*
1) Two private double data fields named x and y that specify the center of the circle with constant get functions.
2) A double data field radius with a constant get function.
3) A static int data field numberOfCircles with a static get function getNumberOfCircles().
4) A constructor that creates a circle with the specified x, y, and radius.
5) A copy constructor Jaleel_Rogers_Circle2D(const Jaleel_Rogers_Circle2D & circle) that creates a circle with a given Jaleel_Rogers_Circle2D object.
6) A destructor that updates numberOfCircles data field.
7) A constant function overlaps(const Jaleel_Rogers_Circle2D& circle) that returns true if the specified circle overlaps with this circle. See Figure 1
 */
#ifndef LAB07_JALEEL_ROGERS_CIRCLE2D_H
#define LAB07_JALEEL_ROGERS_CIRCLE2D_H

class Jaleel_Rogers_Circle2D
{
private:
    double x,y,radius; // 1) Two private double data fields named x & y that specify the center of the circle & 2) A double data field radius
    int static numberOfCircles; // 3) int numberOfCircles

public:
    // 1) - 3) constant get functions
    double const getX(); //Need '()' because they will be returning a value
    double const getY();
    double const getRadius();
    int static getNumberOfCircles();


    Jaleel_Rogers_Circle2D(double newX, double newY, double newRadius); // 4) A constructor that creates a circle with the specified x,y, and radius

    Jaleel_Rogers_Circle2D(const Jaleel_Rogers_Circle2D &circle); // 5) A copy constructor Jaleel_Rogers_Circle2D(const Jaleel_Rogers_Circle2D & circle)
    // The copy constructor is used to initialize the members of a newly created object by copying the members of an already existing object.

    ~Jaleel_Rogers_Circle2D(); // 6) A destructor

    bool const overlaps(const Jaleel_Rogers_Circle2D &circle); // 7) A constant function overlaps(const Jaleel_Rogers_Circle2D& circle)
};

#endif