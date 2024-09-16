#include <iostream>
#include <vector>
using namespace std;

/* Given an integer array nums, find the  subarray with the largest sum, and return its sum.

Example 1:
Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: The subarray [4,-1,2,1] has the largest sum 6.

Example 2:
Input: nums = [1]
Output: 1
Explanation: The subarray [1] has the largest sum 1.

Example 3:
Input: nums = [5,4,-1,7,8]
Output: 23
Explanation: The subarray [5,4,-1,7,8] has the largest sum 23.

Constraints:
1 <= nums.length <= 105
-104 <= nums[i] <= 104 */

/* Kadane's Algorithm

    Intution: Start traversing your array keep each element in the sum and every time keep the max of currSum and prevSum.
    But the catch here is that if at any point sum becomes negative then no point keeping it because 0 is obviously greater
    than negative, so just make your sum 0.
 */

int maxSubArray(vector<int> &nums)
{
    int sum = 0, maxi = nums[0];
    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];

        maxi = max(maxi, sum);
        if (sum < 0)
            sum = 0;
    }
    return maxi;
}

// Using DP
int maxSubArray2(vector<int> nums)
{
    int n = nums.size();
    vector<int> dp(n, 0);
    dp[0] = nums[0];
    int maxi = nums[0];

    for (int i = 1; i < n; i++)
    {
        dp[i] = nums[i] + (dp[i - 1] > 0 ? dp[i - 1] : 0);
        maxi = max(maxi, dp[i]);
    }
    return maxi;
}

int main()
{
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << maxSubArray(nums) << endl;
    cout << maxSubArray2(nums) << endl;

    return 0;
}