#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/*
Given the string s, return the size of the longest substring containing each vowel an even number of times.
That is, 'a', 'e', 'i', 'o', and 'u' must appear an even number of times.

Example 1:
Input: s = "eleetminicoworoep"
Output: 13
Explanation: The longest substring is "leetminicowor" which contains two each of the vowels: e, i and o and
zero of the vowels: a and u.

Example 2:
Input: s = "leetcodeisgreat"
Output: 5
Explanation: The longest substring is "leetc" which contains two e's.

Example 3:
Input: s = "bcbcbc"
Output: 6
Explanation: In this case, the given string "bcbcbc" is the longest because all vowels: a, e, i, o and u appear
zero times.

Constraints:
1 <= s.length <= 5 x 10^5
s contains only lowercase English letters.
*/

// FIRST METHOD
int findTheLongestSubstring(string s)
{
    int len = 0, n = s.size();
    for (int i = 0; i < s.size(); i++)
    {
        unordered_map<char, int> freq;
        for (int j = i; j < s.size(); j++)
        {
            if (s[j] == 'a' || s[j] == 'e' || s[j] == 'i' || s[j] == 'o' ||
                s[j] == 'u')
            {
                freq[s[j]]++;
            }

            bool isEven = true;
            for (auto x : freq)
            {
                if (x.second % 2 != 0)
                    isEven = false;
            }

            if (isEven)
            {
                len = max(len, j - i + 1);
            }
        }
    }

    return len;
}

// SECOND METHOD
int findTheLongestSubstring2(string s)
{
    int len = 0, n = s.size();
    for (int i = 0; i < s.size(); i++)
    {
        int xorval = 0;
        for (int j = i; j < s.size(); j++)
        {
            if (s[j] == 'a' || s[j] == 'e' || s[j] == 'i' || s[j] == 'o' ||
                s[j] == 'u')
            {
                xorval ^= ((s[j] - 'a') + 1);
            }

            if (xorval == 0)
            {
                len = max(len, j - i + 1);
                cout << i << " ---> " << len << endl;
            }
        }
    }

    return len;
}

// THIRD METHOD
int findTheLongestSubstring3(string s)
{
    int prefixXor = 0, n = s.size();

    int characterMap[26] = {0};

    characterMap['a' - 'a'] = 1;
    characterMap['e' - 'a'] = 2;
    characterMap['i' - 'a'] = 4;
    characterMap['o' - 'a'] = 8;
    characterMap['u' - 'a'] = 16;

    // Initialize mp to store the previous index with this prefixXOR value.
    vector<int> mp(32, -1);
    int longestSubstring = 0;

    for (int i = 0; i < n; i++)
    {
        prefixXor ^= characterMap[s[i] - 'a'];

        // If the current character is a vowel, find it's prefix XOR and add
        // it in the map.
        if (mp[prefixXor] == -1 && prefixXor != 0)
            mp[prefixXor] = i;

        // If the value of prefixXOR exists in the map, find the longest
        // subarray.
        longestSubstring = max(longestSubstring, i - mp[prefixXor]);
    }

    return longestSubstring;
}

int main()
{
    return 0;
}