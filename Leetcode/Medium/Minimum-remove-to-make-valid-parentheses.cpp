#include <iostream>
#include <stack>
#include <vector>
using namespace std;

/*
Given a string s of '(' , ')' and lowercase English characters.
Your task is to remove the minimum number of parentheses ( '(' or ')', in any positions ) so that the resulting parentheses string is
valid and return any valid string.

Formally, a parentheses string is valid if and only if:
It is the empty string, contains only lowercase characters, or
It can be written as AB (A concatenated with B), where A and B are valid strings, or
It can be written as (A), where A is a valid string.


Example 1:
Input: s = "lee(t(c)o)de)"
Output: "lee(t(c)o)de"
Explanation: "lee(t(co)de)" , "lee(t(c)ode)" would also be accepted.

Example 2:
Input: s = "a)b(c)d"
Output: "ab(c)d"

Example 3:
Input: s = "))(("
Output: ""
Explanation: An empty string is also valid.


Constraints:
1 <= s.length <= 105
s[i] is either'(' , ')', or lowercase English letter.
*/

//  USING STACK
string minRemoveToMakeValid(string s)
{
    stack<int> stk;
    int n = s.size();
    string res = "";

    for (int i = 0; i < n; i++)
    {
        if (s[i] == '(')
            stk.push(i);
        else if (s[i] == ')')
        {
            if (!stk.empty())
                stk.pop();
            else
                s[i] = '#';
        }
    }

    while (!stk.empty())
    {
        s[stk.top()] = '#';
        stk.pop();
    }

    for (int i = 0; i < n; i++)
    {
        if (s[i] != '#')
            res += s[i];
    }

    return res;
}

// WITHOUT STACK
string minRemoveToMakeValid2(string s)
{
    int n = s.size(), open = 0, close = 0, flag = 0;
    string res = "";

    for (int i = 0; i < n; i++)
    {
        if (s[i] == '(')
        {
            open++;
            flag++;
        }
        else if (s[i] == ')' && flag > 0)
        {
            close++;
            flag--;
        }
    }

    int k = min(open, close);
    close = k;
    open = k;

    for (int i = 0; i < n; i++)
    {
        if (s[i] == '(')
        {
            if (open > 0)
            {
                res += '(';
                open--;
            }
        }

        else if (s[i] == ')')
        {
            if (close > 0 && close > open)
            {
                res += ')';
                close--;
            }
        }
        else
        {
            res += s[i];
        }
    }
    return res;
}

int main()
{
    cout << minRemoveToMakeValid("lee(t(c)o)de)") << endl;
    cout << minRemoveToMakeValid("a)b(c)d") << endl;
    cout << minRemoveToMakeValid("))((") << endl;
    cout << minRemoveToMakeValid("())()(((") << endl;

    cout << "\n\n Method 2 \n\n";

    cout << minRemoveToMakeValid2("lee(t(c)o)de)") << endl;
    cout << minRemoveToMakeValid2("a)b(c)d") << endl;
    cout << minRemoveToMakeValid2("))((") << endl;
    cout << minRemoveToMakeValid2("())()(((") << endl;
    return 0;
}