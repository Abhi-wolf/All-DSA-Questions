#include <iostream>
#include <vector>
using namespace std;

/*
Given an array nums of n integers where nums[i] is in the range [1, n], return an array of all the
integers in the range [1, n] that do not appear in nums.

Example 1:
Input: nums = [4,3,2,7,8,2,3,1]
Output: [5,6]

Example 2:
Input: nums = [1,1]
Output: [2]
*/

vector<int> findDisappearedNumbers(vector<int> &nums)
{
    int n = nums.size();
    vector<int> ans;

    for (int i = 0; i < n; i++)
    {
        int ind = abs(nums[i]) - 1;

        nums[ind] = nums[ind] > 0 ? -nums[ind] : nums[ind];
    }

    for (int i = 0; i < n; i++)
    {
        if (nums[i] > 0)
            ans.push_back(i + 1);
    }

    return ans;
}

void Display1DArray(vector<int> arr)
{
    cout << endl;
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " , ";
    }
    cout << endl;
}

int main()
{
    vector<int> nums = {4, 3, 2, 7, 8, 2, 3, 1};
    vector<int> ans = findDisappearedNumbers(nums);
    Display1DArray(ans);
    return 0;
}