#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
using namespace std;

/*
You are given an undirected weighted graph of n nodes (0-indexed), represented by an edge list where
edges[i] = [a, b] is an undirected edge connecting the nodes a and b with a probability of success of
traversing that edge succProb[i].

Given two nodes start and end, find the path with the maximum probability of success to go from start
to end and return its success probability.

If there is no path from start to end, return 0. Your answer will be accepted if it differs from the correct
answer by at most 1e-5.

Example 1:
Input: n = 3, edges = [[0,1],[1,2],[0,2]], succProb = [0.5,0.5,0.2], start = 0, end = 2
Output: 0.25000
Explanation: There are two paths from start to end, one having a probability of success = 0.2 and the other
has 0.5 * 0.5 = 0.25.

Example 2:
Input: n = 3, edges = [[0,1],[1,2],[0,2]], succProb = [0.5,0.5,0.3], start = 0, end = 2
Output: 0.30000

Example 3:
Input: n = 3, edges = [[0,1]], succProb = [0.5], start = 0, end = 2
Output: 0.00000
Explanation: There is no path between 0 and 2.


Constraints:

2 <= n <= 10^4
0 <= start, end < n
start != end
0 <= a, b < n
a != b
0 <= succProb.length == edges.length <= 2*10^4
0 <= succProb[i] <= 1
There is at most one edge between every two nodes.
*/

void dfs1(unordered_map<int, list<int>> &adjList, int curr, int dest,
          vector<int> &temp, vector<bool> &visited,
          vector<vector<int>> &ans)
{
    visited[curr] = true;
    temp.push_back(curr);

    if (curr == dest)
    {
        ans.push_back(temp);
    }

    for (int x : adjList[curr])
    {
        if (!visited[x])
            dfs1(adjList, x, dest, temp, visited, ans);
    }

    temp.pop_back();
    visited[curr] = false;
}

// FIRST METHOD -- TLE
double maxProbability1(int n, vector<vector<int>> &edges,
                       vector<double> &succProb, int start_node,
                       int end_node)
{
    unordered_map<int, list<int>> adjList;
    vector<bool> visited(n, false);
    vector<vector<int>> ans;
    vector<int> temp;
    double maxProb = 0.0;

    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    dfs1(adjList, start_node, end_node, temp, visited, ans);

    for (int i = 0; i < ans.size(); i++)
    {
        double prob = 0;
        for (int j = 0; j < ans[i].size() - 1; j++)
        {
            for (int k = 0; k < edges.size(); k++)
            {
                if ((edges[k][0] == ans[i][j] &&
                     edges[k][1] == ans[i][j + 1]) ||
                    edges[k][0] == ans[i][j + 1] &&
                        edges[k][1] == ans[i][j])
                {

                    if (prob == 0)
                        prob = succProb[k];
                    else
                        prob *= succProb[k];
                    break;
                }
            }
        }

        maxProb = max(maxProb, prob);
    }

    return maxProb;
}

void dfs2(unordered_map<int, list<pair<int, double>>> &adjList, int curr,
          int dest, double &temp, vector<bool> &visited, double &ans)
{
    visited[curr] = true;

    if (curr == dest)
    {
        ans = max(ans, temp);
        visited[curr] = false; // Unmark before returning
        return;
    }

    for (auto [next, prob] : adjList[curr])
    {
        if (!visited[next])
        {
            double prevTemp = temp;
            temp *= prob; // Multiply the temp with the edge probability
            dfs2(adjList, next, dest, temp, visited, ans);
            temp = prevTemp; // Backtrack the temp value
        }
    }

    visited[curr] = false;
}

//  SECOND METHOD -- TLE
double maxProbability2(int n, vector<vector<int>> &edges,
                       vector<double> &succProb, int start_node,
                       int end_node)
{
    unordered_map<int, list<pair<int, double>>> adjList;
    vector<bool> visited(n, false);
    double maxProb = 0.0;

    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        double prob = succProb[i];

        adjList[u].emplace_back(v, prob);
        adjList[v].emplace_back(u, prob);
    }

    double temp = 1.0;
    dfs2(adjList, start_node, end_node, temp, visited, maxProb);

    return maxProb;
}

// THIRD METHOD -- BELL MAN FORD ALGORITHM
double maxProbability3(int n, vector<vector<int>> &edges,
                       vector<double> &succProb, int start_node,
                       int end_node)
{

    vector<double> maxProb(n);
    maxProb[start_node] = 1.0;

    // relaxation n-1 times
    for (int i = 0; i < n - 1; i++)
    {
        bool hasUpdate = false;

        for (int j = 0; j < edges.size(); j++)
        {
            int u = edges[j][0];
            int v = edges[j][1];
            double prob = succProb[j];

            if (maxProb[u] * prob > maxProb[v])
            {
                maxProb[v] = maxProb[u] * prob;
                hasUpdate = true;
            }

            if (maxProb[v] * prob > maxProb[u])
            {
                maxProb[u] = maxProb[v] * prob;
                hasUpdate = true;
            }
        }

        if (!hasUpdate)
            break;
    }

    return maxProb[end_node];
}

int main()
{
    vector<vector<int>> edges = {{0, 1}, {1, 2}, {0, 2}};
    vector<double> succProb = {0.5, 0.5, 0.2};

    cout << maxProbability1(3, edges, succProb, 0, 2) << endl;
    cout << maxProbability2(3, edges, succProb, 0, 2) << endl;
    cout << maxProbability3(3, edges, succProb, 0, 2) << endl;
    return 0;
}