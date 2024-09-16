#include <iostream>
#include <limits.h>
using namespace std;

/*
You have n books, each with arr[i] a number of pages. m students need to be allocated contiguous books,
with each student getting at least one book.
Out of all the permutations, the goal is to find the permutation where the sum of the maximum number of
pages in a book allotted to a student should be the minimum, out of all possible permutations.

Note: Return -1 if a valid assignment is not possible, and allotment should be in contiguous order
(see the explanation for better understanding).

Examples:

Input: n = 4, arr[] = [12, 34, 67, 90], m = 2
Output: 113
Explanation: Allocation can be done in following ways:
{12} and {34, 67, 90} Maximum Pages = 191
{12, 34} and {67, 90} Maximum Pages = 157
{12, 34, 67} and {90} Maximum Pages =113.
Therefore, the minimum of these cases is 113, which is selected as the output.

Input: n = 3, arr[] = [15, 17, 20], m = 5
Output: -1
Explanation: Allocation can not be done.

Expected Time Complexity: O(n logn)
Expected Auxilliary Space: O(1)

Constraints:
1 <=  n, m <= 105
1 <= arr[i] <= 106
*/

bool isPossible(int arr[], int n, int m, int curr_max)
{
    int studentsRequired = 1;
    int curr_sum = 0;

    for (int i = 0; i < n; i++)
    {
        if (curr_sum + arr[i] > curr_max)
        {
            studentsRequired++;
            curr_sum = arr[i];

            if (studentsRequired > m)
                return false;
        }
        else
        {
            curr_sum += arr[i];
        }
    }
    return true;
}

long long findPages(int n, int arr[], int m)
{
    // return -1 if no. of books is less than
    // no. of students
    if (n < m)
        return -1;

    int mx = INT_MIN;
    long long sum = 0;

    // Count total number of pages
    for (int i = 0; i < n; i++)
    {
        mx = max(mx, arr[i]);
        sum += arr[i];
    }

    int start = mx, end = sum;
    int result = INT_MAX;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        // check if it is possible to distribute
        // books by using mid as current minimum
        if (isPossible(arr, n, m, mid))
        {
            result = mid;
            end = mid - 1;
        }
        else
        {
            // if not possible means pages should be
            // increased so update start = mid + 1
            start = mid + 1;
        }
    }
    return result;
}

int main()
{
    // Number of pages in books
    int arr[] = {12, 34, 67, 90};
    int n = sizeof arr / sizeof arr[0];
    int m = 2; // No. of students

    cout << "Minimum number of pages = "
         << findPages(n, arr, m) << endl;
    return 0;
}