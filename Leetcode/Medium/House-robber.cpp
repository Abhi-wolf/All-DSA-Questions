#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/*
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed,
the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and
it will automatically contact the police if two adjacent houses were broken into on the same night.
Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can
rob tonight without alerting the police.

Example 1:
Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.

Example 2:
Input: nums = [2,7,9,3,1]
Output: 12
Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
Total amount you can rob = 2 + 9 + 1 = 12.

Constraints:
    1 <= nums.length <= 100
    0 <= nums[i] <= 400
*/

//  FIRST METHOD
void Solve(int n, int index, int sum, vector<int> arr, int &ans)
{
    if (index >= n)
    {
        ans = max(ans, sum);
        return;
    }

    if (index < n)
    {
        int sum1 = sum + arr[index];
        // taken
        Solve(n, index + 2, sum1, arr, ans);
        // not taken
        Solve(n, index + 1, sum, arr, ans);
    }
}

int rob(vector<int> &nums)
{
    int ans = 0;
    Solve(nums.size(), 0, 0, nums, ans);
    return ans;
}

//  SECOND METHOD  -- DP
int Solve2(int n, int index, vector<int> nums, unordered_map<int, int> &um)
{
    if (index >= n)
        return 0;

    if (um.find(index) != um.end())
        return um[index];

    int take = nums[index] + Solve2(n, index + 2, nums, um);
    int notTake = Solve2(n, index + 1, nums, um);

    um[index] = max(take, notTake);

    return um[index];
}

int rob2(vector<int> &nums)
{
    unordered_map<int, int> um;
    int ans = Solve2(nums.size(), 0, nums, um);
    return ans;
}

// THIRD METHOD
int rob3(vector<int> &nums)
{
    int rob = 0, norob = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        int newRob = norob + nums[i];
        int newNoRob = max(norob, rob);
        rob = newRob;
        norob = newNoRob;
    }

    return max(rob, norob);
}

int main()
{
    vector<int> nums = {2, 7, 9, 3, 1};
    int res = rob(nums);
    cout << "\nResult 1 = " << res << endl;
    res = rob2(nums);
    cout << "Result 2 = " << res << endl;
    res = rob3(nums);
    cout << "Result 3 = " << res << endl;

    nums = {2, 1, 1, 2};
    res = rob(nums);
    cout << "\nResult 1 = " << res << endl;
    res = rob2(nums);
    cout << "Result 2 = " << res << endl;
    res = rob3(nums);
    cout << "Result 3 = " << res << endl;

    nums = {1, 2, 3, 1};
    res = rob(nums);
    cout << "\nResult 1 = " << res << endl;
    res = rob2(nums);
    cout << "Result 2 = " << res << endl;
    res = rob3(nums);
    cout << "Result 3 = " << res << endl;

    nums = {183, 219, 57, 193, 94, 233, 202, 154, 65, 240, 97, 234, 100, 249, 186, 66, 90, 238, 168, 128, 177, 235, 50, 81, 185, 165, 217, 207, 88, 80, 112, 78, 135, 62, 228, 247, 211};
    res = rob(nums);
    cout << "\nResult 1 = " << res << endl;
    res = rob2(nums);
    cout << "Result 2 = " << res << endl;
    res = rob3(nums);
    cout << "Result 3 = " << res << endl;

    return 0;
}