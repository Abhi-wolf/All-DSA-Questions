#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

/* Given an array of integers arr and an integer k. Find the least number of unique integers after removing exactly k elements.

Example 1:
Input: arr = [5,5,4], k = 1
Output: 1
Explanation: Remove the single 4, only 5 is left.

Example 2:
Input: arr = [4,3,1,1,3,3,2], k = 3
Output: 2
Explanation: Remove 4, 2 and either one of the two 1s or three 3s. 1 and 3 will be left.

Constraints:
1 <= arr.length <= 10^5
1 <= arr[i] <= 10^9
0 <= k <= arr.length  */

int findLeastNumOfUniqueInts(vector<int> &arr, int k)
{
    unordered_map<int, int> um;
    vector<int> freq;
    int count = 0;

    for (auto x : arr)
        um[x]++;

    for (auto y : um)
        freq.push_back(y.second);

    sort(freq.begin(), freq.end());
    for (auto x : freq)
    {
        if (x <= k)
        {
            k -= x;
            count++;
        }
        else
        {
            break;
        }
    }

    return (freq.size() - count);
}

int main()
{
    vector<int> arr = {4, 3, 1, 1, 3, 3, 2};
    int res = findLeastNumOfUniqueInts(arr, 3);
    cout << "Result = " << res << endl;
    return 0;
}