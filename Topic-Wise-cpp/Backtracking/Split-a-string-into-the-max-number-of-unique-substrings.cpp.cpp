#include <iostream>
#include <unordered_set>
using namespace std;

/* Given a string s, return the maximum number of unique substrings that the given string can be split into.
You can split string s into any list of non-empty substrings, where the concatenation of the substrings forms
the original string. However, you must split the substrings such that all of them are unique.

A substring is a contiguous sequence of characters within a string.

Example 1:
Input: s = "ababccc"
Output: 5
Explanation: One way to split maximally is ['a', 'b', 'ab', 'c', 'cc']. Splitting like
['a', 'b', 'a', 'b', 'c', 'cc'] is not valid as you have 'a' and 'b' multiple times.

Example 2:
Input: s = "aba"
Output: 2
Explanation: One way to split maximally is ['a', 'ba'].

Example 3:
Input: s = "aa"
Output: 1
Explanation: It is impossible to split the string any further.

Constraints:
1 <= s.length <= 16
s contains only lower case English letters.*/

void helper(string &s, int ind, unordered_set<string> &st, int &ans)
{
    if (ind == s.size())
    {
        int size = st.size();
        ans = max(ans, size);
        return;
    }

    for (int i = ind + 1; i <= s.size(); i++)
    {
        string temp = s.substr(ind, (i - ind));
        if (st.find(temp) == st.end())
        {
            st.insert(temp);
            helper(s, i, st, ans);
            st.erase(temp);
        }
    }
}

int maxUniqueSplit(string s)
{
    unordered_set<string> st;
    int ans = 0;
    helper(s, 0, st, ans);
    return ans;
}

int main()
{
    cout << maxUniqueSplit("ababccc") << endl;
    cout << maxUniqueSplit("aba") << endl;
    return 0;
}