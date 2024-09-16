#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;

vector<int> shortestPath(vector<pair<int, int>> edges, int n, int m, int src, int dest)
{
    unordered_map<int, list<int>> adj;
    vector<int> ans;
    queue<int> que;
    unordered_map<int, int> parent;
    unordered_map<int, bool> visited;

    // prepare adjacency list
    for (int i = 0; i < m; i++)
    {
        adj[edges[i].first].push_back(edges[i].second);
        adj[edges[i].second].push_back(edges[i].first);
    }

    que.push(src);
    parent[src] = -1;
    visited[src] = true;

    while (!que.empty())
    {
        int curr = que.front();
        que.pop();

        for (int neighbour : adj[curr])
        {
            if (!visited[neighbour])
            {
                visited[neighbour] = true;
                parent[neighbour] = curr;
                que.push(neighbour);
            }
        }
    }

    // find shortest path backward
    int destination = dest;
    ans.push_back(destination);
    while (destination != src)
    {
        destination = parent[destination];
        ans.push_back(destination);
    }

    // reverse to display from front to back
    reverse(ans.begin(), ans.end());
    return ans;
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

    vector<pair<int, int>> edges = {{1, 2}, {2, 3}, {3, 4}, {1, 3}};
    vector<int> ans = shortestPath(edges, 4, 4, 1, 4);
    Display1DArray(ans);
    return 0;
}