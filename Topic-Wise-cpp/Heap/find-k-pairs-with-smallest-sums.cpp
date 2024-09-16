#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

/*
You are given two arrays of positive integers say ‘arr1’ and ‘arr2’ and a positive integer ‘K’. Also ‘arr1’ and ‘arr2’
are already sorted in ascending order. Consider all pairs (x, y) such that ‘x’ belongs to ‘arr1’ and ‘y’ belongs to
‘arr2’. You need to find exactly ‘K’ such pairs with the smallest sum of ‘x’ and ‘y’.

Example:
Let ‘arr1’ be [ ‘1’, ‘2’, ‘6’ ] and ‘arr2’ be [ ‘3’, ‘3’, ‘5’ ] and ‘K’ be 3.

There are 9 possible (x, y) pairs such that ‘x’ belongs to ‘arr1’ and ‘y’ belongs to ‘arr2’. Among all of them 3 pairs
with smaller ‘x’ + ‘y’ are [ (1, 3), (1, 3), (2, 3) ].

Sample Input 1:
2
3 3 3
1 2 3
4 5 6
2 3 2
4 5
2 4 4
Sample Output 1:
1 4
1 5
2 4
4 2
5 2
Explanation of Sample Input 1:
Test case 1:

Among all possible pairs (x, y) such that ‘x’ is from [ ‘1’, ‘2’, ‘3’ ] and ‘y’ is from [ ‘4’, ‘5’, ‘6’ ], 3 pairs
with the smallest sum are (1, 4) with sum 5, (1, 5) with sum 6, and (2, 4) with sum 6.

Test case 2:
Two pairs with the smallest sum are (4, 2) and (4, 4) with sum 6 and 8.
Sample Input 2:
1
3 4 1
5 6 9
1 2 2 4
Sample Output 2:
5 1
Explanation of Sample Input 2:
As the arrays are sorted, the pair with the smallest sum will be (5, 1).
*/

vector<vector<int>> findPairs(int n, int m, vector<int> &arr1, vector<int> &arr2, int k)
{
    vector<vector<int>> ans;
    priority_queue<pair<int, pair<int, int>>> maxheap;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int sum = arr1[i] + arr2[j];

            if (maxheap.size() == k && maxheap.top().first <= sum)
                break;

            maxheap.push({sum, {arr1[i], arr2[j]}});

            if (maxheap.size() > k)
                maxheap.pop();
        }
    }

    while (!maxheap.empty())
    {
        ans.push_back({maxheap.top().second.first, maxheap.top().second.second});
        maxheap.pop();
    }

    reverse(ans.begin(), ans.end());
    return ans;
}

void Display2DArray(vector<vector<int>> arr)
{
    cout << endl;
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr[0].size(); j++)
        {
            cout << arr[i][j] << " , ";
        }
        cout << endl;
    }
    cout << endl;
}

int main()
{
    vector<int> arr1 = {1, 2, 3};
    vector<int> arr2 = {4, 5, 6};
    vector<vector<int>> ans = findPairs(3, 3, arr1, arr2, 3);
    Display2DArray(ans);
    return 0;
}