#include <iostream>
using namespace std;

/*

                  *
                * *
              * * *
            * * * *
          * * * * *
        * * * * * *
      * * * * * * *
    * * * * * * * *
  * * * * * * * * *
* * * * * * * * * *

*/

void pattern1(int n)
{
    for (int i = 1; i <= n; i++)
    {
        // space
        for (int j = 1; j <= (n - i); j++)
            cout << "  ";

        // star
        for (int j = (n - i); j < n; j++)
            cout << "* ";
        cout << endl;
    }
}

/*

* * * * * * * * * *
  * * * * * * * * *
    * * * * * * * *
      * * * * * * *
        * * * * * *
          * * * * *
            * * * *
              * * *
                * *
                  *

*/

void pattern2(int n)
{
    for (int i = 1; i <= n; i++)
    {
        // space
        for (int j = 1; j < i; j++)
            cout << "  ";

        // star
        for (int j = 1; j <= (n - i + 1); j++)
            cout << "* ";

        cout << endl;
    }
}

/*
*
* *
* * *
* * * *
* * *
* *
*

*/

void pattern3(int n)
{
    for (int row = 1; row <= (2 * n - 1); row++)
    {
        if (row <= n)
        {
            for (int col = 1; col <= row; col++)
                cout << "*  ";
            cout << endl;
        }
        else
        {
            for (int col = 1; col <= (2 * n - row); col++)
                cout << "*  ";
            cout << endl;
        }
    }
}

int main()
{
    // pattern1(10);
    pattern2(10);
    // pattern3(10);
    return 0;
}