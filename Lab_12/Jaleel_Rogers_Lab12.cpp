/***************************************************************************
 * Title:               Lab 12
 * Author:              Jaleel Rogers
 * Email:               jrogers1239@floridapoly.edu
 * Creation date:       12/06/2022 @ 11:20 AM
 * Modification date:   12/06/2022 @ 8:30 PM
 * Description: Write a complete C++ program and create 13 classes that form a class tree as shown in the following Figure.
                    •Every class has only one no-argument constructor, one destructor,  no property,
                    and one regular method called toString().
                    •Inside of the no-argument constructor of classname, there is only one output
                    statement to print "√ classname constructor called.". The number of √ equals
                    the level of this class. Add a line break at the end of the printout.
                    •Inside of the destructor of classname, there is only one output statement to print
                    "✕ classname destructor called.". The number of ✕ equals the level of this
                    class. Add a line break at the end of the printout.
                    •Inside of the toString() function, there is only one output statement to
                    print “= classname constructor called.”. The number of = equals the level
                    of this class. Add a line break at the end of the printout.
                    •There is no need to split the code in different files, due to the simplicity of all
                    classes. Therefore, place all 13 classes and the main function in a single
                    source file.
 * ***************************************************************************/
#include <iostream>
using namespace std;
class LivingThing //1st Level
{
public:
    LivingThing()
    {
        cout <<"√ LivingThing constructor called.\n";
    }
    ~LivingThing()
    {
        cout <<"✕ LivingThing destructor called.\n";
    }
    void virtual toString() const
    {
        cout <<"= LivingThing toString called.\n";
    }
};

class Animal : public LivingThing //2nd Level
{
public:

    Animal()
    {
        cout <<"√√ Animal constructor called.\n";
    }
    ~Animal()
    {
        cout <<"✕✕ Animal destructor called.\n";
    }
    void toString() const
    {
        cout <<"== Animal toString called.\n";
    }
};

class Mammal : public Animal //3rd Level
{
public:
    Mammal()
    {
        cout <<"√√√ Mammal constructor called.\n";
    }
    ~Mammal()
    {
        cout <<"✕✕✕ Mammal destructor called.\n";
    }
    void toString() const
    {
        cout <<"=== Mammal toString called.\n";
    }
};

class Cat : public Mammal //4th Level
{
public:
    Cat()
    {
        cout <<"√√√√ Cat constructor called.\n";
    }
    ~Cat()
    {
        cout <<"✕✕✕✕ Cat destructor called.\n";
    }
    void toString() const
    {
        cout <<"==== Cat toString called.\n";
    }
};

class Tiger : public Cat //5th Level
{
public:
    Tiger()
    {
        cout <<"√√√√√ Tiger constructor called.\n";
    }
    ~Tiger()
    {
        cout <<"✕✕✕✕✕ Tiger destructor called.\n";
    }
    void toString() const
    {
        cout <<"===== Tiger toString called.\n";
    }
};

class Lion : public Cat //5th Level
{
public:
    Lion()
    {
        cout <<"√√√√√ Lion constructor called.\n";
    }
    ~Lion()
    {
        cout <<"✕✕✕✕✕ Lion destructor called.\n";
    }
    void toString() const
    {
        cout <<"===== Lion toString called.\n";
    }
};

class Plant : public LivingThing //2nd Level
{
public:
    Plant()
    {
        cout <<"√√ Plant constructor called.\n";
    }
    ~Plant()
    {
        cout <<"✕✕ Plant destructor called.\n";
    }
    void toString() const
    {
        cout <<"== Plant toString called.\n";
    }
};

class Fish : public Animal //3rd Level
{
public:
    Fish()
    {
        cout <<"√√√ Fish constructor called.\n";
    }
    ~Fish()
    {
        cout <<"✕✕✕ Fish destructor called.\n";
    }
    void toString() const
    {
        cout <<"=== Fish toString called.\n";
    }
};

class Sardine : public Fish //4th Level
{
public:
    Sardine()
    {
        cout <<"√√√√ Sardine constructor called.\n";
    }
    ~Sardine()
    {
        cout <<"✕✕✕✕ Sardine destructor called.\n";
    }
    void toString() const
    {
        cout <<"==== Sardine toString called.\n";
    }
};

class Bass : public Fish //4th Level
{
public:
    Bass()
    {
        cout <<"√√√√ Bass constructor called.\n";
    }
    ~Bass()
    {
        cout <<"✕✕✕✕ Bass destructor called.\n";
    }
    void toString() const
    {
        cout <<"==== Bass toString called.\n";
    }
};

class Tree : public Plant //3rd Level
{
public:
    Tree()
    {
        cout <<"√√√ Tree constructor called.\n";
    }
    ~Tree()
    {
        cout <<"✕✕✕ Tree destructor called.\n";
    }
    void toString() const
    {
        cout <<"=== Tree toString called.\n";
    }
};

class Chestnut : public Tree //4th Level
{
public:
    Chestnut()
    {
        cout <<"√√√√ Chestnut constructor called.\n";
    }
    ~Chestnut()
    {
        cout <<"✕✕✕✕ Chestnut destructor called.\n";
    }
    void toString() const
    {
        cout <<"==== Chestnut toString called.\n";
    }
};

class Cherry : public Tree //4th Level
{
public:
    Cherry()
    {
        cout <<"√√√√ Cherry constructor called.\n";
    }
    ~Cherry()
    {
        cout <<"✕✕✕✕ Cherry destructor called.\n";
    }
    void toString() const
    {
        cout <<"==== Cherry toString called.\n";
    }
};

void display(const LivingThing &obj)
{
    cout << "Display ";
    obj.toString();
}
int main()
{
    cout <<"Create sardine:" <<endl;
        Sardine sardineObject;
        cout<<endl;
    cout <<"Creat bass:" << endl;
        Bass bassObject;
        cout<<endl;
    cout << "Create tiger:" << endl;
        Tiger tigerObject;
        cout<<endl;
    cout << "Create lion:" << endl;
        Lion lionObject;
        cout<<endl;
    cout << "Create chestnut:" << endl;
        Chestnut chestnutObject;
        cout<<endl;
    cout << "Create cherry:" << endl;
        Cherry cherryObject;
        cout<<endl;
    cout <<"Create tree:" <<endl;
        Tree treeObject;
        cout<<endl;

    treeObject.toString();
        display(treeObject);

    cout<< "Create animal" <<endl;
        Animal animalObject;
        cout<<endl;

    animalObject.toString();
        display(animalObject);
        cout<<endl;

    cout<< "Call display on six objects of the six leaf classes respectively:" <<endl;
        display(sardineObject);
        display(bassObject);
        display(tigerObject);
        display(lionObject);
        display(chestnutObject);
        display(cherryObject);
        cout<<endl;

    cout<< "destruction started..."<<endl;

    return 0;
}
