//
// Created by jalee on 12/5/2022.
//

#ifndef LAB11_JALEEL_ROGERS_LAB11_OVERNIGHTPACKAGE_H
#define LAB11_JALEEL_ROGERS_LAB11_OVERNIGHTPACKAGE_H
#include "Jaleel_Rogers_Lab11_Package.h"

class Jaleel_Rogers_Lab11_OvernightPackage : public Jaleel_Rogers_Lab11_Package
{
private:
    double overnightFee; // An additional data field
public:
    Jaleel_Rogers_Lab11_OvernightPackage(const string &name, const string &address, const string &city, const string &state, int ZIP, double weight, double costPerOunce, double fee);

    void setOvernightFeePerOunce(double fee);
    const double calculateCost();
    void const printPackageInfo();
};

#endif //LAB11_JALEEL_ROGERS_LAB11_OVERNIGHTPACKAGE_H
