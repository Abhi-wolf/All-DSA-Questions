#include <iostream>
using namespace std;

/*
You are given two strings str1 and str2. Your task is to find the length of the longest
common substring among the given strings.

Examples:
Input: str1 = "ABCDGH", str2 = "ACDGHR"
Output: 4
Explanation: The longest common substring is "CDGH" which has length 4.

Input: str1 = "ABC", str2 = "ACB"
Output: 1
Explanation: The longest common substrings are "A", "B", "C" all having length 1.

Expected Time Complexity: O(n*m).
Expected Auxiliary Space: O(n*m).
*/

int longestCommonSubstr(string str1, string str2)
{
    int n = str1.size(), m = str2.size();
    int len = 0;

    int dp[n + 1][m + 1] = {0};

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (str1[i - 1] == str2[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];

                len = max(len, dp[i][j]);
            }
        }
    }

    return len;
}

int main()
{
    // string str1 = "ABCDGH", str2 = "ACDGHR";
    string str1 = "ABC", str2 = "ACB";
    cout << longestCommonSubstr(str1, str2) << endl;
    return 0;
}