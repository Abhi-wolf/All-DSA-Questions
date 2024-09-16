#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/*  Given a binary array nums and an integer goal, return the number of non-empty subarrays with a sum goal.
A subarray is a contiguous part of the array.

Example 1:
Input: nums = [1,0,1,0,1], goal = 2
Output: 4
Explanation: The 4 subarrays are bolded and underlined below:
[1,0,1,0,1]
[1,0,1,0,1]
[1,0,1,0,1]
[1,0,1,0,1]

Example 2:
Input: nums = [0,0,0,0,0], goal = 0
Output: 15

Constraints:
1 <= nums.length <= 3 * 104
nums[i] is either 0 or 1.
0 <= goal <= nums.length
*/

// PREFIX SUM METHOD
int numSubarraysWithSum(vector<int> &nums, int goal)
{
    int totalCount = 0, currentSum = 0;
    unordered_map<int, int> freq; // To store the frequency of prefix sums

    for (int i = 0; i < nums.size(); i++)
    {
        currentSum += nums[i];
        if (currentSum == goal)
            totalCount++;

        // Check if there is any prefix sum that can be subtracted from the
        // current sum to get the desired goal
        if (freq.find(currentSum - goal) != freq.end())
            totalCount += freq[currentSum - goal];

        freq[currentSum]++;
    }

    return totalCount;
}

// SLIDING WINDOW METHOD
/* After calculating the total count of subarrays with sums less than or equal to the goal using the functionslidingWindowAtMost(nums, goal),
    we need to isolate the subarrays that strictly meet the target goal.This can be achieved by subtracting the total count of subarrays with
    sums less than the goal (slidingWindowAtMost(nums, goal - 1)) from the total count obtained earlier. By subtracting the latter from the former,
    we remove the subarrays that don't reach the goal and are left with only the subarrays that have a sum exactly equal to the goal.*/
int slidingWindowAtMost(vector<int> nums, int goal)
{
    int totalCount = 0, start = 0;
    int currentSum = 0;

    for (int end = 0; end < nums.size(); end++)
    {
        currentSum += nums[end];

        // Adjust the window by moving the start pointer to the right
        // until the sum becomes less than or equal to the goal
        while (start <= end && currentSum > goal)
            currentSum -= nums[start++];

        totalCount += (end - start + 1);
    }

    return totalCount;
}

int numSubarraysWithSum2(vector<int> &nums, int goal)
{
    return slidingWindowAtMost(nums, goal) - slidingWindowAtMost(nums, goal - 1);
}

int main()
{
    vector<int> nums = {1, 0, 1, 0, 1};
    cout << "\n Result = " << numSubarraysWithSum(nums, 2) << endl;
    cout << "\n Result = " << numSubarraysWithSum2(nums, 2) << endl;

    nums = {0, 0, 0, 0, 0};
    cout << "\n Result = " << numSubarraysWithSum(nums, 0) << endl;
    cout << "\n Result = " << numSubarraysWithSum2(nums, 0) << endl;
    return 0;
}