#include <iostream>
using namespace std;

class Hello
{
public:
    Hello()
    {
        cout << "Constructor called \n";
    }

    ~Hello()
    {
        cout << "Desstructor called \n";
    }
};

int main()
{
    Hello obj1;
    Hello obj2;

    return 0;
}