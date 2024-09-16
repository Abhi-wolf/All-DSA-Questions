#include <iostream>
using namespace std;

/*
              *
            * * *
          * * * * *
        * * * * * * *
      * * * * * * * * *
    * * * * * * * * * * *
  * * * * * * * * * * * * *
* * * * * * * * * * * * * * *

 */

void trianglePattern(int n)
{
    for (int i = 1; i <= n; i++)
    {
        // space
        for (int j = 1; j <= (n - i); j++)
            cout << "  ";

        // star (for first right angled triangle)
        for (int j = (n - i); j < n; j++)
            cout << "* ";

        // star (for second right angled trianle)
        for (int j = 1; j < i; j++)
            cout << "* ";

        cout << endl;
    }
}

/*
 * * * * * * * * * * * * * * *
   * * * * * * * * * * * * *
     * * * * * * * * * * *
       * * * * * * * * *
         * * * * * * *
           * * * * *
             * * *
               *

 */
void inverseTriangle(int n)
{
    for (int i = 1; i <= n; i++)
    {
        // space
        for (int j = 1; j < i; j++)
            cout << "  ";

        // star (for first right angled triangle)
        for (int j = 1; j <= (n - i + 1); j++)
            cout << "* ";

        // star (for first right angled triangle)
        for (int j = 1; j <= (n - i); j++)
            cout << "* ";

        cout << endl;
    }
}

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

void trianlgePattern2(int n)
{
    for (int i = 1; i <= n; i++)
    {
        // space
        for (int j = 1; j <= (n - i); j++)
            cout << " ";

        // star
        for (int j = (n - i); j < n; j++)
            cout << "* ";
        cout << endl;
    }
}

/*

       *
      ***
     *****
    *******
   *********
  ***********
 *************
***************
 *************
  ***********
   *********
    *******
     *****
      ***
       *

*/
void conicalUpperAndLower(int n)
{
    for (int i = 1; i <= (2 * n - 1); i++)
    {
        // upper
        if (i <= n)
        {
            // space
            for (int j = 1; j <= (n - i); j++)
                cout << " ";

            // star
            for (int j = n - i; j < n; j++)
                cout << "*";

            // star
            for (int j = 1; j < i; j++)
                cout << "*";
        }
        else
        {
            // space
            for (int j = n; j < i; j++)
                cout << " ";

            // star
            for (int j = 1; j <= (2 * n - i); j++)
                cout << "*";

            // star
            for (int j = 1; j <= (2 * n - 1 - i); j++)
                cout << "*";
        }
        cout << endl;
    }
}

/*

       *
      * *
     * * *
    * * * *
   * * * * *
  * * * * * *
 * * * * * * *
* * * * * * * *
 * * * * * * *
  * * * * * *
   * * * * *
    * * * *
     * * *
      * *
       *

*/

void conicalUpperAndLower2(int n)
{
    for (int i = 1; i <= (2 * n - 1); i++)
    {
        if (i <= n)
        {
            // space
            for (int j = 1; j <= (n - i); j++)
                cout << " ";

            // star
            for (int j = (n - i); j < n; j++)
                cout << "* ";
        }
        else
        {
            // space
            for (int j = n; j < i; j++)
                cout << " ";

            // star
            for (int j = 1; j <= (2 * n - i); j++)
                cout << "* ";
        }
        cout << endl;
    }
}

int main()
{
    // trianglePattern(30);
    // inverseTriangle(8);

    conicalUpperAndLower2(8);
    return 0;
}