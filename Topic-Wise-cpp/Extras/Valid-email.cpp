#include <iostream>
using namespace std;

bool isChar(char ch)
{
    return ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'));
}

bool isDigit(char ch)
{
    return (ch >= '0' && ch <= '9');
}

bool isValidEmail(string email)
{
    if (!isChar(email[0]))
        return 0;

    int at = -1, dot = -1;

    for (int i = 0; i < email.length(); i++)
    {
        if (email[i] == '@')
            at = i;
        else if (email[i] == '.')
            dot = i;
    }

    if (at == -1 || dot == -1)
        return 0;

    cout << "dot=" << dot << ", at=" << at << endl;

    if (dot < at)
        return 0;

    return !(dot >= (email.length() - 1));
}
int main()
{
    if (isValidEmail("revie.w-team@geeksforgeeksorg"))
    {
        cout << "Valid \n";
    }
    else
    {
        cout << "Invalid \n";
    }
    return 0;
}