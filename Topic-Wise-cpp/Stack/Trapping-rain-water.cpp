#include <iostream>
using namespace std;

/*
Given an array arr[] of N non-negative integers representing the height of blocks. If width of each block is 1,
compute how much water can be trapped between the blocks during the rainy season.


Example 1:
Input: N = 6
arr[] = {3,0,0,2,0,4}
Output: 10
Explanation:

Example 2:
Input: N = 4
arr[] = {7,4,0,9}
Output: 10
Explanation:
Water trapped by above block of height 4 is 3 units and above
block of height 0 is 7 units. So, the total unit of water trapped is 10 units.

Example 3:
Input: N = 3
arr[] = {6,9,9}
Output: 0
Explanation:
No water will be trapped.

Your Task:
You don't need to read input or print anything. The task is to complete the function trappingWater()
which takes arr[] and N as input parameters and returns the total amount of water that can be trapped.


Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)


Constraints:
3 < N < 106
0 < Ai < 108

*/

long long trappingWater(int arr[], int n)
{
    long long ans = 0;

    int maxLeft[n], maxRight[n];
    int maxi = arr[0];

    // calculate maximum of left
    for (int i = 0; i < n; i++)
    {
        maxi = max(maxi, arr[i]);
        maxLeft[i] = maxi;
    }

    maxi = arr[n - 1];
    // calculate maximum of right
    for (int i = n - 1; i >= 0; i--)
    {
        maxi = max(maxi, arr[i]);
        maxRight[i] = maxi;
    }

    // find minimum of both the leftmaximum and rightmaximum
    for (int i = 0; i < n; i++)
    {
        maxLeft[i] = min(maxLeft[i], maxRight[i]);
        // calculate ans = maximum height to hold water for an index - height of index
        ans += (maxLeft[i] - arr[i]);
    }

    return ans;
}

int main()
{
    int arr[] = {7, 4, 0, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Answer = " << trappingWater(arr, n) << endl;
    return 0;
}