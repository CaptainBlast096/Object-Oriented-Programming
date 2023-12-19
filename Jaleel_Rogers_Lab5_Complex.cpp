/***************************************************************************
 * Title:               Lab 5
 * Author:              Jaleel Rogers
 * Email:               jrogers1239@floridapoly.edu
 * Creation date:       10/25/2022 @ 6:10 PM
 * Modification date:   10/25/2022 @ 11:15 PM
 * Description: Implementing header file
 **************************************************************************/
#include "Jaleel_Rogers_Lab5_Complex.h"

Jaleel_Rogers_Lab5_Complex::Jaleel_Rogers_Lab5_Complex() //A deafult complex number with 0 for real and img
{
    real = 0;
    img = 0;
}

//Treat Complex like a regular class and implementation in one file but with the class and ::
Jaleel_Rogers_Lab5_Complex::Jaleel_Rogers_Lab5_Complex(double newReal, double newImg)
{
    real = newReal;
    img = newImg;
}

double const Jaleel_Rogers_Lab5_Complex::getReal()
        {
            return real;
        };


double const Jaleel_Rogers_Lab5_Complex::getImg()
{
    return img;
};

void Jaleel_Rogers_Lab5_Complex::setReal(double newReal)
{
    real = newReal;
}

void Jaleel_Rogers_Lab5_Complex::setImg(double newImg)
{
    img = newImg;
}

void Jaleel_Rogers_Lab5_Complex::printComplex()
{
    /*
   if (img < 0)
   {
       cout << " - " << -img << "i" << endl;
   }
   else
   {
       cout << " + " << img << "i" << endl;
   }
     */
    if(img!=0)
        cout << real << ((img>0)? "+":"") << img <<"i"; // If img is not equal to 0 print the real, if img is less than 0 add the + else space then img i | else jus the real number
    else
        cout << real; // Eaiser if a compact the if-else statment
}
Jaleel_Rogers_Lab5_Complex Jaleel_Rogers_Lab5_Complex::addition(Jaleel_Rogers_Lab5_Complex &comp)
{
    double realAddition = real + comp.real;
    double imgAddition = img + comp.img;
    return Jaleel_Rogers_Lab5_Complex(realAddition, imgAddition);
}

//Since its outside of the class, you do not have to reference class
Jaleel_Rogers_Lab5_Complex additionTwo(Jaleel_Rogers_Lab5_Complex & comp1, Jaleel_Rogers_Lab5_Complex & comp2)
{
    Jaleel_Rogers_Lab5_Complex addComplex = Jaleel_Rogers_Lab5_Complex();

    addComplex = addComplex.addition(comp1);
    addComplex = addComplex.addition(comp2);

    return addComplex;
}

Jaleel_Rogers_Lab5_Complex additionArray(Jaleel_Rogers_Lab5_Complex complexArray[] , int size)
{
    Jaleel_Rogers_Lab5_Complex sum = Jaleel_Rogers_Lab5_Complex();
            for (int i = 0; i < size; i++)
    {
        sum = sum.addition(complexArray[i]);
    }
            return sum;
}

