#include <iostream>
#include <vector>
using namespace std;

/*
Given an unsorted array arr of size n of positive integers. One number 'A' from set {1, 2,....,N} is
missing and one number 'B' occurs twice in array. Find these two numbers.
Your task is to complete the function findTwoElement() which takes the array of integers arr and n as
parameters and returns an array of integers of size 2 denoting the answer (The first index contains B
and second index contains A)

Examples

Input: n = 2 arr[] = {2, 2}
Output: 2 1
Explanation: Repeating number is 2 and smallest positive missing number is 1.
Input: n = 3 arr[] = {1, 3, 3}
Output: 3 2
Explanation: Repeating number is 3 and smallest positive missing number is 2.
Expected Time Complexity: O(n)
Expected Auxiliary Space: O(1)

Constraints:
2 ≤ n ≤ 105
1 ≤ arr[i] ≤ n
*/

// FIRST
vector<int> findTwoElement(vector<int> arr, int n)
{
    vector<int> hash(n + 1, 0);
    vector<int> ans(2, -1);

    for (int i = 0; i < n; i++)
    {
        hash[arr[i]]++;
    }

    for (int i = 1; i <= n; i++)
    {
        if (hash[i] == 2)
            ans[0] = i;
        else if (hash[i] == 0)
            ans[1] = i;
    }
    return ans;
}

// SECOND -- will not work in large test cases
vector<int> findTwoElement2(vector<int> arr, int n)
{
    long long int originalSum = 0, duplicateSum = 0, originalSquareSum = 0, duplicateSquareSum = 0;

    originalSum = (n * (n + 1)) / 2;
    originalSquareSum = (n * (n + 1) * (2 * n + 1)) / 6;

    for (int i = 0; i < n; i++)
    {
        duplicateSum += arr[i];
        duplicateSquareSum += (1ll * arr[i] * 1ll * arr[i]);
    }

    cout << originalSum << " , " << originalSquareSum << endl;
    cout << duplicateSum << " , " << duplicateSquareSum << endl;

    int firstEqu = duplicateSum - originalSum;
    int secondEqu = duplicateSquareSum - originalSquareSum;

    cout << firstEqu << " --> " << secondEqu << endl;

    secondEqu /= firstEqu;

    int repeatedNo = (firstEqu + secondEqu) / 2;
    int missingNo = repeatedNo - firstEqu;
    return {(int)repeatedNo, (int)missingNo};
}

vector<int> findTwoElement3(vector<int> &arr)
{
    vector<int> ans(2, -1);
    int n = arr.size();

    //   original arr = 1,3,3
    //   new arr      = -1,3,-3
    for (int i = 0; i < n; i++)
    {
        int curr = abs(arr[i]);

        if (arr[curr - 1] < 0)
        {
            ans[0] = curr;
        }
        else
        {
            arr[curr - 1] = -arr[curr - 1];
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (arr[i] > 0)
        {
            ans[1] = i + 1;
            break;
        }
    }

    return ans;
}

int main()
{
    vector<int> arr = {1, 3, 3};
    vector<int> ans = findTwoElement2(arr, 3);

    cout << ans[0] << ", " << ans[1] << endl;

    return 0;
}