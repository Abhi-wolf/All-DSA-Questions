#include <iostream>
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

string longestPalindrome(string s)
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
    return 0;
}