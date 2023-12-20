//
// Created by jalee on 12/4/2022.
//

#ifndef LAB11_JALEEL_ROGERS_LAB11_MYSET_H
#define LAB11_JALEEL_ROGERS_LAB11_MYSET_H

class Jaleel_Rogers_Lab11_MySet
{
private:
    unsigned int range;
    int size;
    bool *set;
public:
    Jaleel_Rogers_Lab11_MySet(unsigned maxNum);
    Jaleel_Rogers_Lab11_MySet(const Jaleel_Rogers_Lab11_MySet &s);
    void insertElement(int k);
    void deleteElement(int k);
    void const printSet();
    bool const isEqualTo(const Jaleel_Rogers_Lab11_MySet &r);
    ~Jaleel_Rogers_Lab11_MySet();
};
#endif //LAB11_JALEEL_ROGERS_LAB11_MYSET_H
