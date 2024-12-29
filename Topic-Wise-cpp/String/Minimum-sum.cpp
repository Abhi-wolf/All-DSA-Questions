#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

string minSum(vector<int> arr)
{
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int x : arr)
        pq.push(x);

    string num1 = "", num2 = "";
    int rem = 0;
    string ans = "";

    while (!pq.empty())
    {
        int x = pq.top();
        pq.pop();

        num1 += (x + '0');

        if (!pq.empty())
        {
            x = pq.top();
            pq.pop();

            num2 += (x + '0');
        }
    }

    int i = num1.size() - 1, j = num2.size() - 1;

    // cout << num1 << " - " << num2 << endl;

    while (i >= 0 && j >= 0)
    {
        int sum = (num1[i--] - '0') + (num2[j--] - '0') + rem;

        rem = sum / 10;
        sum %= 10;

        ans += (sum + '0');
    }

    while (i >= 0)
    {
        int sum = (num1[i--] - '0') + rem;

        rem = sum / 10;
        sum %= 10;

        ans += (sum + '0');
    }

    while (j > 0)
    {
        int sum = (num2[j--] - '0') + rem;

        rem = sum / 10;
        sum %= 10;

        ans += (sum + '0');
    }

    if (rem > 0)
    {
        ans += (rem + '0');
    }

    i = 0;
    reverse(ans.begin(), ans.end());

    while (i < ans.size() && ans[i] == '0')
        i++;

    ans = ans.substr(i);

    return ans;
}

string minSum2(vector<int> arr)
{
    sort(arr.begin(), arr.end());

    string num1 = "", num2 = "";
    int rem = 0;
    string ans = "";

    for (int i = 0; i < arr.size(); i++)
    {

        num1 += (arr[i] + '0');
        i++;

        if (i < arr.size())
        {
            num2 += (arr[i] + '0');
        }
    }

    int i = num1.size() - 1, j = num2.size() - 1;

    while (i >= 0 && j >= 0)
    {
        int sum = (num1[i--] - '0') + (num2[j--] - '0') + rem;

        rem = sum / 10;
        sum %= 10;

        ans += (sum + '0');
    }

    while (i >= 0)
    {
        int sum = (num1[i--] - '0') + rem;

        rem = sum / 10;
        sum %= 10;

        ans += (sum + '0');
    }

    while (j > 0)
    {
        int sum = (num2[j--] - '0') + rem;

        rem = sum / 10;
        sum %= 10;

        ans += (sum + '0');
    }

    if (rem > 0)
    {
        ans += (rem + '0');
    }

    i = 0;
    reverse(ans.begin(), ans.end());

    while (i < ans.size() && ans[i] == '0')
        i++;

    ans = ans.substr(i);

    return ans;
}

int main()
{
    cout << minSum({6, 8, 4, 5, 2, 3}) << endl;
    cout << minSum({5, 3, 0, 7, 4}) << endl;
    cout << minSum({9, 4}) << endl;
    cout << minSum({9, 4, 0, 0, 1, 2, 0}) << endl;
    return 0;
}