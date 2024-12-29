#include <iostream>
#include <vector>
#include <unordered_map>
#include <limits.h>
using namespace std;

/* On an 2 x 3 board, there are five tiles labeled from 1 to 5, and an empty square represented
by 0. A move consists of choosing 0 and a 4-directionally adjacent number and swapping it.
The state of the board is solved if and only if the board is [[1,2,3],[4,5,0]].

Given the puzzle board board, return the least number of moves required so that the state of
the board is solved. If it is impossible for the state of the board to be solved, return -1.

Example 1:
Input: board = [[1,2,3],[4,0,5]]
Output: 1
Explanation: Swap the 0 and the 5 in one move.

Example 2:
Input: board = [[1,2,3],[5,4,0]]
Output: -1
Explanation: No number of moves will make the board solved.

Example 3:
Input: board = [[4,1,2],[5,0,3]]
Output: 5
Explanation: 5 is the smallest number of moves that solves the board.
An example path:
After move 0: [[4,1,2],[5,0,3]]
After move 1: [[4,1,2],[0,5,3]]
After move 2: [[0,1,2],[4,5,3]]
After move 3: [[1,0,2],[4,5,3]]
After move 4: [[1,2,0],[4,5,3]]
After move 5: [[1,2,3],[4,5,0]]

Constraints:
board.length == 2
board[i].length == 3
0 <= board[i][j] <= 5
Each value board[i][j] is unique.*/

// METHOD - 01 (SOME ARE WRONG SOME ARE CORRECT)
vector<vector<int>> original = {{1, 2, 3}, {4, 5, 0}};

void helper(vector<vector<int>> &board, vector<vector<int>> &visited, int i, int j, int rows, int cols, int moves, int &ans)
{

    if (original == board)
    {
        ans = min(ans, moves);
        return;
    }

    if (i < 0 || j < 0 || i >= rows || j >= cols)
        return;

    visited[i][j] = 1;

    // up
    if (i > 0 && visited[i - 1][j] != 1)
    {
        swap(board[i][j], board[i - 1][j]);
        helper(board, visited, i - 1, j, rows, cols, moves + 1, ans);
        swap(board[i][j], board[i - 1][j]);
    }

    // down
    if (i < rows - 1 && visited[i + 1][j] != 1)
    {
        swap(board[i][j], board[i + 1][j]);
        // visited[i][j] = 1;
        helper(board, visited, i + 1, j, rows, cols, moves + 1, ans);
        // visited[i][j] = 0;
        swap(board[i][j], board[i + 1][j]);
    }

    // left
    if (j > 0 && visited[i][j - 1] != 1)
    {
        swap(board[i][j], board[i][j - 1]);
        // visited[i][j] = 1;
        helper(board, visited, i, j - 1, rows, cols, moves + 1, ans);
        // visited[i][j] = 0;
        swap(board[i][j], board[i][j - 1]);
    }

    // right
    if (j < cols - 1 && visited[i][j + 1] != 1)
    {
        swap(board[i][j], board[i][j + 1]);
        // visited[i][j] = 1;
        helper(board, visited, i, j + 1, rows, cols, moves + 1, ans);
        // visited[i][j] = 0;
        swap(board[i][j], board[i][j + 1]);
    }

    visited[i][j] = 0;
}

int slidingPuzzle(vector<vector<int>> &board)
{
    int rows = 2, cols = 3, moves = 0, ans = INT_MAX;
    vector<vector<int>> visited(rows, vector<int>(cols, 0));
    int rowOfZero = -1, colsOfZero = -1;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (board[i][j] == 0)
            {
                rowOfZero = i;
                colsOfZero = j;
                break;
            }
        }
    }

    helper(board, visited, rowOfZero, colsOfZero, rows, cols, moves, ans);
    return ans == 0 ? -1 : ans;
}

// METHOD - 02
vector<vector<int>> directions = {{1, 3}, {0, 2, 4}, {1, 5}, {0, 4}, {3, 5, 1}, {4, 2}};
string serializeBoard(vector<vector<int>> &board)
{
    string str = "";
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[i].size(); j++)
        {
            str += to_string(board[i][j]);
        }
    }

    return str;
}

void dfs(string state, unordered_map<string, int> &visited, int zeroPos,
         int moves)
{

    /* Skip if this state has been visited with fewer or equal moves */
    if (visited.count(state) && visited[state] <= moves)
    {
        return;
    }

    visited[state] = moves;

    for (int nextPos : directions[zeroPos])
    {
        swap(state[zeroPos], state[nextPos]);

        dfs(state, visited, nextPos, moves + 1);

        swap(state[zeroPos], state[nextPos]);
    }
}

int slidingPuzzle2(vector<vector<int>> &board)
{
    string startState = serializeBoard(board);

    unordered_map<string, int> visited;

    dfs(startState, visited, startState.find('0'), 0);

    return visited.count("123450") ? visited["123450"] : -1;
}

int main()
{
    // vector<vector<int>> board = {{1, 2, 3}, {4, 0, 5}};
    // vector<vector<int>> board = {{4, 1, 2}, {5, 0, 3}};
    // vector<vector<int>> board = {{1, 2, 3}, {5, 4, 0}};
    vector<vector<int>> board = {{3, 2, 4}, {1, 5, 0}};
    cout << "\n\n";
    int ans = slidingPuzzle(board);
    cout << "Answer = " << ans << endl;
    ans = slidingPuzzle2(board);
    cout << "Answer = " << ans << endl;
    cout << "\n\n";
    return 0;
}