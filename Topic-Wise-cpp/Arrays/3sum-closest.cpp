#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/* Given an integer array nums of length n and an integer target, find three integers in nums such
that the sum is closest to target.

Return the sum of the three integers.
You may assume that each input would have exactly one solution.

Example 1:
Input: nums = [-1,2,1,-4], target = 1
Output: 2
Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).

Example 2:
Input: nums = [0,0,0], target = 1
Output: 0
Explanation: The sum that is closest to the target is 0. (0 + 0 + 0 = 0).

Constraints:
3 <= nums.length <= 500
-1000 <= nums[i] <= 1000
-104 <= target <= 104       */

int threeSumClosest(vector<int> &nums, int target)
{
    int n = nums.size();
    int sum = nums[0] + nums[1] + nums[2];
    sort(nums.begin(), nums.end());

    for (int i = 0; i < n - 2; i++)
    {
        if (i > 0 && nums[i] == nums[i - 1])
            continue;

        int j = i + 1, k = nums.size() - 1;

        while (j < k)
        {
            int currsum = nums[i] + nums[j] + nums[k];

            if (currsum == target)
                return currsum;
            if (abs(target - currsum) < abs(target - sum))
            {
                sum = currsum;
            }

            if (currsum > target)
                k--;
            else
                j++;
        }
    }

    return sum;
}

int main()
{
    vector<int> nums = {-1, 2, 1, -4};
    cout << threeSumClosest(nums, 1) << endl;
    return 0;
}