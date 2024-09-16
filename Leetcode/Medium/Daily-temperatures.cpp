#include <iostream>
#include <vector>
#include <stack>
using namespace std;

/*   Given an array of integers temperatures represents the daily temperatures, return an array
answer such that answer[i] is the number of days you have to wait after the ith day to get a warmer
temperature. If there is no future day for which this is possible, keep answer[i] == 0 instead.

Example 1:
Input: temperatures = [73,74,75,71,69,72,76,73]
Output: [1,1,4,2,1,1,0,0]

Example 2:
Input: temperatures = [30,40,50,60]
Output: [1,1,1,0]

Example 3:
Input: temperatures = [30,60,90]
Output: [1,1,0]

Constraints:
1 <= temperatures.length <= 105
30 <= temperatures[i] <= 100
*/

//  USING STACK
vector<int> dailyTemperatures(vector<int> &temperatures)
{
    int n = temperatures.size();
    vector<int> res(n, 0);
    stack<pair<int, int>> stk;
    stk.push({temperatures[n - 1], n - 1});

    for (int i = n - 2; i >= 0; i--)
    {
        while (!stk.empty() && temperatures[i] >= stk.top().first)
            stk.pop();

        if (!stk.empty())
        {
            res[i] = stk.top().second - i;
        }
        stk.push({temperatures[i], i});
    }
    return res;
}

void Display(vector<int> res)
{
    if (res.size() == 0)
    {
        cout << "No element present\n";
        return;
    }

    for (int i = 0; i < res.size(); i++)
        cout << res[i] << ", ";
    cout << endl;
}

int main()
{
    vector<int> temperatures = {73, 74, 75, 71, 69, 72, 76, 73};
    vector<int> res = dailyTemperatures(temperatures);
    Display(res);
    return 0;
}