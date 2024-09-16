#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <unordered_map>
using namespace std;

/*
There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites
where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return true if you can finish all courses. Otherwise, return false.

Example 1:
Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take.
To take course 1 you should have finished course 0. So it is possible.

Example 2:
Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take.
To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.


Constraints:

1 <= numCourses <= 2000
0 <= prerequisites.length <= 5000
prerequisites[i].length == 2
0 <= ai, bi < numCourses
All the pairs prerequisites[i] are unique.
*/

// check if there is a valid topological sort present -- if yes then true else false
bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
{
    unordered_map<int, list<int>> adj;
    vector<int> indegress(numCourses, 0);
    int count = 0;

    queue<int> que;

    // make adjecency list and prepare indegree vector
    for (int i = 0; i < prerequisites.size(); i++)
    {
        int u = prerequisites[i][1];
        int v = prerequisites[i][0];

        adj[u].push_back(v);
        indegress[v]++;
    }

    // push the course with zero prerequisites
    for (int i = 0; i < numCourses; i++)
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

    // check for cycle -- if cycle then false;
    if (count != numCourses)
        return false;

    return true;
}

int main()
{
    // vector<vector<int>> prerequisites = {{1, 0}, {0, 1}};
    vector<vector<int>> prerequisites = {{1, 0}};
    if (canFinish(2, prerequisites))
        cout << "Yes can finish \n";
    else
        cout << "Cannot finish \n";
    return 0;
}