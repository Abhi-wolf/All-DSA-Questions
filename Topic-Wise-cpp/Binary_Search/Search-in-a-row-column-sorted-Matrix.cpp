#include <iostream>
#include <vector>
using namespace std;

/*
Given a matrix of size n x m, where every row and column is sorted in increasing order, and a number x.
Find whether element x is present in the matrix or not. Return a boolean value true if x is present in the
matrix and false if it is not present.

Examples :
Input:  matrix[][] = [[3, 30, 38],[36, 43, 60],[40, 51, 69]], x = 62
Output: 0
Explanation: 62 is not present in the matrix, so output is 0.

Input: matrix[][] = [[18, 21, 27, 38, 55, 67]], x = 55
Output: 1
Explanation: 55 is present in the matrix.

Expected Time Complexity: O(n + m)
Expected Auxiliary Space: O(1)
*/

// TC -- O(nlogm)
bool search1(vector<vector<int>> &matrix, int n, int m, int x)
{

    for (int i = 0; i < n; i++)
    {
        if (matrix[i][0] <= x && matrix[i][m - 1] >= x)
        {
            int start = 0, end = m - 1;

            while (start <= end)
            {
                int mid = start + (end - start) / 2;

                if (matrix[i][mid] == x)
                    return 1;
                else if (matrix[i][mid] > x)
                    end = mid - 1;
                else
                    start = mid + 1;
            }
        }
    }
    return 0;
}

// TC -- O(n+m)
bool search2(vector<vector<int>> &matrix, int n, int m, int x)
{

    int i = 0, j = m - 1;

    while (i >= 0 && i < n && j >= 0 && j < m)
    {
        if (matrix[i][j] == x)
            return 1;
        //   if matrix[i][j] is greater than x than the x would be found in left side
        else if (matrix[i][j] > x)
            j--;
        //   if matrix[i][j] is less than x than the x would be found in down side
        else if (matrix[i][j] < x)
            i++;
    }
    return 0;
}

int main()
{
    vector<vector<int>> matrix = {{3, 30, 38}, {36, 43, 60}, {40, 51, 69}};
    int n = matrix.size();
    int m = matrix[0].size();

    cout << "Is Present = " << search2(matrix, n, m, 30) << endl;
    return 0;
}