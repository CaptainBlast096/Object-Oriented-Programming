/***************************************************************************
 * Title:               Lab 3 Part B
 * Author:              Jaleel Rogers
 * Email:               jrogers1239@floridapoly.edu
 * Creation date:       10/20/2022 @ 8:00 AM
 * Modification date:   10/20/2022 @ 8:30 AM
 * Description:         Write a complete C++ program that creates a pointer called p and an integer
                            variable called num with a value 5. Your program must print the following outputs:
                        • Print the value of the integer number directly from the num variable.
                        • Print the value of the integer number indirectly from the p pointer.
                        • Print the address of the integer variable directly from the num variable (Use &).
                        • Print the address of the integer variable indirectly from the p pointer.
                        • Print the value of the p pointer.
                        • Print the address of the p pointer.
 **************************************************************************/
/*
 * Steps of logic
 *  1. Create a pointer and an integer using the pointer
 *  2. Then assign the memory of int num to the pointer
 * */
#include <iostream>
using namespace std;

int main()
{

    int num = 5;
    int *ptr;

    cout << "The value of the num is " << num << endl; //Print the value of the integer number directly from the num variable.

    ptr = &num;
    cout <<"The value of the num is " << *ptr << endl; //Print the value of the integer number indirectly from the p pointer.

    cout <<"The address of the num is " << &num << endl; //Print the address of the integer variable directly from the num variable (Use &).

    cout <<"The address of the num is " << ptr << endl; //Print the address of the integer variable indirectly from the p pointer.

    cout <<"The value of the p pointer is " << ptr << endl; //Print the value of the p pointer.

    cout <<"The address of the p pointer " << &ptr << endl; //Print the address of the p pointer


    return 0;
}
