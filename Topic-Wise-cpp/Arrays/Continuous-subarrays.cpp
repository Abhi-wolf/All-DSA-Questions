#include <bits/stdc++.h>
using namespace std;

/*You are given a 0-indexed integer array nums. A subarray of nums is called continuous if:
Let i, i + 1, ..., j be the indices in the subarray. Then, for each pair of indices i <= i1, i2 <= j,
0 <= |nums[i1] - nums[i2]| <= 2.

Return the total number of continuous subarrays.
A subarray is a contiguous non-empty sequence of elements within an array.

Example 1:
Input: nums = [5,4,2,4]
Output: 8
Explanation:
Continuous subarray of size 1: [5], [4], [2], [4].
Continuous subarray of size 2: [5,4], [4,2], [2,4].
Continuous subarray of size 3: [4,2,4].
Thereare no subarrys of size 4.
Total continuous subarrays = 4 + 3 + 1 = 8.
It can be shown that there are no more continuous subarrays.

Example 2:
Input: nums = [1,2,3]
Output: 6
Explanation:
Continuous subarray of size 1: [1], [2], [3].
Continuous subarray of size 2: [1,2], [2,3].
Continuous subarray of size 3: [1,2,3].
Total continuous subarrays = 3 + 2 + 1 = 6.

Constraints:
1 <= nums.length <= 105
1 <= nums[i] <= 109 */

// METHOD 01 (TLE)
long long continuousSubarrays1(vector<int>& nums) {
        long long cnt = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            int mini = nums[i], maxi = nums[i];

            for (int j = i; j < n; j++) {
                mini = min(mini, nums[j]);
                maxi = max(maxi, nums[j]);

                if (abs(maxi - mini) <= 2) {
                    cnt++;
                } else {
                    break;
                }
            }
        }

        return cnt;
    }


// METHOD 02 (O(nlogn))
long long continuousSubarrays2(vector<int>& nums) {
    int size = nums.size(), left = 0, right = 0;
            long long cnt = 0;

            // Min and max heaps storing indices, sorted by nums[index] values
            priority_queue<int, vector<int>, function<bool(int, int)>> minheap(
                [&nums](int a, int b) { return nums[a] > nums[b]; });
            priority_queue<int, vector<int>, function<bool(int, int)>> maxheap(
                [&nums](int a, int b) { return nums[a] < nums[b]; });

            while (right < size) {
                 // Add current index to both heaps
                minheap.push(right);
                maxheap.push(right);

                // While window violates |nums[i] - nums[j]| ≤ 2 condition
                // Shrink window from left and remove outdated indices
                while (left < right &&
                       nums[maxheap.top()] - nums[minheap.top()] > 2) {
                    left++;

                    while (!minheap.empty() && minheap.top() < left)
                        minheap.pop();
                    while (!maxheap.empty() && maxheap.top() < left)
                        maxheap.pop();
                }
                 // Add count of all valid subarrays ending at right
                cnt += (right - left + 1);
                right++;
            }

            return cnt;
}

// METHOD 03 (O(nlogk)≈O(n))
long long continuousSubarrays3(vector<int>& nums) {
    int size=nums.size(),left=0,right=0;
    map<int,int>freq;
    long long cnt=0;

    while(right<size) {
        freq[nums[right]]++;

        while(freq.rbegin()->first - freq.begin()->first > 2) {
            freq[nums[left]]--;

            if(freq[nums[left]]==0) freq.erase(nums[left]);
            left++;
        }

        cnt += (right-left+1);
        right++;
    }
    return cnt;
}

int main() {
    vector<int>nums1={5,4,2,4};
    vector<int>nums2={1,2,3};

    cout<<"Result 1 = "<<continuousSubarrays3(nums1)<<endl;
    cout<<"Result 2 = "<<continuousSubarrays3(nums2)<<endl;

    return 0;
}
