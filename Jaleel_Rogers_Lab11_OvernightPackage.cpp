//
// Created by jalee on 12/5/2022.
//

#include "Jaleel_Rogers_Lab11_OvernightPackage.h"

void setOvernightFeePerOunce(double extraFeePerOunce);
double const calculateCost();
void const printPackageInfo();

Jaleel_Rogers_Lab11_OvernightPackage::Jaleel_Rogers_Lab11_OvernightPackage(const string &name, const string &address, const string &city, const string &state, int ZIP, double weight, double costPerOunce, double fee)
: Jaleel_Rogers_Lab11_Package(name, address, city, state, ZIP, weight, costPerOunce)
{
    if (costPerOunce > 0 && weight > 0 && fee <= 0)
    {
        ID--;
    }
        setOvernightFeePerOunce(fee); //Setting the overnight fee
}

void Jaleel_Rogers_Lab11_OvernightPackage::setOvernightFeePerOunce(double fee)
{
    if (fee <= 0)
    {
        cout <<"Overnight fee must be > 0.0" << endl;
    }

    else
    {
        overnightFee = fee;
    }
}

const double Jaleel_Rogers_Lab11_OvernightPackage::calculateCost()
{
    return Jaleel_Rogers_Lab11_Package::calculateCost() + weight * overnightFee;
}

void const Jaleel_Rogers_Lab11_OvernightPackage::printPackageInfo()
{
    cout <<"-----------------------------------------------------" << endl;
    cout << "Jaleel_Rogers_Lab11_Package id " << packageID << ":" << endl;
    cout << "\n"<<name << endl;
    cout << address << endl;
    cout << city << ", "<<state << ", "<< ZIP << endl;
    cout << "\nCost: $" <<calculateCost() << endl;
    cout <<"-----------------------------------------------------" << endl;
}