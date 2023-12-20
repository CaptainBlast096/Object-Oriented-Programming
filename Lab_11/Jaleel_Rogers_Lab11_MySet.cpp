#include "Jaleel_Rogers_Lab11_MySet.h"
#include <iostream>
using namespace std;
Jaleel_Rogers_Lab11_MySet::Jaleel_Rogers_Lab11_MySet(unsigned maxNum) : range(maxNum), size(0)
{
    set = new bool [maxNum + 1];

    for(unsigned int i = 0; i <= range; i++)
    {
        set[i] = false;
    }
}

Jaleel_Rogers_Lab11_MySet::Jaleel_Rogers_Lab11_MySet(const Jaleel_Rogers_Lab11_MySet &s) : range(s.range), size(s.size)
{
    set = new bool[range + 1];

    for(unsigned int i = 0; i <= range; i++)
    {
        set[i] = s.set[i];
    }
}

Jaleel_Rogers_Lab11_MySet::~Jaleel_Rogers_Lab11_MySet()
{
    delete [] set;
}

void Jaleel_Rogers_Lab11_MySet::insertElement(int k)
{
    if (k < 0 || k > range)
    {
        cout << "Warning: " << k << " is out of range [0," << range <<"]" << endl;
    }

    else if (!set[k])
    {
        set[k] = true;
        size++;
    }
}

void Jaleel_Rogers_Lab11_MySet::deleteElement(int k)
{
    if (k < 0 || k > range)
    {
        cout << "Warning: " << k << " is out of range [0," << range <<"]" << endl;
    }

    else if (set[k])
    {
        set[k] = false;
        size--;
    }
}

void const Jaleel_Rogers_Lab11_MySet::printSet()
{
    // set firstElement to false
    bool firstElement = false;
    cout << "{";
// loop over the array set
    for(unsigned int i=0;i<=range;i++)
    {
        if(set[i]) // ith element is in set
        {
            if(!firstElement) // this is the first element to display
            {
                cout << " " << i; // display it without comma
                firstElement = true; // set firstElement to true
            }
            else // not the first element, print a preceding comma followed by i
                cout << ", " << i;
        }
    }
    if(!firstElement) // set is empty, display 3 dash
        cout << " ---";
    cout << " }" << endl;
}

bool const Jaleel_Rogers_Lab11_MySet:: isEqualTo(const Jaleel_Rogers_Lab11_MySet& s)
{

// range of both sets are equal and number of elements are equal
    if(range == s.range && size == s.size)
    {
// loop over the array
        for(unsigned int i=0;i<=range;i++)
        {
            if(set[i] != s.set[i]) // ith element are not equal, return false
            {
                return false;
            }
        }
        return true; // sets are equal
    }
    return false; // sets are not equal
}

