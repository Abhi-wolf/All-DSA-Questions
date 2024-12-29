#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

/* Given an array arr[] that contains positive and negative integers (may contain 0 as well). Find the
maximum product that we can get in a subarray of arr.
Note: It is guaranteed that the output fits in a 32-bit integer.

Examples
Input: arr[] = [-2, 6, -3, -10, 0, 2]
Output: 180
Explanation: The subarray with maximum product is {6, -3, -10} with product = 6 * (-3) * (-10) = 180.

Input: arr[] = [-1, -3, -10, 0, 60]
Output: 60
Explanation: The subarray with maximum product is {60}.

Input: arr[] = [2, 3, 4]
Output: 24
Explanation: For an array with all positive elements, the result is product of all elements.

Constraints:
1 ≤ arr.size() ≤ 106
-10  ≤  arr[i]  ≤  10*/

int maxProduct(vector<int> &arr)
{
    int maxprod = INT_MIN, n = arr.size();

    for (int i = 0; i < n; i++)
    {
        int prod = arr[i];
        maxprod = max(maxprod, prod);

        for (int j = i + 1; j < n; j++)
        {
            prod *= arr[j];
            maxprod = max(maxprod, prod);
        }
    }

    return maxprod;
}

int maxProduct2(vector<int> &arr)
{
    int maxprod = INT_MIN, n = arr.size();
    int leftToright = 1, rightToLeft = 1;

    for (int i = 0; i < n; i++)
    {
        if (leftToright == 0)
            leftToright = 1;
        if (rightToLeft == 0)
            rightToLeft = 1;

        leftToright *= arr[i];
        rightToLeft *= arr[n - i - 1];

        maxprod = max(maxprod, max(rightToLeft, leftToright));
    }

    return maxprod;
}

int maxProduct3(vector<int> &arr)
{
    int maxprod = arr[0], n = arr.size();
    int currmax = arr[0], currmin = arr[0];

    for (int i = 1; i < n; i++)
    {
        int temp = max({arr[i], arr[i] * currmax, arr[i] * currmin});
        currmin = min({arr[i], arr[i] * currmax, arr[i] * currmin});

        currmax = temp;

        maxprod = max(maxprod, currmax);
    }

    return maxprod;
}

int main()
{
    return 0;
}