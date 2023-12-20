/***************************************************************************
 * Title:               Lab 5
 * Author:              Jaleel Rogers
 * Email:               jrogers1239@floridapoly.edu
 * Creation date:       10/25/2022 @ 6:10 PM
 * Modification date:   10/25/2022 @ 11:15 PM
 * Description: A header file that contains:
 *                  1) A double data field (private) named real for the real part of a complex number.
                    2) A double data field (private) named img for the imaginary part of a complex number.
                    3) A no-arg constructor that creates a default complex number with real 0 and img 0.
                    4) The accessor and mutator functions for real and img.
                    5) A user-defined constructor that creates a complex object with given two data fields.
                    6) A method (inside of the class) named printComplex that prints the given complex
                    number on the console. (3 + 4i or 2 – 8i, etc.)

                    void printComplex ()

                    7) A method (inside of the class) named addition returns the sum of two complex
                    numbers.

                    Complex addition (Complex & comp)

                    Hint: You must call the function with a complex object in the main function. Therefore,
                    you only need to provide the second object as an argument.


                    8) A method (outside of the class) named additionTwo returns the sum of two complex
                    numbers.

                    Complex additionTwo (Complex & comp1, Complex & comp2)

                    Hint: Because this function is not defined and implemented inside of the class, you
                    should provide two complex numbers.

                    9) A method (outside of the class) named additionArray returns the sum of an array of
                    Complex objects.
 **************************************************************************/
#ifndef LAB05_JALEEL_ROGERS_LAB5_COMPLEX_H
#define LAB05_JALEEL_ROGERS_LAB5_COMPLEX_H

#include <iostream>
using namespace std;

class Jaleel_Rogers_Lab5_Complex
{
private:

    double real; //1) real number
    double img; //2) imaginary number
public:
    //Constructors
    Jaleel_Rogers_Lab5_Complex(); //Default constructor
    Jaleel_Rogers_Lab5_Complex(double newReal, double newImg); // 3) user-defined constructor | Declarations go here not implementations

    //4) Asccessors and Mutators
    double const getReal();
    double const getImg();
    void setReal(double newReal);
    void setImg (double newImg);

    void printComplex(); //6)

    //Addition
    Jaleel_Rogers_Lab5_Complex addition(Jaleel_Rogers_Lab5_Complex & comp); //7) A method named addition returns the sum of two complex numbers
};
//Literally outside of the class
// additionTwo
Jaleel_Rogers_Lab5_Complex additionTwo(Jaleel_Rogers_Lab5_Complex & comp1, Jaleel_Rogers_Lab5_Complex & comp2); //8) Returns sum of two complex numbers
//additionArray
Jaleel_Rogers_Lab5_Complex additionArray (Jaleel_Rogers_Lab5_Complex complexArray[] , int size); //9) Returns sum of the array of Complex Objects

#endif //LAB05_JALEEL_ROGERS_LAB5_COMPLEX_H
