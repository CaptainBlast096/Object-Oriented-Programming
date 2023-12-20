//
// Created by jalee on 12/5/2022.
//

#include "Jaleel_Rogers_Lab11_TwoDayPackage.h"

void setFlatFee(double flatFee);
double const calculateCost();
void const printPackageInfo();

Jaleel_Rogers_Lab11_TwoDayPackage::Jaleel_Rogers_Lab11_TwoDayPackage(const string &name, const string &address, const string &city, const string &state, int ZIP, double weight, double costPerOunce, double fee)
: Jaleel_Rogers_Lab11_Package(name, address, city, state, ZIP, weight, costPerOunce) //Calls Jaleel_Rogers_Lab11_Package constructor
{
    if (costPerOunce > 0 && weight > 0 && fee <= 0)
    {
        ID--;
    }
    setFlatFee(fee);
}

void Jaleel_Rogers_Lab11_TwoDayPackage::setFlatFee(double fee)
{
    if (fee <= 0)
    {
        cout << "Flat fee must be > 0.0" << endl;
    }

    else
    {
        flatFee = fee;
    }
}

const double Jaleel_Rogers_Lab11_TwoDayPackage::calculateCost() //Computes and returns the cost for TwoDay Jaleel_Rogers_Lab11_Package
{
    return Jaleel_Rogers_Lab11_Package::calculateCost() + flatFee;
}

void const Jaleel_Rogers_Lab11_TwoDayPackage::printPackageInfo()
{
    cout <<"-----------------------------------------------------" << endl;
    cout << "Jaleel_Rogers_Lab11_Package id " << packageID << ":" << endl;
    cout << "\n"<<name << endl;
    cout << address << endl;
    cout << city << ", "<<state << ", "<< ZIP << endl;
    cout << "\nCost: $" <<calculateCost() << endl;
    cout <<"-----------------------------------------------------" << endl;
}
