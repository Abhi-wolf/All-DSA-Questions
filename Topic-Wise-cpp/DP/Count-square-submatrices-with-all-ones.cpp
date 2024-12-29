#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

/*
Given a m * n matrix of ones and zeros, return how many square submatrices have all ones.
Example 1:

Input: matrix =
[
  [0,1,1,1],
  [1,1,1,1],
  [0,1,1,1]
]
Output: 15
Explanation:
There are 10 squares of side 1.
There are 4 squares of side 2.
There is  1 square of side 3.
Total number of squares = 10 + 4 + 1 = 15.

Example 2:
Input: matrix =
[
  [1,0,1],
  [1,1,0],
  [1,1,0]
]
Output: 7
Explanation:
There are 6 squares of side 1.
There is 1 square of side 2.
Total number of squares = 6 + 1 = 7.

Constraints:
1 <= arr.length <= 300
1 <= arr[0].length <= 300
0 <= arr[i][j] <= 1
*/

int solve(int i, int j, vector<vector<int>> &matrix, vector<vector<int>> &dp)
{
    if (i < 0 || i >= matrix.size() || j < 0 || j >= matrix[0].size())
        return 0;

    if (matrix[i][j] == 0)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    int right = solve(i, j + 1, matrix, dp);
    int diagonal = solve(i + 1, j + 1, matrix, dp);
    int below = solve(i + 1, j, matrix, dp);

    return dp[i][j] = 1 + min(right, min(diagonal, below));
}

int countSquares(vector<vector<int>> &matrix)
{
    int cnt = 0;
    int rows = matrix.size(), cols = matrix[0].size();

    vector<vector<int>> dp(rows, vector<int>(cols, -1));

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cnt += solve(i, j, matrix, dp);
        }
    }

    return cnt;
}

// METHOD -- 2
int countSquares2(vector<vector<int>> &matrix)
{
    int rows = matrix.size(), cols = matrix[0].size(), ans = 0;

    for (int i = 1; i < rows; i++)
    {
        for (int j = 1; j < cols; j++)
        {
            if (matrix[i][j] == 1)
            {
                matrix[i][j] =
                    1 + min(matrix[i - 1][j],
                            min(matrix[i - 1][j - 1], matrix[i][j - 1]));
            }
        }
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            ans += matrix[i][j];
        }
    }

    return ans;
}

int main()
{

    vector<vector<int>> matrix = {
        {0, 1, 1, 1},
        {1, 1, 1, 1},
        {0, 1, 1, 1}};

    cout << countSquares(matrix) << endl;
    cout << countSquares2(matrix) << endl;
    return 0;
}