#include <iostream>
#include <vector>
using namespace std;

/*
Given an array, arr[], determine if arr can be split into three consecutive parts such that the sum of each
part is equal. If possible, return any index pair(i, j) in an array such that sum(arr[0..i]) = sum(arr[i+1..j])
= sum(arr[j+1..n-1]), otherwise return an array {-1,-1}.

Note: Driver code will print true if arr can be split into three equal sum subarrays, otherwise, it is false.

Examples :
Input:  arr[] = [1, 3, 4, 0, 4]
Output: true
Explanation: [1, 2] is valid pair as sum of subarray arr[0..1] is equal to sum of subarray arr[2..3] and also
to sum of subarray arr[4..4]. The sum is 4.

Input: arr[] = [2, 3, 4]
Output: false
Explanation: No three subarrays exist which have equal sum.

Input: arr[] = [0, 1, 1]
Output: false

Constraints:
3 ≤ arr.size() ≤ 106
0 ≤ arr[i] ≤ 106
*/

int findSum(vector<int> &arr, int start, int end)
{
    int sum = 0;

    for (int i = start; i <= end; i++)
        sum += arr[i];

    return sum;
}

// METHOD 1
vector<int> findSplit(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 0; i < n - 2; i++)
    {
        for (int j = i + 1; j < n - 1; j++)
        {

            int firstsum = findSum(arr, 0, i);
            int secsum = findSum(arr, i + 1, j);
            int thirsum = findSum(arr, j + 1, n - 1);

            if (firstsum == secsum && secsum == thirsum)
                return {i, j};
        }
    }

    return {-1, -1};
}

// METHOD 2
vector<int> findSplit2(vector<int> &arr)
{
    vector<int> res;
    int total = 0;

    for (int ele : arr)
        total += ele;

    // If the total sum is not divisible by 3,
    // it's impossible to split the array
    if (total % 3 != 0)
    {
        res = {-1, -1};
        return res;
    }

    // Keep track of the sum of current segment
    int currSum = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        currSum += arr[i];

        // If the valid segment is found, store its index
        // and reset current sum to zero
        if (currSum == total / 3)
        {
            currSum = 0;
            res.push_back(i);

            // If two valid segments are found and third non
            // empty segment is possible, return the index pair
            if (res.size() == 2 && i < arr.size() - 1)
                return res;
        }
    }

    // If no index pair is possible
    res = {-1, -1};
    return res;
}

int main()
{
    vector<int> arr = {1, 3, 4, 0, 4};
    vector<int> res1 = findSplit(arr);
    vector<int> res2 = findSplit2(arr);

    for (int x : res1)
        cout << x << ", ";

    cout << "\n\n";

    for (int x : res2)
        cout << x << ", ";

    return 0;
}