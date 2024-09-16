#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/* Given a set of distinct positive integers nums, return the largest subset answer such that every
pair (answer[i], answer[j]) of elements in this subset satisfies:
answer[i] % answer[j] == 0, or
answer[j] % answer[i] == 0
If there are multiple solutions, return any of them.

Example 1:
Input: nums = [1,2,3]
Output: [1,2]
Explanation: [1,3] is also accepted.

Example 2:
Input: nums = [1,2,4,8]
Output: [1,2,4,8]

Constraints:
1 <= nums.length <= 1000
1 <= nums[i] <= 2 * 109
All the integers in nums are unique.
*/

void solve(vector<int> nums, int index, vector<int> temp, vector<int> &ans)
{
    if (index > nums.size())
        return;

    if (index <= nums.size())
    {
        if (temp.size() > ans.size())
            ans = temp;
    }

    for (int i = index; i < nums.size(); i++)
    {
        if (temp.size() == 0)
        {
            temp.push_back(nums[i]);
            solve(nums, i + 1, temp, ans);
            temp.pop_back();
        }

        else
        {
            int end = temp[temp.size() - 1];
            if (nums[i] % end == 0 || end % nums[i] == 0)
            {
                temp.push_back(nums[i]);
                solve(nums, i + 1, temp, ans);
                temp.pop_back();
            }
        }
    }
}

vector<int> largestDivisibleSubset(vector<int> &nums)
{
    vector<int> temp, ans;
    sort(nums.begin(), nums.end());
    solve(nums, 0, temp, ans);

    return ans;
}

void Display(vector<int> res)
{
    if (res.size() == 0)
    {
        cout << "Array is empty\n";
        return;
    }

    for (int i = 0; i < res.size(); i++)
        cout << res[i] << ", ";
    cout << endl;
}

int main()
{
    vector<int> nums = {3, 4, 16, 8};
    vector<int> res = largestDivisibleSubset(nums);
    Display(res);
    return 0;
}