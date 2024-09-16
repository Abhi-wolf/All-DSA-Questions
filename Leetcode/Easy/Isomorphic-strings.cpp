#include <iostream>
#include <unordered_map>
using namespace std;

/*
Given two strings s and t, determine if they are isomorphic.
Two strings s and t are isomorphic if the characters in s can be replaced to get t.
All occurrences of a character must be replaced with another character while preserving
the order of characters. No two characters may map to the same character, but a character
may map to itself.

Example 1:
Input: s = "egg", t = "add"
Output: true

Example 2:
Input: s = "foo", t = "bar"
Output: false

Example 3:
Input: s = "paper", t = "title"
Output: true

Constraints:
1 <= s.length <= 5 * 104
t.length == s.length
s and t consist of any valid ascii character.
*/

bool isIsomorphic(string s, string t)
{
    unordered_map<char, char> um1, um2;
    int n = s.size();
    if (n != t.size())
        return false;
    for (int i = 0; i < n; i++)
    {
        char ch1 = s[i], ch2 = t[i];

        if (um1.count(ch1) == 0 && um2.count(ch2) == 0)
        {
            um1[ch1] = ch2;
            um2[ch2] = ch1;
        }

        else
        {
            if (um1[ch1] != ch2 || um2[ch2] != ch1)
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    bool ans = isIsomorphic("egg", "add");
    cout << "Answer = " << ans << endl;

    ans = isIsomorphic("egs", "add");
    cout << "Answer = " << ans << endl;
    return 0;
}