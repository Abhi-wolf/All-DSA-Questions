void helper(vector<vector<int>> &board, vector<vector<int>> &visited, int i, int j, int rows, int cols, int moves, int &ans)
{
    cnt++;
    cout << cnt << ", ";
    if (original == board)
    {
        cout << "moves = " << moves << ", ";
        ans = min(ans, moves);
        return;
    }

    if (i < 0 || j < 0 || i >= rows || j >= cols)
        return;

    // up
    if (i > 0 && visited[i - 1][j] != 1)
    {
        swap(board[i][j], board[i - 1][j]);
        visited[i][j] = 1;
        helper(board, visited, i - 1, j, rows, cols, moves + 1, ans);
        visited[i][j] = 0;
        swap(board[i][j], board[i - 1][j]);
    }

    // down
    if (i < rows - 1 && visited[i + 1][j] != 1)
    {
        swap(board[i][j], board[i + 1][j]);
        visited[i][j] = 1;
        helper(board, visited, i + 1, j, rows, cols, moves + 1, ans);
        visited[i][j] = 0;
        swap(board[i][j], board[i + 1][j]);
    }

    // left
    if (j > 0 && visited[i][j - 1] != 1)
    {
        swap(board[i][j], board[i][j - 1]);
        visited[i][j] = 1;
        helper(board, visited, i, j - 1, rows, cols, moves + 1, ans);
        visited[i][j] = 0;
        swap(board[i][j], board[i][j - 1]);
    }

    // right
    if (j < cols - 1 && visited[i][j + 1] != 1)
    {
        swap(board[i][j], board[i][j + 1]);
        visited[i][j] = 1;
        helper(board, visited, i, j + 1, rows, cols, moves + 1, ans);
        visited[i][j] = 0;
        swap(board[i][j], board[i][j + 1]);
    }
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
