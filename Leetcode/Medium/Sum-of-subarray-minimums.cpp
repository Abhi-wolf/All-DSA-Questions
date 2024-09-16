#include <iostream>
#include <vector>
#include <stack>
using namespace std;

const int MOD = 1e9 + 7;

/*
    Given an array of integers arr, find the sum of min(b), where b ranges over every (contiguous) subarray of arr.
    Since the answer may be large, return the answer modulo 109 + 7.

    Example 1:
    Input: arr = [3,1,2,4]
    Output: 17
    Explanation:
    Subarrays are [3], [1], [2], [4], [3,1], [1,2], [2,4], [3,1,2], [1,2,4], [3,1,2,4].
    Minimums are 3, 1, 2, 4, 1, 1, 2, 1, 1, 1.
    Sum is 17.

    Example 2:
    Input: arr = [11,81,94,43,3]
    Output: 444

    Constraints:
        1 <= arr.length <= 3 * 104
        1 <= arr[i] <= 3 * 104
*/

/*
    Intuition
    To arrive at the solution, we must track two things for each element arr[i]:
        left[i]: the index of the first smaller element to the left of arr[i]
        right[i]: the index of the first element that is less than or equal to arr[i] to the right
    With left[i] and right[i] determined, the number of subarrays in which arr[i] is the minimum can be calculated
        by (i - left[i]) * (right[i] - i).

    The implementation leverages two main concepts: the "Monotonic Stack" pattern and the "Prefix Sum" pattern, to
    efficiently solve the problem without having to evaluate every subarray explicitly.
*/

// optimised solution O(n)
int sumSubarrayMins(vector<int> &arr)
{
    int n = arr.size();
    long long int ans = 0;
    vector<int> left(n), right(n, n);
    stack<int> stk;

    for (int i = 0; i < n; i++)
    {
        while (!stk.empty() && arr[stk.top()] > arr[i])
            stk.pop();

        left[i] = (stk.empty()) ? -1 : stk.top();
        stk.push(i);
    }

    while (!stk.empty())
        stk.pop();

    for (int j = n - 1; j >= 0; j--)
    {
        while (!stk.empty() && arr[stk.top()] >= arr[j])
            stk.pop();

        right[j] = (stk.empty()) ? n : stk.top();
        stk.push(j);
    }

    for (int i = 0; i < n; i++)
    {
        ans = (ans + (long long)(arr[i] * (i - left[i]) * (right[i] - i))) % MOD;
    }

    return (int)ans;
}

// for smaller inputs (not optimised O(n^2))
int sumSubarrayMins2(vector<int> &arr)
{
    int ans = 0;
    int MOD = 1E9 + 7;
    int n = arr.size();

    for (int i = 0; i < n; i++)
        ans += arr[i];

    for (int i = 0; i < n - 1; i++)
    {
        int mn = arr[i];
        int j = i + 1;
        while (j < n)
        {
            if (arr[j] < mn)
                mn = min(mn, arr[j]);

            ans += mn;
            ans %= MOD;
            j++;
        }
    }

    return ans;
}

int main()
{
    vector<int> vec = {3, 1, 2, 4};
    int ans = sumSubarrayMins(vec);
    cout << "Answer = " << ans << endl;
    ans = sumSubarrayMins2(vec);
    cout << "Answer = " << ans << endl;
    return 0;
}
