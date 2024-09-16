#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/* Given an array arr containing n integers and an integer k.
Your task is to find the length of the longest Sub-Array with the sum of the elements equal to the given value k.

Examples:
Input : arr[] = {10, 5, 2, 7, 1, 9}, k = 15
Output : 4
Explanation: The sub-array is {5, 2, 7, 1}.

Input : arr[] = {-1, 2, 3}, k = 6
Output : 0
Explanation: There is no such sub-array with sum 6.

Expected Time Complexity: O(n).
Expected Auxiliary Space: O(n).

Constraints:
1<=n<=105
-105<=arr[i], K<=105    */

int lenOfLongSubarr(vector<int> A, int K)
{
    unordered_map<int, int> preSum;
    int N = A.size();
    int len = 0, sum = 0;

    for (int i = 0; i < N; i++)
    {
        sum += A[i];

        if (sum == K)
            len = max(len, i + 1);

        int rem = sum - K;

        if (preSum.find(rem) != preSum.end())
        {
            int length = i - preSum[rem];
            len = max(len, length);
        }

        if (preSum.find(sum) == preSum.end())
            preSum[sum] = i;
    }
    return len;
}

int main()
{
    vector<int> A = {10, 5, 2, 7, 1, 9};
    vector<int> B = {-1, 2, 3};
    cout << lenOfLongSubarr(A, 15) << endl;
    cout << lenOfLongSubarr(B, 6) << endl;
    return 0;
}