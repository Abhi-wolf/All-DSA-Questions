#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

/* Given a square matrix mat[][] of n*n size, the task is to determine the diagonal pattern which is a linear arrangement
of the elements of the matrix as depicted in the following example:

Example 1:
Input: n = 3
mat[][] = {{1, 2, 3},{4, 5, 6},{7, 8, 9}}
Output: {1, 2, 4, 7, 5, 3, 6, 8, 9}
Explanation:
Starting from (0, 0): 1,
Move to the right to (0, 1): 2,
Move diagonally down to (1, 0): 4,
Move diagonally down to (2, 0): 7,
Move diagonally up to (1, 1): 5,
Move diagonally up to (0, 2): 3,
Move to the right to (1, 2): 6,
Move diagonally up to (2, 1): 8,
Move diagonally up to (2, 2): 9
There for the output is {1, 2, 4, 7, 5, 3, 6, 8, 9}.

Example 2:
Input: n = 2
mat[][] = {{1, 2},{3, 4}}
Output: {1, 2, 3, 4}
Explanation:
Starting from (0, 0): 1,
Move to the right to (0, 1): 2,
Move diagonally down to (1, 0): 3,
Move to the right to (1, 1): 4
There for the output is {1, 2, 3, 4}.
Your Task:
You only need to implement the given function matrixDiagonally() which takes a matrix mat[][] of size n*n as an input and returns a
list of integers containing the matrix diagonally. Do not read input, instead use the arguments given in the function.

Expected Time Complexity: O(n*n).
Expected Auxiliary Space: O(n*n).

Constraints:
1 <= n <= 100
-100 <= elements of matrix <= 100
*/

// METHOD 1
vector<int> matrixDiagonally(vector<vector<int>> &mat)
{
    int n = mat.size();

    if (n < 2)
        return mat[0];

    vector<int> ans;
    int clock = 1;
    ans.push_back(mat[0][0]);

    for (int j = 1; j < n; j++)
    {
        int a = 0, b = j;
        vector<int> temp;
        while (a < n && b >= 0)
        {
            temp.push_back(mat[a][b]);
            a++;
            b--;
        }

        if (clock == 0)
        {
            reverse(temp.begin(), temp.end());
            clock = 1;
        }
        else
        {
            clock = 0;
        }

        ans.insert(ans.end(), temp.begin(), temp.end());
    }

    for (int i = 1; i < n; i++)
    {
        int a = i, b = n - 1;
        vector<int> temp;
        while (a < n && b >= 0)
        {
            temp.push_back(mat[a][b]);
            a++;
            b--;
        }

        if (clock == 0)
        {
            reverse(temp.begin(), temp.end());
            clock = 1;
        }
        else
        {
            clock = 0;
        }

        ans.insert(ans.end(), temp.begin(), temp.end());
    }

    return ans;
}

// METHOD 2
vector<int> matrixDiagonally2(vector<vector<int>> &mat)
{
    map<int, vector<int>> mp;
    int n = mat.size();
    vector<int> ans;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            mp[i + j].push_back(mat[i][j]);
        }
    }

    for (auto it : mp)
    {
        vector<int> temp = it.second;

        if (it.first % 2 != 0)
            ans.insert(ans.end(), it.second.begin(), it.second.end());
        else
        {
            reverse(it.second.begin(), it.second.end());
            ans.insert(ans.end(), it.second.begin(), it.second.end());
        }
    }
    return ans;
}

void Display(vector<int> ans)
{
    if (ans.size() == 0)
    {
        cout << "No elements present\n";
        return;
    }

    cout << endl;
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << ", ";
    cout << endl;
}

int main()
{
    vector<vector<int>> mat = {{1, 2, 3},
                               {4, 5, 6},
                               {7, 8, 9}};

    vector<int> ans = matrixDiagonally(mat);
    Display(ans);
    ans.clear();
    ans = matrixDiagonally2(mat);
    Display(ans);
    ans.clear();

    mat = {{1, 2},
           {3, 4}};

    ans = matrixDiagonally(mat);
    Display(ans);
    ans.clear();
    ans = matrixDiagonally2(mat);
    Display(ans);

    return 0;
}