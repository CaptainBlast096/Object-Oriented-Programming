
/***************************************************************************
 * Title:               Lab 1 Part B
 * Author:              Jaleel Rogers
 * Email:               jrogers1239@floridapoly.edu
 * Creation date:       10/17/2022 @ 12:10 PM
 * Modification date:   10/17/2022 @ 9:20 PM
 * Description:         Write a program that prompts the user to enter the distance to drive, the fuel
                        efficiency of the car in miles per gallon, and the price per gallon, and displays the
                        cost of the trip. Here is a sample run:
 **************************************************************************/
#include <iostream>
using namespace std;

int main()
{
    double drivingDistance, milesGallon, priceGallon, drivingCost;
    // input input galore
    cout << "Enter the driving distance:";
    cin >> drivingDistance;
    cout << "Enter miles per gallon:";
    cin >> milesGallon;
    cout << "Enter price per gallon:";
    cin >> priceGallon;
    cout << "The cost of driving is $";
    cin >> drivingCost;
    return 0;
}