#include <iostream>
#include <vector>
using namespace std;

/*
You are given an array of integer nums[] where each number represents a vote to a candidate. Return the
candidates that have votes greater than one-third of the total votes, If there's not a majority vote, return -1.

Examples:
Input: nums = [2, 1, 5, 5, 5, 5, 6, 6, 6, 6, 6]
Output: [5, 6]
Explanation: 5 and 6 occur more n/3 times.
Input: nums = [1, 2, 3, 4, 5]
Output: [-1]
Explanation: no candidate occur more than n/3 times.

Expected Time Complexity: O(n)
Expected Space Complexity: O(1)

Constraint:
1 <=  nums.size()  <= 106
-109 <= nums[i] <= 109
*/

vector<int> findMajority(vector<int> &nums)
{
    vector<int> res;
    int size = nums.size();
    int oneThird = size / 3;

    // there can be maximum two elements whose freq can be greater than n/3 in an array
    int fir = -1, sec = -1, c1 = 0, c2 = 0;

    for (int x : nums)
    {
        if (c1 == 0 && sec != x)
        {
            fir = x;
            c1 = 1;
        }
        else if (c2 == 0 && fir != x)
        {
            sec = x;
            c2 = 1;
        }
        else
        {
            if (fir == x)
                c1++;
            else if (sec == x)
                c2++;
            else
            {
                c1--;
                c2--;
            }
        }
    }

    // confirm it
    c1 = 0, c2 = 0;
    for (int x : nums)
    {
        if (fir == x)
            c1++;
        else if (sec == x)
            c2++;
    }

    if (c1 > oneThird)
        res.push_back(fir);
    if (c2 > oneThird)
        res.push_back(sec);

    if (res.size() == 0)
        return {-1};

    return res;
}

int main()
{
    vector<int> nums{2, 1, 5, 5, 5, 5, 6, 6, 6, 6, 6};
    vector<int> res = findMajority(nums);

    cout << "\n\n";
    for (int x : res)
        cout << x << ", ";
    cout << "\n\n";
    return 0;
}