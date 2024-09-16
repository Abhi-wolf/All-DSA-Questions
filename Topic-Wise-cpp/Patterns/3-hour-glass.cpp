#include <iostream>
using namespace std;

/*

* * * * * * * * * * *
  * * * * * * * * *
    * * * * * * *
      * * * * *
        * * *
          *
        * * *
      * * * * *
    * * * * * * *
  * * * * * * * * *
* * * * * * * * * * *

*/

void hourGlassPattern(int n)
{
    for (int i = 1; i <= (2 * n - 1); i++)
    {
        if (i <= n)
        {
            // space
            for (int j = 1; j < i; j++)
                cout << "  ";

            // star
            for (int j = 1; j <= (n - i + 1); j++)
                cout << "* ";

            // star
            for (int j = 1; j <= (n - i); j++)
                cout << "* ";
        }
        else
        {
            for (int j = 1; j < (2 * n - i); j++)
                cout << "  ";

            for (int j = 1; j <= (i - n + 1); j++)
                cout << "* ";

            for (int j = 1; j <= (i - n); j++)
                cout << "* ";
        }
        cout << endl;
    }
}

int main()
{
    hourGlassPattern(6);

    return 0;
}