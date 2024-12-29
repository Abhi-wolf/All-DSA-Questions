#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*
You are given two m x n binary matrices grid1 and grid2 containing only 0's (representing water) and 1's (representing
land). An island is a group of 1's connected 4-directionally (horizontal or vertical). Any cells outside of the grid
are considered water cells.
An island in grid2 is considered a sub-island if there is an island in grid1 that contains all the cells that make up
this island in grid2.

Return the number of islands in grid2 that are considered sub-islands.

Example 1:
Input: grid1 = [[1,1,1,0,0],[0,1,1,1,1],[0,0,0,0,0],[1,0,0,0,0],[1,1,0,1,1]],
grid2 = [[1,1,1,0,0],[0,0,1,1,1],[0,1,0,0,0],[1,0,1,1,0],[0,1,0,1,0]]
Output: 3
Explanation: In the picture above, the grid on the left is grid1 and the grid on the right is grid2.
The 1s colored red in grid2 are those considered to be part of a sub-island. There are three sub-islands.

Example 2:
Input: grid1 = [[1,0,1,0,1],[1,1,1,1,1],[0,0,0,0,0],[1,1,1,1,1],[1,0,1,0,1]],
grid2 = [[0,0,0,0,0],[1,1,1,1,1],[0,1,0,1,0],[0,1,0,1,0],[1,0,0,0,1]]
Output: 2
Explanation: In the picture above, the grid on the left is grid1 and the grid on the right is grid2.
The 1s colored red in grid2 are those considered to be part of a sub-island. There are two sub-islands.


Constraints:

m == grid1.length == grid2.length
n == grid1[i].length == grid2[i].length
1 <= m, n <= 500
grid1[i][j] and grid2[i][j] are either 0 or 1.
*/

int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

// Helper method to check if the cell at the position (x, y) in the 'grid'
// is a land cell.
bool isCellLand(int x, int y, vector<vector<int>> &grid)
{
    return grid[x][y] == 1;
}

// Traverse all cells of island starting at position (x, y) in 'grid2',
// and check this island is a sub-island in 'grid1'.
bool isSubIsland(int x, int y, vector<vector<int>> &grid1,
                 vector<vector<int>> &grid2,
                 vector<vector<bool>> &visited)
{
    int totalRows = grid2.size(), totalCols = grid2[0].size();

    bool issubisland = true;

    queue<pair<int, int>> pending;
    pending.push({x, y});
    visited[x][y] = true;

    while (!pending.empty())
    {
        int currX = pending.front().first;
        int currY = pending.front().second;

        pending.pop();

        // If the current position cell is not a land cell in 'grid1',
        // then the current island can't be a sub-island.
        if (!isCellLand(currX, currY, grid1))
        {
            issubisland = false;
        }

        for (auto dir : directions)
        {
            int nextX = currX + dir[0];
            int nextY = currY + dir[1];

            // If the next cell is inside 'grid2', is never visited and
            // is a land cell, then we traverse to the next cell.
            if (nextX >= 0 && nextY >= 0 && nextX < totalRows &&
                nextY < totalCols && !visited[nextX][nextY] &&
                isCellLand(nextX, nextY, grid2))
            {
                // Push the next cell in the queue and mark it as visited.
                pending.push({nextX, nextY});
                visited[nextX][nextY] = true;
            }
        }
    }
    return issubisland;
}

int countSubIslands(vector<vector<int>> &grid1,
                    vector<vector<int>> &grid2)
{
    int totalRows = grid2.size();
    int totalCols = grid2[0].size();

    vector<vector<bool>> visited(totalRows, vector<bool>(totalCols, false));
    int count = 0;

    for (int i = 0; i < totalRows; i++)
    {
        for (int j = 0; j < totalCols; j++)
        {
            // If cell at the position (x, y) in the 'grid2' is not visited,
            // is a land cell in 'grid2', and the island
            // starting from this cell is a sub-island in 'grid1', then we
            // increment the count of sub-islands.
            if (!visited[i][j] && isCellLand(i, j, grid2) &&
                isSubIsland(i, j, grid1, grid2, visited))
                count++;
        }
    }
    return count;
}

int main()
{
    vector<vector<int>> grid1 = {{1, 1, 1, 0, 0}, {0, 1, 1, 1, 1}, {0, 0, 0, 0, 0}, {1, 0, 0, 0, 0}, {1, 1, 0, 1, 1}};
    vector<vector<int>> grid2 = {{1, 1, 1, 0, 0}, {0, 0, 1, 1, 1}, {0, 1, 0, 0, 0}, {1, 0, 1, 1, 0}, {0, 1, 0, 1, 0}};

    cout << "No of sub islands = " << countSubIslands(grid1, grid2) << endl;
    return 0;
}