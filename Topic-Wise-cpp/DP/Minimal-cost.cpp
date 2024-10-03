#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

/*
There is an array arr of heights of stone and Geek is standing at the first stone and can
jump to one of the following: Stone i+1, i+2, ... i+k stone, where k is the maximum number
of steps that can be jumped and cost will be |hi-hj| is incurred, where j is the stone to
land on. Find the minimum possible total cost incurred before the Geek reaches the last
stone.

Example:

Input: k = 3, arr[]= [10, 30, 40, 50, 20]
Output: 30
Explanation: Geek will follow the path 1->2->5, the total cost would be | 10-30| + |30-20| = 30, which is minimum
Input: k = 1, arr[]= [10, 20, 10]
Output: 20
Explanation: Geek will follow the path 1->2->3, the total cost would be |10 - 20| + |20 - 10| = 20.
Expected Time Complexity: O(n*k)
Expected Auxilary Space: O(n)

Constraint:
1<= arr.size() <=104
1 <= k <= 100
1 <= arr[i] <= 104
*/

void solve(vector<int> &arr, int ind, int k, int sum, int &ans)
{

    if (ind == arr.size() - 1)
    {
        ans = min(ans, sum);
        return;
    }

    if (ind >= arr.size())
    {
        return;
    }

    for (int i = ind + 1; i <= ind + k && i < arr.size(); i++)
    {
        solve(arr, i, k, sum + abs(arr[ind] - arr[i]), ans);
    }
}

int minimizeCost(int k, vector<int> &arr)
{
    int ans = INT_MAX, sum = 0;
    solve(arr, 0, k, sum, ans);
    return ans;
}

int solve2(vector<int> &arr, int ind, int k, vector<int> &dp)
{

    if (ind == arr.size() - 1)
    {
        return 0;
    }

    if (ind >= arr.size())
    {
        return INT_MAX;
    }

    if (dp[ind] != -1)
        return dp[ind];

    int cost = INT_MAX;
    for (int i = 1; i <= k && i + ind < arr.size(); i++)
    {
        cost = min(cost, abs(arr[ind] - arr[ind + i]) + solve2(arr, i + ind, k, dp));
    }

    return dp[ind] = cost;
}

int minimizeCost2(int k, vector<int> &arr)
{
    int ans = INT_MAX, sum = 0;
    vector<int> dp(arr.size() + 1, -1);
    return solve2(arr, 0, k, dp);
}

int main()
{
    vector<int> arr = {10, 30, 40, 50, 20};
    cout << minimizeCost(3, arr) << endl;
    cout << minimizeCost2(3, arr) << endl;
    return 0;
}