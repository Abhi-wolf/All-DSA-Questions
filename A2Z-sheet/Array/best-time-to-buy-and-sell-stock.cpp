#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

/* You are given an array prices where prices[i] is the price of a given stock on the ith day.
You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.
Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

Example 1:
Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.

Example 2:
Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transactions are done and the max profit = 0.

Constraints:

1 <= prices.length <= 105
0 <= prices[i] <= 104   */

// DP
int maxProfit(vector<int> &prices)
{
    int maxProfit = 0, size = prices.size(), mini = prices[0];
    int dp[size];

    for (int i = 0; i < size; i++)
    {
        mini = min(mini, prices[i]);
        dp[i] = mini;
    }

    for (int i = 0; i < size; i++)
    {
        maxProfit = max(maxProfit, (prices[i] - dp[i]));
    }
    return maxProfit;
}

int maxProfit2(vector<int> &prices)
{
    int maxProfit = 0, size = prices.size(), miniPrice = INT_MAX,
        profit = 0;

    for (int i = 0; i < size; i++)
    {
        miniPrice = min(miniPrice, prices[i]);

        profit = prices[i] - miniPrice;

        maxProfit = max(profit, maxProfit);
    }

    return maxProfit;
}

int main()
{
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    cout << maxProfit(prices) << endl;
    cout << maxProfit2(prices) << endl;
    return 0;
}