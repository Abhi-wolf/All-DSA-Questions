#include <iostream>
#include <vector>
using namespace std;

/*
Given a string s, return the longest palindromic substring in s.

Example 1:
Input: s = "babad"
Output: "bab"
Explanation: "aba" is also a valid answer.

Example 2:
Input: s = "cbbd"
Output: "bb"

Constraints:

1 <= s.length <= 1000
s consist of only digits and English letters.
*/

// FIRST METHOD -- TLE
bool isPalindrome(string str, int i, int j)
{
    int start = i, end = j - 1;

    while (start < end)
    {
        if (str[start] != str[end])
            return false;
        start++;
        end--;
    }

    return true;
}

string longestPalindrome(string s)
{

    for (int len = s.size(); len > 0; len--)
    {
        for (int j = 0; j <= s.size() - len; j++)
        {
            if (isPalindrome(s, j, j + len))
            {
                return s.substr(j, len);
            }
        }
    }
    return "";
}

// SECOND METHOD  -- USING DYNAMIC PROGRAMMING
int startIdx = 0, maxLen = 1;
bool checkPalindrome(string &s, int start, int end, vector<vector<int>> &dp)
{
    if (start >= end)
        return true;

    if (dp[start][end] != -1)
        return dp[start][end];

    bool ans = false;

    if (s[start] == s[end])
        ans = checkPalindrome(s, start + 1, end - 1, dp);

    if (ans)
    {
        int len = end - start + 1;
        if (len > maxLen)
        {
            startIdx = start;
            maxLen = len;
        }
    }
    return dp[start][end] = ans;
}

string longestPalindrome(string s)
{
    int n = s.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            bool ans = checkPalindrome(s, i, j, dp);
        }
    }

    return s.substr(startIdx, maxLen);
}

// THIRD METHOD
string expand(string str, int i, int j)
{
    int left = i, right = j;

    while (left >= 0 && right < str.size() && str[left] == str[right])
    {
        left--;
        right++;
    }

    return str.substr(left + 1, right - left - 1);
}

string longestPalindrome2(string s)
{
    string ans = "";

    for (int i = 0; i < s.size(); i++)
    {
        // odd length palindrome
        string odd = expand(s, i, i);
        if (odd.size() > ans.size())
            ans = odd;

        // even length palindrome
        string even = expand(s, i, i + 1);
        if (even.size() > ans.size())
            ans = even;
    }

    return ans;
}

int main()
{
    cout << longestPalindrome("babad") << endl;
    cout << longestPalindrome2("babad") << endl;
    return 0;
}