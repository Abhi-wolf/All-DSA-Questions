#include <iostream>
#include <vector>
#include <unordered_map>
#include <limits.h>
using namespace std;

/*
Given an unsorted integer array nums. Return the smallest positive integer that is not present in nums.

You must implement an algorithm that runs in O(n) time and uses O(1) auxiliary space.

Example 1:
Input: nums = [1,2,0]
Output: 3
Explanation: The numbers in the range [1,2] are all in the array.

Example 2:
Input: nums = [3,4,-1,1]
Output: 2
Explanation: 1 is in the array but 2 is missing.

Example 3:
Input: nums = [7,8,9,11,12]
Output: 1
Explanation: The smallest positive integer 1 is missing.

Constraints:
1 <= nums.length <= 105
-231 <= nums[i] <= 231 - 1
*/

int firstMissingPositive(vector<int> &nums)
{
    unordered_map<int, int> um;
    long long int maxi = INT_MIN;

    for (int x : nums)
    {
        um[x]++;
        if (x > maxi)
            maxi = x;
    }

    for (int i = 1; i <= maxi; i++)
    {
        if (um.find(i) == um.end())
            return i;
    }

    if (maxi <= 0)
        return 1;
    return maxi + 1;
}

int firstMissingPositive2(vector<int> &nums)
{
    int n = nums.size();
    vector<bool> seen(n + 1, false); // Array for lookup

    // Mark the elements from nums in the lookup array
    for (int num : nums)
    {
        if (num > 0 && num <= n)
        {
            seen[num] = true;
        }
    }

    // Iterate through integers 1 to n
    // return smallest missing positive integer
    for (int i = 1; i <= n; i++)
    {
        if (!seen[i])
        {
            return i;
        }
    }

    // If seen contains all elements 1 to n
    // the smallest missing positive number is n + 1
    return n + 1;
}

int firstMissingPositive3(vector<int> &nums)
{
    int n = size(nums);

    for (int i = 0; i < n; i++)
    {
        int x = nums[i]; // x = current element

        // x>=1 && x<=n : to check if x is in range[1, n]
        // x != i+1 : skip if at index i correct element is present.
        // nums[x-1]!=x: skip if at index x-1 correct element is present
        while (x >= 1 && x <= n && x != i + 1 && nums[x - 1] != x)
        {
            swap(nums[x - 1], nums[i]);
            x = nums[i];
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (nums[i] == i + 1)
            continue;
        return i + 1;
    }

    return n + 1;
}

int firstMissingPositive4(vector<int> &nums)
{
    int n = nums.size(), i = 0;
    // Use cycle sort to place positive elements smaller than n
    // at the correct index
    while (i < n)
    {
        if (nums[i] > 0 && nums[i] <= n && nums[i] != nums[nums[i] - 1])
        {
            swap(nums[i], nums[nums[i] - 1]);
        }
        else
        {
            i++;
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (nums[i] != i + 1)
            return (i + 1);
    }

    return n + 1;
}

int main()
{
    vector<int> nums = {3, 4, -1, 1};
    cout << firstMissingPositive(nums) << endl;
    cout << firstMissingPositive2(nums) << endl;
    cout << firstMissingPositive3(nums) << endl;
    cout << firstMissingPositive4(nums) << endl;
    return 0;
}