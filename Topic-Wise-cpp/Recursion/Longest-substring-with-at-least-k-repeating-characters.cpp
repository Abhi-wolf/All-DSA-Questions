#include <iostream>
using namespace std;

/*
Given a string s and an integer k, return the length of the longest substring of s such that the frequency
of each character in this substring is greater than or equal to k.
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

/*
        DIVIDE AND CONQUER

https://leetcode.com/problems/longest-substring-with-at-least-k-repeating-characters/Figures/395/divide_and_conquer.png

Divide the problem into subproblems. (Divide Phase).
Repeatedly solve each subproblem independently and combine the result to solve
the original problem. (Conquer Phase). We could apply this strategy by
recursively splitting the string into substrings and combine the result to find
the longest substring that satisfies the given condition. The longest substring
for a string starting at index start and ending at index end can be given by,

longestSustring(start, end) = max(longestSubstring(start, mid),
longestSubstring(mid+1, end)) Finding the split position (mid)

The string would be split only when we find an invalid character. An invalid
character is the one with a frequency of less than k. As we know, the invalid
character cannot be part of the result, we split the string at the index where
we find the invalid character, recursively check for each split, and combine the
result.

TC -- O(N^2)
SC -- O(N)
   */

int solve(string &s, int start, int end, int k)
{
    if (end < k)
        return 0;
    int countMap[26] = {0};

    for (int i = start; i < end; i++)
    {
        countMap[s[i] - 'a']++;
    }

    for (int mid = start; mid < end; mid++)
    {
        if (countMap[s[mid] - 'a'] >= k)
            continue;

        int midNext = mid + 1;

        while (midNext < end && countMap[s[midNext] - 'a'] < k)
            midNext++;

        return max(solve(s, start, mid, k), solve(s, mid + 1, end, k));
    }

    return (end - start);
}

int longestSubstring(string s, int k)
{
    int n = s.size();

    return solve(s, 0, n, k);
}

// BRUTE FORCE
// TC -- O(N^2) , SC -- O(26) -- O(1)
int longestSubstring2(string s, int k)
{

    int len = 0, a = 0;

    for (int j = 0; j < s.size(); j++)
    {
        int freq[26] = {0};
        for (int i = j; i < s.size(); i++)
        {
            freq[s[i] - 'a']++;

            if (freq[s[i] - 'a'] >= k)
            {
                bool isOk = true;

                for (int x : freq)
                {
                    if (x > 0 && x < k)
                    {
                        isOk = false;
                        break;
                    }
                }

                if (isOk)
                    len = max(len, i - j + 1);
            }
        }
    }

    return len;
}

int main()
{
    string str = "ababbc";
    cout << "len = " << longestSubstring(str, 2) << endl;
    cout << "len = " << longestSubstring2(str, 2) << endl;
    return 0;
}