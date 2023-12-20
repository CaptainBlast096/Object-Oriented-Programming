//
// Created by jalee on 12/5/2022.
//

#ifndef LAB11_JALEEL_ROGERS_LAB11_PACKAGE_H
#define LAB11_JALEEL_ROGERS_LAB11_PACKAGE_H
#include <iostream>

using namespace std;

class Jaleel_Rogers_Lab11_Package
{
protected:
    //Customer information
    const string name;
    const string address;
    const string city;
    const string state;

    int ZIP;

    //Jaleel_Rogers_Lab11_Package specifications
    double weight; //Make in ounces
    double costPerOunce;//Per ounce

    int packageID; //Jaleel_Rogers_Lab11_Package's ID
    static int ID; // Counter for the current ID
public:
    //Constructor
    Jaleel_Rogers_Lab11_Package(const string &name, const string &address, const string &city, const string &state, int ZIP, double weight, double costPerOunce); // Difficulties trying to call it in source code

    void setWeight(double weight);
    void setCostPerOunce(double costPerOunce);
    const double calculateCost();
    void const printPackageInfo();
};


#endif //LAB11_JALEEL_ROGERS_LAB11_PACKAGE_H
