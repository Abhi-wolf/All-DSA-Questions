#include <iostream>
#include <vector>
using namespace std;

/*
You are given an integer array nums of size n.
Consider a non-empty subarray from nums that has the maximum possible bitwise AND.
In other words, let k be the maximum value of the bitwise AND of any subarray of nums. Then, only subarrays
with a bitwise AND equal to k should be considered.
Return the length of the longest such subarray.

The bitwise AND of an array is the bitwise AND of all the numbers in it.
A subarray is a contiguous sequence of elements within an array.

Example 1:
Input: nums = [1,2,3,3,2,2]
Output: 2
Explanation:
The maximum possible bitwise AND of a subarray is 3.
The longest subarray with that value is [3,3], so we return 2.

Example 2:
Input: nums = [1,2,3,4]
Output: 1
Explanation:
The maximum possible bitwise AND of a subarray is 4.
The longest subarray with that value is [4], so we return 1.

Constraints:
1 <= nums.length <= 105
1 <= nums[i] <= 106
*/

// TLE
int longestSubarray1(vector<int> &nums)
{
    int len = 0, maxandsum = 0;
    int n = nums.size();
    for (int i = 0; i < nums.size(); i++)
    {
        int andsum = nums[i];
        for (int j = i; j < nums.size(); j++)
        {
            andsum = andsum & nums[j];
            if (andsum > maxandsum)
            {
                maxandsum = andsum;
                len = j - i + 1;
            }
            else if (andsum == maxandsum)
            {
                len = max(len, j - i + 1);
            }
        }
    }

    return len;
}

// TLE
int longestSubarray2(vector<int> &nums)
{
    int len = 0, maxele = 0;
    int n = nums.size();
    for (int i = 0; i < nums.size(); i++)
    {
        maxele = max(maxele, nums[i]);
    }

    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == maxele)
        {
            int a = i, b = i;
            while (a >= 0 && nums[a] == maxele)
                a--;
            while (b < n && nums[b] == maxele)
                b++;

            len = max(len, b - a - 1);
        }
    }

    return len;
}

/*
    Find maximum element in vector.
    Find the length of longest subarray (contiguous) which contains only
       maximum element.
*/
int longestSubarray3(vector<int> &nums)
{
    int len = 1, maxele = 0;
    int n = nums.size(), subarraylen = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        maxele = max(maxele, nums[i]);
    }

    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == maxele)
        {
            subarraylen++;
            len = max(len, subarraylen);
        }
        else
        {
            subarraylen = 0;
        }
    }

    return len;
}

int main()
{
    vector<int> nums = {1, 2, 3, 3, 2, 2};
    cout << "Ans1 = " << longestSubarray1(nums) << endl;
    cout << "Ans2 = " << longestSubarray2(nums) << endl;
    cout << "Ans3 = " << longestSubarray3(nums) << endl;
    return 0;
}