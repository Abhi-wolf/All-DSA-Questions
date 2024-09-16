#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/*
Given four integer arrays nums1, nums2, nums3, and nums4 all of length n, return the number of tuples (i, j, k, l) such that:
0 <= i, j, k, l < n
nums1[i] + nums2[j] + nums3[k] + nums4[l] == 0

Example 1:
Input: nums1 = [1,2], nums2 = [-2,-1], nums3 = [-1,2], nums4 = [0,2]
Output: 2
Explanation:
The two tuples are:
1. (0, 0, 0, 1) -> nums1[0] + nums2[0] + nums3[0] + nums4[1] = 1 + (-2) + (-1) + 2 = 0
2. (1, 1, 0, 0) -> nums1[1] + nums2[1] + nums3[0] + nums4[0] = 2 + (-1) + (-1) + 0 = 0

Example 2:
Input: nums1 = [0], nums2 = [0], nums3 = [0], nums4 = [0]
Output: 1


Constraints:
n == nums1.length
n == nums2.length
n == nums3.length
n == nums4.length
1 <= n <= 200
-228 <= nums1[i], nums2[i], nums3[i], nums4[i] <= 228
*/

int fourSumCount(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3,
                 vector<int> &nums4)
{
    int cnt = 0;
    int n1 = nums1.size(), n2 = nums2.size(), n3 = nums3.size(),
        n4 = nums4.size();

    unordered_map<int, int> mp;

    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < n2; j++)
        {
            mp[nums1[i] + nums2[j]]++;
        }
    }

    for (int a = 0; a < n3; a++)
    {
        for (int b = 0; b < n4; b++)
        {
            int sum = nums3[a] + nums4[b];

            if (mp.find(0 - sum) != mp.end())
                cnt += mp[0 - sum];
        }
    }

    return cnt;
}

int main()
{
    vector<int> nums1 = {1, 2};
    vector<int> nums2 = {-2, -1};
    vector<int> nums3 = {-1, 2};
    vector<int> nums4 = {0, 2};

    cout << "Count = " << fourSumCount(nums1, nums2, nums3, nums4) << endl;
    return 0;
}