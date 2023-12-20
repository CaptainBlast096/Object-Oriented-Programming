/***************************************************************************
 * Title:               Lab 11 Problem 2
 * Author:              Jaleel Rogers
 * Email:               jrogers1239@floridapoly.edu
 * Creation date:       12/04/2022 @ 7:00 PM
 * Modification date:   12/04/2022 @ 10:00 PM
 * Description: Design a class named MySet which can hold integers from 0 to a defined range. The set is represented
 *                  as a dynamic array of Boolean values. Element with the index j is true if integer j is in the set.
 *                  Element with the index k is false if integer k is not in the set. The class contains:
 * ***************************************************************************/

#include <iostream>
#include "Jaleel_Rogers_Lab11_MySet.h"
using namespace std;

int main()
{
    //Jaleel_Rogers_Lab11_MySet Object 1
        cout << "1) Creates a first Jaleel_Rogers_Lab11_MySet object s1 with the range of numbers [0; 20]" <<endl;
        Jaleel_Rogers_Lab11_MySet s1(20);
        cout <<"s1 = ";
        s1.printSet();
        cout <<"s1.insertElement(13)" << endl;
        cout <<"s1 = ";
        s1.insertElement(13);
        s1.printSet();
        cout <<"s1.insertElement(7)" << endl;
        cout <<"s1 = ";
        s1.insertElement(7);
        s1.printSet();
        cout <<"s1.insertElement(20)" << endl;
        cout <<"s1 = ";
        s1.insertElement(20);
        s1.printSet();
        cout <<"s1.insertElement(21)" << endl;
        s1.insertElement(21);
        cout <<"s1 = ";
        s1.printSet();
        cout <<"s1.deleteElement(22)" << endl;
        s1.deleteElement(22);
        cout <<"s1 = ";
        s1.printSet();
        cout <<"s1.deleteElement(13)" << endl;
        s1.deleteElement(13);
        cout <<"s1 = ";
        s1.printSet();

    //Jaleel_Rogers_Lab11_MySet Object 2
        cout << "6) Creates a second Jaleel_Rogers_Lab11_MySet object s2 with the range of numbers [0; 100]." <<endl;
        Jaleel_Rogers_Lab11_MySet s2(100);
        cout <<"s2 = ";
        s2.printSet();
        cout <<"s2.isEqualTo(s1) = " << s2.isEqualTo(s1) <<endl;

    //Jaleel_Rogers_Lab11_MySet Object 3
        cout << "8) Creates a third Jaleel_Rogers_Lab11_MySet object s3 with the copy constructor with the first object as the argument" <<endl;
        Jaleel_Rogers_Lab11_MySet s3(s1);
        cout <<"s3 = ";
        s3.printSet();
        cout <<"s3.isEqualTo(s1) = " << s3.isEqualTo(s1);
    return 0;
}
