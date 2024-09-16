#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

// CYCLE DETECTION IN DIRECTED GRAPH

// DFS
bool isCyclicDirectedDFS(vector<int> adj[], int node, unordered_map<int, bool> &visited, unordered_map<int, bool> &dfsVisited)
{
    visited[node] = true;
    dfsVisited[node] = true;

    for (int neighbour : adj[node])
    {
        if (!visited[neighbour])
        {
            if (isCyclicDirectedDFS(adj, neighbour, visited, dfsVisited))
                return true;
        }
        else if (dfsVisited[neighbour])
        {
            return true;
        }
    }

    dfsVisited[node] = false;
    return false;
}

bool isCyclic(int V, vector<int> adj[])
{
    unordered_map<int, bool> visited, dfsVisited;
    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            if (isCyclicDirectedDFS(adj, i, visited, dfsVisited))
                return true;
        }
    }
    return false;
}

// BFS
bool detectCycleInDirectedGraphBFS(int v, vector<int> adj[])
{
    // for valid topological sort the count will be equal to V
    int count = 0;
    queue<int> que;

    vector<int> indegress(v, 0);

    for (int i = 0; i < v; i++)
    {
        for (int j : adj[i])
            indegress[j]++;
    }

    for (int i = 0; i < v; i++)
    {
        if (indegress[i] == 0)
            que.push(i);
    }

    while (!que.empty())
    {
        int curr = que.front();
        que.pop();

        count++;

        for (int neighbour : adj[curr])
        {
            indegress[neighbour]--;

            if (indegress[neighbour] == 0)
                que.push(neighbour);
        }
    }

    if (count == v)
        return false; // no cycle
    else
        return true; // cycle present
}

int main()
{
    vector<int> adj[4] = {{1}, {2}, {3}, {3}}; // cycle
    vector<int> adj2[4] = {{1}, {2}, {3}, {}}; // no cycle
    cout << isCyclic(4, adj) << endl;
    cout << isCyclic(4, adj2) << endl;
    cout << detectCycleInDirectedGraphBFS(4, adj) << endl;
    cout << detectCycleInDirectedGraphBFS(4, adj2) << endl;
    return 0;
}
