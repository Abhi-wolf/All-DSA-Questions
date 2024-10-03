#include <iostream>
using namespace std;

bool isDigit(char ch)
{
    return (ch >= '0' && ch <= '9');
}

bool isvalidPhone(string str)
{
    int size = str.size();
    if (size > 12 || size < 10)
        return false;

    /*
The first digit should contain numbers between 6 to 9.
The rest 9 digit can contain any number between 0 to 9.
The mobile number can have 11 digits also by including 0 at the starting.
The mobile number can be of 12 digits also by including 91 at the starting
    */
    int i = 0;
    if (size == 11)
    {
        if (str[0] == '0')
            i++;
        else
            return false;
        cout << "11 \n";
    }
    else if (size == 12)
    {
        if (str[0] == '9' && str[i] == '1')
            i += 2;
        else
            return false;
        cout << "12 \n";
    }
    else
    {
        if (str[i] < '6')
            return false;
        else
            i++;
        cout << "10 \n";
    }

    while (i < size)
    {
        if (!isDigit(str[i]))
            return false;
        i++;
    }

    return true;
}

int main()
{
    if (isvalidPhone("7873923408"))
    {
        cout << "Valid phone \n";
    }
    else
    {
        cout << "InValid phone \n";
    }

    if (isvalidPhone("5873923408"))
    {
        cout << "Valid phone \n";
    }
    else
    {
        cout << "InValid phone \n";
    }
    return 0;
}