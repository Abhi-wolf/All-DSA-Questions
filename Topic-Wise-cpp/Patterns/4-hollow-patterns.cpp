#include <iostream>
using namespace std;

/*

* * * * * *
*         *
*         *
*         *
*         *
* * * * * *

*/
void hollowSquare(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == 1 || i == n || j == 1 || j == n)
                cout << "* ";
            else
                cout << "  ";
        }
        cout << endl;
    }
}

/*

          *
        *   *
      *       *
    *           *
  *               *
* * * * * * * * * * *

*/

void hollowFullPyramid(int n)
{
    for (int i = 1; i <= n; i++)
    {
        // space
        for (int j = 1; j <= (n - i); j++)
            cout << "  ";

        // star (for first right angled triangle)
        for (int j = (n - i); j < n; j++)
        {
            if (j == (n - i) || i == n)
                cout << "* ";
            else
                cout << "  ";
        }

        // star (for second right angled trianle)
        for (int j = 1; j < i; j++)
        {
            if (j == i - 1 || i == n)
                cout << "* ";
            else
                cout << "  ";
        }

        cout << endl;
    }
}

/*

* * * * * * * * * * *
  *               *
    *           *
      *       *
        *   *
          *

*/

void hollowInversePyramid(int n)
{
    for (int i = 1; i <= n; i++)
    {
        // space
        for (int j = 1; j < i; j++)
            cout << "  ";

        // star (for first right angled triangle)
        for (int j = 1; j <= (n - i + 1); j++)
        {
            if (j == 1 || i == 1)
                cout << "* ";
            else
                cout << "  ";
        }

        // star (for first right angled triangle)
        for (int j = 1; j <= (n - i); j++)
        {
            if (j == (n - i) || i == 1)
                cout << "* ";
            else
                cout << "  ";
        }

        cout << endl;
    }
}
int main()
{
    // hollowSquare(6);
    // hollowFullPyramid(6);
    hollowInversePyramid(6);
    return 0;
}