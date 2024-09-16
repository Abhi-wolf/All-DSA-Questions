#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

// not working

int solve(vector<vector<int>> &grid, int n, int row, int col, vector<vector<int>> &dp)
{
    cout << row << ", " << col << endl;
    if (row >= n || col >= n || row < 0 || col < 0)
        return INT_MAX;

    if (row == n - 1 && col == n - 1)
    {
        cout << row << " ," << col << endl;
        return grid[row][col];
    }

    if (dp[row][col] != INT_MAX)
        return dp[row][col];

    int top = INT_MAX, bottom = INT_MAX, left = INT_MAX, right = INT_MAX;

    if (row > 0) // Move up
        top = solve(grid, n, row - 1, col, dp);

    if (row < n - 1) // Move down
        bottom = solve(grid, n, row + 1, col, dp);

    if (col > 0) // Move left
        left = solve(grid, n, row, col - 1, dp);

    if (col < n - 1) // Move right
        right = solve(grid, n, row, col + 1, dp);

    return dp[row][col] = grid[row][col] + min(top, min(bottom, min(left, right)));
}

// Function to return the minimum cost to react at bottom
// right cell from top left cell.
int minimumCostPath(vector<vector<int>> &grid)
{
    int ans = INT_MAX;
    int n = grid[0].size();
    vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
    solve(grid, n, 0, 0, dp);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << dp[i][j] << ", ";
        cout << endl;
    }

    return ans;
}

int main()
{
    // vector<vector<int>> grid = {{9, 4, 9, 9}, {6, 7, 6, 4}, {8, 3, 3, 7}, {7, 4, 9, 10}};
    vector<vector<int>> grid = {{4, 4}, {3, 7}};
    cout << minimumCostPath(grid) << endl;
    return 0;
}