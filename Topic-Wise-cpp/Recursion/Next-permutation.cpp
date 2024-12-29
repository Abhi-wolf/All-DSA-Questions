#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
A permutation of an array of integers is an arrangement of its members into a sequence or linear order.
For example, for arr = [1,2,3], the following are all the permutations of arr: [1,2,3], [1,3,2], [2, 1, 3],
[2, 3, 1], [3,1,2], [3,2,1].
The next permutation of an array of integers is the next lexicographically greater permutation of its integer. More formally,
if all the permutations of the array are sorted in one container according to their lexicographical order, then the next permutation
of that array is the permutation that follows it in the sorted container. If such arrangement is not possible, the array must be
rearranged as the lowest possible order (i.e., sorted in ascending order).

For example, the next permutation of arr = [1,2,3] is [1,3,2].
Similarly, the next permutation of arr = [2,3,1] is [3,1,2].
While the next permutation of arr = [3,2,1] is [1,2,3] because [3,2,1] does not have a lexicographical larger rearrangement.
Given an array of integers nums, find the next permutation of nums.

The replacement must be in place and use only constant extra memory.

Example 1:
Input: nums = [1,2,3]
Output: [1,3,2]

Example 2:
Input: nums = [3,2,1]
Output: [1,2,3]

Example 3:
Input: nums = [1,1,5]
Output: [1,5,1]

Constraints:
1 <= nums.length <= 100
0 <= nums[i] <= 100
*/

void findAllPermutations(vector<int> nums, int ind,
                         vector<vector<int>> &permutations)
{
    if (ind == nums.size())
    {
        permutations.push_back(nums);
        return;
    }

    for (int i = ind; i < nums.size(); i++)
    {
        if (i != ind && nums[i] == nums[ind])
            continue;

        swap(nums[i], nums[ind]);
        findAllPermutations(nums, ind + 1, permutations);
    }
}
// METHOD 1
void nextPermutation(vector<int> &nums)
{
    vector<vector<int>> permutations;

    vector<int> temp = nums;
    sort(temp.begin(), temp.end());

    findAllPermutations(temp, 0, permutations);

    sort(permutations.begin(), permutations.end());

    auto it = find(permutations.begin(), permutations.end(), nums);

    if (it != permutations.end())
    {
        int ind = distance(permutations.begin(), it);

        if (ind == permutations.size() - 1)
            nums = permutations[0];
        else
            nums = permutations[ind + 1];
    }
}

// METHOD 2
void nextPermutation2(vector<int> &nums)
{
    next_permutation(nums.begin(), nums.end());
}

// METHOD 3
void nextPermutation3(vector<int> &nums)
{
    int n = nums.size(), ind = -1;

    // find the point where nums[i] < nums[i+1]
    for (int i = n - 2; i >= 0; i--)
    {
        if (nums[i] < nums[i + 1])
        {
            ind = i;
            break;
        }
    }

    // ind==-1
    if (ind == -1)
    {
        reverse(nums.begin(), nums.end());
        return;
    }

    // find the element just greater than the element at ind from last
    for (int i = n - 1; i > ind; i--)
    {
        if (nums[i] > nums[ind])
        {
            swap(nums[i], nums[ind]);
            break;
        }
    }

    reverse(nums.begin() + ind + 1, nums.end());
}

int main()
{
    vector<int> nums = {1, 2, 3};
    nextPermutation(nums);
    nextPermutation2(nums);
    nextPermutation3(nums);
    return 0;
}