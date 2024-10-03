#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*
Given a string expression of numbers and operators, return all possible results from computing all the different
possible ways to group numbers and operators. You may return the answer in any order.

The test cases are generated such that the output values fit in a 32-bit integer and the number of different
results does not exceed 104.

Example 1:
Input: expression = "2-1-1"
Output: [0,2]
Explanation:
((2-1)-1) = 0
(2-(1-1)) = 2

Example 2:
Input: expression = "2*3-4*5"
Output: [-34,-14,-10,-10,10]
Explanation:
(2*(3-(4*5))) = -34
((2*3)-(4*5)) = -14
((2*(3-4))*5) = -10
(2*((3-4)*5)) = -10
(((2*3)-4)*5) = 10

Constraints:
1 <= expression.length <= 20
expression consists of digits and the operator '+', '-', and '*'.
All the integer values in the input expression are in the range [0, 99].
*/

/*
 If the expression is empty, return an empty list.
 If the expression is a single digit, return a list with that number.
 If the expression has two characters and the first is a digit, the second
 must also be a digit. We convert the expression to a number and return it in
 a list. For longer expressions, we find operators to split the expression.
 We iterate through each character, and when we find an operator, we
 recursively evaluate the parts before and after it. We store the results of
 these evaluations in separate lists. Then, we combine the results from the
 left and right parts using the operator and store the final values in a
 list.
 https://leetcode.com/problems/different-ways-to-add-parentheses/Figures/241/subtree.png
 */
// Time complexity: O(n*2^n) Space complexity: O(2^n)
vector<int> diffWaysToCompute(string expression)
{
    vector<int> res;

    // base case : if the expression is empty return the empty list
    if (expression.length() == 0)
    {
        return res;
    }

    // base case : if the expression length is one, convert that into integer and return it as a list
    if (expression.length() == 1)
    {
        res.push_back(stoi(expression));
        return res;
    }

    // base case : if the expression length is two and the first one is a digit, convert them into integer and return it as a list
    if (expression.length() == 2 && isdigit(expression[0]))
    {
        res.push_back(stoi(expression));
        return res;
    }

    // itertate through each character
    for (int i = 0; i < expression.length(); i++)
    {
        char curr = expression[i];

        // if the curr character is digit then continue
        if (isdigit(curr))
            continue;

        // divide where the curr character is +, -, or *
        vector<int> leftRes = diffWaysToCompute(expression.substr(0, i));
        vector<int> rightRes = diffWaysToCompute(expression.substr(i + 1));

        // combine left and right results
        for (int leftVal : leftRes)
        {
            for (int rightVal : rightRes)
            {
                int computedVal = 0;

                switch (curr)
                {
                case '+':
                    computedVal = leftVal + rightVal;
                    break;
                case '-':
                    computedVal = leftVal - rightVal;
                    break;
                case '*':
                    computedVal = leftVal * rightVal;
                    break;
                }
                res.push_back(computedVal);
            }
        }
    }

    return res;
}

void Display1DArray(vector<int> arr)
{
    cout << endl;
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << ", ";
    }
    cout << endl;
}

int main()
{
    vector<int> ans = diffWaysToCompute("2*3-4*5");
    Display1DArray(ans);
    return 0;
}