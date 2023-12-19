/***************************************************************************
 * Title:               Lab 11 Problem 3
 * Author:              Jaleel Rogers
 * Email:               jrogers1239@floridapoly.edu
 * Creation date:       12/05/2022 @ 12:00 AM
 * Modification date:   12/05/2022 @ 6:30 PM
 * Description: Create a base class Package that includes protected data members representing the name, address, city,
 *                  state and ZIP code for the recipient of the package, the weight (in ounces) and
 *                  cost per ounce to ship the package. Package class also contains a static data member
 *                  ID and the following methods
 * ***************************************************************************/


#include "Jaleel_Rogers_Lab11_Package.h"
#include "Jaleel_Rogers_Lab11_TwoDayPackage.h"
#include "Jaleel_Rogers_Lab11_OvernightPackage.h"
using namespace std;

int main()
{
    Jaleel_Rogers_Lab11_Package p1("John Smith", "1020 Orange St", "Lakeland", "FL", 33111, 10.5, 0.4);
    Jaleel_Rogers_Lab11_TwoDayPackage p2("Bob George", "21 Pine Rd", "Cambridge", "MA", 44444, 10.5, 0.65, 2.0);
    Jaleel_Rogers_Lab11_OvernightPackage p3("Don Kelly", "9 Main St", "Denver", "CO", 66666, 12.25, 0.7, 0.25);



    p1.printPackageInfo();
    p2.printPackageInfo();
    p3.printPackageInfo();

    return 0;
}
