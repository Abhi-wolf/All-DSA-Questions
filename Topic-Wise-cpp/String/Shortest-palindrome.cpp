#include <iostream>
#include <algorithm>
using namespace std;

string shortestPalindrome2(string s)
{
    int n = s.length();

    if (n == 0)
        return s;

    // find longest palindromic prefix
    int left = 0;
    for (int right = n - 1; right >= 0; right--)
    {
        if (s[left] == s[right])
            left++;
    }

    // if the whole string is a palindrome, return the original string
    if (left == n)
        return s;

    // extract the last part that is not part of palindromic prefix
    string nonPalindromeSuffix = s.substr(left);
    string reverseSuffix = nonPalindromeSuffix;
    reverse(reverseSuffix.begin(), reverseSuffix.end());

    // form the shortest palindrome
    return reverseSuffix + shortestPalindrome2(s.substr(0, left)) +
           nonPalindromeSuffix;
}

/*
First, we need to find out which part of the string is already a palindrome. So,
we check the original string and see how much of it matches the end of its
reversed version. This helps us figure out the longest palindromic prefix.

To do this, we look at different prefixes of the original string and compare
them to suffixes of the reversed string. If a prefix matches a suffix of the
reversed string, it’s part of a palindrome.

Once we find the longest palindromic prefix, we need to reverse the rest of the
string (the part not included in the prefix) and add this reversed part to the
start of the original string. This gives us the shortest possible palindrome.

For example: Let’s take the string "abcbabcab". We reverse the string to get
"bacbabcba". By comparing prefixes of "abcbabcab" with suffixes of "bacbabcba",
we find that the longest prefix "abcba" matches with the suffix "abcba" in the
reversed string. This is a palindrome.

To form the shortest palindrome, we then need to reverse the remaining part of
the original string that doesn’t overlap with this prefix. In our example, the
remaining part is "bcab". Reversing "bcab" gives us "bacb". Adding this to the
start of the original string results in "bacbabcbabcab".
*/
bool isEqual(string first, string second)
{
    for (int i = 0; i < first.size(); i++)
    {
        if (first[i] != second[i])
            return false;
    }
    return true;
}

string shortestPalindrome1(string s)
{

    int n = s.size();
    string reversedStr = s;
    reverse(reversedStr.begin(), reversedStr.end());

    for (int i = 0; i < n; i++)
    {
        // check is aacecaaa == aaacecaa if not then aacecaa == aacecaa this goes on
        if (isEqual(s.substr(0, n - i), reversedStr.substr(i)))
        {
            return reversedStr.substr(0, i) + s;
        }
    }

    return reversedStr + s;
}

int main()
{
    cout << shortestPalindrome1("aacecaaa") << endl;
    cout << shortestPalindrome1("abcd") << endl;

    cout << shortestPalindrome2("aacecaaa") << endl;
    cout << shortestPalindrome2("abcd") << endl;
    return 0;
}