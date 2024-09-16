#include <iostream>
#include <vector>
using namespace std;

/* Given n non-negative integers representing an elevation map where the width of each bar is 1,
compute how much water it can trap after raining.

Example 1:
Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.

Example 2:
Input: height = [4,2,0,3,2,5]
Output: 9

Constraints:
n == height.length
1 <= n <= 2 * 104
0 <= height[i] <= 105   */

int trap1(vector<int> &height)
{
    int res = 0, n = height.size();

    for (int i = 0; i < n; i++)
    {
        // left max
        int leftMax = height[i];
        for (int j = 0; j < i; j++)
            leftMax = max(leftMax, height[j]);

        // right max
        int rightMax = height[i];
        for (int j = i + 1; j < n; j++)
            rightMax = max(rightMax, height[j]);

        res += (min(leftMax, rightMax) - height[i]);
    }
    return res;
}

int trap2(vector<int> &height)
{
    int res = 0, n = height.size();

    int left[n];
    int right[n];
    left[0] = height[0];
    right[n - 1] = height[n - 1];

    // left max array
    for (int i = 1; i < n; i++)
        left[i] = max(left[i - 1], height[i]);

    // right max array
    for (int i = n - 2; i >= 0; i--)
        right[i] = max(right[i + 1], height[i]);

    // compare using both the arrays
    for (int i = 1; i < n - 1; i++)
    {
        int var = min(left[i - 1], right[i + 1]);
        if (var > height[i])
            res += (var - height[i]);
    }

    return res;
}

int main()
{
    vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    cout << trap1(height) << endl;
    cout << trap2(height) << endl;
    return 0;
}