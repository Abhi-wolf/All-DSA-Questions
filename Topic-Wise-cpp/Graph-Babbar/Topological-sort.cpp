#include <iostream>
#include <stack>
#include <vector>
#include <list>
#include <queue>
#include <unordered_map>
using namespace std;

// TOPOLOGICAL SORT -- only in acyclic graph(no cycle)
// for every edge u --> v , u should appear before v in the ordering

void topologicalSortDFS(vector<int> adj[], unordered_map<int, bool> &visited, stack<int> &stk, int node)
{
    visited[node] = true;

    for (int i : adj[node])
    {
        if (!visited[i])
        {
            topologicalSortDFS(adj, visited, stk, i);
        }
    }
    stk.push(node);
}

vector<int> topoSort(int V, vector<int> adj[])
{
    unordered_map<int, bool> visited;
    stack<int> stk;
    vector<int> ans;

    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            topologicalSortDFS(adj, visited, stk, i);
        }
    }

    while (!stk.empty())
    {
        ans.push_back(stk.top());
        stk.pop();
    }
    return ans;
}

// USING KHAN'S ALGORITHM
vector<int> topologicalSortBFS(vector<int> adj[], int v, int e)
{
    cout << adj[0].size() << endl;

    unordered_map<int, list<int>> adjList;
    vector<int> indegree(v, 0);
    vector<int> ans;
    queue<int> que;

    // create adj list
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < adj[i].size(); j++)
        {
            adjList[i].push_back(adj[i][j]);
        }
    }

    // find all indegress
    for (auto x : adjList)
    {
        for (auto y : x.second)
        {
            indegree[y]++;
        }
    }

    // push nodes with zero indegree
    for (int i = 0; i < v; i++)
    {
        if (indegree[i] == 0)
            que.push(i);
    }

    // applyBFS
    while (!que.empty())
    {
        int curr = que.front();
        que.pop();

        // store in ans
        ans.push_back(curr);

        // neighnour indegree update
        for (int neighbour : adjList[curr])
        {
            indegree[neighbour]--;

            if (indegree[neighbour] == 0)
                que.push(neighbour);
        }
    }

    return ans;
}

int main()
{
    vector<int> adj[4] = {{}, {0}, {0}, {0}};
    // vector<int> ans = topoSort(4, adj);
    // for (int i : ans)
    //     cout << i << ", ";

    vector<int> adj2[8] = {{}, {2}, {}, {5}, {}, {}, {3, 5}, {1, 3}};

    vector<int> ans1 = topologicalSortBFS(adj2, 8, 6);
    for (int i : ans1)
        cout << i << ", ";

    return 0;
}