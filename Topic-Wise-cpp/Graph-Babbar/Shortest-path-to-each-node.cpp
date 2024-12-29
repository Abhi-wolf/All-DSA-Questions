#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <queue>
#include <set>
#include <unordered_map>
using namespace std;

/* You are given an Undirected Graph having unit weight of the edges, find the shortest path from src to all the vertex
and if it is unreachable to reach any vertex, then return -1 for that vertex.

Example1:
Input:
n = 9, m= 10
edges=[[0,1],[0,3],[3,4],[4,5],[5,6],[1,2],[2,6],[6,7],[7,8],[6,8]]
src=0
Output:
0 1 2 1 2 3 3 4 4
Explanation:

Example2:
Input:
n = 4, m= 4
edges=[[0,0],[1,1],[1,3],[3,0]]
src=3
Output:
1 1 -1 0
Explanation:

Your Task:
You don't need to print or input anything. Complete the function shortest path() which takes a 2d vector or array of edges
representing the edges of an undirected graph with unit weight, an integer n as the number of nodes, an integer m as a number
of edges and an integer src as the input parameters and returns an integer array or vector, denoting the vector of distance
from src to all nodes.

Constraint:
1<=n,m<=10000
0<=edges[i][j]<=n-1

Expected Time Complexity: O(N + E), where N is the number of nodes and E is the edges
Expected Space Complexity: O(N)*/

// TLE
vector<int> shortestPath(vector<vector<int>> edges, int n, int m, int src)
{
    unordered_map<int, list<int>> adj;
    vector<int> dist(n, 0);
    queue<int> que;
    unordered_map<int, bool> visited;

    // prepare adjacency list
    for (int i = 0; i < m; i++)
    {
        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]);
    }

    que.push(src);
    visited[src] = true;

    while (!que.empty())
    {
        int curr = que.front();
        que.pop();

        for (int neighbour : adj[curr])
        {
            if (!visited[neighbour])
            {
                dist[neighbour] = dist[curr] + 1;
                visited[neighbour] = true;
                que.push(neighbour);
            }
        }
    }

    return dist;
}

// DIJKSTRA ALGORITHM
vector<int> shortestPath2(vector<vector<int>> &edges, int src)
{
    int n = edges.size();

    unordered_map<int, list<pair<int, int>>> adjlist;
    set<pair<int, int>> st;

    vector<int> dist(n, 1e9 + 7);

    for (int i = 0; i < edges.size(); i++)
    {
        for (int j = 0; j < edges[i].size(); j++)
        {
            int u = i;
            int v = edges[i][j];
            int wt = 1;

            adjlist[u].push_back(make_pair(v, wt));
        }
    }

    dist[src] = 0;
    st.insert({0, src});

    while (!st.empty())
    {
        auto curr = *(st.begin());

        int currdist = curr.first;
        int currnode = curr.second;

        st.erase(st.begin());

        for (auto neigh : adjlist[currnode])
        {
            if (currdist + 1 < dist[neigh.first])
            {
                auto record = st.find(make_pair(dist[neigh.first], neigh.first));

                if (record != st.end())
                {
                    st.erase(record);
                }

                dist[neigh.first] = currdist + 1;
                st.insert(make_pair(dist[neigh.first], neigh.first));
            }
        }
    }
    return dist;
}

void Display1DArray(vector<int> arr)
{
    cout << endl;
    for (int i = 0; i < arr.size(); i++)
    {
        cout << "arr[" << i << "] = " << arr[i] << endl;
    }
    cout << endl;
}
int main()
{

    vector<vector<int>> edges = {{0, 1}, {0, 3}, {3, 4}, {4, 5}, {5, 6}, {1, 2}, {2, 6}, {6, 7}, {7, 8}, {6, 8}};
    vector<int> ans = shortestPath(edges, 9, 10, 0);
    Display1DArray(ans);

    vector<vector<int>> edges2 = {{1, 3}, {0, 2}, {1, 6}, {0, 4}, {3, 5}, {4, 6}, {2, 5, 7, 8}, {6, 8}, {7, 6}};
    vector<int> ans2 = shortestPath2(edges2, 0);
    Display1DArray(ans2);
    return 0;
}