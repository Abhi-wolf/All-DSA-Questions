#include <bits/stdc++.h>
using namespace std;
int infinity = 1e9 + 7;

vector<int> shortestPath(vector<vector<int>> &edges, int src)
{
    int n = edges.size();

    unordered_map<int, list<pair<int, int>>> adjlist;
    set<pair<int, int>> st;

    vector<int> dist(n, infinity);

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

void display(vector<int> res)
{
    cout << "\n\n";

    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << ", ";
    }

    cout << "\n\n";
}

int main()
{
    vector<vector<int>> edges = {{1, 3}, {0, 2}, {1, 6}, {0, 4}, {3, 5}, {4, 6}, {2, 5, 7, 8}, {6, 8}, {7, 6}};
    vector<int> res = shortestPath(edges, 0);
    display(res);
    return 0;
}