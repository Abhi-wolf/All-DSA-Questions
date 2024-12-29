#include <iostream>
using namespace std;

/* Given two strings s1 and s2. Return a minimum number of times s1 has to be repeated such that s2 is a substring of it.
If s2 can never be a substring then return -1.
Note: Both the strings contain only lowercase letters.

Examples:
Input: s1 = "ww", s2 = "www"
Output: 2
Explanation: Repeating s1 two times (wwww), s2 is a substring of it.

Input: s1 = "abcd", s2 = "cdabcdab"
Output: 3
Explanation: Repeating s1 three times (abcdabcdabcd), s2 is a substring of it. s2 is not a substring of s2 when it is
repeated less than 3 times.

Input: s1 = "ab", s2 = "cab"
Output: -1
Explanation: No matter how many times we repeat s1, we can't get a string such that s2 is a substring of it.*/

bool isSubStringFound(string s1, string s2)
{
    int n = s1.size(), m = s2.size();

    for (int i = 0; i <= n - m; i++)
    {
        int j = 0;

        for (j = 0; j < m; j++)
        {
            if (s1[i + j] != s2[j])
            {
                break;
            }
        }

        if (j == m)
            return true;
    }
    return false;
}

int minRepeats(string &s1, string &s2)
{
    int ans = 1;
    string temp = s1;

    while (s1.size() < s2.size())
    {
        s1 += temp;
        ans++;
    }

    if (isSubStringFound(s1, s2))
    {
        return ans;
    }

    else if (isSubStringFound(s1 + temp, s2))
    {
        return ans + 1;
    }

    else
    {
        return -1;
    }
}

int main()
{
    string s1 = "abcd", s2 = "cdabcdab";
    cout << minRepeats(s1, s2) << endl;
    return 0;
}