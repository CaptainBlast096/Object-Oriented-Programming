/***************************************************************************
 * Title:               Lab 7
 * Author:              Jaleel Rogers
 * Email:               jrogers1239@floridapoly.edu
 * Creation date:       11/03/2022 @ 12:30 PM
 * Modification date:   11/04/2022 @ 7:27 AM
 * Description: Write a test program (testComplex.cpp) that:
Write a test program (testCircle2D.cpp) that does the following:
1) Dynamically creates a Jaleel_Rogers_Circle2D object on the heap using the constructor with the
following arguments (2, 2, 5.5) and assigns the object address to the pointer pCir1.
2) Creates a Jaleel_Rogers_Circle2D object cir2(-6, -3, 1.5).
3) Calls getNumberOfCircles() function.
4) Creates a Jaleel_Rogers_Circle2D object cir3 with the copy constructor with the cir2 object as an
argument.
5) Calls getNumberOfCircles() function from the cir3.
6) Calls overlaps(const Jaleel_Rogers_Circle2D& circle) function from pCir1 pointer with the cir2 as an
argument.
7) Calls overlaps(const Jaleel_Rogers_Circle2D& circle) function from cir3 object with the cir2 as an
argument.
8) Frees the memory allocated dynamically.
9) Calls getNumberOfCircles() function.
 * ***************************************************************************/

//Name the files as the lab wants them when finished rename and refactor to make life less difficult
#include <iostream>
#include "Jaleel_Rogers_Circle2D.h" // Use the header file not the cpp file or else will get a runtime error caused by multiple definitions
using namespace std;
int main()
{
    Jaleel_Rogers_Circle2D *pCir1;
   pCir1 =  new Jaleel_Rogers_Circle2D(2, 2, 5.5);


cout << "pCir1 is created with center at (2,2) and radius of 5.5" <<endl;

    Jaleel_Rogers_Circle2D cir2(-6, -3, 1.5);
cout << "cir2 is created with center at (-6,-3) and radius of 1.5" <<endl;

cout << "The current number of circles is " << Jaleel_Rogers_Circle2D::getNumberOfCircles() << endl;

   Jaleel_Rogers_Circle2D cir3 = Jaleel_Rogers_Circle2D(cir2); // Better than  Jaleel_Rogers_Circle2D cir3 = cir2 because cir2 is never used
cout << "cir3 is copied from cir2 with center at (-6,3) and radius of 1.5" << endl;

cout << "The current number of circles is " << cir3.getNumberOfCircles() << endl;

cout <<"pCir1 overlaps cir2 = " << pCir1 ->overlaps(cir2) << endl; // The arrow operator is used to direct access members of a class using pointers

cout <<"Cir3 overlaps cir2 = " <<  cir3.overlaps(cir2) <<endl; //Since cir3 is not a pointer you would use the dot operator

delete pCir1; //Don't do this Jaleel_Rogers_Circle2 Jaleel_Rogers_Circle2D(pCir1);
cout << "pCir1's memory is freed" << endl;

cout << "The current number of circles is " << Jaleel_Rogers_Circle2D::getNumberOfCircles() << endl;

    return 0;
}
