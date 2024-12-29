#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>
using namespace std;

int infinity = 1e9 + 7;

// DIJKSTRA ALGORITHM

vector<int> dijkstra(vector<vector<int>> &arr, int edges, int vertices, int src)
{
    unordered_map<int, vector<pair<int, int>>> adj;
    set<pair<int, int>> st; // distance, node

    for (int i = 0; i < arr.size(); i++)
    {
        int u = arr[i][0];
        int v = arr[i][1];
        int w = arr[i][2];

        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }

    vector<int> dist(vertices, infinity);
    dist[src] = 0;
    st.insert(make_pair(0, src));

    while (!st.empty())
    {
        // take top pair
        auto temp = *(st.begin());

        int currDist = temp.first;
        int node = temp.second;

        // remove the top
        st.erase(st.begin());

        for (auto x : adj[node])
        {
            if (currDist + x.second < dist[x.first])
            {
                auto record = st.find(make_pair(dist[x.first], x.first));

                if (record != st.end())
                {
                    st.erase(record);
                }

                dist[x.first] = currDist + x.second;

                st.insert(make_pair(dist[x.first], x.first));
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
    vector<vector<int>> arr = {{0, 1, 7}, {0, 2, 1}, {0, 3, 2}, {1, 2, 3}, {1, 4, 1}, {1, 3, 5}, {3, 4, 7}};

    vector<int> res = dijkstra(arr, 7, 5, 0);
    display(res);

    return 0;
}
