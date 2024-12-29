#include <iostream>
#include <vector>
using namespace std;

/* You are given an integer array prices where prices[i] is the price of a given stock on the ith day.
On each day, you may decide to buy and/or sell the stock. You can only hold at most one share of the stock at any
time. However, you can buy it then immediately sell it on the same day.
Find and return the maximum profit you can achieve.

Example 1:
Input: prices = [7,1,5,3,6,4]
Output: 7
Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
Total profit is 4 + 3 = 7.

Example 2:
Input: prices = [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
Total profit is 4.

Example 3:
Input: prices = [7,6,4,3,1]
Output: 0
Explanation: There is no way to make a positive profit, so we never buy the stock to achieve the maximum profit of 0.

Constraints:
1 <= prices.length <= 3 * 104
0 <= prices[i] <= 104*/

void helper(vector<int> &prices, int ind, int prc, int profit,
            int &maxprofit)
{

    maxprofit = max(maxprofit, profit);

    if (ind >= prices.size())
    {
        return;
    }

    // we have already bought and now we have to sell
    if (prc != -1)
    {
        for (int i = ind; i < prices.size(); i++)
        {
            if (prices[i] > prc)
            {
                helper(prices, i + 1, -1, profit + prices[i] - prc,
                       maxprofit);
            }
        }
    }
    else
    {
        // we have to buy
        for (int i = ind; i < prices.size(); i++)
        {
            helper(prices, i + 1, prices[i], profit, maxprofit);
        }
    }
}

// METHOD 1 (TLE)
int maxProfit1(vector<int> &prices)
{
    int maxprofit = 0;

    for (int i = 0; i < prices.size(); i++)
    {
        helper(prices, i, prices[i], 0, maxprofit);
    }

    return maxprofit;
}

// METHOD 2
int maxProfit2(vector<int> &prices)
{
    int maxprofit = 0, i = 0, n = prices.size() - 1;

    for (int i = 0; i < n; i++)
    {
        int diff = prices[i + 1] - prices[i];

        if (diff > 0)
            maxprofit += diff;
    }

    return maxprofit;
}

int main()
{
    vector<int> nums = {7, 1, 5, 3, 6, 4};
    cout << maxProfit1(nums) << endl;
    cout << maxProfit2(nums) << endl;
    return 0;
}