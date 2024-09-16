#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <limits.h>
using namespace std;

/*
    You are given a 0-indexed array nums consisting of positive integers.
    You can choose two indices i and j, such that i != j, and the sum of digits
    of the number nums[i] is equal to that of nums[j].
    Return the maximum value of nums[i] + nums[j] that you can obtain over all
    possible indices i and j that satisfy the conditions.

    Example 1:

Input: nums = [18,43,36,13,7]
Output: 54
Explanation: The pairs (i, j) that satisfy the conditions are:
- (0, 2), both numbers have a sum of digits equal to 9, and their sum is 18 + 36 = 54.
- (1, 4), both numbers have a sum of digits equal to 7, and their sum is 43 + 7 = 50.
So the maximum sum that we can obtain is 54.

Example 2:

Input: nums = [10,12,19,14]
Output: -1
Explanation: There are no two numbers that satisfy the conditions, so we return -1.



Constraints:

    1 <= nums.length <= 105
    1 <= nums[i] <= 109

*/

int maximumSum(vector<int> &nums)
{
    unordered_map<int, priority_queue<int>> um;
    int ans = INT_MIN;

    for (int i = 0; i < nums.size(); i++)
    {
        int num = nums[i];
        int sum = 0;
        while (num > 0)
        {
            sum += num % 10;
            num /= 10;
        }

        um[sum].push(nums[i]);
    }

    for (auto x : um)
    {
        priority_queue<int> pq = x.second;
        if (pq.size() > 1)
        {
            int fir = 0, sec = 0;
            fir = pq.top();
            pq.pop();
            sec = pq.top();
            pq.pop();
            ans = max(ans, (fir + sec));
        }
    }
    if (ans == INT_MIN)
        return -1;
    return ans;
}

int main()
{
    vector<int> nums = {18, 43, 36, 13, 7};
    int ans = maximumSum(nums);
    cout << "Result = " << ans << endl;
    return 0;
}