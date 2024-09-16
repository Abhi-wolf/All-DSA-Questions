#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

/*
Given an array arr[] of non-negative integers. Each array element represents the maximum length of the jumps that can
be made forward from that element. This means if arr[i] = x, then we can jump any distance y such that y ≤ x.
Find the minimum number of jumps to reach the end of the array starting from the first element. If an element is 0,
then you cannot move through that element.
Note:  Return -1 if you can't reach the end of the array.

Examples :
Input: arr[] = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9}
Output: 3
Explanation:First jump from 1st element to 2nd element with value 3. From here we jump to 5th element with value 9,
and from here we will jump to the last.
Input: arr = {1, 4, 3, 2, 6, 7}
Output: 2
Explanation: First we jump from the 1st to 2nd element and then jump to the last element.

Input: arr = {0, 10, 20}
Output: -1
Explanation: We cannot go anywhere from the 1st element.

Expected Time Complexity: O(n)
Expected Space Complexity: O(1)

Constraints:
0 ≤ arr[i] ≤ 105
2 ≤ arr.size() ≤ 106
*/

int minJumps(vector<int> &arr)
{
    int n = arr.size();
    vector<int> jump(n, INT_MAX);

    // USING DP
    jump[0] = 0;

    if (arr[0] == 0)
        return -1;

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (jump[j] != INT_MAX && i <= (j + arr[j]))
            {
                jump[i] = min(jump[i], jump[j] + 1);
                break;
            }
        }
    }

    return jump[n - 1] == INT_MAX ? -1 : jump[n - 1];
}

// GREEDY
int minJumps2(vector<int> &arr)
{
    int n = arr.size();
    int jump = 0;
    int pos = 0;
    int mx = 0;
    for (int i = 0; i < n; i++)
    {
        mx = max(mx, i + arr[i]);
        if (i == pos)
        {
            pos = mx;
            jump++;
        }
        if (pos >= n - 1)
            return jump;
    }
    return -1;
}

int main()
{
    vector<int> arr = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9};
    cout << "Jumps = " << minJumps(arr) << endl;
    cout << "Jumps = " << minJumps2(arr) << endl;
    return 0;
}