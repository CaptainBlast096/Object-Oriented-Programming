/***************************************************************************
 * Title:               Lab 11 Problem 1
 * Author:              Jaleel Rogers
 * Email:               jrogers1239@floridapoly.edu
 * Creation date:       12/04/2022 @ 5:30 PM
 * Modification date:   12/05/2022 @ 6:30 PM
 * Description: Design a generic function that returns true if all the elements in the second array are greater than
    any element in the first array. Test the function with an array of int, double, and string values.
 * ***************************************************************************/

#include <iostream>

using namespace std;

template<typename T>
bool isGreater(const T list1[], const T list2 [], int size1, int size2)
{
    T left = list1[0];
    T right = list2[0];
    //T list1_max = list1[0]; // list1_max will contain the highest element of list 1
    for (int i = 1; i < size1; i++) // for loop will assign a new element in list1_max if said element is greater
                                        //than the already contained element
    {
        if (list1[i] < left)
        {
            left = list1[i];
        }
    }

    for (int i = 1; i < size2; i++) //Return true if list2's elements are greater than list1's
    {
        if (list2[i] > right)
        {
            right = list2[i];
        }

    }
    return (left > right);

}


int main()
{
    cout << "Are all elements in the left array larger than any elements in the right array?" <<endl;

    //Int template
        int int_array1 [] = {9,10,11,23};
        int int_array2 [] = {5,3,2,7};
        cout << "{9, 10, 11, 23} > {5, 3, 2, 7}? " << isGreater(int_array1,int_array2,4,4) << endl;
    //Double template
        double double_array1 [] = {9.4,10.3,11.2,2.3};
        double double_array2 [] = {5.1,3.2,2.3,7.4};
        cout << "{9.4, 10.3, 11.2, 2.3} > {5.1, 3.2, 2.3, 7.4}? " << isGreater(double_array1,double_array2,4,4) << endl;
    //String template
        string string_array1 [] = {"Miami", "Lakeland", "Tampa", "Orlando"};
        string string_array2 [] = {"Dallas", "Austin", "Antonia"};
        cout << R"({"Miami", "Lakeland", "Tampa", "Orlando"} > {"Dallas", "Austin", "Antonia"}? )" << isGreater(string_array1,string_array2,4,3) << endl;

return 0;
}
