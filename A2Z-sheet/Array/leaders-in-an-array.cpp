#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>
using namespace std;

/* Given an array arr of n positive integers, your task is to find all the leaders in the array. An element of the array is considered a leader if it is greater than all the elements on its right side or if it is equal to the maximum element on its right side. The rightmost element is always a leader.

Examples

Input: n = 6, arr[] = {16,17,4,3,5,2}
Output: 17 5 2
Explanation: Note that there is nothing greater on the right side of 17, 5 and, 2.
Input: n = 5, arr[] = {10,4,2,4,1}
Output: 10 4 4 1
Explanation: Note that both of the 4s are in output, as to be a leader an equal element is also allowed on the right. side
Input: n = 4, arr[] = {5, 10, 20, 40}
Output: 40
Explanation: When an array is sorted in increasing order, only the rightmost element is leader.
Input: n = 4, arr[] = {30, 10, 10, 5}
Output: 30 10 10 5
Explanation: When an array is sorted in non-increasing order, all elements are leaders.
Expected Time Complexity: O(n)
Expected Auxiliary Space: O(n)

Constraints:
1 <= n <= 107
0 <= arr[i] <= 107 */

vector<int> leaders(int n, int a[])
{
    vector<int> arr;
    int max1 = a[n - 1], i;

    arr.push_back(max1); // last element is always a leader

    for (i = n - 2; i >= 0; i--)
    { // iterate from second last element to first element

        max1 = max(max1, a[i]); // keep track of maximum so far

        if (a[i] == max1)
        { // if maximum so far equals the current element
            // push it to vector
            arr.push_back(a[i]);
        }
    }

    reverse(arr.begin(), arr.end()); // reverse the vector

    // to change 2 5 17 --> 17 5 2

    return arr;
}

vector<int> leaders2(int n, int arr[])
{
    vector<int> dp(n), res;
    int maxi = arr[n - 1];

    for (int i = n - 1; i >= 0; i--)
    {
        maxi = max(maxi, arr[i]);
        dp[i] = maxi;
    }

    for (int i = 0; i < n; i++)
    {
        if (dp[i] == arr[i])
            res.push_back(dp[i]);
    }
    return res;
}

int main()
{
    int arr[] = {16, 17, 4, 3, 5, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    vector<int> res1, res2;
    res1 = leaders(n, arr);
    res2 = leaders2(n, arr);

    return 0;
}