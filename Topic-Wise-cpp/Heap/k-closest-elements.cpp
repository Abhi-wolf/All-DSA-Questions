#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

/*
Given a sorted array of unique elements in increasing order, arr[] of n integers, and a value x. Find the K closest
elements to x in arr[].
Keep the following points in mind:

If x is present in the array, then it need not be considered.
If two elements have the same difference as x, the greater element is prioritized.
If sufficient elements are not present on the right side, take elements from the left and vice versa.

Example 1:
Input:
n = 13
arr[] = {12, 16, 22, 30, 35, 39, 42,
         45, 48, 50, 53, 55, 56}
k = 4, x = 35
Output: 39 30 42 45
Explanation:
First closest element to 35 is 39.
Second closest element to 35 is 30.
Third closest element to 35 is 42.
And fourth closest element to 35 is 45.

Example 2:
Input:
n = 5
arr[] = {1, 2, 3, 6, 10}
k = 3, x = 4
Output: 3 6 2
Explanation:
First closest element is 3.
There are two elements 2 and 6 for which
the difference with 4 is same i.e. 2.
So first take greatest number 6
then the lower number 2.

Your Task:
You don't need to read input or print anything. Complete the function printKClosest() which takes arr[], n, k, and x
as input parameters and returns an array of integers containing the K closest elements to x in arr[].

Expected Time Complexity: O(log n + k)
Expected Auxiliary Space: O(k)

Constraints:
1 ≤ n ≤ 105
1 ≤ k ≤ n
1 ≤ x ≤ 106
1 ≤ arr[i] ≤ 106
*/

// binary search
int findCrossOver(vector<int> arr, int key)
{
    int start = 0, end = arr.size() - 1;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        if (arr[mid] == key)
            return mid;
        else if (arr[mid] <= key)
            start = mid + 1;
        else
            end = mid - 1;
    }

    return start - 1;
}

// USING BINARY SEARCH -- TC = O(logn + k), SC = O(1)
vector<int> printKClosest1(vector<int> arr, int n, int k, int x)
{
    // find the crossover point
    int left = findCrossOver(arr, x);

    int right = left + 1; // right index to search
    int count = 0;        // to keep track of count of elements
    vector<int> ans;

    // if x is present in arr, then reduce left index
    if (arr[left] == x)
        left--;

    // compare elements on left and right of the crossover
    // point to find the k closest elements
    while (left >= 0 && right < n && count < k)
    {
        if (x - arr[left] < arr[right] - x)
            ans.push_back(arr[left--]);
        else
            ans.push_back(arr[right++]);

        count++;
    }

    // If there are no more elements on right side, then
    // move to left elements
    while (left >= 0 && count < k)
    {
        ans.push_back(arr[left--]);
        count++;
    }

    // If there are no more elements on left side, then
    // move to right elements
    while (right < n && count < k)
    {
        ans.push_back(arr[right++]);
        count++;
    }

    return ans;
}

// USING PRIORITY QUEUE -- TC = O(nlogk)  SC = O(k)
vector<int> printKClosest2(vector<int> arr, int n, int k, int x)
{
    priority_queue<pair<int, int>> maxheap;
    vector<int> ans;

    for (int num : arr)
    {
        // negative for (If two elements have the same difference as x, the greater element is prioritized)
        if (num != x)
            maxheap.push({abs(x - num), -num});

        if (maxheap.size() > k)
            maxheap.pop();
    }

    while (!maxheap.empty())
    {
        ans.push_back(-1 * maxheap.top().second);
        maxheap.pop();
    }

    reverse(ans.begin(), ans.end());
    return ans;
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

int main()
{
    vector<int> arr = {12, 16, 22, 30, 35, 39, 42,
                       45, 48, 50, 53, 55, 56};
    vector<int> ans = printKClosest1(arr, 13, 4, 35);
    Display1DArray(ans);
    arr = {1, 2, 3, 6, 10};
    ans = printKClosest1(arr, 5, 3, 4);
    Display1DArray(ans);
    return 0;
}