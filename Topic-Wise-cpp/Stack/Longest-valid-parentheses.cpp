#include <iostream>
#include <stack>
using namespace std;

/*
Given a string containing just the characters '(' and ')', return the length of the longest valid (well-formed)
parentheses substring.

Example 1:
Input: s = "(()"
Output: 2
Explanation: The longest valid parentheses substring is "()".

Example 2:
Input: s = ")()())"
Output: 4
Explanation: The longest valid parentheses substring is "()()".

Example 3:
Input: s = ""
Output: 0
*/

/*
1) s[i] == '(' - In this case, we will push the index into the stack (just
    as we do in valid parentheses check).

2) s[i] == ')' - In this case, we will pop the index from the stack (again
just as in parentheses check). Now, after popping, we need to do some simple
checks which are main steps of this problem. Again, there will be following
scenarios that may occur -
    stack is not empty - If stack is not empty, then this
may be our longest valid parentheses. We update the MAX_len as max(MAX_len,
current index - stack.top()). Do notice, that our bottom of stack will always
hold index preceding to a potential valid parentheses.

    stack becomes empty - This will only
happen when we have an extra ')' bracket. There may have been valid parentheses
previously which have been updated and stored in MAX_len. But, since we now have
an extra closing bracket any further extensions of previous valid parentheses is
not possible. So, push the current index into stack, again which will denote
that bottom of stack will hold the index preceding to a potential valid
parentheses.
*/
int longestValidParentheses1(string s)
{
    int len = 0;
    stack<int> stk;
    stk.push(-1);

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
            stk.push(i);
        else
        {
            stk.pop();
            if (stk.empty())
                stk.push(i);
            else
            {
                len = max(len, i - stk.top());
            }
        }
    }

    return len;
}

/*
    1) Scan the string from beginning to end.

    2) If current character is '(',
    push its index to the stack. If current character is ')' and the
    character at the index of the top of stack is '(', we just find a
    matching pair so pop from the stack. Otherwise, we push the index of
    ')' to the stack.

    3) After the scan is done, the stack will only
    contain the indices of characters which cannot be matched. Then
    let's use the opposite side - substring between adjacent indices
    should be valid parentheses.

    4) If the stack is empty, the whole input
    string is valid. Otherwise, we can scan the stack to get longest
    valid substring as described in step 3.
    */

int longestValidParentheses2(string s)
{
    int len = 0;
    stack<int> stk;

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
            stk.push(i);
        else
        {
            if (!stk.empty())
            {
                if (s[stk.top()] == '(')
                    stk.pop();
                else
                    stk.push(i);
            }
            else
            {
                stk.push(i);
            }
        }
    }

    if (stk.empty())
        len = s.size();
    else
    {
        int a = s.size(), b = 0;

        while (!stk.empty())
        {
            b = stk.top();
            stk.pop();

            len = max(len, a - b - 1);
            a = b;
        }

        len = max(len, a);
    }
    return len;
}
int main()
{
    cout << longestValidParentheses1(")()())") << endl;
    cout << longestValidParentheses2(")()())") << endl;
    return 0;
}