#include <iostream>
using namespace std;

namespace Add
{
    int a = 5, b = 6;
    int add()
    {
        return (a + b);
    }
}

int main()
{
    int res = Add::add();
    cout << res << endl;
    return 0;
}