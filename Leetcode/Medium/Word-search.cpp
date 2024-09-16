#include <iostream>
#include <vector>
using namespace std;

/*
Given an m x n grid of characters board and a string word, return true if word exists in the grid.
The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or
vertically neighboring. The same letter cell may not be used more than once.

Example 1:
Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
Output: true

Example 2:
Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
Output: true

Example 3:
Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
Output: false


Constraints:
m == board.length
n = board[i].length
1 <= m, n <= 6
1 <= word.length <= 15
board and word consists of only lowercase and uppercase English letters.
*/

bool dfs(vector<vector<char>> board, string word, int i, int j, int count)
{
    if (word.length() == count)
        return true;

    if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || board[i][j] != word[count])
        return false;

    char temp = board[i][j];
    board[i][j] = '*'; // mark as visited

    bool ans = dfs(board, word, i - 1, j, count + 1) || dfs(board, word, i + 1, j, count + 1) || dfs(board, word, i, j - 1, count + 1) || dfs(board, word, i, j + 1, count + 1);

    board[i][j] = temp; // backtrack
    return ans;
}

bool exist(vector<vector<char>> &board, string word)
{
    int row = board.size();
    int col = board[0].size();

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (board[i][j] == word[0] && dfs(board, word, i, j, 0))
                return true;
        }
    }
    return false;
}

int main()
{

    vector<vector<char>> board = {{'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};

    string word = "ABCCED";
    bool res = exist(board, word);
    cout << "Result = " << res << endl;

    word = "ABFB";
    res = exist(board, word);
    cout << "Result = " << res << endl;

    return 0;
}