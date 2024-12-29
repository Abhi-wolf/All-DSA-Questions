#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/* You are given an m x n binary matrix matrix.
You can choose any number of columns in the matrix and flip every cell in that column (i.e., Change the
value of the cell from 0 to 1 or vice versa).
Return the maximum number of rows that have all values equal after some number of flips.

Example 1:
Input: matrix = [[0,1],[1,1]]
Output: 1
Explanation: After flipping no values, 1 row has all values equal.

Example 2:
Input: matrix = [[0,1],[1,0]]
Output: 2
Explanation: After flipping values in the first column, both rows have equal values.

Example 3:
Input: matrix = [[0,0,0],[0,0,1],[1,1,0]]
Output: 2
Explanation: After flipping values in the first two columns, the last two rows have equal values.

Constraints:
m == matrix.length
n == matrix[i].length
1 <= m, n <= 300
matrix[i][j] is either 0 or 1.*/

// METHOD 01
int maxEqualRowsAfterFlips(vector<vector<int>> &matrix)
{
    // rows can be made equal if elements of the row is exactly same or
    // opposite to that of the row
    int cols = matrix[0].size();
    int maxIdenticalRows = 0;

    for (vector<int> currRow : matrix)
    {
        // create flipped row
        vector<int> flippedRow(cols);
        int cnt = 0;

        for (int j = 0; j < cols; j++)
        {
            flippedRow[j] = 1 - currRow[j];
        }

        // check for the rows that are similar to the original row or to the
        // flipped row
        for (vector<int> temp : matrix)
        {
            if (temp == currRow || temp == flippedRow)
            {
                cnt++;
            }
        }

        maxIdenticalRows = max(maxIdenticalRows, cnt);
    }

    return maxIdenticalRows;
}

// METHOD 02
/* a row and its complement actually form the same pattern, just with opposite digits
    1 0 1 0         T F T F (T=1)
    0 1 0 1  ---->  T F T F (T=0)
    1 0 1 0         T F T F (T=1)

*/

int maxEqualRowsAfterFlips2(vector<vector<int>> &matrix)
{

    int cols = matrix[0].size();
    int maxIdenticalRows = 0;
    unordered_map<string, int> mp;

    for (vector<int> currRow : matrix)
    {
        string temp = "";

        for (int j = 0; j < cols; j++)
        {
            if (currRow[0] == currRow[j])
                temp += "T";
            else
                temp += "F";
        }

        mp[temp]++;
    }

    for (auto &entry : mp)
    {
        maxIdenticalRows = max(maxIdenticalRows, entry.second);
    }

    return maxIdenticalRows;
}

int main()
{
    vector<vector<int>> matrix = {{0, 0, 0}, {0, 0, 1}, {1, 1, 0}};
    cout << "METHOD 01 = " << maxEqualRowsAfterFlips(matrix) << endl;
    cout << "METHOD 02 = " << maxEqualRowsAfterFlips2(matrix) << endl;
    return 0;
}