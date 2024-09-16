#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

/*
You are given an array of strings arr. A string s is formed by the concatenation of a subsequence of arr
that has unique characters. Return the maximum possible length of s.
A subsequence is an array that can be derived from another array by deleting some or no elements without
changing the order of the remaining elements.

Example 1:
Input: arr = ["un","iq","ue"]
Output: 4
Explanation: All the valid concatenations are:
- ""
- "un"
- "iq"
- "ue"
- "uniq" ("un" + "iq")
- "ique" ("iq" + "ue")
Maximum length is 4.

Example 2:
Input: arr = ["cha","r","act","ers"]
Output: 6
Explanation: Possible longest valid concatenations are "chaers" ("cha" + "ers") and "acters" ("act" + "ers").

Example 3:
Input: arr = ["abcdefghijklmnopqrstuvwxyz"]
Output: 26
Explanation: The only string in arr has all 26 characters.

Constraints:
    1 <= arr.length <= 16
    1 <= arr[i].length <= 26
    arr[i] contains only lowercase English letters.
*/

// recursion  and backtracking

bool isUniquePath(string str)
{
    unordered_set<char> st;
    for (int i = 0; i < str.size(); i++)
    {
        if (st.count(str[i]))
            return false;
        st.insert(str[i]);
    }
    return true;
}

void DFS(vector<string> &arr, int index, int &ans, string str)
{
    if (isUniquePath(str))
        ans = max(ans, static_cast<int>(str.size()));

    if (index == arr.size() || !isUniquePath(str))
        return;

    for (int i = index; i < arr.size(); i++)
    {
        string s1 = str;
        DFS(arr, i + 1, ans, s1 + arr[i]);
    }
}

int maxLength(vector<string> &arr)
{
    int ans = 0;
    DFS(arr, 0, ans, "");
    return ans;
}

int main()
{
    vector<string> arr = {"cha", "r", "act", "ers", "bd"};
    arr = {"a", "abc", "d", "de", "def"};
    int res = maxLength(arr);
    cout << "result = " << res << endl;
    return 0;
}