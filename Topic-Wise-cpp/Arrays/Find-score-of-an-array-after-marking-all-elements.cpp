#include <bits/stdc++.h>
using namespace std;

/* You are given an array nums consisting of positive integers.
Starting with score = 0, apply the following algorithm:
Choose the smallest integer of the array that is not marked. If there is a tie, choose the one with the smallest index.
Add the value of the chosen integer to score.
Mark the chosen element and its two adjacent elements if they exist.
Repeat until all the array elements are marked.
Return the score you get after applying the above algorithm.

Example 1:
Input: nums = [2,1,3,4,5,2]
Output: 7
Explanation: We mark the elements as follows:
- 1 is the smallest unmarked element, so we mark it and its two adjacent elements: [2,1,3,4,5,2].
- 2 is the smallest unmarked element, so we mark it and its left adjacent element: [2,1,3,4,5,2].
- 4 is the only remaining unmarked element, so we mark it: [2,1,3,4,5,2].
Our score is 1 + 2 + 4 = 7.

Example 2:
Input: nums = [2,3,5,1,3,2]
Output: 5
Explanation: We mark the elements as follows:
- 1 is the smallest unmarked element, so we mark it and its two adjacent elements: [2,3,5,1,3,2].
- 2 is the smallest unmarked element, since there are two of them, we choose the left-most one, so we mark the one at index 0 and its right adjacent element: [2,3,5,1,3,2].
- 2 is the only remaining unmarked element, so we mark it: [2,3,5,1,3,2].
Our score is 1 + 2 + 2 = 5.

Constraints:
1 <= nums.length <= 105
1 <= nums[i] <= 106 */

class Solution {
    static bool cmp(pair<int,int>&a,pair<int,int>&b) {
        if(a.second == b.second) return a.first < b.first;

        return a.second < b.second;
    }

    public:
    long long findScore(vector<int>& nums) {
        int size=nums.size();
        long long score=0;

        vector<pair<int,int>>items;
        vector<bool>marked(size,false);

        for(int i=0;i<size;i++) {
            items.push_back({i,nums[i]});
        }

        sort(items.begin(),items.end(),cmp);

        for(int i=0;i<size;i++) {
            int ind=items[i].first;

            if(!marked[ind]) {
                score += items[i].second;
                marked[ind]=true;
                if(ind < size-1) marked[ind+1] = true;
                if(ind > 0 ) marked[ind-1] = true;
            }
        }


        return score;
    }
};


int main() {
    Solution obj= Solution();
    vector<int>nums1={2,1,3,4,5,2};
    vector<int>nums2={2,3,5,1,3,2};
    cout<<"Result  1 = "<<obj.findScore(nums1)<<endl;
    cout<<"Result  2 = "<<obj.findScore(nums2)<<endl;

    return 0;
}
