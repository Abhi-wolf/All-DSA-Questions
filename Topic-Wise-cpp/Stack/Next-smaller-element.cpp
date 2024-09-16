#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    vector<int> ans;
    stack<int> stk;

    for (int i = n - 1; i >= 0; i--)
    {
        while (!stk.empty() && stk.top() >= arr[i])
        {
            stk.pop();
        }

        if (stk.empty())
            ans.push_back(-1);
        else
        {
            ans.push_back(stk.top());
        }
        stk.push(arr[i]);
    }
    reverse(ans.begin(), ans.end());
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
    vector<int> arr = {2, 1, 4, 3};
    int n = arr.size();

    vector<int> ans = nextSmallerElement(arr, n);
    Display1DArray(ans);
    return 0;
}