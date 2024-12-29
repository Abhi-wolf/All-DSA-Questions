#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

/* You are given an n x n integer matrix. You can do the following operation any number of times:
Choose any two adjacent elements of matrix and multiply each of them by -1.
Two elements are considered adjacent if and only if they share a border.
Your goal is to maximize the summation of the matrix's elements. Return the maximum sum of the matrix's
elements using the operation mentioned above.

Example 1:
Input: matrix = [[1,-1],[-1,1]]
Output: 4
Explanation: We can follow the following steps to reach sum equals 4:
- Multiply the 2 elements in the first row by -1.
- Multiply the 2 elements in the first column by -1.

Example 2:
Input: matrix = [[1,2,3],[-1,-2,-3],[1,2,3]]
Output: 16
Explanation: We can follow the following step to reach sum equals 16:
- Multiply the 2 last elements in the second row by -1.

Constraints:
n == matrix.length == matrix[i].length
2 <= n <= 250
-105 <= matrix[i][j] <= 105*/

/* INTUTION
To maximize the matrix sum, let’s first imagine the ideal situation: if every element in the matrix were
positive, we would have the highest possible sum. Since we can flip pairs of adjacent elements by multiplying
them by -1, we could, in theory, make all values positive if we wanted. So, we start by calculating the sum
of the absolute values of all elements, as this would be the ideal maximum sum if all elements were positive.

Next, we need to think about when flipping doesn’t work perfectly. Specifically, if there’s an odd number of
negative elements, it won’t be possible to make everything positive because one negative will always remain.
This observation leads us to a simple rule: if there’s an even count of negative numbers, we can flip them
all to positive values. But if the count is odd, one number has to stay negative, which means the sum can’t
be quite as high as in the ideal case.

To minimize the impact of this remaining negative, we want it to be the smallest number in the matrix. So,
while calculating the absolute sum, we also track the smallest absolute value. This way, if we end up with
an odd count of negatives, we can subtract twice this smallest value from the total. This subtraction
accounts for the one unavoidable negative element and keeps the final sum as high as possible.*/

long long maxMatrixSum(vector<vector<int>> &matrix)
{
    long long totalsum = 0;
    int minAbsVal = INT_MAX;
    int s = 0;
    int negcnt = 0;

    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[i].size(); j++)
        {
            totalsum += abs(matrix[i][j]);

            if (matrix[i][j] < 0)
            {
                negcnt++;
            }

            minAbsVal = min(minAbsVal, abs(matrix[i][j]));
        }
    }

    if (negcnt % 2 != 0)
    {
        totalsum -= 2 * minAbsVal;
    }

    return totalsum;
}

int main()
{
    vector<vector<int>> matrix = {{1, 2, 3}, {-1, -2, -3}, {1, 2, 3}};
    cout << "Result = " << maxMatrixSum(matrix) << endl;
    return 0;
}