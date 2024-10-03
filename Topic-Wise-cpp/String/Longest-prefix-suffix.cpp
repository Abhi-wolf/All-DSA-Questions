#include <iostream>
using namespace std;

/*
Given a string of characters, find the length of the longest proper prefix which is also a proper suffix.
NOTE: Prefix and suffix can be overlapping but they should not be equal to the entire string.

Examples :
Input: str = "abab"
Output: 2
Explanation: "ab" is the longest proper prefix and suffix.

Input: str = "aaaa"
Output: 3
Explanation: "aaa" is the longest proper prefix and suffix.

Expected Time Complexity: O(|str|)
Expected Auxiliary Space: O(|str|)

Constraints:
1 ≤ |str| ≤ 106
str contains lower case English alphabets
*/

int lps(string str)
{
    int p = 0;          // Prefix pointer
    int s = 1;          // Suffix pointer
    int cnt = 0;        // Count of matching prefix-suffix
    int pos = 1;        // Starting position of suffix
    int n = str.size(); // Length of the string

    while (p < n && s < n)
    {
        if (str[p] == str[s])
        {
            cnt++;
            p++;
            s++;
        }
        else
        {
            cnt = 0;
            pos++;
            s = pos;
            p = 0;
        }
    }

    return cnt;
}
int main()
{
    cout << lps("aaaa") << endl;
    return 0;
}