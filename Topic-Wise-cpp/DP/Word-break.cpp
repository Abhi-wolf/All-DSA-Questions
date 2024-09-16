#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

/*
Given a string s and a dictionary of strings wordDict, return true if s can be segmented into a space-separated
sequence of one or more dictionary words.
Note that the same word in the dictionary may be reused multiple times in the segmentation.

Example 1:
Input: s = "leetcode", wordDict = ["leet","code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".

Example 2:
Input: s = "applepenapple", wordDict = ["apple","pen"]
Output: true
Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
Note that you are allowed to reuse a dictionary word.

Example 3:
Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
Output: false

Constraints:
1 <= s.length <= 300
1 <= wordDict.length <= 1000
1 <= wordDict[i].length <= 20
s and wordDict[i] consist of only lowercase English letters.
All the strings of wordDict are unique.
*/

bool solve(string s, unordered_set<string> &freq)
{
    int len = s.size();

    if (len == 0)
        return true;

    for (int i = 1; i <= len; i++)
    {
        if (freq.find(s.substr(0, i)) != freq.end() && solve(s.substr(i), freq))
        {
            return true;
        }
    }
    return false;
}

bool wordBreak(string s, vector<string> &wordDict)
{
    unordered_set<string> freq;

    for (string word : wordDict)
        freq.insert(word);

    vector<string> temp;
    return solve(s, freq);
}

bool solve2(string s, unordered_set<string> &freq, vector<int> &dp)
{
    int len = s.size();

    if (len == 0)
        return true;

    if (dp[len] != -1)
        return dp[len];

    for (int i = 1; i <= len; i++)
    {
        if (freq.find(s.substr(0, i)) != freq.end() && solve2(s.substr(i), freq, dp))
        {
            return dp[len] = true;
        }
    }
    return dp[len] = false;
}

bool wordBreak2(string s, vector<string> &wordDict)
{
    unordered_set<string> wordSet(
        wordDict.begin(), wordDict.end()); // Use a set for fast lookup
    vector<int> dp(s.size() + 1, -1);      // Memoization array to store results
    return solve2(s, wordSet, dp);
}

int main()
{
    vector<string> wordDict = {"abbcbda", "cbdaaa", "b", "dadaaad", "dccbbbc", "dccadd", "ccbdbc", "bbca", "bacbcdd", "a", "bacb", "cbc", "adc", "c", "cbdbcad", "cdbab", "db", "abbcdbd", "bcb", "bbdab", "aa", "bcadb", "bacbcb", "ca", "dbdabdb", "ccd", "acbb", "bdc", "acbccd", "d", "cccdcda", "dcbd", "cbccacd", "ac", "cca", "aaddc", "dccac", "ccdc", "bbbbcda", "ba", "adbcadb", "dca", "abd", "bdbb", "ddadbad", "badb", "ab", "aaaaa", "acba", "abbb"};
    if (wordBreak2("acaaaaabbbdbcccdcdaadcdccacbcccabbbbcdaaaaaadb", wordDict))
        cout << "Found \n";
    else
        cout << "Not Found \n";
    return 0;
}