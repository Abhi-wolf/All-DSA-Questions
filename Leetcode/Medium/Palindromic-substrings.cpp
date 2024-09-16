#include <iostream>
using namespace std;

/* Given a string s, return the number of palindromic substrings in it.
A string is a palindrome when it reads the same backward as forward.
A substring is a contiguous sequence of characters within the string.

Example 1:
Input: s = "abc"
Output: 3
Explanation: Three palindromic strings: "a", "b", "c".

Example 2:
Input: s = "aaa"
Output: 6
Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".

Constraints:
1 <= s.length <= 1000
s consists of lowercase English letters.  */

// FIRST METHOD (TLE)
bool isPalindrome(string str)
{
    int i = 0, j = str.size() - 1;
    while (i <= j)
    {
        if (str[i] != str[j])
            return false;
        i++;
        j--;
    }
    return true;
}

int countSubstrings1(string s)
{
    int ans = 0;
    for (int i = 0; i < s.size(); i++)
    {
        string str = "";
        for (int j = i; j < s.size(); j++)
        {
            str += s[j];
            if (str.size() == 1)
                ans++;
            else if (isPalindrome(str))
                ans++;
        }
    }
    return ans;
}

// SECOND METHOD
/*  approach --  if the string is palindrome then if we can add same char to left end and right end of
    string then that string will also be a palindrome
*/
int palindromeCount(string str, int left, int right)
{
    int count = 0;
    while (left >= 0 && right < str.size() && str[left] == str[right])
    {
        count++;
        left--;
        right++;
    }
    return count;
}

int countSubstrings2(string s)
{
    int ans = 0;
    for (int i = 0; i < s.size(); i++)
    {
        int evenLength = palindromeCount(s, i, i + 1);
        int oddLength = palindromeCount(s, i - 1, i + 1);

        ans += (oddLength + evenLength + 1);
    }
    return ans;
}

int main()
{
    int res = countSubstrings1("abc");
    cout << "abc = " << res << endl;
    res = countSubstrings2("abc");
    cout << "abc = " << res << endl;

    res = countSubstrings1("aaa");
    cout << "aaa = " << res << endl;
    res = countSubstrings2("aaa");
    cout << "aaa = " << res << endl;

    res = countSubstrings1("hello");
    cout << "hello = " << res << endl;
    res = countSubstrings2("hello");
    cout << "hello = " << res << endl;

    return 0;
}