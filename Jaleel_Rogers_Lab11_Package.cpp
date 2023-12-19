//
// Created by jalee on 8/6/2022.
//

#include "Jaleel_Rogers_Lab11_Package.h"



// Put ID in Jaleel_Rogers_Lab11_Package lab
int Jaleel_Rogers_Lab11_Package::ID = 0; // Initialize to 0

Jaleel_Rogers_Lab11_Package::Jaleel_Rogers_Lab11_Package(const string &name, const string &address, const string &city, const string &state, int ZIP, double weight, double costPerOunce)
: name(name), address(address), city(city), state(state), ZIP(ZIP)
{
    setWeight(weight);
    setCostPerOunce(costPerOunce);

    ID++; //Increments by 1
    packageID = ID; // Updating ID
}

void Jaleel_Rogers_Lab11_Package::setWeight(double weight)
{
    if (weight <= 0) // Checking if weight is positive
    {
        std::cout << "weight must be > 0.0" << std::endl; // Ensures weight must be
    }

    else
    {
        this-> weight = weight; // setting weight as an input
    }
}

void Jaleel_Rogers_Lab11_Package::setCostPerOunce(double costPerOunce)
{
    if (costPerOunce <= 0) //Checking if cost is positive
    {
        std::cout << "cost must be > 0.0)" << std::endl;
    }

    else
    {
        this-> costPerOunce = costPerOunce;
    }

}
const double Jaleel_Rogers_Lab11_Package::calculateCost()  //Put const in the derived class not the base class
{
    return weight * costPerOunce;
}

//Function displays package information
void const Jaleel_Rogers_Lab11_Package::printPackageInfo()
{
    cout <<"-----------------------------------------------------" << endl;
    cout << "Jaleel_Rogers_Lab11_Package id " << packageID << ":" << endl;
    cout << "\n"<<name << endl;
    cout << address << endl;
    cout << city << ", "<<state << ", "<< ZIP << endl;
    cout << "\nCost: $" <<calculateCost() << endl;
    cout <<"-----------------------------------------------------" << endl;
}

