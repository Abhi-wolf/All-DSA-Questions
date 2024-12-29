#include <iostream>
#include <vector>
using namespace std;

/*
Consider a rat placed at (0, 0) in a square matrix mat of order n* n. It has to reach the destination at (n - 1, n - 1).
Find all possible paths that the rat can take to reach from source to destination. The directions in which the rat can
move are 'U'(up), 'D'(down), 'L' (left), 'R' (right). Value 0 at a cell in the matrix represents that it is blocked and
rat cannot move to it while value 1 at a cell in the matrix represents that rat can be travel through it.
Note: In a path, no cell can be visited more than one time. If the source cell is 0, the rat cannot move to any other cell.
In case of no path, return an empty list. The driver will output "-1" automatically.

Examples:
Input: mat[][] = [[1, 0, 0, 0],
                [1, 1, 0, 1],
                [1, 1, 0, 0],
                [0, 1, 1, 1]]
Output: DDRDRR DRDDRR
Explanation: The rat can reach the destination at (3, 3) from (0, 0) by two paths - DRDDRR and DDRDRR, when printed in sorted
order we get DDRDRR DRDDRR.

Input: mat[][] = [[1, 0],
                [1, 0]]
Output: -1
Explanation: No path exists and destination cell is blocked.

Expected Time Complexity: O(3n^2)
Expected Auxiliary Space: O(l * x)
Here l = length of the path, x = number of paths.

Constraints:
2 ≤ n ≤ 5
0 ≤ mat[i][j] ≤ 1
*/

void solve(vector<vector<int>> &mat, int i, int j, string res, vector<vector<bool>> &visited, vector<string> &ans)
{
    if (i == mat.size() - 1 && j == mat[0].size() - 1)
    {
        ans.push_back(res);
        cout << res << ", ";
        return;
    }

    if (i < 0 || j < 0 || i >= mat.size() || j >= mat[0].size() || mat[i][j] == 0 || visited[i][j] == true)
        return;

    visited[i][j] = true;

    solve(mat, i + 1, j, res + 'D', visited, ans); // Down
    solve(mat, i - 1, j, res + 'U', visited, ans); // Up
    solve(mat, i, j - 1, res + 'L', visited, ans); // Left
    solve(mat, i, j + 1, res + 'R', visited, ans); // Right

    visited[i][j] = false;
}

vector<string> findPath(vector<vector<int>> &mat)
{
    int n = mat.size();
    vector<string> ans;
    vector<vector<bool>> visited(n, vector<bool>(n, false));

    if (mat[0][0] == 0 || mat[n - 1][n - 1] == 0)
        return ans;

    solve(mat, 0, 0, "", visited, ans);

    return ans;
}

int main()
{
    vector<vector<int>> mat = {{1, 0, 0, 0},
                               {1, 1, 0, 1},
                               {1, 1, 0, 0},
                               {0, 1, 1, 1}};

    vector<vector<int>> mat2 = {{1, 0}, {1, 1}};

    vector<string> ans = findPath(mat);
    return 0;
}
