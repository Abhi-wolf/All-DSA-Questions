#include <iostream>
using namespace std;

/*

    1
   1 1
  1 2 1
 1 3 3 1
1 4 6 4 1

*/

void pascalsTriangle(int n)
{
    for (int i = 1; i <= n; i++)
    {
        // space
        for (int j = 1; j <= (n - i); j++)
            cout << " ";

        int c = 1;
        for (int k = 1; k <= i; k++)
        {
            cout << c << " ";
            c = (c * (i - k)) / k;
        }
        cout << endl;
    }
}

/*

1
2 3
4 5 6
7 8 9 10
11 12 13 14 15

*/

void floydsTriangle(int n)
{
    int cnt = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << cnt << " ";
            cnt++;
        }
        cout << endl;
    }
}

int main()
{
    pascalsTriangle(5);
    floydsTriangle(5);
    return 0;
}