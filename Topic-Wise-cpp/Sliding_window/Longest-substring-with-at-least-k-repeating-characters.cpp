#include <iostream>
#include <vector>
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

int getMaxUniqueLetters(string str)
{
    bool map[26] = {0};
    int maxunique = 0;

    for (int i = 0; i < str.length(); i++)
    {
        if (!map[str[i] - 'a'])
        {
            maxunique++;
            map[str[i] - 'a'] = true;
        }
    }

    return maxunique;
}

/*
Find the number of unique characters in the string s and store the count in variable maxUnique. For s = aabcbacad,
the unique characters are a,b,c,d and maxUnique = 4.

Iterate over the string s with the value of currUnique ranging from 1 to maxUnique. In each iteration, currUnique
is the maximum number of unique characters that must be present in the sliding window.

The sliding window starts at index windowStart and ends at index windowEnd and slides over string s until windowEnd
reaches the end of string s. At any given point, we shrink or expand the window to ensure that the number of unique
characters is not greater than currUnique.

If the number of unique character in the sliding window is less than or equal to currUnique, expand the window from
the right by adding a character to the end of the window given by windowEnd

Otherwise, shrink the window from the left by removing a character from the start of the window given by windowStart.

Keep track of the number of unique characters in the current sliding window having at least k frequency given by
countAtLeastK. Update the result if all the characters in the window have at least k frequency.
*/

int longestSubstring(string s, int k)
{
    int countmap[26] = {0};
    int maxunique = getMaxUniqueLetters(s);
    int res = 0;

    for (int currunique = 1; currunique <= maxunique; currunique++)
    {
        // reset the map
        for (int i = 0; i < 26; i++)
            countmap[i] = 0;

        int winstart = 0, windend = 0, idx = 0, unique = 0,
            countAtLeastK = 0;

        while (windend < s.size())
        {
            // expand window
            if (unique <= currunique)
            {
                idx = s[windend] - 'a';
                if (countmap[idx] == 0)
                    unique++;

                countmap[idx]++;

                if (countmap[idx] == k)
                    countAtLeastK++;

                windend++;
            }
            // shrink window
            else
            {
                idx = s[winstart] - 'a';
                if (countmap[idx] == k)
                    countAtLeastK--;

                countmap[idx]--;

                if (countmap[idx] == 0)
                    unique--;

                winstart++;
            }

            if (unique == currunique && unique == countAtLeastK)
                res = max(windend - winstart, res);
        }
    }
    return res;
}

int main()
{
    string str = "aaabb";
    cout << "len = " << longestSubstring(str, 3) << endl;
    return 0;
}