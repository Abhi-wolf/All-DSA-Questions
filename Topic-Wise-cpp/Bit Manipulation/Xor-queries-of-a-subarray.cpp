#include <iostream>
#include <vector>
using namespace std;

/*
You are given an array arr of positive integers. You are also given the array queries where queries[i] = [lefti, righti].

For each query i compute the XOR of elements from lefti to righti (that is, arr[lefti] XOR arr[lefti + 1]
XOR ... XOR arr[righti] ).
Return an array answer where answer[i] is the answer to the ith query.

Example 1:
Input: arr = [1,3,4,8], queries = [[0,1],[1,2],[0,3],[3,3]]
Output: [2,7,14,8]
Explanation:
The binary representation of the elements in the array are:
1 = 0001
3 = 0011
4 = 0100
8 = 1000
The XOR values for queries are:
[0,1] = 1 xor 3 = 2
[1,2] = 3 xor 4 = 7
[0,3] = 1 xor 3 xor 4 xor 8 = 14
[3,3] = 8

Example 2:
Input: arr = [4,8,2,10], queries = [[2,3],[1,3],[0,0],[0,3]]
Output: [8,0,4,4]

Constraints:
1 <= arr.length, queries.length <= 3 * 104
1 <= arr[i] <= 109
queries[i].length == 2
0 <= lefti <= righti < arr.length
*/

int xorval(vector<int> &arr, int start, int end)
{
    int val = 0;
    for (int i = start; i <= end; i++)
        val ^= arr[i];

    return val;
}

// FIRST METHOD
vector<int> xorQueries1(vector<int> &arr, vector<vector<int>> &queries)
{
    vector<int> ans;
    for (int i = 0; i < queries.size(); i++)
    {
        int start = queries[i][0];
        int end = queries[i][1];
        int res = xorval(arr, start, end);

        ans.push_back(res);
    }

    return ans;
}

/*   Prefix XOR Array
    Assume the array is [a,b,c,d,e].

    prefixXOR[0]=0(XOR of elements before the start)
    prefixXOR[1]=a
    prefixXOR[2]=a⊕b
    prefixXOR[3]=a⊕b⊕c
    prefixXOR[4]=a⊕b⊕c⊕d
    prefixXOR[5]=a⊕b⊕c⊕d⊕e

    To query the XOR from index 1 to 3:

    prefixXOR[4]=a⊕b⊕c⊕d

    prefixXOR[1]=a

    XORing these:

    prefixXOR[4]⊕prefixXOR[1]=(a⊕b⊕c⊕d)⊕a=b⊕c⊕d

    This gives the XOR of elements from index 1 to 3.
    */
// SECOND METHOD
vector<int> xorQueries2(vector<int> &arr, vector<vector<int>> &queries)
{
    int n = arr.size();
    vector<int> ans, prefixXor(n + 1, 0);

    for (int i = 0; i < n; i++)
    {
        prefixXor[i + 1] = prefixXor[i] ^ arr[i];
    }

    for (int i = 0; i < queries.size(); i++)
    {
        int res = prefixXor[queries[i][1] + 1] ^ prefixXor[queries[i][0]];

        ans.push_back(res);
    }

    return ans;
}

// THIRD METHOD  (In place Prefix XOR)
vector<int> xorQueries3(vector<int> &arr, vector<vector<int>> &queries)
{
    int n = arr.size();
    vector<int> ans;

    for (int i = 1; i < n; i++)
    {
        arr[i] ^= arr[i - 1];
    }

    for (int i = 0; i < queries.size(); i++)
    {
        int res = 0;
        if (queries[i][0] > 0)
            res = arr[queries[i][0] - 1] ^ arr[queries[i][1]];
        else
            res = arr[queries[i][1]];
        ans.push_back(res);
    }

    return ans;
}

void Display1DArray(vector<int> arr)
{
    cout << endl;
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << ", ";
    }
    cout << endl;
}

int main()
{
    vector<int> arr = {1, 3, 4, 8};

    vector<vector<int>> queries = {{0, 1}, {1, 2}, {0, 3}, {3, 3}};

    vector<int> ans1 = xorQueries1(arr, queries);
    vector<int> ans2 = xorQueries2(arr, queries);
    vector<int> ans3 = xorQueries3(arr, queries);

    Display1DArray(ans1);
    Display1DArray(ans2);
    Display1DArray(ans3);

    return 0;
}