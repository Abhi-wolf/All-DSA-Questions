#include <iostream>
#include <vector>
using namespace std;

/*
Given an array arr of lowercase strings, determine if the strings can be chained together to form a circle.
A string X can be chained together with another string Y if the last character of X is the same as the first
character of Y. If every string of the array can be chained with exactly two strings of the array(one with
the first character and the second with the last character of the string), it will form a circle.

For example, for the array arr[] = {"for", "geek", "rig", "kaf"} the answer will be Yes as the given strings
can be chained as "for", "rig", "geek" and "kaf"

Examples

Input: arr[] = ["abc", "bcd", "cdf"]
Output: 0
Explaination: These strings can't form a circle because no string has 'd'at the starting index.
Input: arr[] = ["ab" , "bc", "cd", "da"]
Output: 1
Explaination: These strings can form a circle of strings.
Expected Time Complexity: O(n)
Expected Auxiliary Space: O(n)

Constraints:
1 ≤ length of strings ≤ 20
*/

void dfs(int node, vector<bool> &visited, vector<vector<int>> &adj)
{
    visited[node] = true;

    for (auto neigh : adj[node])
    {
        if (!visited[neigh])
            dfs(neigh, visited, adj);
    }
}

int isCircle(vector<string> &arr)
{
    vector<int> inDegree(26, 0), outDegree(26, 0);

    vector<vector<int>> adj(26);

    // create adjacency list
    // calculate indegree and outdegree on nodes

    for (auto str : arr)
    {
        int u = str[0] - 'a';
        int v = str[str.size() - 1] - 'a';

        adj[u].push_back(v);
        inDegree[v]++;
        outDegree[u]++;
    }

    // for Eulerian circuit to exist, indegree and outdegree of node should be equal
    for (int i = 0; i < 26; i++)
    {
        if (inDegree[i] != outDegree[i])
            return 0;
    }

    vector<bool> visited(26, false);
    int node = arr[0][0] - 'a';

    dfs(node, visited, adj);

    for (int i = 0; i < 26; i++)
    {
        if (inDegree[i] && !visited[i])
            return 0;
    }

    return 1;
}

int main()
{
    vector<string> arr = {"ab", "bc", "cd", "da"};
    cout << "Is circle = " << isCircle(arr) << endl;
    return 0;
}