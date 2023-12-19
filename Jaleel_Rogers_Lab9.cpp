/***************************************************************************
 * Title:               Lab 9
 * Author:              Jaleel Rogers
 * Email:               jrogers1239@floridapoly.edu
 * Creation date:       11/24/2022 @ 9:15 PM
 * Modification date:   11/26/2022 @ 5:50 PM
 * Description: Create a class named ThreeDPoint to model a point in a three-dimensional space.
    Let ThreeDPoint be derived from MyPoint with the following additional features:
        • A data field named z that represents the z-coordinate.
        • A no-arg constructor that constructs a point with coordinates (0, 0, 0).
        • A constructor that constructs a point with three specified coordinates.
        • A constant get function that returns the z value.
        • A constant distance(const MyPoint& p) function to return the distance between this point and the other point
            in the three-dimensional space using dynamic casting.

 * ***************************************************************************/

#include <iostream>
#include <cmath>

using namespace std;

class MyPoint
{

protected:
    //Modified the specifier for polymorphism
    //Variables in parent/base class
    double x;
    double y;
public:

    MyPoint()
    {
        x = y = 0; // y = 0 & x = y therefore x = 0
    }

    MyPoint(double x, double y)
    {
        this -> x = x;
        this -> y = y;
    }

    double getx() const
    {
        return x;
    }
    double gety() const
    {
        return y;
    }

    void setx(double x)
    {
        this -> x = x;
    }
    void sety(double y) {
        this -> y = y;
    }

    //Inheriting the distance function
    virtual double distance(const MyPoint & p2)
    {
        return sqrt((x - p2.x) * (x - p2.x) + (y - p2.y) * (y - p2.y));
    }

    friend istream & operator >> (istream & is, MyPoint & p);
    friend ostream & operator << (ostream & os,const MyPoint & p);
};


istream & operator >> (istream & is, MyPoint & p)
{
    cout << "please enter x y: ";
    is >> p.x >> p.y;
    return is;
}

ostream & operator << (ostream & os,const MyPoint & p)
{
    cout << "(x,y)=" << "(" << p.x << "," << p.y << ")";
    return os;
}

class ThreeDPoint: public MyPoint // class  <derived_class_name> : <access-specifier> <base_class_name>
{

private:
//Variables in child/derived class
    double z;

public:
    double getZ() const // Have in similar format as MyPoint in order to prevent any minor errors
    {
        return z;
    }

    //Three-arg constructor
    ThreeDPoint(double pX, double pY, double pZ) // Don't add the data type in the base class
    {
        x = pX;
        y = pY;
        z = pZ;
    }
    ThreeDPoint()
    {
        x= 0;
        y = 0;
        z = 0;
    }
    //Return the distance between this point and the other point in the three-dimensional space
    double distance(const MyPoint &p) const
    {
        const ThreeDPoint * point = dynamic_cast < const ThreeDPoint * > ( & p);

        if (point != nullptr)
        {
            return sqrt(pow((x - p.getx()), 2) + pow((y - p.gety()), 2) + pow((z - point -> getZ()), 2));
        }

        else
        {
            return sqrt(pow((x - p.getx()), 2) + pow((y - p.gety()), 2) + pow(z, 2));
        }
    }

    //Insertion and extraction operators for inherited class
    friend istream & operator >> (istream & is, ThreeDPoint &p);
    friend ostream & operator << (ostream & os,const ThreeDPoint &p);

};

//Need an insertion and extraction operator in this class too

istream & operator >> (istream & is, ThreeDPoint &p)
{
    cout << "please enter x y z: ";
    is >> p.x >> p.y >> p.z;
    return is;
}

ostream & operator << (ostream & os, const ThreeDPoint & p)
{
    cout << "(x,y,z)=" << "(" << p.getx() << "," << p.gety() << "," << p.getZ() << ")";
    return os;
}

int main()
{
    //Question 1
    cout << "1. Test the constructors of ThreeDPoint: " <<endl;
    cout << "1.1 Create ThreeDPoint object p1 with the no-arg constructor: " << endl;
    ThreeDPoint p1; //First object
    cout << "p1 is (x,y,z) = (" << p1.getx() << "," << p1.gety() << "," << p1.getZ() << ")" << endl;

    cout << "1.2 Create ThreeDPoint object p2 with the 3-args constructor: " <<endl;
    ThreeDPoint p2(10,30,25.5); //First object
    cout << "p2 is (x,y,z) = (" << p2.getx() << "," << p2.gety() << "," << p2.getZ() << ")" << endl;

    //Question 2
    cout << "2. Test the distance function:" << endl;
    cout << "The distance between p1 and p2 is " << p1.distance(p2) << endl;

    //Question 3
    cout << "3. Test the insertion and extraction operators:" << endl;

    cout <<"3.1 Create ThreeDPoint object p3 and p4 with no-arg constructor:" << endl;
    ThreeDPoint p3,p4;

    cout << "3.2 Use cin >> p3 to set p3's (x,y,z):" << endl;
    cout <<"For p3,";
    cin >> p3;

    cout <<"3.3 Use cout << p3 to print p3" <<endl;
    cout << "p3 is" << p3 << endl;

    cout <<"3.4 Use cin >> p4 to set p4's (x,y,z):" << endl;
    cout <<"For p4, ";
    cin >> p4;

    cout <<"3.5 Use cout << p4 to print p4" <<endl;
    cout << "p4 is" << p4 << endl;

    cout <<"3.6 Test the distance function:" <<endl;
    cout << "The distance between p3 and p4 is " << p3.distance(p4) << endl;

    //Question 4
    cout <<"4. Create ThreeDPoint p5 and MyPoint p6 using their no-arg constructors:" <<endl;
    ThreeDPoint p5;
    MyPoint p6;

    cout <<"4.1 Use >> to set p5 and p6, then use << to print p5 and p6:" <<endl;
    cout << "For p5,";
    cin >> p5;
    cout <<"For p6,";
    cin >> p6;
    cout << "p5 is " << p5 << "; " << "p6 is  " << p6<< endl;

    //Question5
    cout << "5. Test the polymorphism using p5.distance(p6):" <<endl;
    cout <<"The distance between p5 and p6 is " << p5.distance(p6);

    return 0;
}