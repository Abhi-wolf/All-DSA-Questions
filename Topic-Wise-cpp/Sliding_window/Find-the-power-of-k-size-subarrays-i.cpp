#include <iostream>
#include <queue>
#include <vector>
using namespace std;

/* You are given an array of integers nums of length n and a positive integer k.
The power of an array is defined as:
Its maximum element if all of its elements are consecutive and sorted in ascending order.
-1 otherwise.
You need to find the power of all subarrays of nums of size k.
Return an integer array results of size n - k + 1, where results[i] is the power of nums[i..(i + k - 1)].

Example 1:
Input: nums = [1,2,3,4,3,2,5], k = 3
Output: [3,4,-1,-1,-1]
Explanation:
There are 5 subarrays of nums of size 3:
[1, 2, 3] with the maximum element 3.
[2, 3, 4] with the maximum element 4.
[3, 4, 3] whose elements are not consecutive.
[4, 3, 2] whose elements are not sorted.
[3, 2, 5] whose elements are not consecutive.

Example 2:
Input: nums = [2,2,2,2,2], k = 4
Output: [-1,-1]

Example 3:
Input: nums = [3,2,3,2,3,2], k = 2
Output: [-1,3,-1,3,-1]

Constraints:
1 <= n == nums.length <= 500
1 <= nums[i] <= 105
1 <= k <= n */

// METHOD 1
vector<int> resultsArray1(vector<int> &nums, int k)
{
    vector<int> res;

    int n = nums.size();

    for (int i = 0; i <= n - k; i++)
    {
        int isSorted = 1;
        int maxEle = nums[i];

        for (int j = i + 1; j < (i + k) && j < n; j++)
        {
            if ((nums[j] - nums[j - 1]) != 1)
            {
                isSorted = 0;
            }

            maxEle = max(maxEle, nums[j]);
        }

        if (isSorted == 1)
        {
            res.push_back(maxEle);
        }
        else
        {
            res.push_back(-1);
        }
    }

    return res;
}

/* We use a deque to store the indices of elements in the valid sequence.
    We'll maintain a window of size k to slide through the array, focusing on
    two aspects: keeping track of the current valid window, and ensuring the
    consecutive property holds.

    As we move to a new element, we first check if it breaks the consecutive
    sequence with the last inserted element in the deque. If it does, we
    invalidate the entire window and clear the deque. Otherwise, we add the
    current element’s index to the deque.

    When our window size reaches k, we examine the size of the deque. If the
    deque contains exactly k indices, we conclude that we have a valid subarray,
    and we can retrieve the maximum element efficiently from the end of the
    deque. If the deque does not have k elements, we set the result for that
    position to -1.*/

// METHOD 2
vector<int> resultsArray2(vector<int> &nums, int k)
{
    vector<int> res;
    deque<int> indDeque;
    int n = nums.size();

    for (int i = 0; i < n; i++)
    {
        if (!indDeque.empty() && indDeque.front() < (i - k + 1))
        {
            indDeque.pop_front();
        }

        if (!indDeque.empty() && nums[i] != nums[i - 1] + 1)
        {
            indDeque.clear();
        }

        indDeque.push_back(i);

        if (i >= k - 1)
        {
            if (indDeque.size() == k)
            {
                res.push_back(nums[indDeque.back()]);
            }
            else
            {
                res.push_back(-1);
            }
        }
    }

    return res;
}

/* we can replace the deque with a simple counter that tracks the length of
the consecutive sequence. As we go through the array, we check each element with
the one that follows it. If they are consecutive, we increase our counter.
Otherwise, we reset the counter to 1 since the sequence is broken.

When our counter reaches k, it signals that we’ve found a valid subarray of size
k. At this point, we store the last element of this sequence as the result. For
any indices that don’t meet the consecutive condition, we set their result to
-1.*/

// METHOD 3
vector<int> resultsArray3(vector<int> &nums, int k)
{
    if (k == 1)
        return nums;

    int n = nums.size(), consecutiveCount = 1;
    vector<int> res(n - k + 1, -1);

    for (int i = 0; i < n - 1; i++)
    {
        if (nums[i] + 1 == nums[i + 1])
            consecutiveCount++;
        else
            consecutiveCount = 1;

        if (consecutiveCount >= k)
        {
            res[i - k + 2] = nums[i + 1];
        }
    }

    return res;
}

void Display1DArray(vector<int> arr)
{
    cout << endl;
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << ", ";
    }
    cout << endl;
}

int main()
{
    vector<int> nums = {1, 2, 3, 4, 3, 2, 5};
    vector<int> res1 = resultsArray1(nums, 3);
    vector<int> res2 = resultsArray2(nums, 3);
    vector<int> res3 = resultsArray3(nums, 3);

    Display1DArray(res1);
    Display1DArray(res2);
    Display1DArray(res3);
    return 0;
}