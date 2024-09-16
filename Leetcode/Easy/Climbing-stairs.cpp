#include <iostream>
#include <vector>
using namespace std;

/*
    You are climbing a staircase. It takes n steps to reach the top.
Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

Example 1:
Input: n = 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps

Example 2:
Input: n = 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step

Constraints:    1 <= n <= 45
*/

// FIRST METHOD
void solve1(int n, int &ans)
{
    if (n == 0)
    {
        ans++;
        return;
    }

    if (n < 0)
        return;

    solve1(n - 1, ans);
    solve1(n - 2, ans);
}

// SECOND METHOD
int solve2(int n)
{
    if (n <= 0)
        return 0;

    if (n == 1)
        return 1;

    if (n == 2)
        return 2;

    return (solve2(n - 1) + solve2(n - 2));
}

// THIRD METHOD -- USING DP
int solveDP(int n, vector<int> &dp)
{
    if (n <= 0)
        return 0;

    if (n == 1)
        return 1;

    if (n == 2)
        return 2;

    if (dp[n] != -1)
        return dp[n];

    dp[n] = solveDP(n - 1, dp) + solveDP(n - 2, dp);

    return dp[n];
}
int main()
{
    int arr[10] = {1, 2, 4, 5, 6, 9, 10, 15, 20, 42};

    // first method
    for (int i = 0; i < 10; i++)
    {
        int ans = 0;
        solve1(arr[i], ans);
        cout << "For " << arr[i] << " steps no 0f ways to climb = " << ans << endl;
    }
    cout << "\n\n";

    // second method
    for (int i = 0; i < 10; i++)
    {
        cout << "For " << arr[i] << " steps no 0f ways to climb = " << solve2(arr[i]) << endl;
    }

    cout << "\n\n";
    // third method
    for (int i = 0; i < 10; i++)
    {
        vector<int> dp(arr[i] + 1, -1);
        cout << "For " << arr[i] << " steps no 0f ways to climb = " << solveDP(arr[i], dp) << endl;
    }

    return 0;
}
