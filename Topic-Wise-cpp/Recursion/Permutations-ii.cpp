#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
Given a collection of numbers, nums, that might contain duplicates, return all possible
unique permutations in any order.

Example 1:
Input: nums = [1,1,2]
Output:
[[1,1,2],
 [1,2,1],
 [2,1,1]]

Example 2:
Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

*/

void helper(vector<int> nums, vector<vector<int>> &ans, int ind)
{
    if (ind == nums.size())
    {
        ans.push_back(nums);
        return;
    }

    for (int i = ind; i < nums.size(); i++)
    {
        if (i != ind && nums[i] == nums[ind])
            continue;
        swap(nums[i], nums[ind]);
        helper(nums, ans, ind + 1);
    }
}

vector<vector<int>> permuteUnique(vector<int> &nums)
{
    int n = nums.size();
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;

    helper(nums, ans, 0);

    return ans;
}

void Display2DArray(vector<vector<int>> arr)
{
    cout << endl;
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr[i].size(); j++)
        {
            cout << arr[i][j] << " , ";
        }
        cout << endl;
    }
}

int main()
{
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> ans = permuteUnique(nums);
    Display2DArray(ans);
    return 0;
}