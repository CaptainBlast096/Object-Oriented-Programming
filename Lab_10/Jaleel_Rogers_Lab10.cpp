/***************************************************************************
 * Title:               Lab 10
 * Author:              Jaleel Rogers
 * Email:               jrogers1239@floridapoly.edu
 * Creation date:       11/28/2022 @ 12:30 PM
 * Modification date:   11/30/2022 @ 6:30 PM
 * Description: Design a generic class named myVector that contains:
    1) A T pointer type data field named vec.
    2) Two int data fields named numOfElements and capacity.
    3) A no-arg constructor that creates a myVector object with a default capacity (4).
    4)  A user-defined constructor that creates a myVector object with the specified
    capacity.
    5)  A copy constructor myVector(const myVector & vector) that creates a
    myVector object with a given myVector object. It has to be a deep copy.
    6) A destructor that makes the dynamically created array free. (Use delete)
    7) A function void print() that prints all current elements.
    8)  A function void insertBeg(T value) that inserts the given value to the beginning
    of the array. You should shift the elements to the right in your array.
    9)  A function void insertEnd(T value) that inserts the given value to the end of the
    array. No need shifting.
    10) A function void removeBeg() that removes the first element of the array. You
        should shift the elements to the left in your array.
    11) A function void removeEnd() that removes the last element of the array. No
        need shifting.
    12) A function void increaseCapacity()  that increases the capacity of the array by
        twice if the size of the array is equal to the capacity. This function must be
        called from insertEnd() and insertBeg() functions.
        COP 3337 - Object Oriented Programming
    13) A function void decreaseCapacity()  that decreases the capacity of the array by half
        if the size of the array is equal to half of the capacity. This function must be called
        from removeEnd() and removeBeg() functions.
    14) Implement == (equal) operator overloading for two myVector objects. It should
        return true if two vectors are identical, false otherwise.
        bool operator == (const myVector & secondVector);

Write test code that tests all functions, constructors, and the destructor. For each subtask, use print
to show the current elements:
    1) Create an integer myVector object called intVector.
    2) Call the insertEnd(4), insertBeg(3), insertEnd(6), insertEnd(2), insertBeg(1),
    removeEnd(),  and removeBeg() functions from the intVector object.
    3) Create another integer myVector object called intVector2.
    4) Call the insertEnd(4), insertBeg(7), insertEnd(6), insertEnd(2), insertBeg(1),
    removeEnd(),  and removeBeg() functions from the intVector2 object.
    5) Use == operator to show these vectors are not identical.
    6) Repeat the same test with character myVector objects called charVector and
    charVector2.
 * ***************************************************************************/
#include <iostream>

using namespace std;


template <typename T> class myVector
{
private:
    T *vec; //T pointer
    int numOfElements = 0; // If I do not have my numofElements set to 0 the array has an unlimited number of elements, producing unpredictable numbers.
    int capacity = 0;
public:
    myVector() //Default Constructor
    {
        vec = new T[capacity]; //Use capacity as the size
        capacity = 4;
    }
    myVector(int capacity) // User-defined constructor
    {
        vec = new T[capacity];
        this-> capacity = capacity;
    }
    myVector(const myVector &vector) //Copy-Constructor
    {
     vec = new T [vector.capacity];
     capacity = vector.capacity;
    numOfElements = vector.numOfElements;

     for (int i = 0; i < vector.numOfElements; i++)
     {
         vec[i] = vector.vec[i];
     }
    }

    ~myVector() //Destructor
    {
      delete [] vec;
    }

    void print()
    {
        cout << "vec: (";
        for (int i = 0; i < numOfElements; i++)
        {
            cout << vec[i] << ((numOfElements-i > 1)? " ":"");
        }
        cout << ")" <<endl;
    }

    void insertBeg(T value)
    {
        numOfElements++;
        increaseCapacity();

        for (int i = numOfElements -1; i >= 0; i--)
        {
            vec[i] = vec[i - 1]; //Shifting elements to the right by 1 position
        }
        vec[0] = value;
    }

    void insertEnd(T value)
    {
       increaseCapacity();
       vec[numOfElements++] = value;
    }

    void removeBeg()
    {
        for (int i = 0; i < numOfElements - 1; i++)
        {
            vec[i] = vec[i+1];
        }
        numOfElements--; //Decrementing size of the vector
        if (numOfElements == capacity /2)
        {
            decreaseCapacity();
        }
    }

    void removeEnd()
    {
        vec[numOfElements - 1] = NULL; // Removes the last value
        numOfElements--; //Decrements the size of the vector

        if (numOfElements == capacity / 2)
        {
            decreaseCapacity();
        }
    }

    void increaseCapacity()
    {
        if (numOfElements == capacity)
        {
            capacity = capacity * 2; //Doubles the capacity
        }
    }

    void decreaseCapacity()
    {
        if (numOfElements == capacity / 2)
        {
            T* old = vec;
            capacity = .5 * numOfElements; //Halves the capacity
            vec = new T[numOfElements * 2];

            for (int i = 0; i < numOfElements; i++)
            {
                vec[i] = old[i];
            }
            delete [] old;
        }
    }

    bool operator == (const myVector &secondVector)
    {
        if (numOfElements == secondVector.numOfElements )
        {
            for (int i = 0; i < numOfElements; i++)
                if (vec[i] != secondVector.vec[i])
                {
                    return false;
                }
                else
                {
                    return true;
                }
        }
        else
        {
            return true;
        }
    }

};


int main()
{
    //Vector int 1
        cout << "intVector created: no elements at the beginning." <<endl;
        myVector<int> intVector = myVector<int>();
        intVector.print();
        cout << "intVector.insertEnd(4):" <<endl;
            intVector.insertEnd(4);
            intVector.print();
        cout <<"intVector.insertBeg(3):" << endl;
            intVector.insertBeg(3);
            intVector.print();
        cout <<"intVector.insertEnd(6):" << endl;
            intVector.insertEnd(6);
            intVector.print();
        cout <<"intVector.insertEnd(2):" << endl;
            intVector.insertEnd(2);
            intVector.print();
        cout <<"intVector.insertBeg(1):" << endl;
            intVector.insertBeg(1);
            intVector.print();
        cout <<"intVector.removeEnd():" << endl;
            intVector.removeEnd();
            intVector.print();
        cout <<"intVector.removeBeg():" << endl;
            intVector.removeBeg();
            intVector.print();

    //Vector int 2
        cout << "intVector2 created: no elements at the beginning." <<endl;
        myVector<int> intVector2 = myVector<int>();
        intVector2.print();
        cout << "intVector2.insertEnd(4):" <<endl;
            intVector2.insertEnd(4);
            intVector2.print();
        cout <<"intVector2.insertBeg(7):" << endl;
            intVector2.insertBeg(7);
            intVector2.print();
        cout <<"intVector2.insertEnd(6):" << endl;
            intVector2.insertEnd(6);
            intVector2.print();
        cout <<"intVector2.insertEnd(2):" << endl;
            intVector2.insertEnd(2);
            intVector2.print();
        cout <<"intVector2.insertBeg(1):" << endl;
            intVector2.insertBeg(1);
            intVector2.print();
        cout <<"intVector2.removeEnd():" << endl;
            intVector2.removeEnd();
            intVector2.print();
        cout <<"intVector2.removeBeg():" << endl;
            intVector2.removeBeg();
            intVector2.print();
        if (intVector == intVector2)
        {
            cout <<"Integer vectors are the same!" <<endl;
        }
        else
        {
            cout <<"Integer vectors are not the same!" <<endl;
        }
        cout << endl;
    //Vector char
        cout << "charVector created: no elements at the beginning." <<endl;
        myVector<char> charVector = myVector<char>();
        charVector.print();
        cout <<"charVector.insertEnd('a'):" << endl;
            charVector.insertEnd('a');
            charVector.print();
        cout <<"charVector.insertBeg('b'):" << endl;
            charVector.insertBeg('b');
            charVector.print();
        cout <<"charVector.insertEnd('c'):" << endl;
            charVector.insertEnd('c');
            charVector.print();
        cout <<"charVector.insertEnd('d'):" << endl;
            charVector.insertEnd('d');
            charVector.print();
        cout <<"charVector.insertBeg('e'):" << endl;
            charVector.insertBeg('e');
            charVector.print();
        cout <<"charVector.removeEnd():" << endl;
            charVector.removeEnd();
            charVector.print();
        cout <<"charVector.removeBeg():" << endl;
            charVector.removeBeg();
            charVector.print();

    //Vector char 2
        cout <<"charVector2.created: no elements at the beginning" << endl;
        myVector<char> charVector2 = myVector<char>();
        charVector2.print();
        cout <<"charVector2.insertEnd('a'):" << endl;
            charVector2.insertEnd('a');
            charVector2.print();
        cout <<"charVector2.insertBeg('b'):" << endl;
            charVector2.insertBeg('b');
            charVector2.print();
        cout <<"charVector2.insertEnd('c'):" << endl;
            charVector2.insertEnd('c');
            charVector2.print();
        cout <<"charVector2.insertEnd('d'):" << endl;
            charVector2.insertEnd('d');
            charVector2.print();
        cout <<"charVector2.insertBeg('e'):" << endl;
            charVector2.insertBeg('e');
            charVector2.print();
        cout <<"charVector2.removeEnd():" << endl;
            charVector2.removeEnd();
            charVector2.print();
        cout <<"charVector2.removeBeg():" << endl;
            charVector2.removeBeg();
            charVector2.print();
        if (charVector == charVector2)
        {
            cout <<"Character vectors are the same!";
        }
        else
        {
            cout <<"Character vectors are not the same!";
        }
    return 0;
}
