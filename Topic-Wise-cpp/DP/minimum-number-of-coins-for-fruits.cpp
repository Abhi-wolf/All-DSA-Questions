#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

/*
You are given an integer array prices where prices[i] denotes the number of coins needed to purchase the ith fruit.
The fruit market has the following reward for each fruit:

If you purchase the ith fruit at prices[i] coins, you can get any number of the next (i + 1) fruits for free.
Note that even if you can take fruit j for free, you can still purchase it for prices[j] coins to receive its reward.

Return the minimum number of coins needed to acquire all the fruits.

Example 1:
Input: prices = [3,1,2]
Output: 4

Explanation:
Purchase the 1st fruit with prices[0] = 3 coins, you are allowed to take the 2nd fruit for free.
Purchase the 2nd fruit with prices[1] = 1 coin, you are allowed to take the 3rd fruit for free.
Take the 3rd fruit for free.
Note that even though you could take the 2nd fruit for free as a reward of buying 1st fruit, you purchase it to
receive its reward, which is more optimal.

Example 2:
Input: prices = [1,10,1,1]
Output: 2
Explanation:
Purchase the 1st fruit with prices[0] = 1 coin, you are allowed to take the 2nd fruit for free.
Take the 2nd fruit for free.
Purchase the 3rd fruit for prices[2] = 1 coin, you are allowed to take the 4th fruit for free.
Take the 4th fruit for free.

Example 3:
Input: prices = [26,18,6,12,49,7,45,45]
Output: 39
Explanation:
Purchase the 1st fruit with prices[0] = 26 coin, you are allowed to take the 2nd fruit for free.
Take the 2nd fruit for free.
Purchase the 3rd fruit for prices[2] = 6 coin, you are allowed to take the 4th, 5th and 6th (the next three) fruits for free.
Take the 4th fruit for free.
Take the 5th fruit for free.
Purchase the 6th fruit with prices[5] = 7 coin, you are allowed to take the 8th and 9th fruit for free.
Take the 7th fruit for free.
Take the 8th fruit for free.
Note that even though you could take the 6th fruit for free as a reward of buying 3rd fruit, you purchase it to
receive its reward, which is more optimal.

Constraints:
1 <= prices.length <= 1000
1 <= prices[i] <= 105
*/

void solve(vector<int> &prices, int ind, int sum, int &ans)
{
    if (ind >= prices.size())
        return; // Base case: if index is out of bounds
    if (ind == prices.size() - 1)
    {                        // If the last element is reached
        ans = min(ans, sum); // Update the minimum answer
        return;
    }

    // Loop to explore possible next steps
    for (int i = ind + 1; i <= 2 * ind + 2; i++)
    {
        if (i < prices.size())
        {
            solve(prices, i, sum + prices[i], ans);
        }
        else
        {
            ans = min(ans, sum);
        }
    }
}

int minimumCoins(vector<int> &prices)
{
    if (prices.size() == 0)
        return 0;

    int ans = INT_MAX, sum = prices[0];

    solve(prices, 0, sum, ans);
    return ans;
}

int solve2(vector<int> &prices, int ind, vector<int> &dp)
{
    if (ind >= prices.size())
        return 0; // Base case: if index is out of bounds

    if (dp[ind] != 0)
        return dp[ind];

    int res = INT_MAX;
    // Loop to explore possible next steps
    for (int i = ind + 1; i <= 2 * ind + 2; i++)
    {
        res = min(res, solve2(prices, i, dp));
    }

    return dp[ind] = res + prices[ind];
}

int minimumCoins2(vector<int> &prices)
{
    if (prices.size() == 0)
        return 0;

    vector<int> dp(prices.size(), 0);

    solve2(prices, 0, dp);
    return dp[0];
}

int main()
{
    vector<int> prices = {26, 18, 6, 12, 49, 7, 45, 45};
    cout << "Without DP = " << minimumCoins(prices) << endl;
    cout << "With DP = " << minimumCoins2(prices) << endl;
    return 0;
}