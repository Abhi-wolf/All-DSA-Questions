#include <iostream>
#include <unordered_map>
#include <unordered_set>
using namespace std;

/*
Given a pair of strings of equal lengths, Geek wants to find the better string. The better string is the
string having more number of distinct subsequences.
If both the strings have equal count of distinct subsequence then return str1.

Example 1:
Input:
str1 = "gfg", str2 = "ggg"
Output: "gfg"
Explanation: "gfg" have 6 distinct subsequences whereas "ggg" have 3 distinct subsequences.

Example 2:
Input: str1 = "a", str2 = "b"
Output: "a"
Explanation: Both the strings have only 1 distinct subsequence.

Your Task:
You don't need to read input or print anything. Your task is to complete the function betterString()
which takes str1 and str2 as input parameters and returns the better string.

Expected Time Complexity: O( N ), where N is the length of both provided strings.
Expected Auxiliary Space: O( N )

Constraints:
1 <= N <= 30
*/

// METHOD 01
void helper(string &str, int ind, string &temp, unordered_set<string> &st)
{
    if (ind == str.size())
    {
        st.insert(temp);
        return;
    }

    temp.push_back(str[ind]);
    helper(str, ind + 1, temp, st);
    temp.pop_back();

    helper(str, ind + 1, temp, st);
}

string betterString(string str1, string str2)
{
    unordered_set<string> s1, s2;
    string temp1 = "", temp2 = "";
    helper(str1, 0, temp1, s1);
    helper(str2, 0, temp2, s2);

    if (s1.size() >= s2.size())
        return str1;
    return str2;
}

// METHOD 02
int distSubSeq(string str)
{
    unordered_map<char, int> mp;
    int count = 0;

    for (char ch : str)
    {
        int newCount = count * 2;

        if (mp.find(ch) != mp.end())
        {
            newCount -= mp[ch];
        }

        mp[ch] = count;
        count = newCount;
    }

    return count;
}

string betterString2(string str1, string str2)
{

    int s1 = distSubSeq(str1);
    int s2 = distSubSeq(str2);

    if (s1 >= s2)
        return str1;
    return str2;
}

int main()
{
    cout << betterString("gfg", "ggg") << endl;
    cout << betterString2("gfg", "ggg") << endl;
    return 0;
}