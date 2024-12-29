#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

/* You are given an integer array nums and three integers k, op1, and op2.
You can perform the following operations on nums:

Operation 1: Choose an index i and divide nums[i] by 2, rounding up to the nearest whole number.
You can perform this operation at most op1 times, and not more than once per index.
Operation 2: Choose an index i and subtract k from nums[i], but only if nums[i] is greater than or equal to k.
You can perform this operation at most op2 times, and not more than once per index.

Note: Both operations can be applied to the same index, but at most once each.
Return the minimum possible sum of all elements in nums after performing any number of operations.

Example 1:
Input: nums = [2,8,3,19,3], k = 3, op1 = 1, op2 = 1
Output: 23
Explanation:
Apply Operation 2 to nums[1] = 8, making nums[1] = 5.
Apply Operation 1 to nums[3] = 19, making nums[3] = 10.
The resulting array becomes [2, 5, 3, 10, 3], which has the minimum possible sum of 23 after applying the operations.

Example 2:
Input: nums = [2,4,3], k = 3, op1 = 2, op2 = 1
Output: 3
Explanation:
Apply Operation 1 to nums[0] = 2, making nums[0] = 1.
Apply Operation 1 to nums[1] = 4, making nums[1] = 2.
Apply Operation 2 to nums[2] = 3, making nums[2] = 0.
The resulting array becomes [1, 2, 0], which has the minimum possible sum of 3 after applying the operations.

Constraints:
1 <= nums.length <= 100
0 <= nums[i] <= 105
0 <= k <= 105
0 <= op1, op2 <= nums.length*/

void helper(vector<int> nums, int &k, int op1, int op2, int ind, int &res)
{
    if (op1 == 0 && op2 == 0)
    {
        int sum = 0;
        for (int x : nums)
        {
            sum += x;
        }
        res = min(sum, res);
        return;
    }

    if (ind >= nums.size())
    {
        int sum = 0;
        for (int x : nums)
        {
            sum += x;
        }
        res = min(sum, res);
        return;
    }

    //  perform first operation
    if (op1 > 0)
    {
        vector<int> temp = nums;
        temp[ind] = (temp[ind] + 1) / 2;
        helper(temp, k, op1 - 1, op2, ind + 1, res);
    }

    //  perform second operation
    if (op2 > 0 && nums[ind] >= k)
    {
        vector<int> temp = nums;
        temp[ind] -= k;
        helper(temp, k, op1, op2 - 1, ind + 1, res);
    }

    //  perform both operation (first op1, then op2)
    if (op1 > 0 && op2 > 0)
    {
        int left = (nums[ind] + 1) / 2;

        if (left >= k)
        {
            vector<int> temp = nums;
            temp[ind] = left - k;
            helper(temp, k, op1 - 1, op2 - 1, ind + 1, res);
        }
    }

    //  perform both operation (first op2, then op1)
    if (op1 > 0 && op2 > 0 && nums[ind] >= k)
    {
        int left = nums[ind] - k;
        vector<int> temp = nums;
        temp[ind] = (left + 1) / 2;

        helper(temp, k, op1 - 1, op2 - 1, ind + 1, res);
    }

    // no operation performed on the index element
    helper(nums, k, op1, op2, ind + 1, res);
}

int minArraySum(vector<int> &nums, int k, int op1, int op2)
{
    int res = INT_MAX;
    helper(nums, k, op1, op2, 0, res);
    return res;
}

int main()
{
    vector<int> nums = {2, 8, 3, 19, 3};
    cout << "Result = " << minArraySum(nums, 3, 1, 1) << endl;
    return 0;
}