#include <iostream>
#include <vector>
#include <stack>
#include <limits.h>
using namespace std;

/*
Given an integer array arr of integers, the task is to find the maximum absolute difference between the nearest left
smaller element and the nearest right smaller element of every element in array arr. If for any component of the arr,
the nearest smaller element doesn't exist then consider it as 0.

Examples :

Input: arr = [2, 1, 8]
Output: 1
Explanation: left smaller array ls = [0, 0, 1], right smaller array rs = [1, 0, 0]. Maximum Diff of abs(ls[i] - rs[i]) = 1

Input: arr = [2, 4, 8, 7, 7, 9, 3]
Output: 4
Explanation: left smaller array ls = [0, 2, 4, 4, 4, 7, 2], right smaller rs = [0, 3, 7, 3, 3, 3, 0]. Maximum Diff of
abs(ls[i] - rs[i]) = abs(7 - 3) = 4


Expected Time Complexity: O(n)
Expected Space Complexity: O(n)

Constraints:
1 <= arr.size() <= 106
1<= arr[i] <=109
*/

int findMaxDiff(vector<int> &arr)
{
    int n = arr.size(), maxDiff = INT_MIN;
    vector<int> left(n, 0), right(n, 0);

    stack<int> stk;
    // for left arr
    for (int i = 0; i < n; i++)
    {
        // pop element from stack until top element of stack becomes lower than the current arr[i];
        while (!stk.empty() && stk.top() >= arr[i])
            stk.pop();

        // if stack is not empty than push the stack top in the left array
        if (!stk.empty())
            left[i] = stk.top();

        // push the current arr[i] in to the stack
        stk.push(arr[i]);
    }

    while (!stk.empty())
        stk.pop();

    // for right arr
    for (int i = n - 1; i >= 0; i--)
    {
        // pop element from stack until top element of stack becomes lower than the current arr[i];
        while (!stk.empty() && stk.top() >= arr[i])
            stk.pop();

        // if stack is not empty than push the stack top in the left array
        if (!stk.empty())
            right[i] = stk.top();

        // push the current arr[i] in to the stack
        stk.push(arr[i]);
    }

    // calculate maximum absolute difference
    for (int i = 0; i < n; i++)
    {
        maxDiff = max(maxDiff, abs(left[i] - right[i]));
    }

    return maxDiff;
}

int main()
{
    vector<int> arr = {2, 4, 8, 7, 7, 9, 3};
    cout << "Answer = " << findMaxDiff(arr) << endl;
    return 0;
}