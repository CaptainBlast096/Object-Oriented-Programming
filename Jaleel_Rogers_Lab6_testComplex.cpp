/***************************************************************************
 * Title:               Lab 6 testComplex
 * Author:              Jaleel Rogers
 * Email:               jrogers1239@floridapoly.edu
 * Creation date:       07/07/2022 @ 4:00 PM
 * Modification date:   07/07/2022 @ 10:37 PM
 * Description: Write a test program (testComplex.cpp) that:
1) Creates a Jaleel_Rogers_Lab6_Complex object with no-arg constructor.
2) Change real and imaginary part of the first object with 2.4 and 4.1, respectively.
3) Create another Jaleel_Rogers_Lab6_Complex object using the user-defined constructor with real 3.2 and
imaginary -3.6.
4) Call the addition function from the first object with providing the second Jaleel_Rogers_Lab6_Complex
object as an argument. Print the result using the printComplex function.
5) Call the additionTwo function by providing the first and second objects as
arguments. Print the result using the printComplex function.
6) Create an array of Jaleel_Rogers_Lab6_Complex objects with at least four Jaleel_Rogers_Lab6_Complex numbers. Call the
additionArray function by providing the array and size of the array as arguments.
(you shouldn’t provide the size if you work with a vector). You are required to use
either addition method of the class or additionTwo function to calculate the sum of
Jaleel_Rogers_Lab6_Complex objects. Print the result using the printComplex function.
 * ***************************************************************************/
#include "Jaleel_Rogers_Lab6_Complex.h"

Jaleel_Rogers_Lab6_Complex additionTwo (Jaleel_Rogers_Lab6_Complex &comp1, Jaleel_Rogers_Lab6_Complex &comp2) // Decided to putt additionTwo and additionArray in testComplex
                                                    // Returns the sums of two complex numbers called math
{
    double realAddition = comp1.getReal() + comp2.getReal();
    double imgAddition = comp1.getImg() + comp2.getImg();

    Jaleel_Rogers_Lab6_Complex math (realAddition, imgAddition);
    return math;
}

Jaleel_Rogers_Lab6_Complex additionArray (Jaleel_Rogers_Lab6_Complex complexArray[], int size) // Returns the sum of an array of the complex numbers as objects called math
{
    Jaleel_Rogers_Lab6_Complex math;
    for (int i = 0; i < size; i++)
    {
        math = additionTwo(math, complexArray[i]); // Using "math" within the function tell me the location from
                                                    //where the program will find the array
    }
    return math;
}
int main() // Output should be located in testComplex
{
    Jaleel_Rogers_Lab6_Complex math1;
    // Construct with no argument

    math1.setReal(2.4);
    math1.setImg(4.1);
    //First object, set real number to 2.4 and imaginary number to 4.1


    Jaleel_Rogers_Lab6_Complex math2;
    math2.setReal(3.2);
    math2.setImg(-3.6);
    //Second object, set real number to 3.2 and imaginary number to -3.6

    Jaleel_Rogers_Lab6_Complex addition = math1.addition(math2);
    //Calling the addition function from first object with second Jaleel_Rogers_Lab6_Complex object as an argument

    addition.printComplex();
    //Print the result using the printComplex function;

    Jaleel_Rogers_Lab6_Complex addingTwoObjects = additionTwo (math1, math2);
    // Adds the two objects together
    // Calls additionTwo

    addingTwoObjects.printComplex();
    //Prints the results of "addingTwoObjects

    Jaleel_Rogers_Lab6_Complex array[] = {Jaleel_Rogers_Lab6_Complex (-1, 2), Jaleel_Rogers_Lab6_Complex (2, -3), Jaleel_Rogers_Lab6_Complex (3, -4), Jaleel_Rogers_Lab6_Complex (4, 5)};
    // Creating the array of four complex numbers.

    Jaleel_Rogers_Lab6_Complex addArray = additionArray(array, 4);
    // The array of four objects contain complex numbers

    addArray.printComplex();
    //Prints the results of "addArray"
}