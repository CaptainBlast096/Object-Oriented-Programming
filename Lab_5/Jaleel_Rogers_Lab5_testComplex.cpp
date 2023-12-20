/***************************************************************************
 * Title:               Lab 5
 * Author:              Jaleel Rogers
 * Email:               jrogers1239@floridapoly.edu
 * Creation date:       10/25/2022 @ 6:10 PM
 * Modification date:   10/25/2022 @ 11:15 PM
 * Description:       Output
 **************************************************************************/
#include "Jaleel_Rogers_Lab5_Complex.h" // Include the ehader file

int main()
{

    Jaleel_Rogers_Lab5_Complex comp1 = Jaleel_Rogers_Lab5_Complex(); //First object | default value
    cout << "c1 created with no-arg constructor = ";
    comp1.printComplex();
    cout << endl;

    //Set the values
    comp1.setReal(2.4);
    comp1.setImg(4.1);
    cout << "c1 real and imaginary parts changed = ";
    comp1.printComplex();
    cout << endl;


    cout << "c2 created using the user-defined constructor = ";
    Jaleel_Rogers_Lab5_Complex comp2 = Jaleel_Rogers_Lab5_Complex(3.2,-3.6); // Second object | user constructed
    comp2.printComplex();
    cout << endl;


    Jaleel_Rogers_Lab5_Complex comp3 = comp1.addition(comp2); //Third object | Complex1 + Complex2
    cout << "c3=c1.addition(c2) = ";
    comp3.printComplex();
    cout << endl;


    Jaleel_Rogers_Lab5_Complex comp4; //Fourth object | Complex2 + Complex3
    comp4 = additionTwo(comp2,comp3);
    cout << "c4 = additionTwo(c2,c3) = ";
    comp4.printComplex();
    cout << endl;


    Jaleel_Rogers_Lab5_Complex comp5[] = {Jaleel_Rogers_Lab5_Complex(1,1), Jaleel_Rogers_Lab5_Complex(2,2), Jaleel_Rogers_Lab5_Complex(3,3), Jaleel_Rogers_Lab5_Complex(4,4), Jaleel_Rogers_Lab5_Complex(5,5)};
    //Object 5 | Array format
    cout << "additionArray(carray, 5): ";
    for (Jaleel_Rogers_Lab5_Complex i : comp5) { i.printComplex(); cout << " + ";}


    // Sixth object |Adds array into the complex number
    Jaleel_Rogers_Lab5_Complex comp6 =Jaleel_Rogers_Lab5_Complex();
    comp6 = additionArray(comp5, 5);
    comp6.printComplex();
    cout << endl;

    return 0;
}
