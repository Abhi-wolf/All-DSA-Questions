#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

/*
Given an n x n array of integers matrix, return the minimum sum of any falling path through matrix.
A falling path starts at any element in the first row and chooses the element in the next row that is either
directly below or diagonally left/right. Specifically, the next element from position (row, col) will be
(row + 1, col - 1), (row + 1, col), or (row + 1, col + 1).

Example 1:
Input: matrix = [[2,1,3],[6,5,4],[7,8,9]]
Output: 13
Explanation: There are two falling paths with a minimum sum as shown.

Example 2:
Input: matrix = [[-19,57],[-40,-5]]
Output: -59
Explanation: The falling path with a minimum sum is shown.

Constraints:
    n == matrix.length == matrix[i].length
    1 <= n <= 100
    -100 <= matrix[i][j] <= 100
*/

void solve(vector<vector<int>> arr, int row, int col, int r, int c, int res, int &ans)
{
    if (r >= row - 1)
    {
        ans = min(ans, res);
        return;
    }

    int fir = INT_MAX, sec = INT_MAX, thir = INT_MAX;

    // take all three possible indexes
    if (r < row - 1 && c > 0)
        fir = arr[r + 1][c - 1];

    if (r < row - 1)
        sec = arr[r + 1][c];

    if (r < row - 1 && c < col - 1)
        thir = arr[r + 1][c + 1];

    // solve for all three indexes
    if (fir != INT_MAX)
        solve(arr, row, col, r + 1, c - 1, res + fir, ans);

    if (sec != INT_MAX)
        solve(arr, row, col, r + 1, c, res + sec, ans);

    if (thir != INT_MAX)
        solve(arr, row, col, r + 1, c + 1, res + thir, ans);
}

int minFallingPathSum(vector<vector<int>> &matrix)
{
    int ans = INT_MAX;
    int row = matrix.size();

    for (int i = 0; i < row; i++)
    {
        int res = matrix[0][i];
        solve(matrix, row, row, 0, i, res, ans);
    }

    return ans;
}

// improved method -DP
int solve2(vector<vector<int>> &mat, int row, int col, vector<vector<int>> &dp)
{
    int m = mat.size();
    int n = mat[0].size();

    if (dp[row][col] != INT_MAX)
        return dp[row][col];

    if (row == m - 1)
        return dp[row][col] = mat[row][col];

    int left = INT_MAX, right = INT_MAX;

    if (col > 0)
        left = solve2(mat, row + 1, col - 1, dp);

    int straight = solve2(mat, row + 1, col, dp);

    if (col < n - 1)
        right = solve2(mat, row + 1, col + 1, dp);

    dp[row][col] = min(left, min(straight, right)) + mat[row][col];

    return dp[row][col];
}

int minFallingPathSum2(vector<vector<int>> &matrix)
{
    int row = matrix.size();
    int col = matrix[0].size();

    if (row == 1 || col == 1)
        return matrix[0][0];

    vector<vector<int>> dp(row, vector<int>(col, INT_MAX));
    int ans = INT_MAX;

    for (int i = 0; i < row; i++)
    {
        ans = min(ans, solve2(matrix, 0, i, dp));
    }

    return ans;
}

int main()
{
    vector<vector<int>> matrix1 = {{2, 1, 3}, {6, 5, 4}, {7, 8, 9}};
    vector<vector<int>> matrix2 = {{-19, 57}, {-40, -5}};
    vector<vector<int>> matrix3 = {{100, -42, -46, -41}, {31, 97, 10, -10}, {-58, -51, 82, 89}, {51, 81, 69, -51}};
    int x = minFallingPathSum2(matrix1);
    cout << "\n Answer = " << x << endl;
    x = minFallingPathSum2(matrix2);
    cout << "\n Answer = " << x << endl;
    x = minFallingPathSum2(matrix3);
    cout << "\n Answer = " << x << endl;
    return 0;
}