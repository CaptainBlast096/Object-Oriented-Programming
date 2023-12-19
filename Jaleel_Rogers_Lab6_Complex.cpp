/***************************************************************************
 * Title:               Lab 6 Jaleel_Rogers_Lab6_Complex
 * Author:              Jaleel Rogers
 * Email:               jrogers1239@floridapoly.edu
 * Creation date:       07/07/2022 @ 4:00 PM
 * Modification date:   07/07/2022 @ 10:37 PM
 * Description:
 * In this lab, you must separate your class definition from its implementation. Design a
class named Jaleel_Rogers_Lab6_Complex that contains:

1) A double data field (private) named real for the real part of a complex number.
2) A double data field (private) named img for the imaginary part of a complex
number.
3) A no-arg constructor that creates a default complex number with real 0.0 and
img 0.0.
4) The accessor and mutator functions for real and img.
5) A user-defined constructor that creates a complex object with given two data
fields.
6) A method of the class (inside of the class) named printComplex that prints the
given complex number on the console. (3 + 4i or 2 – 8i, etc.)

void printComplex ()
7) A method of the class (inside of the class) named addition returns the sum of
two complex numbers.
Jaleel_Rogers_Lab6_Complex addition (Jaleel_Rogers_Lab6_Complex &comp)
Hint: You must call the function with a complex object in the main function.
Therefore, you only need to provide the second object as an argument.

8) A function (outside of the class) named additionTwo returns the sum of two
complex numbers.

Jaleel_Rogers_Lab6_Complex additionTwo (Jaleel_Rogers_Lab6_Complex &comp1, Jaleel_Rogers_Lab6_Complex &comp2)

Hint: Because this function is not defined and implemented inside of the class,
you should provide two complex numbers.

9) A function (outside of the class) named additionArray returns the sum of an
array of Jaleel_Rogers_Lab6_Complex objects. You are also allowed to use vector of complex
numbers instead.

Jaleel_Rogers_Lab6_Complex additionArray (Jaleel_Rogers_Lab6_Complex complexArray[ ], int size)
 * ***************************************************************************/
#include "Jaleel_Rogers_Lab6_Complex.h" // Important
#include <iostream> // Connects the header file to this file
#include <iomanip> // Allows me to modify the output like controlling the decimal place
                // Have to use "::" since its modifying output
Jaleel_Rogers_Lab6_Complex::Jaleel_Rogers_Lab6_Complex() : real (0.0), img (0.0) // No argument constructor
{
// a double data field privated names real for complex and img for imaginary numbers along with a class called complex with no args
}
Jaleel_Rogers_Lab6_Complex::Jaleel_Rogers_Lab6_Complex(double newReal, double newImg) : real (newReal), img (newImg) // User-defined constructor
// I originally had Jaleel_Rogers_Lab6_Complex::Jaleel_Rogers_Lab6_Complex(double real, double img) : real (real), img (img)
    //Becuase I had the variable assigned to another variable that has the exact name to itself the first 2 sets
    //of  numbers were 0 due to the alloted values being zero

    //Because I changed the assigned value as a different named variable it was able to see the difference and
    // have a different data set inside of it
{

}

void Jaleel_Rogers_Lab6_Complex::printComplex() // A method that prints the statements
{
    std::cout << std::setprecision(1) << std::fixed;
    //setprecision - Sets decimal format
    //fixed - Floating point values will have a set format, ensuring everything looks consistent
    std::cout << real << " ";

    if (img < 0)
    {
        std::cout << " - " << -img << "i" << std::endl; // Makes img into a negative
    }
    else
    {
        std::cout << " + " << img << "i" << std::endl;
    }

}

Jaleel_Rogers_Lab6_Complex Jaleel_Rogers_Lab6_Complex::addition (Jaleel_Rogers_Lab6_Complex &comp) // User defined constructor containing two data fields
// Method inside the class named addition and returns the sum of two complex numbers
{
    double realAddition = real + comp.real; //&comp is being referenced and storing value
                                            // Like with the Circle &c object
    double imgAddition = img + comp.img; // Adds the default value and user define value

    Jaleel_Rogers_Lab6_Complex math (realAddition, imgAddition);
    return math;
}
// Mutators
void Jaleel_Rogers_Lab6_Complex::setReal(double newReal)
{
    real = newReal;
}

void Jaleel_Rogers_Lab6_Complex::setImg(double newImg)
{
    img = newImg;
}
// Accessors
double Jaleel_Rogers_Lab6_Complex::getReal()
{
    return real;
}

double Jaleel_Rogers_Lab6_Complex::getImg()
{
    return img;
}