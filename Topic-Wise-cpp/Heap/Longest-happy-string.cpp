#include <iostream>
#include <queue>
using namespace std;

/*
A string s is called happy if it satisfies the following conditions:

s only contains the letters 'a', 'b', and 'c'.
s does not contain any of "aaa", "bbb", or "ccc" as a substring.
s contains at most a occurrences of the letter 'a'.
s contains at most b occurrences of the letter 'b'.
s contains at most c occurrences of the letter 'c'.
Given three integers a, b, and c, return the longest possible happy string. If there are multiple
longest happy strings, return any of them. If there is no such string, return the empty string "".

A substring is a contiguous sequence of characters within a string.

Example 1:
Input: a = 1, b = 1, c = 7
Output: "ccaccbcc"
Explanation: "ccbccacc" would also be a correct answer.

Example 2:
Input: a = 7, b = 1, c = 0
Output: "aabaa"
Explanation: It is the only correct answer in this case.

Constraints:
0 <= a, b, c <= 100
a + b + c > 0
*/

// METHOD 1 -- TC = O(a+b+c), SC = O(a+b+c);
string longestDiverseString(int a, int b, int c)
{
    priority_queue<pair<int, char>> maxheap;
    string ans = "";

    if (a > 0)
        maxheap.push({a, 'a'});
    if (b > 0)
        maxheap.push({b, 'b'});
    if (c > 0)
        maxheap.push({c, 'c'});

    while (!maxheap.empty())
    {
        pair<int, char> p1 = maxheap.top();
        maxheap.pop();

        int count = p1.first;
        char ch = p1.second;

        // if the last two elements are same as ch then pick the second one
        // from the maxheap
        if (ans.size() >= 2 && ans[ans.size() - 1] == ch &&
            ans[ans.size() - 2] == ch)
        {
            if (maxheap.empty())
                break;

            pair<int, char> temp = maxheap.top();
            maxheap.pop();

            ans += temp.second;

            // again add to maxheap if the count is not zero
            if (temp.first - 1 > 0)
            {
                maxheap.push({temp.first - 1, temp.second});
            }
        }
        else
        {
            count--;
            ans += ch;
        }

        // if count is not zero add to maxheap again
        if (count > 0)
        {
            maxheap.push({count, ch});
        }
    }
    return ans;
}

// METHOD 2 -- TC = O(a+b+c), SC = O(1); (GREEDY)
string longestDiverseString2(int a, int b, int c)
{
    string ans = "";
    int curra = 0, currb = 0, currc = 0;
    int total = a + b + c;

    for (int i = 0; i < total; i++)
    {
        // If 'a' is maximum and it's streak is less than 2, or if
        // streak of 'b' or 'c' is 2, then 'a' will be the next
        // character.
        if ((a >= b && a >= c && curra != 2) ||
            (a > 0 && (currb == 2 || currc == 2)))
        {
            ans += 'a';
            a--;
            curra++;
            currb = 0;
            currc = 0;
        }
        else if ((b >= a && b >= c && currb != 2) ||
                 (b > 0 && (currc == 2 || curra == 2)))
        {
            ans += 'b';
            b--;
            currb++;
            curra = 0;
            currc = 0;
        }
        else if ((c >= a && c >= b && currc != 2) ||
                 (c > 0 && (currb == 2 || curra == 2)))
        {
            ans += 'c';
            c--;
            currc++;
            curra = 0;
            currb = 0;
        }
    }

    return ans;
}

int main()
{
    cout << longestDiverseString(1, 1, 7) << endl;
    cout << longestDiverseString(7, 1, 0) << endl;
    cout << longestDiverseString2(1, 1, 7) << endl;
    cout << longestDiverseString2(7, 1, 0) << endl;
    return 0;
}