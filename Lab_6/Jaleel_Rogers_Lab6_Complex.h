/***************************************************************************
 * Title:               Lab 6 testComplex
 * Author:              Jaleel Rogers
 * Email:               jrogers1239@floridapoly.edu
 * Creation date:       07/07/2022 @ 4:00 PM
 * Modification date:   07/07/2022 @ 10:37 PM
 * Description: Will contain the functions used in both files
 * ***************************************************************************/
#ifndef LAB_6_JALEEL_ROGERS_LAB6_COMPLEX_H // Added in automatically
#define LAB_6_JALEEL_ROGERS_LAB6_COMPLEX_H


class Jaleel_Rogers_Lab6_Complex
{
private:
    double real;
    double img;
public:
    Jaleel_Rogers_Lab6_Complex(); // No argument constructor |  put this information inside - double newReal =0.0, double newImg = 0.0
   // Don't add a body, wont correctly work in "Jaleel_Rogers_Lab6_Complex" File

    void setReal(double newReal);
    void setImg(double newImg);

    double getReal();
    double getImg();
   // Don't add a body
   // No return statement


    Jaleel_Rogers_Lab6_Complex(double newReal, double newImg); // User-defined method

    void printComplex();

    Jaleel_Rogers_Lab6_Complex addition (Jaleel_Rogers_Lab6_Complex &comp);

};
// Name outside of header - Jaleel_Rogers_Lab6_Complex additionTwo (Jaleel_Rogers_Lab6_Complex &comp1, Jaleel_Rogers_Lab6_Complex &comp2);
// Name outside of header - Jaleel_Rogers_Lab6_Complex additionArray (Jaleel_Rogers_Lab6_Complex complexArray[], int size);
#endif //LAB_6_JALEEL_ROGERS_LAB6_COMPLEX_H
