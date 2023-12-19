/***************************************************************************
 * Title:               Lab 3 Part C
 * Author:              Jaleel Rogers
 * Email:               jrogers1239@floridapoly.edu
 * Creation date:       10/20/2022 @ 8:00 AM
 * Modification date:   10/20/2022 @ 6:50 PM
 * Description:         Write a function that returns the sum of values at even locations of an array with the
                            following headers:
                                double sumEven (const double * arr, int size)
                        Write a test program that reads six double values, invokes this function, and displays
                            the sum of values at even locations.

 **************************************************************************/
#include <iostream>

using namespace std;
double sumEven (const double * arr, int size)
{
    /*
    int arrayLength = size;
    size = 6;

     Put into the main and turn into a for loop to simplify
     */
    double sum = 0;

    for (int i = 1; i < size; i += 2) //Definition of odd: 2k + 1
    {

         /*
        if (arr[i] % 2 == 0) //i % 2 is good for finding if a number is even or odd
        {
        sum += * (arr + 1);
        }
          //Can't use mod because array is a double
          */

            sum += *(arr + i ); // Using pointers is convenient to reference | stores odd integers
    }
   return sum;
}
int main()
{
    double array[6]; // Declared array
    cout << "Please enter six double number:";
    for (int i = 0; i < 6; i++)
    {
        cin >> array[i];
    }
    cout << "Sum of values at even location: " << sumEven(array,6) << endl;
    return 0;
}