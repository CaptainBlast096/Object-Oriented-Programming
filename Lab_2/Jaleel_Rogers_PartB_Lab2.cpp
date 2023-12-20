/***************************************************************************
 * Title:               Lab 2 Part A
 * Author:              Jaleel Rogers
 * Email:               jrogers1239@floridapoly.edu
 * Creation date:       10/18/2022 @ 6:00 AM
 * Modification date:   10/18/2022 @ 7:30 AM
 * Description:         Write a function that counts and returns number of digits in an integer number
                        using the following header:

                        int getDigit (int n)

                         Write a test program (main) that prompts the user to enter an integer and displays number of
                         digits in the given integer number.
 **************************************************************************/

#include <iostream>
#include <iomanip> //Library for setprecision and setw
using namespace std;
int main()
{

cout <<setw(10)<<"Meters\tFeet" << endl; // Originally had the setw() in the loop but that somewhat displaced some iterations
cout << setprecision(3) << fixed;
for (int i = 1 ; i < 16; i++)
{
    double meters =  3.280;
    cout << i <<"\t"<<(meters * i) << endl;
}

    return 0;
}
