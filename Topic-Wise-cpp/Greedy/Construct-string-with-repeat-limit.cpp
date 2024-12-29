#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <limits.h>
using namespace std;

string repeatLimitedString(string s, int repeatLimit)
{
    vector<int> freq(26, 0);

    for (char ch : s)
    {
        freq[ch - 'a']++;
    }

    string res = "";
    int currInd = 25;

    while (currInd >= 0)
    {
        if (freq[currInd] == 0)
        {
            currInd--;
            continue;
        }

        int use = min(freq[currInd], repeatLimit);

        res.append(use, 'a' + currInd);

        freq[currInd] -= use;

        if (freq[currInd] > 0)
        {
            int smallerInd = currInd - 1;

            while (smallerInd >= 0 && freq[smallerInd] == 0)
                smallerInd--;

            if (smallerInd < 0)
                break;

            res.push_back('a' + smallerInd);
            freq[smallerInd]--;
        }
    }

    return res;
}

string repeatLimitedString2(string s, int repeatLimit)
{
    unordered_map<char, int> freq;
    for (char ch : s)
        freq[ch]++;

    priority_queue<char> maxheap;

    for (auto x : freq)
    {
        maxheap.push(x.first);
    }

    string res = "";

    while (!maxheap.empty())
    {
        char currChar = maxheap.top();
        maxheap.pop();

        int use = min(freq[currChar], repeatLimit);

        res.append(use, currChar);

        freq[currChar] -= use;

        if (freq[currChar] > 0 && !maxheap.empty())
        {
            char nextChar = maxheap.top();
            maxheap.pop();

            res.push_back(nextChar);
            freq[nextChar]--;

            if (freq[nextChar] > 0)
            {
                maxheap.push(nextChar);
            }

            maxheap.push(currChar);
        }
    }

    return res;
}

int main()
{
    cout << "Result (METHOD 01)= " << repeatLimitedString("cczazcc", 3) << endl;
    cout << "Result (METHOD 01)= " << repeatLimitedString("aababab", 2) << endl;

    cout << "Result (METHOD 02)= " << repeatLimitedString2("cczazcc", 3) << endl;
    cout << "Result (METHOD 02)= " << repeatLimitedString2("aababab", 2) << endl;
    return 0;
}