#include <iostream>
#include <vector>
#include <stack>
using namespace std;

/*
The stock span problem is a financial problem where we have a series of n daily price quotes for a stock
and we need to calculate the span of stocks price for all n days.
The span Si of the stocks price on a given day i is defined as the maximum number of consecutive days just
before the given day, for which the price of the stock on the given day is less than or equal to its price
on the current day.

For example, if an array of 7 days prices is given as {100, 80, 60, 70, 60, 75, 85}, then the span values
for corresponding 7 days are {1, 1, 1, 2, 1, 4, 6}.

Example 1:
Input:
N = 7, price[] = [100 80 60 70 60 75 85]
Output:
1 1 1 2 1 4 6
Explanation:
Traversing the given input span
100 is greater than equal to 100 and there are no more elements behind it so the span is 1,
80 is greater than equal to 80 and smaller than 100 so the span is 1,
60 is greater than equal to 60 and smaller than 80 so the span is 1,
70 is greater than equal to 60,70 and smaller than 80 so the span is 2,
60 is greater than equal to 60 and smaller than 70 so the span is 1,
75 is greater than equal to 60,70,60,75 and smaller than 100 so the span is 4,
85 is greater than equal to 80,60,70,60,75,85 and smaller than 100 so the span is 6.
Hence the output will be 1 1 1 2 1 4 6.

Example 2:
Input:
N = 6, price[] = [10 4 5 90 120 80]
Output:
1 1 2 4 5 1
Explanation:
Traversing the given input span
10 is greater than equal to 10 and there are no more elements behind it so the span is 1,
4 is greater than equal to 4 and smaller than 10 so the span is 1,
5 is greater than equal to 4,5 and smaller than 10 so the span is 2,
90 is greater than equal to all previous elements so the span is 4,
120 is greater than equal to all previous elements so the span is 5,
80 is greater than equal to 80 and smaller than 120 so the span is 1,
Hence the output will be 1 1 2 4 5 1.

User Task:
The task is to complete the function calculateSpan() which takes two parameters, an array price[] denoting
the price of stocks, and an integer N denoting the size of the array and number of days. This function finds
the span of stock's price for all N days and returns an array of length N denoting the span for the i-th day.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).

Constraints:
1 ≤ N ≤ 105
1 ≤ C[i] ≤ 105

*/

vector<int> calculateSpan(int price[], int n)
{
    vector<int> ans;
    stack<pair<int, int>> stk;

    for (int i = 0; i < n; i++)
    {
        while (!stk.empty() && stk.top().first <= price[i])
            stk.pop();

        if (stk.empty())
            ans.push_back(i + 1);
        else
        {
            int ind = stk.top().second;
            ans.push_back(i - ind);
        }
        stk.push({price[i], i});
    }
    return ans;
}

vector<int> calculateSpan2(int price[], int n)
{
    vector<int> ans;
    stack<int> stk;

    for (int i = 0; i < n; i++)
    {
        while (!stk.empty() && price[stk.top()] <= price[i])
            stk.pop();

        if (stk.empty())
            ans.push_back(i + 1);
        else
        {
            ans.push_back(i - stk.top());
        }
        stk.push(i);
    }
    return ans;
}

void Display1DArray(vector<int> arr)
{
    cout << endl;
    for (int i = 0; i < arr.size(); i++)
    {
        cout << "arr[" << i << "] = " << arr[i] << endl;
    }
    cout << endl;
}

int main()
{
    int price[] = {100, 80, 60, 70, 60, 75, 85};
    int n = sizeof(price) / sizeof(price[0]);
    vector<int> ans = calculateSpan(price, n);
    Display1DArray(ans);

    vector<int> ans2 = calculateSpan2(price, n);
    Display1DArray(ans2);

    return 0;
}