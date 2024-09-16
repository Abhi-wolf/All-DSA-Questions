#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>
using namespace std;

/*
Find the largest rectangular area possible in a given histogram where the largest rectangle can be
made of a number of contiguous bars. For simplicity, assume that all bars have the same width and
the width is 1 unit, there will be N bars height of each bar will be given by the array arr.

Example 1:
Input:
N = 7
arr[] = {6,2,5,4,5,1,6}
Output: 12
Explanation: In this example the largest area would be 12 of height 4 and width 3. We can achieve this
area by choosing 3rd, 4th and 5th bars.


Example 2:
Input:
N = 8
arr[] = {7 2 8 9 1 3 6 5}
Output: 16
Explanation: Maximum size of the histogram will be 8  and there will be 2 consecutive
histogram. And hence the area of the histogram will be 8x2 = 16.

Your Task:
The task is to complete the function getMaxArea() which takes the array arr[] and its size N as inputs
and finds the largest rectangular area possible and returns the answer.

Expected Time Complxity : O(N)
Expected Auxilliary Space : O(N)

Constraints:
1 ≤ N ≤ 106
0 ≤ arr[i] ≤ 1012
*/

// TLE
long long getMaxArea(long long arr[], int n)
{
    int maxArea = 0;

    for (int i = 0; i < n; i++)
    {
        int left = i, right = i + 1;

        while (left >= 0 && arr[left] >= arr[i])
            left--;
        while (right < n && arr[right] >= arr[i])
            right++;

        int width = right - left - 1;
        int area = width * arr[i];

        maxArea = max(maxArea, area);
    }
    return maxArea;
}

void Display1DArray(vector<int> arr)
{
    cout << endl;
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " , ";
    }
    cout << endl;
}

long long getMaxArea2(long long arr[], int n)
{
    vector<long long> index(n);
    stack<long long> stk;
    long long maxArea = 0;

    // first calculate right smallest
    for (int i = n - 1; i >= 0; i--)
    {
        while (!stk.empty() && arr[stk.top()] >= arr[i])
            stk.pop();

        // if there's no smaller height (store n index)
        if (stk.empty())
            index[i] = n;
        else
        {
            index[i] = stk.top();
        }
        stk.push(i);
    }

    while (!stk.empty())
        stk.pop();

    // second calculate left smallest
    for (int i = 0; i < n; i++)
    {
        while (!stk.empty() && arr[stk.top()] >= arr[i])
            stk.pop();

        // if there's no smaller height (store -1 index)
        if (stk.empty())
            index[i] -= -1;
        else
        {
            index[i] -= stk.top();
        }
        stk.push(i);
    }

    for (int i = 0; i < n; i++)
    {
        long long area = arr[i] * (index[i] - 1);
        maxArea = max(area, maxArea);
    }

    return maxArea;
}
int main()
{
    // long long arr[] = {6, 2, 5, 4, 5, 1, 6};
    long long arr[] = {7, 2, 8, 9, 1, 3, 6, 5};
    // long long arr[] = {6, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Maximum area = " << getMaxArea2(arr, n) << endl;
    return 0;
}