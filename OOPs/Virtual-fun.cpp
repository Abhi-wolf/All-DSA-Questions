#include <iostream>
using namespace std;

class Base
{
public:
    virtual void print()
    {
        cout << "Print base class \n";
    }

    void show()
    {
        cout << "Show base class \n";
    }
};

class Derived : public Base
{
public:
    void print()
    {
        cout << "Print derived class \n";
    }

    void show()
    {
        cout << "Show derived class \n";
    }
};

int main()
{
    Base *ptr;
    Derived obj1;
    ptr = &obj1;

    // virtual function, binded at runtime
    ptr->print();

    // non-virtual function, binded at compile time
    ptr->show();
    return 0;
}