#include <iostream>
#include <unordered_map>
#include <map>     //for multimap
#include <utility> // for pair
#include <bits/stdc++.h>
using namespace std;

/*Given a string s, sort it in decreasing order based on the frequency of the characters. The frequency o
f a character is the number of times it appears in the string.
Return the sorted string. If there are multiple answers, return any of them.

Example 1:
Input: s = "tree"
Output: "eert"
Explanation: 'e' appears twice while 'r' and 't' both appear once.
So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.

Example 2:
Input: s = "cccaaa"
Output: "aaaccc"
Explanation: Both 'c' and 'a' appear three times, so both "cccaaa" and "aaaccc" are valid answers.
Note that "cacaca" is incorrect, as the same characters must be together.

Example 3:
Input: s = "Aabb"
Output: "bbAa"
Explanation: "bbaA" is also a valid answer, but "Aabb" is incorrect.
Note that 'A' and 'a' are treated as two different characters.

Constraints:
1 <= s.length <= 5 * 105
s consists of uppercase and lowercase English letters and digits.*/

// FIRST METHOD
// using unordered_map and vector
bool com(pair<char, int> &a, pair<char, int> &b)
{
    return a.second > b.second;
}

string frequencySort(string str)
{
    unordered_map<char, int> um;
    vector<pair<char, int>> vec;
    string ans = "";

    for (auto x : str)
        um[x]++;

    for (auto y : um)
        vec.push_back({y.first, y.second});

    sort(vec.begin(), vec.end(), com);

    for (auto a : vec)
    {
        int num = a.second;
        while (num--)
            ans.push_back(a.first);
    }

    return ans;
}

// SECOND METHOD
string frequencySort2(string str)
{
    unordered_map<char, int> um;
    multimap<int, char> mulMap;
    string ans = "";

    for (auto x : str)
        um[x]++;

    for (auto x : um)
        mulMap.insert({x.second, x.first});

    for (auto it = mulMap.rbegin(); it != mulMap.rend(); ++it)
    {
        int num = it->first;
        while (num--)
            ans.push_back(it->second);
    }
    return ans;
}

// THIRD METHOD
string frequencySort3(string str)
{
    unordered_map<char, int> um;
    priority_queue<pair<int, char>> pq;
    string ans = "";

    for (auto x : str)
        um[x]++;

    for (auto y : um)
        pq.push({y.second, y.first});

    while (!pq.empty())
    {
        int num = pq.top().first;
        while (num--)
            ans.push_back(pq.top().second);

        pq.pop();
    }
    return ans;
}

int main()
{
    string str = "cccaaa";
    cout << "\nfirst method = " << frequencySort(str) << endl;
    cout << "second method = " << frequencySort2(str) << endl;
    cout << "third method = " << frequencySort3(str) << endl;
    str = "tree";
    cout << "\nfirst method = " << frequencySort(str) << endl;
    cout << "second method = " << frequencySort2(str) << endl;
    cout << "third method = " << frequencySort3(str) << endl;
    return 0;
}