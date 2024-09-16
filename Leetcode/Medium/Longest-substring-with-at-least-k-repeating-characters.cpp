#include <iostream>
#include <unordered_map>
using namespace std;

/*
Given a string s and an integer k, return the length of the longest substring of s such that the
frequency of each character in this substring is greater than or equal to k.

if no such substring exists, return 0.

Example 1:
Input: s = "aaabb", k = 3
Output: 3
Explanation: The longest substring is "aaa", as 'a' is repeated 3 times.

Example 2:
Input: s = "ababbc", k = 2
Output: 5
Explanation: The longest substring is "ababb", as 'a' is repeated 2 times and 'b' is repeated 3 times.

Constraints:
    1 <= s.length <= 104
    s consists of only lowercase English letters.
    1 <= k <= 105
*/

int longestSubstring(string s, int k)
{
    unordered_map<char, int> um;
    int ans = 0;

    int i = 0, j = 0;
    while (j < s.size())
    {
        um[s[j]]++;

        if (um[s[j]] >= k)
        {
            bool isAllCharsHaveKorMoreThanKchars = true;
            for (auto x : um)
            {
                if (x.second < k)
                {
                    isAllCharsHaveKorMoreThanKchars = false;
                    break;
                }
            }

            if (isAllCharsHaveKorMoreThanKchars == true)
            {
                ans = max(ans, (j - i + 1));
            }
        }
        j++;
    }

    j = s.size() - 1;
    while (i < s.size())
    {
        bool isAllCharsHaveKorMoreThanKchars = true;
        for (auto x : um)
        {
            if (x.second < k)
            {
                isAllCharsHaveKorMoreThanKchars = false;
                break;
            }
        }

        if (isAllCharsHaveKorMoreThanKchars == true)
        {
            ans = max(ans, (j - i + 1));
        }

        um[s[i]]--;
        if (um[s[i]] <= 0)
            um.erase(s[i]);
        i++;
    }
    return ans;
}

int main()
{
    // string str = "aaabb";
    // string str = "ababbc";
    string str = "cbabbad";
    int res = longestSubstring(str, 2);
    cout << " Result = " << res << endl;
    return 0;
}