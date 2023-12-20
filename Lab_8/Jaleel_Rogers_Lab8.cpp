/***************************************************************************
 * Title:               Lab 
 * Author:              Jaleel Rogers
 * Email:               jrogers1239@floridapoly.edu
 * Creation date:       11/19/2022 @ 7:30 PM
 * Modification date:   11/04/2022 @ 7:27 AM
 * Description: Write a test program (testComplex.cpp) that:

 * ***************************************************************************/

#include <iostream>
#include <cmath>


using namespace std;

class Complex
{
private:

    double a;
    double b;

public:
//Three Constructors

    //Constructor where object will be 0
    Complex()
    {
        a = 0.0;
        b = 0.0;
    }

    //Constructor where b is 0
    Complex(double pA)
    {
        a = pA;
        b = 0;
    }

    //Constructor where a and b is 0
    Complex(double pA, double pB)
    {

        a = pA;
        b = pB;
    }

//Getters

    //Gets Real Number
    double getRealPart()
    {

        return a;
    }

    //Gets Imaginary Number
    double getImaginaryPart()
    {
        return b;
    }

//toString function
    //converts complex number to string
    string toString()
    {
        string str = to_string(a) + " + " + to_string(b);

        return str;
    }

//Overloading operators

    Complex operator+=(Complex &c)
    {
        this->a += c.a;
        this->b += c.b;

        return *this;
    }

    Complex operator-=(Complex &c)
    {
        this->a -= c.a;
        this->b -= c.b;

        return *this;
    }

    Complex operator*=(Complex &c)
    {
        Complex temp = *this;

        temp.a = ((this->a * c.a) - (this->b * c.b));
        temp.b = ((this->b * c.a) + (this->a * c.b));

        *this = temp;
        return *this;
    }

    Complex operator/=(Complex &c)
    {
        Complex temp;

        temp.a = ((this->a * c.a) + (this->b * c.b)) / ((c.a * c.a) + (c.b * c.b));
        temp.b = ((this->b * c.a) - (this->a * c.b)) / ((c.a * c.a) + (c.b * c.b));

        *this = temp;
        return *this;
    }


//Overloading sign operators

    Complex operator+()
    {
        Complex temp = *this;

        temp.a = abs(temp.a);
        temp.b = abs(temp.b);

        *this = temp;
        return *this;
    }

    Complex operator-()
    {
        Complex temp = *this;

        if(temp.a > 0)
        {
            temp.a = temp.a - temp.a - temp.a;
        }

        else
        {
            temp.a = abs(temp.a);
        }

        if(temp.b > 0)
        {
            temp.b = temp.b - temp.b - temp.b;
        }

        else
        {
            temp.b = abs(temp.b);
        }

        *this = temp;
        return *this;
    }

    //Operators with contents within its parameters are meant for regular numbers
    Complex operator+(double n)
    {
        this->a += n;
        return *this;
    }

    Complex operator-(double n)
    {
        this->a -= n;
        return *this;
    }

    Complex &operator++()
    {
        ++a;
        return *this;
    }

    Complex operator++(int)
    {
        Complex temp = *this;

        ++a;
        return temp;
    }


    Complex &operator--()
    {
        --a;
        return *this;
    }


    Complex operator--(int)
    {
        Complex temp = *this;

        --a;
        return temp;
    }

    double operator[](int index)
    {

        switch (index)
        {
            case 0:
                return this->a;
                break;
            case 1:
                return this->b;
                break;
            default:
                cout << "Number does not exist";
                break;
        }
    }

//Arithmetic
    Complex add(Complex &c)
    {
        double real = a + c.a;
        double imaginary = b + c.b;

        return Complex(real, imaginary);
    }

    Complex subtract(Complex &c)
    {
        double real = a - c.a;
        double imaginary = b - c.b;

        return Complex(real, imaginary);
    }

    Complex multiply(Complex &c)
    {

        double real = ((a * c.a) - (b * c.b));
        double imaginary = ((b * c.a) - (a * c.b));

        return Complex(real, imaginary);
    }

    //divide two complex numbers
    Complex divide(Complex &c)
    {
        double real = ((a * c.a) + (b * c.b)) / ((c.a * c.a) + (c.b * c.b));
        double imaginary = ((b * c.a) - (a * c.b)) / ((c.a * c.a) + (c.b * c.b));

        return Complex(real, imaginary);
    }

//Absolute
    double absolute()
    {
        return (sqrt(pow(getRealPart(),2) + pow(getImaginaryPart(),2)));
    }

    //Insertion & Extraction
    friend ostream &operator<<(ostream &out, Complex c);
    /*
     * Original Implementation:
         ostream &operator <<(ostream &out, const Complex& c)
            {
                cout << c.toString();
                return out;
            }
    */
    friend istream &operator>>(istream &in, Complex c);
    /*
     * Original Implementation:
        istream &operator>>(istream &in, Complex c);
           {
               cout << "Enter number a and b for (a + bi): ";
               cin >> c.a >> c.b;
               return in;
           }
           */
};

//Implementing the extraction and insertion
ostream &operator<<(ostream &out, Complex c)
{

    out << c.a;
    out << " + ";
    out << c.b << "i" << endl;

    return out;
}

istream &operator>>(istream &in, Complex c)
{

    cout << "Enter real part ";
    in >> c.a;
    cout << "Enter Complex number ";
    in >> c.b;

    return in;
}

//implementation of arithmetic

Complex operator+(Complex& num1, Complex& num2)
{

    Complex temp((num1.getRealPart() + num2.getRealPart()),(num1.getImaginaryPart() + num2.getImaginaryPart()));
    return temp;

}

Complex operator-(Complex& num1, Complex& num2)
{

    Complex temp((num1.getRealPart() - num2.getRealPart()),(num1.getImaginaryPart() - num2.getImaginaryPart()));
    return temp;

}

Complex operator*(Complex& num1, Complex& num2)
{

    Complex temp((((num1.getRealPart() * num2.getRealPart()) - (num1.getImaginaryPart() * num2.getImaginaryPart()))),((num1.getImaginaryPart() * num2.getRealPart())+(num1.getRealPart() * num2.getImaginaryPart())));
    return temp;
}

Complex operator/(Complex& num1, Complex& num2)
{

    Complex temp((((num1.getRealPart() * num2.getRealPart()) + (num1.getImaginaryPart() * num2.getImaginaryPart())) / ((num2.getRealPart() * num2.getRealPart()) + (num2.getImaginaryPart() * num2.getImaginaryPart()))),(((num1.getImaginaryPart() * num2.getRealPart()) - (num1.getRealPart() * num2.getImaginaryPart())) / ((num2.getRealPart() * num2.getRealPart()) + (num2.getImaginaryPart() * num2.getImaginaryPart()))));
    return temp;
}

int main()
{


    //#1
    cout << "1. Test constructors: " << endl;
    cout << "1.1 Create complex number c0 with no-arg constructor Complex():" << endl;

    //gets real and imaginary part of no arg constructor
    Complex c0;
    cout << "c0 = 0, it's real part Re(c0) = " << c0.getRealPart() << ", it's imaginary part Im(c0) = " << c0.getImaginaryPart();
    cout << ", it's absolute value |c0| = " << c0.absolute() << endl;

    //gets real and imaginary part of one arg constructor
    int a = 0;
    cout << "1.2 create a complex number c1 with constructor Complex(a): " << endl;
    cout << "Enter a number a: ";
    cin >> a;
    Complex c1(a);
    cout << "c1 = 3, it's real part Re(c1) = " << c1.getRealPart() << ", it's imaginary part Im(c1) = " << c1.getImaginaryPart();
    cout << ", it's absolute value |c1| = " << c1.absolute() << endl;

    //gets real and imaginary part of two arg constructor
    int c,d = 0;
    cout << "1.3 create a complex number c2 with constructor Complex(a,b): " << endl;
    cout << "Enter number a, b: ";
    cin >> c >> d;
    Complex c2(c,d);
    cout << "c2 = " << c2.getRealPart() << " + " << c2.getImaginaryPart() << "i, it's real part Re(c2) = " << c2.getRealPart();
    cout << ", it's imaginary part Im(c2) = " << c2.getImaginaryPart() << ", it's absolute value |c2| = "  << c2.absolute() << endl;

    //#2
    //Insertion and extraction operators
    int n1,n2 = 0;
    cout << "2. Test overloaded stream insertion operator >> and extraction operator <<:" << endl;
    cout << "Enter two complex numbers following the prompts:" << endl;
    cout << "Enter the first complex number cx1 with (cin >> cx1): Enter a and b for (a + bi): ";
    cin >> n1 >> n2;
    Complex cx1(n1,n2);
    cout << "\'cout << cx1\' prints ";
    cout << cx1;

    cout << "Enter the second complex number cx2 with (cin >> cx2): Enter a and b for (a + bi): ";
    cin >> n1 >> n2;
    Complex cx2(n1,n2);
    cout << "\'cout << cx2\' prints " << cx2 << endl;

    //#3
    //Arithmetic operators
    cout << "3. Test overloaded arithmetic operators +, -, *, /:" <<endl;
    Complex comp1(3,4), comp2(5,6);
    cout << "(3 + 4i) + (5 + 6i) = " << comp1 + comp2;
    cout << "(3 + 4i) - (5 + 6i) = " << comp1 - comp2;
    cout << "(3 + 4i) * (5 + 6i) = " << comp1 * comp2;
    cout << "(3 + 4i) / (5 + 6i) = " << comp1 / comp2 <<endl;

    //#4
    //Augmented operators
    cout << "4. Test overloaded augmented arithmetic operators +=, -=, *=, /=:" << endl;
    cout << "cx1 = 3 + 4i; cx2 = 5 + 6i" << endl;
    cout << "(cx2 += cx1); cx2 = ";
    cx2 += cx1;
    cout << cx2;

    cout << "(cx2 -= cx1); cx2 = ";
    cx2 -= cx1;
    cout << cx2;

    cout << "(cx2 *= cx1); cx2 = ";
    cx2 *= cx1;
    cout << cx2;

    cout << "(cx2 /= cx1); cx2 = ";
    cx2 /= cx1;
    cout << cx2 <<endl;

    //#5
    //Unary
    Complex comp3, comp4;
    comp4 = cx1;
    cout << "5. Test overloaded Unary operators: " << endl;
    cout << "5.1 Test overloaded sign operators +, -:" << endl;
    cout << "cx1 = " << cx1;
    +cx1;
    cout << "+cx1 = " << cx1;

    cout << "-cx1 = ";
    -cx1;
    cout << cx1;

    cout << "5.2 Test overloaded prefixes ++, --:" << endl;
    cout << "cx1 = " << cx1;
    cout << "++cx1; cx1 = " << ++cx1;
    cout << "--cx1; cx1 = " << --cx1;

    cout << "5.2 Test overloaded postfixes ++, --:" << endl;
    cout << "cx1 = " << cx1;
    cout << "\'cout << cx1++;\' prints " << cx1++;
    cout << "\'cout << cx1--\' prints " << cx1--;
    cout << "cx1 = " << cx1 <<endl;

    //#6
    //Subscript
    cout << "6. Test overloaded subscript operator []:" << endl;
    cout << "cx1 = " << cx1;
    cout << "cx1[0] = " << cx1[0] << endl;
    cout << "cx1[1] = " << cx1[1] << endl;
    cout << "cx2[0] == cx2.getRealPart() = " << (cx2[0] == cx2.getRealPart() ? true : false) << endl;
    cout << "cx2[1] == cx2.getImaginaryPart() = " << (cx2[1] == cx2.getImaginaryPart() ? true : false) << endl;

    //#7
    //Implicit conversion
    cout << "7. Test implicit conversion from double to Complex:" << endl;
    cout << "cx2 = " << cx2;
    cout << "3 + cx2 = "  << cx2 + 3;
    cout << "3.4 + cx2 = " << cx2 + 3.4;

    return 0;
}
