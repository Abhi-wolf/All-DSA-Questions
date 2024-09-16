#include <iostream>
#include <unordered_map>
using namespace std;

/*
Given a string s, find the length of the longest substring without repeating characters.

Example 1:
Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.

Example 2:
Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.

Example 3:
Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.

Constraints:
    0 <= s.length <= 5 * 104
    s consists of English letters, digits, symbols and spaces.
*/

int lengthOfLongestSubstring(string s)
{
    if (s.size() == 0)
        return 0;

    unordered_map<char, int> um;
    int i = 0, j = 0;
    int ans = 0;

    while (j < s.size())
    {

        if (um[s[j]] == 0)
            um[s[j]]++;

        else
        {
            int n = um.size();
            ans = max(ans, n);

            while (um[s[j]] > 0)
            {
                um[s[i]]--;
                if (um[s[i]] <= 0)
                    um.erase(s[i]);

                i++;
            }
            um[s[j]]++;
        }
        j++;
    }
    int n = um.size();
    ans = max(ans, n);

    return ans;
}

int main()
{
    string str = "bbbbb";
    int res = lengthOfLongestSubstring(str);
    cout << "Length of longest substring without repeating characters = " << res << endl;
    return 0;
}