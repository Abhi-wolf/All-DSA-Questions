#include <iostream>
#include <vector>
#include <stack>
using namespace std;
#define MAX 100

/*
Given a binary matrix M of size n X m. Find the maximum area of a rectangle formed only of 1s in the given matrix.

Example 1:

Input:
n = 4, m = 4
M[][] = {{0 1 1 0},
         {1 1 1 1},
         {1 1 1 1},
         {1 1 0 0}}
Output: 8
Explanation: For the above test case the
matrix will look like
0 1 1 0
1 1 1 1
1 1 1 1
1 1 0 0
the max size rectangle is
1 1 1 1
1 1 1 1
and area is 4 *2 = 8.

Your Task:
Your task is to complete the function maxArea which returns the maximum size rectangle area in a binary-sub-matrix with all 1’s.
 The function takes 3 arguments the first argument is the Matrix M[ ] [ ] and the next two are two integers n and m which denotes
 the size of the matrix M.

Expected Time Complexity : O(n*m)
Expected Auixiliary Space : O(m)

Constraints:
1<=n,m<=1000
0<=M[][]<=1
*/

int maxRectangleArea(int arr[], int n)
{
    vector<int> index(n);
    stack<int> stk;
    int maxArea = 0;

    for (int i = n - 1; i >= 0; i--)
    {
        while (!stk.empty() && arr[stk.top()] >= arr[i])
            stk.pop();

        if (stk.empty())
            index[i] = n;
        else
        {
            index[i] = stk.top();
        }
        stk.push(i);
    }

    while (!stk.empty())
        stk.pop();

    for (int i = 0; i < n; i++)
    {
        while (!stk.empty() && arr[stk.top()] >= arr[i])
            stk.pop();

        if (stk.empty())
            index[i] -= -1;
        else
        {
            index[i] -= stk.top();
        }
        stk.push(i);
    }

    for (int i = 0; i < n; i++)
    {
        int area = arr[i] * (index[i] - 1);
        maxArea = max(maxArea, area);
    }

    return maxArea;
}

// we have to find the maximum area in histogram for each row
/*
            0, 1, 1, 0
            1, 2, 2, 1
            2, 3, 3, 2
            3, 4, 0, 0
*/

int maxArea(int M[MAX][MAX], int n, int m)
{

    int arr[m] = {0};
    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            // if the M[i][j]==0 it means the there's no ground floor
            if (M[i][j] == 0)
                arr[j] = 0;
            else
                arr[j] += M[i][j];
        }

        for (int k = 0; k < m; k++)
            cout << arr[k] << ", ";
        cout << "\n\n";
        int area = maxRectangleArea(arr, m);
        ans = max(ans, area);
    }
    return ans;
}

int main()
{
    int M[MAX][MAX] = {{0, 1, 1, 0},
                       {1, 1, 1, 1},
                       {1, 1, 1, 1},
                       {1, 1, 0, 0}};

    int M1[MAX][MAX] = {{1, 1, 1, 1, 1}, {0, 1, 0, 0, 0}};
    int M2[MAX][MAX] = {{1, 0, 0, 0},
                        {0, 1, 1, 1},
                        {0, 0, 1, 0},
                        {0, 1, 1, 1}};

    // cout << "Answer = " << maxArea(M1, 2, 5) << endl;
    cout << "Answer = " << maxArea(M2, 4, 4) << endl;
    return 0;
}