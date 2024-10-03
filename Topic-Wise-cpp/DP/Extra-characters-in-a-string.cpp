#include <iostream>
#include <vector>
#include <limits.h>
#include <unordered_set>
#include <unordered_map>
using namespace std;

/*
You are given a 0-indexed string s and a dictionary of words dictionary. You have to break s into one or more
non-overlapping substrings such that each substring is present in dictionary. There may be some extra characters
in s which are not present in any of the substrings.
Return the minimum number of extra characters left over if you break up s optimally.

Example 1:
Input: s = "leetscode", dictionary = ["leet","code","leetcode"]
Output: 1
Explanation: We can break s in two substrings: "leet" from index 0 to 3 and "code" from index 5 to 8. There is
only 1 unused character (at index 4), so we return 1.

Example 2:
Input: s = "sayhelloworld", dictionary = ["hello","world"]
Output: 3
Explanation: We can break s in two substrings: "hello" from index 3 to 7 and "world" from index 8 to 12. The
characters at indices 0, 1, 2 are not used in any substring and thus are considered as extra characters. Hence,
we return 3.

Constraints:
1 <= s.length <= 50
1 <= dictionary.length <= 50
1 <= dictionary[i].length <= 50
dictionary[i] and s consists of only lowercase English letters dictionary contains distinct words
*/

int solve(string &str, unordered_set<string> &st, int ind, vector<int> &dp)
{
    if (ind >= str.size())
        return 0;

    if (dp[ind] != -1)
        return dp[ind];

    string currStr = "";
    int minExtra = str.size();

    for (int i = ind; i < str.size(); i++)
    {
        currStr.push_back(str[i]);
        int currExtra = (st.count(currStr)) ? 0 : currStr.size();

        int nextExtra = solve(str, st, i + 1, dp);

        minExtra = min(minExtra, (currExtra + nextExtra));
    }

    return dp[ind] = minExtra;
}

int minExtraChar(string s, vector<string> &dictionary)
{
    unordered_set<string> st;
    int n = s.size();
    vector<int> dp(n, -1);

    for (string str : dictionary)
    {
        st.insert(str);
    }

    int ans = solve(s, st, 0, dp);
    cout << "ans = " << ans << endl;

    for (int i : dp)
        cout << i << ", ";
    cout << endl;

    return ans;
}

// 2nd METHOD
class TrieNode
{
public:
    unordered_map<char, TrieNode *> children;
    bool is_word;

    TrieNode()
    {
        is_word = false;
    }
};

TrieNode *buildTrie(vector<string> &dictionary)
{
    auto root = new TrieNode();

    for (auto &word : dictionary)
    {
        auto node = root;
        for (auto &c : word)
        {
            if (node->children.find(c) == node->children.end())
            {
                node->children[c] = new TrieNode();
            }
            node = node->children[c];
        }
        node->is_word = true;
    }
    return root;
}
int solve2(string &s, vector<int> &dp, int ind, TrieNode *root)
{
    if (ind == s.size())
        return 0;

    if (dp[ind] != -1)
        return dp[ind];

    // Assume that all characters from 'ind' are extra by default
    int leftOver = s.size() - ind;
    TrieNode *node = root;

    for (int i = ind; i < s.size(); i++)
    {
        char ch = s[i];

        if (node->children.find(ch) == node->children.end())
        {
            break; // No further matches in Trie, stop here
        }

        node = node->children[ch];

        // If this node marks the end of a valid word, calculate leftover characters
        if (node->is_word)
        {
            leftOver = min(leftOver, solve2(s, dp, i + 1, root));
        }
    }

    // The number of leftover characters if no word starts at 'ind'
    return dp[ind] = min(leftOver, 1 + solve2(s, dp, ind + 1, root));
}
int minExtraChar2(string s, vector<string> &dictionary)
{
    int n = s.length();
    auto root = buildTrie(dictionary);
    vector<int> dp(n + 1, -1);
    dp[n] = 0;
    int ans = solve2(s, dp, 0, root);
    cout << "ans = " << ans << endl;

    for (int i : dp)
        cout << i << ", ";
    cout << endl;

    return ans;
}

int main()
{
    string s = "leetscode";
    string s2 = "sayhelloworld";
    string s3 = "voctvochpgutoywpnafylzelqsnzsbandjcqdciyoefi";

    vector<string> dictionary = {"leet", "code", "leetcode"};
    vector<string> dictionary2 = {"hello", "world"};
    vector<string> dictionary3 = {"tf", "v", "wadrya", "a", "cqdci", "uqfg", "voc", "zelqsn", "band", "b", "yoefi", "utoywp", "herqqn", "umra", "frfuyj", "vczatj", "sdww"};
    minExtraChar(s3, dictionary3);

    minExtraChar2(s, dictionary);
    minExtraChar2(s2, dictionary2);
    minExtraChar2(s3, dictionary3);
    return 0;
}