#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

/*
Given an integer array nums and an integer k, split nums into k non-empty subarrays such that the
largest sum of any subarray is minimized.
Return the minimized largest sum of the split.
A subarray is a contiguous part of the array.

Example 1:
Input: nums = [7,2,5,10,8], k = 2
Output: 18
Explanation: There are four ways to split nums into two subarrays.
The best way is to split it into [7,2,5] and [10,8], where the largest sum among the two subarrays is only 18.

Example 2:
Input: nums = [1,2,3,4,5], k = 2
Output: 9
Explanation: There are four ways to split nums into two subarrays.
The best way is to split it into [1,2,3] and [4,5], where the largest sum among the two subarrays is only 9.

Constraints:
1 <= nums.length <= 1000
0 <= nums[i] <= 106
1 <= k <= min(50, nums.length)
*/

bool isPossible(vector<int> nums, int maxSum, int k)
{
    int noOfSubArrays = 1, currSum = 0;

    for (int x : nums)
    {
        currSum += x;
        if (currSum > maxSum)
        {
            noOfSubArrays++;
            currSum = x;

            if (noOfSubArrays > k)
                return false;
        }
    }
    return noOfSubArrays <= k;
}

int splitArray(vector<int> &nums, int k)
{
    int minSum = INT_MIN, maxSum = 0;
    int ans = 0;

    for (int num : nums)
    {
        minSum = max(minSum, num);
        maxSum += num;
    }

    int start = minSum, end = maxSum;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        if (isPossible(nums, mid, k))
        {
            ans = mid;
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return ans;
}

int main()
{
    vector<int> nums = {7, 2, 5, 10, 8};
    cout << "Answer = " << splitArray(nums, 2) << endl;
    return 0;
}