#include <iostream>
#include <vector>
using namespace std;

/*
Given a permutation of some of the first natural numbers in an array arr[], determine if the array can be sorted
in exactly two swaps. A swap can involve the same pair of indices twice.
Return true if it is possible to sort the array with exactly two swaps, otherwise return false.

Examples:
Input: arr = [4, 3, 2, 1]
Output: true
Explanation: First, swap arr[0] and arr[3]. The array becomes [1, 3, 2, 4]. Then, swap arr[1] and arr[2]. The array
becomes [1, 2, 3, 4], which is sorted.

Input: arr = [4, 3, 1, 2]
Output: false
Explanation: It is not possible to sort the array with exactly two swaps.
*/

void swapOne(vector<int> &arr)
{
    int n = arr.size();

    for (int i = 0; i < n; i++)
    {
        if (arr[i] != i + 1)
        {
            int temp = arr[i];
            arr[i] = arr[temp - 1];
            arr[temp - 1] = temp;
            break;
        }
    }
}

int countUnsorted(vector<int> &arr)
{
    int cnt = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] != i + 1)
            cnt++;
    }

    return cnt;
}

bool checkSorted(vector<int> &arr)
{
    int n = arr.size();

    int unsorted = countUnsorted(arr);

    if (unsorted == 0 || unsorted == 3)
        return true;
    else if (unsorted == 4)
    {
        swapOne(arr);
        swapOne(arr);

        return countUnsorted(arr) == 0;
    }

    return false;
}

int main()
{
    vector<int> v1 = {4, 3, 1, 2};
    vector<int> v2 = {4, 3, 2, 1};

    cout << checkSorted(v1) << endl;
    cout << checkSorted(v2) << endl;
    return 0;
}