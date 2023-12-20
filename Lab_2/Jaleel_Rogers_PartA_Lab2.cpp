/***************************************************************************
 * Title:               Lab 2 Part A
 * Author:              Jaleel Rogers
 * Email:               jrogers1239@floridapoly.edu
 * Creation date:       10/18/2022 @ 5:00 AM
 * Modification date:   10/18/2022 @ 5:30 AM
 * Description:         Write a function that counts and returns number of digits in an integer number
                        using the following header:

                        int getDigit (int n)

                         Write a test program (main) that prompts the user to enter an integer and displays number of
                         digits in the given integer number.
 **************************************************************************/
#include <iostream>

using namespace std;
int getDigit(int number)
{


    int digitCounter = 0;

    while (number != 0)
        {
        number = number / 10; // Divide the number by ten in order to get to increase its decimal place, getting closer till it reaches 0
        digitCounter+=1;
        }
   return digitCounter;
}

int main()
{
    int x;
     cout << "Enter an integer:";
    cin >> x;
    cout << "The number of digits in: " << x << " is " << getDigit(x);
    return 0;
}
