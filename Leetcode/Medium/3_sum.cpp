
#include <bits/stdc++.h>
using namespace std;

// tle in both

void solve(vector<int> arr, vector<int> temp, int idx, int k, set<vector<int>> &st)
{
    if (temp.size() == 3)
    {
        int sum = temp[0] + temp[1] + temp[2];
        if (sum == k)
        {
            sort(temp.begin(), temp.end());
            st.insert(temp);
        }
        return;
    }

    if (temp.size() > 3 || idx >= arr.size())
        return;

    for (int i = idx; i < arr.size(); i++)
    {
        temp.push_back(arr[i]);
        solve(arr, temp, i + 1, k, st);
        temp.pop_back();
    }
}

void solve2(vector<int> arr, vector<int> temp, int idx, int k, set<vector<int>> &st, int sum)
{
    if (temp.size() == 3 && sum == k)
    {

        st.insert(temp);
        return;
    }

    if (temp.size() > 3 || idx >= arr.size())
        return;

    for (int i = idx; i < arr.size(); i++)
    {
        if ((k - sum) < arr[i] && sum > 0)
            break;

        temp.push_back(arr[i]);
        solve2(arr, temp, i + 1, k, st, sum + arr[i]);
        temp.pop_back();
    }
}

vector<vector<int>> findTriplets(vector<int> arr, int K)
{
    set<vector<int>> st;
    vector<vector<int>> res;
    vector<int> temp;
    sort(arr.begin(), arr.end());
    // solve(arr, temp, 0, K, st);
    solve2(arr, temp, 0, K, st, 0);

    for (auto x : st)
    {
        res.push_back(x);
    }

    return res;
}

void display(vector<vector<int>> res)
{
    cout << endl;
    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res[0].size(); j++)
        {
            cout << res[i][j] << ", ";
        }
        cout << endl;
    }
    cout << endl;
}

int main()
{
    vector<int> arr = {10, 5, 5, 5, 2};
    vector<vector<int>> res = findTriplets(arr, 12);
    display(res);

    arr = {1, 2, 3, 4};
    res = findTriplets(arr, 11);
    display(res);

    arr = {1, 1, 2, 2, 1, 1};
    res = findTriplets(arr, 4);
    display(res);
    return 0;
}