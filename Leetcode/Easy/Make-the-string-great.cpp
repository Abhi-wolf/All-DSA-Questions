#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

/* A good string is a string which doesn't have two adjacent characters s[i] and s[i + 1] where: 0 <= i <= s.length - 2
s[i] is a lower-case letter and s[i + 1] is the same letter but in upper-case or vice-versa.
To make the string good, you can choose two adjacent characters that make the string bad and remove them. You can keep doing
this until the string becomes good.

Return the string after making it good. The answer is guaranteed to be unique under the given constraints.
Notice that an empty string is also good.

Example 1:
Input: s = "leEeetcode"
Output: "leetcode"
Explanation: In the first step, either you choose i = 1 or i = 2, both will result "leEeetcode" to be reduced to "leetcode".

Example 2:
Input: s = "abBAcC"
Output: ""
Explanation: We have many possible scenarios, and all lead to the same answer. For example:
"abBAcC" --> "aAcC" --> "cC" --> ""
"abBAcC" --> "abBA" --> "aA" --> ""

Example 3:
Input: s = "s"
Output: "s"

Constraints:
1 <= s.length <= 100
s contains only lower and upper case English letters.*/

string makeGood(string s)
{
    stack<char> stk;
    string str = "";

    for (char ch : s)
    {
        if (stk.empty())
            stk.push(ch);

        else if (ch >= 97 && ch <= 122 && stk.top() >= 65 &&
                 stk.top() <= 90)
        {
            if ((ch - stk.top()) == 32)
                stk.pop();
            else
                stk.push(ch);
        }

        else if (ch >= 65 && ch <= 90 && stk.top() >= 97 &&
                 stk.top() <= 122)
        {
            if ((stk.top() - ch) == 32)
                stk.pop();
            else
                stk.push(ch);
        }

        else
        {
            stk.push(ch);
        }
    }

    while (!stk.empty())
    {
        str += stk.top();
        stk.pop();
    }
    reverse(str.begin(), str.end());
    return str;
}

bool check(char x, char y) { return abs(x - y) == 32; }

string makeGood2(string s)
{
    string str = "";

    for (char ch : s)
    {
        if (!str.empty() && check(str.back(), ch))
            str.pop_back();
        else
            str += ch;
    }

    return str;
}

int main()
{
    cout << makeGood2("leEeetcode") << endl;
    cout << makeGood("leEeetcode") << endl;

    cout << makeGood2("abBAcC") << endl;
    cout << makeGood("abBAcC") << endl;

    cout << makeGood2("mC") << endl;
    cout << makeGood("mC") << endl;
    return 0;
}