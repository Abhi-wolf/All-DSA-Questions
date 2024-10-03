#include <iostream>
#include <unordered_map>
#include <vector>
#include <limits.h>
using namespace std;

/*
Given two strings s and p. Find the smallest window in the string s consisting of all the characters
(including duplicates) of the string p.  Return "-1" in case there is no such window present. In case
there are multiple such windows of same length, return the one with the least starting index.
Note : All characters are in Lowercase alphabets.

Examples:
Input: s = "timetopractice", p = "toc"
Output: toprac
Explanation: "toprac" is the smallest substring in which "toc" can be found.

Input: s = "zoomlazapzo", p = "oza"
Output: apzo
Explanation: "apzo" is the smallest substring in which "oza" can be found.

Expected Time Complexity: O(|s|)
Expected Auxiliary Space: O(n), n = len(p)

Constraints:
1 ≤ |s|, |p| ≤ 105
*/

// FIRST METHOD (TLE)
string smallestWindow(string s, string p)
{
    unordered_map<char, int> mp;

    for (char ch : p)
        mp[ch]++;

    int n = s.size(), sizeOfMap = mp.size(), required = 0;
    int len = n + 1, ind = -1, start = 0, end = 0;

    while (end < n)
    {
        if (mp.find(s[end]) != mp.end())
        {
            mp[s[end]]--;

            if (mp[s[end]] == 0)
                required++;

            while (required == sizeOfMap)
            {
                if (len > (end - start + 1))
                {
                    ind = start;
                    len = end - start + 1;
                }

                if (mp.find(s[start]) != mp.end())
                {
                    mp[s[start]]++;

                    if (mp[s[start]] > 0)
                        required--;
                }
                start++;
            }
        }

        // cout << "end = " << end << "  start=" << start << " len=" << len << endl;
        end++;
    }
    if (ind == -1)
        return "-1";
    return s.substr(ind, len);
}

// SECOND METHOD
string smallestWindow2(string s, string p)
{
    vector<int> freq(26);
    int n = s.length();
    for (auto &c : p)
        freq[c - 'a']++;

    vector<int> tempCnt(26, 0);
    int i = 0, j = 0;
    int ans = INT_MAX;
    int st = -1;

    auto check = [&]() -> bool
    {
        for (int i = 0; i < 26; i++)
        {
            if (freq[i] > tempCnt[i])
                return false;
        }
        return true;
    };

    while (j < n)
    {
        tempCnt[s[j] - 'a']++;

        if (!check())
            j++;

        else
        {
            while (check())
            {
                if (j - i + 1 < ans)
                {
                    ans = j - i + 1;
                    st = i;
                }
                tempCnt[s[i] - 'a']--;
                i++;
            }
            j++;
        }
    }
    return ans == INT_MAX ? "-1" : s.substr(st, ans);
}

int main()
{
    cout << smallestWindow("timetopractice", "toc") << endl;
    cout << smallestWindow2("timetopractice", "toc") << endl;

    cout << smallestWindow("zoomlazapzo", "oza") << endl;
    cout << smallestWindow2("zoomlazapzo", "oza") << endl;

    cout << smallestWindow("abc", "ac") << endl;
    cout << smallestWindow2("abc", "ac") << endl;
    return 0;
}