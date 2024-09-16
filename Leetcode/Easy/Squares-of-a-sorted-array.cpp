#include <iostream>
#include <vector>
using namespace std;

/*
Given an integer array nums sorted in non-decreasing order, return an array of the squares of each number
sorted in non-decreasing order.

Example 1:
Input: nums = [-4,-1,0,3,10]
Output: [0,1,9,16,100]
Explanation: After squaring, the array becomes [16,1,0,9,100].
After sorting, it becomes [0,1,9,16,100].

Example 2:
Input: nums = [-7,-3,2,3,11]
Output: [4,9,9,49,121]

Constraints:
1 <= nums.length <= 104
-104 <= nums[i] <= 104
nums is sorted in non-decreasing order.
*/

vector<int> sortedSquares(vector<int> &nums)
{
    int n = nums.size();
    vector<int> ans(n);
    int s = 0, e = n - 1;

    for (int i = n - 1; i >= 0; i--)
    {
        if (abs(nums[s]) >= abs(nums[e]))
        {
            ans[i] = nums[s] * nums[s];
            s++;
        }
        else
        {
            ans[i] = nums[e] * nums[e];
            e--;
        }
    }
    return ans;
}

void Display(vector<int> ans)
{
    if (ans.size() == 0)
    {
        cout << "Array is empty\n";
        return;
    }

    cout << "\n";
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << ", ";
    cout << "\n";
}

int main()
{
    vector<int> nums = {-4, -1, 0, 3, 10};
    vector<int> ans = sortedSquares(nums);
    Display(ans);
    return 0;
}