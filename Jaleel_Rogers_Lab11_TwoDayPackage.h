//
// Created by jalee on 12/5/2022.
//

#ifndef LAB11_JALEEL_ROGERS_LAB11_TWODAYPACKAGE_H
#define LAB11_JALEEL_ROGERS_LAB11_TWODAYPACKAGE_H

#include "Jaleel_Rogers_Lab11_Package.h"

class Jaleel_Rogers_Lab11_TwoDayPackage: public Jaleel_Rogers_Lab11_Package //Derived and base class
{
private:
    double flatFee; //Charges for two-day delivery | an additional field
public:
    Jaleel_Rogers_Lab11_TwoDayPackage(const string &name, const string &address, const string &city, const string &state, int ZIP, double weight, double costPerOunce, double fee);// : public Jaleel_Rogers_Lab11_Package

    //Originally were located in responding source code file
    void setFlatFee(double fee);
    const double calculateCost();
    void const printPackageInfo();
};

#endif //LAB11_JALEEL_ROGERS_LAB11_TWODAYPACKAGE_H
