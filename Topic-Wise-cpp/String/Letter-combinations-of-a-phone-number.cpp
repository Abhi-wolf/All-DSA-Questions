#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/*
Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could
represent. Return the answer in any order.
A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any
letters.

Example 1:
Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]

Example 2:
Input: digits = ""
Output: []

Example 3:
Input: digits = "2"
Output: ["a","b","c"]

Constraints:
0 <= digits.length <= 4
digits[i] is a digit in the range ['2', '9'].
*/

void helper(vector<string> &res, unordered_map<char, string> um, string str,
            string temp, int ind)
{
    if (ind == str.size())
    {
        res.push_back(temp);
        return;
    }

    char ch = str[ind];
    string s = um[ch];

    for (char ch : s)
    {
        helper(res, um, str, temp + ch, ind + 1);
    }
}

vector<string> letterCombinations(string digits)
{

    unordered_map<char, string> um;
    vector<string> res;

    if (digits.size() == 0)
        return res;

    um['1'] = "";
    um['2'] = "abc";
    um['3'] = "def";
    um['4'] = "ghi";
    um['5'] = "jkl";
    um['6'] = "mno";
    um['7'] = "pqrs";
    um['8'] = "tuv";
    um['9'] = "wxyz";

    helper(res, um, digits, "", 0);

    return res;
}

void Display(vector<string> ans)
{
    for (string str : ans)
        cout << str << ", ";
    cout << endl;
}

int main()
{
    string digits = "23";
    vector<string> ans = letterCombinations(digits);
    Display(ans);
    return 0;
}