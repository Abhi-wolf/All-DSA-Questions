#include <iostream>
#include <unordered_map>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

set<string> subStrings(string str)
{
    set<string> sub;

    for (int i = 0; i < str.size(); i++)
    {
        string s = "";
        for (int j = i; j < str.size(); j++)
        {
            s += str[j];
            if (s != "")
                sub.insert(s);
        }
    }
    return sub;
}

// tle
vector<string> shortestSubstrings(vector<string> &arr)
{
    unordered_map<string, set<string>> um;
    vector<string> res(arr.size(), "");
    vector<string> repeatedString;

    for (int i = 0; i < arr.size(); i++)
    {
        if (um.find(arr[i]) == um.end())
        {
            set<string> st = subStrings(arr[i]);
            um[arr[i]] = st;
        }

        else
        {
            repeatedString.push_back(arr[i]);
        }
    }

    for (int i = 0; i < arr.size(); i++)
    {
        set<string> st = um[arr[i]];
        string notFound = "";

        if (find(repeatedString.begin(), repeatedString.end(), arr[i]) == repeatedString.end())
        {
            for (auto x : st)
            {

                bool found = false; // Added: To track if a substring is found in other strings
                for (auto y : um)
                {
                    if (y.first != arr[i] && y.second.find(x) != y.second.end())
                    {
                        found = true;
                        break; // No need to continue searching if substring is found
                    }
                }
                if (!found)
                {
                    if (notFound == "")
                        notFound = x;
                    else
                    {
                        if (notFound.size() > x.size())
                            notFound = x;
                        else
                            notFound = min(notFound, x);
                    }
                }
            }
        }

        res[i] = (notFound.empty() ? "" : notFound);
    }
    //         ["g","x","z","r","i","c","h"]

    return res;
}

void Display(vector<string> res)
{
    if (res.size() == 0)
        return;

    for (int i = 0; i < res.size(); i++)
        cout << res[i] << ", ";

    cout << endl;
}

int main()
{
    vector<string> arr1 = {"cab", "ad", "bad", "c"};
    vector<string> res1 = shortestSubstrings(arr1);
    Display(res1);

    vector<string> arr2 = {"abc", "bcd", "abcd"};
    vector<string> res2 = shortestSubstrings(arr2);
    Display(res2);

    vector<string> arr3 = {"gfnt", "xn", "mdz", "yfmr", "fi", "wwncn", "hkdy"};
    vector<string> res3 = shortestSubstrings(arr3);
    Display(res3);

    vector<string> arr4 = {"fhi", "ct", "s", "o", "o"};
    vector<string> res4 = shortestSubstrings(arr4);
    Display(res4);

    return 0;
}