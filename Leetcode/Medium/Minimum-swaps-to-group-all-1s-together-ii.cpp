#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

int minSwapsForVal(vector<int> &nums, int val)
{
    int totalVal = 0;
    int len = nums.size();

    // find number of values present -- acts as window size
    for (int num : nums)
    {
        if (num == val)
            totalVal++;
    }

    if (totalVal == 0 || totalVal == len)
        return 0;

    int start = 0, end = 0;
    int currValInWindow = 0, maxValInWindow = 0;

    // first window
    while (end < totalVal)
    {
        if (nums[end] == val)
            currValInWindow++;

        end++;
    }

    maxValInWindow = max(currValInWindow, maxValInWindow);

    // slide the window
    while (end < len)
    {
        if (nums[start] == val)
            currValInWindow--;

        if (nums[end] == val)
            currValInWindow++;

        start++;
        end++;

        maxValInWindow = max(maxValInWindow, currValInWindow);
    }

    return totalVal - maxValInWindow;
}

// FIRST METHOD
int minSwaps2(vector<int> &nums)
{
    int ones = minSwapsForVal(nums, 1);
    int zeros = minSwapsForVal(nums, 0);

    return min(ones, zeros);
}

// SECOND METHOD
int minSwaps(vector<int> &nums)
{
    int len = nums.size();
    int minSwaps = INT_MAX;
    int totalOnes = 0;

    // calculate total ones -- acts as window size
    for (int num : nums)
        totalOnes += num;

    int start = 0, end = 0;
    int onesCount = 0;

    while (start < len)
    {
        // maintain the window size
        while ((end - start) < totalOnes)
        {
            onesCount += nums[end % len]; // %len to tackle when end goes beyond len -- to maintain circular nature
            end++;
        }

        // find minium swaps
        minSwaps = min(minSwaps, totalOnes - onesCount);
        onesCount -= nums[start];
        start++;
    }

    return minSwaps;
}

int main()
{
    vector<int> nums = {0, 1, 0, 1, 1, 0, 0};
    vector<int> nums2 = {0, 1, 1, 1, 0, 0, 1, 1, 0};
    vector<int> nums3 = {1, 1, 0, 0, 1};

    cout << minSwaps(nums) << endl;
    cout << minSwaps(nums2) << endl;
    cout << minSwaps(nums3) << endl;

    cout << minSwaps2(nums) << endl;
    cout << minSwaps2(nums2) << endl;
    cout << minSwaps2(nums3) << endl;
    return 0;
}