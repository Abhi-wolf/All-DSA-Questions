#include <iostream>
#include <vector>
using namespace std;

/*
You are given row x col grid representing a map where grid[i][j] = 1 represents land and grid[i][j] = 0 represents water.

Grid cells are connected horizontally/vertically (not diagonally). The grid is completely surrounded by water, and there is
exactly one island (i.e., one or more connected land cells).

The island doesn't have "lakes", meaning the water inside isn't connected to the water around the island. One cell is a square
with side length 1. The grid is rectangular, width and height don't exceed 100. Determine the perimeter of the island.

Example 1:
Input: grid = [[0,1,0,0],[1,1,1,0],[0,1,0,0],[1,1,0,0]]
Output: 16
Explanation: The perimeter is the 16 yellow stripes in the image above.

Example 2:
Input: grid = [[1]]
Output: 4

Example 3:
Input: grid = [[1,0]]
Output: 4

Constraints:
row == grid.length
col == grid[i].length
1 <= row, col <= 100
grid[i][j] is 0 or 1.
There is exactly one island in grid.
*/

void solve(vector<vector<int>> &grid, int &m, int &n, int i, int j,
           int &peri, vector<vector<int>> &visited)
{
    if (i < 0 || i >= m || j < 0 || j >= n || visited[i][j] == 1 ||
        grid[i][j] == 0)
        return;

    // up
    if (i == 0 || (i > 0 && grid[i - 1][j] == 0))
        peri++;

    // down
    if (i == m - 1 || (i < m - 1 && grid[i + 1][j] == 0))
        peri++;

    // left
    if (j == 0 || (j > 0 && grid[i][j - 1] == 0))
        peri++;

    // right
    if (j == n - 1 || (j < n - 1 && grid[i][j + 1] == 0))
        peri++;

    visited[i][j] = 1;

    solve(grid, m, n, i - 1, j, peri, visited);
    solve(grid, m, n, i + 1, j, peri, visited);
    solve(grid, m, n, i, j - 1, peri, visited);
    solve(grid, m, n, i, j + 1, peri, visited);
}

// METHOD 1
int islandPerimeter(vector<vector<int>> &grid)
{
    int peri = 0;
    int m = grid.size(), n = grid[0].size();
    int startRow = -1, startCol = -1;
    vector<vector<int>> visited(m, vector<int>(n, 0));

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == 1)
            {
                startRow = i;
                startCol = j;
                break;
            }
        }

        if (startRow != -1)
            break;
    }

    solve(grid, m, n, startRow, startCol, peri, visited);
    return peri;
}

// METHOD 2
int islandPerimeter2(vector<vector<int>> &grid)
{
    int count = 0;
    int len = grid.size(), len1;
    for (int i = 0; i < grid.size(); i++)
    {
        len1 = grid[i].size();
        for (int j = 0; j < grid[i].size(); j++)
        {
            if (grid[i][j] == 1)
            {
                count += 4;
                if (i > 0 && grid[i - 1][j] == 1)
                    count--;
                if (i < len - 1 && grid[i + 1][j] == 1)
                    count--;
                if (j > 0 && grid[i][j - 1] == 1)
                    count--;
                if (j < len1 - 1 && grid[i][j + 1] == 1)
                    count--;
            }
        }
    }
    return count;
}

int main()
{
    vector<vector<int>> grid = {{0, 1, 0, 0}, {1, 1, 1, 0}, {0, 1, 0, 0}, {1, 1, 0, 0}};
    cout << islandPerimeter(grid) << endl;
    cout << islandPerimeter2(grid) << endl;
    return 0;
}