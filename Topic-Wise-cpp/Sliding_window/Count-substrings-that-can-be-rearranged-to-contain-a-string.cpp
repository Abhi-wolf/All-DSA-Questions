#include <iostream>
#include <unordered_map>
using namespace std;

/*
You are given two strings word1 and word2.
A string x is called valid if x can be rearranged to have word2 as a prefix.
Return the total number of valid substrings of word1.
Note that the memory limits in this problem are smaller than usual, so you must implement a
solution with a linear runtime complexity.

Example 1:
Input: word1 = "bcca", word2 = "abc"
Output: 1
Explanation:
The only valid substring is "bcca" which can be rearranged to "abcc" having "abc" as a prefix.

Example 2:
Input: word1 = "abcabc", word2 = "abc"
Output: 10
Explanation:
All the substrings except substrings of size 1 and size 2 are valid.

Example 3:
Input: word1 = "abcabc", word2 = "aaabc"
Output: 0

Constraints:
1 <= word1.length <= 106
1 <= word2.length <= 104
word1 and word2 consist only of lowercase English letters.
*/

long long validSubstringCount(string word1, string word2)
{
    // store all the chars of word2 in map
    unordered_map<char, int> freq;

    for (char ch : word2)
        freq[ch]++;

    long long left = 0, requiredCount = freq.size(), n = word1.size();
    long long cnt = 0, validCount = 0;

    // map to store the freq of chars in word1
    unordered_map<char, int> window_freq;

    for (int right = 0; right < n; right++)
    {
        char ch = word1[right];

        // check if the char exist in word2, if yes add the char in the window
        if (freq.find(ch) != freq.end())
        {
            window_freq[ch]++;

            // check is the freq is equal in both if yes increase the validCount
            if (window_freq[ch] == freq[ch])
                validCount++;
        }

        // it means all the chars of word2 are present in the substring
        while (validCount == requiredCount)
        {
            // all the string including that point will be the answer
            cnt += (n - right);

            // remove the leftmost character from the map
            char leftChar = word1[left];
            if (freq.find(leftChar) != freq.end())
            {
                if (window_freq[leftChar] == freq[leftChar])
                    validCount--;

                window_freq[leftChar]--;
            }
            left++;
        }
    }

    return cnt;
}

long long validSubstringCount2(string word1, string word2)
{
    // store all the chars of word2 in map
    int freq[26] = {0};

    for (char ch : word2)
        freq[ch - 'a']++;

    int left = 0, requiredCount = 0, validCount = 0;
    long long cnt = 0, n = word1.size();

    for (int i : freq)
        if (i > 0)
            requiredCount++;

    // map to store the freq of chars in word1
    int window_freq[26] = {0};

    for (int right = 0; right < n; right++)
    {
        char ch = word1[right];

        // check if the char exist in word2, if yes add the char in the
        // window
        if (freq[ch - 'a'] > 0)
        {
            window_freq[ch - 'a']++;

            // check is the freq is equal in both if yes increase the
            // validCount
            if (window_freq[ch - 'a'] == freq[ch - 'a'])
                validCount++;
        }

        // it means all the chars of word2 are present in the substring
        while (validCount == requiredCount)
        {
            // all the string including that point will be the answer
            cnt += (n - right);

            // remove the leftmost character from the map
            char leftChar = word1[left];

            if (freq[leftChar - 'a'] > 0)
            {
                if (window_freq[leftChar - 'a'] == freq[leftChar - 'a'])
                    validCount--;

                window_freq[leftChar - 'a']--;
            }
            left++;
        }
    }

    return cnt;
}
int main()
{
    cout << validSubstringCount("abcabc", "abc") << endl;
    cout << validSubstringCount2("abcabc", "abc") << endl;
    return 0;
}