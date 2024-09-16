#include <iostream>
#include <stack>
using namespace std;

/* Given a string s containing only three types of characters: '(', ')' and '*', return true if s is valid.

The following rules define a valid string:
Any left parenthesis '(' must have a corresponding right parenthesis ')'.
Any right parenthesis ')' must have a corresponding left parenthesis '('.
Left parenthesis '(' must go before the corresponding right parenthesis ')'.
'*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string "".


Example 1:
Input: s = "()"
Output: true

Example 2:
Input: s = "(*)"
Output: true

Example 3:
Input: s = "(*))"
Output: true

Constraints:
1 <= s.length <= 100
s[i] is '(', ')' or '*'.*/

bool checkValidString(string s)
{
    stack<int> openBracket, asteriks;
    int n = s.size(), i = 0;

    while (i < n)
    {
        if (s[i] == '(')
            openBracket.push(i);
        else if (s[i] == '*')
            asteriks.push(i);
        else
        {
            if (!openBracket.empty())
                openBracket.pop();
            else if (!asteriks.empty() > 0)
                asteriks.pop();
            else
                return false;
        }
        i++;
    }

    while (!openBracket.empty() && !asteriks.empty())
    {
        // If an open bracket appears after an asterisk, it cannot be
        // balanced, return false
        if (openBracket.top() > asteriks.top())
        {
            // '*' before '(' which cannot be balanced.
            return false;
        }
        openBracket.pop();
        asteriks.pop();
    }
    // If all open brackets are matched and there are no unmatched open
    // brackets left, return true
    return openBracket.empty();
}

int main()
{
    cout << checkValidString("(((((*(()((((*((**(((()()*)()()()*((((**)())*)*)))))))(())(()))())((*()()(((()((()*(())*(()**)()(())") << endl;
    cout << checkValidString("(((*)") << endl;
    cout << checkValidString("(*))") << endl;
    return 0;
}