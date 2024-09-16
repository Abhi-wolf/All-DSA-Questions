#include <iostream>
#include <vector>
#include <stack>
using namespace std;

/*
You are given an array arr, you need to find any three elements in it such that arr[i] < arr[j] < arr[k]
and i < j < k.

Note:
The output will be 1 if the subsequence returned by the function is present in the array arr
If the subsequence is not present in the array then return an empty array, the driver code will print 0.
If the subsequence returned by the function is not in the format as mentioned then the output will be -1.

Examples :
Input: arr = [1, 2, 1, 1, 3]
Output: 1
Explanation: A subsequence 1 2 3 exist.

Input: arr = [1, 1, 3]
Output: 0
Explanation: No such Subsequence exist, so empty array is returned (the driver code automatically prints 0 in this case).

Expected Time Complexity: O(n)
Expected Auxiliary Space: O(n)

Constraints:
1 <= arr.size() <= 105
1 <= arr[i] <= 106
*/

vector<int> find3Numbers(vector<int> &arr)
{
    int n = arr.size();
    if (n < 3)
        return {};

    vector<int> leftsmaller(n, -1), rightlarger(n, -1);
    stack<int> stk;

    // find left smaller element
    for (int i = 0; i < n; i++)
    {
        while (!stk.empty() && stk.top() >= arr[i])
            stk.pop();
        if (!stk.empty())
            leftsmaller[i] = stk.top();
        stk.push(arr[i]);
    }

    // empty stack
    while (!stk.empty())
        stk.pop();

    // find right smaller element
    for (int i = n - 1; i >= 0; i--)
    {
        while (!stk.empty() && stk.top() <= arr[i])
            stk.pop();
        if (!stk.empty())
            rightlarger[i] = stk.top();
        stk.push(arr[i]);
    }

    for (int i = 0; i < n; i++)
    {
        if (leftsmaller[i] == -1 || rightlarger[i] == -1)
            continue;
        return {leftsmaller[i], arr[i], rightlarger[i]};
    }

    return {};
}

int main()
{
    vector<int> arr = {1, 2, 1, 1, 3};
    vector<int> ans = find3Numbers(arr);

    for (int i : ans)
        cout << i << ", ";
    cout << endl;
    return 0;
}