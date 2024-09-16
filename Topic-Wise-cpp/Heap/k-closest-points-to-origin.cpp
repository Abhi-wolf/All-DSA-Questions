#include <iostream>
#include <vector>
#include <queue>
using namespace std;
/*
Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane and an integer k,
return the k closest points to the origin (0, 0).
The distance between two points on the X-Y plane is the Euclidean distance (i.e., √(x1 - x2)2 + (y1 - y2)2).

You may return the answer in any order. The answer is guaranteed to be unique (except for the order that it is in).

Example 1:
Input: points = [[1,3],[-2,2]], k = 1
Output: [[-2,2]]
Explanation:
The distance between (1, 3) and the origin is sqrt(10).
The distance between (-2, 2) and the origin is sqrt(8).
Since sqrt(8) < sqrt(10), (-2, 2) is closer to the origin.
We only want the closest k = 1 points from the origin, so the answer is just [[-2,2]].

Example 2:
Input: points = [[3,3],[5,-1],[-2,4]], k = 2
Output: [[3,3],[-2,4]]
Explanation: The answer [[-2,4],[3,3]] would also be accepted.

Constraints:

1 <= k <= points.length <= 104
-104 <= xi, yi <= 104
*/

vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
{
    priority_queue<pair<double, pair<int, int>>> maxheap;
    vector<vector<int>> ans;

    for (int i = 0; i < points.size(); i++)
    {
        int x = points[i][0];
        int y = points[i][1];

        // calculate dist between the point and the center
        double dist = (x * x) + (y * y);

        // push distance and the points in the max heap
        maxheap.push({dist, {x, y}});

        // if size of heap is greater than k then pop the elements from top
        if (maxheap.size() > k)
            maxheap.pop();
    }

    while (!maxheap.empty())
    {
        ans.push_back({maxheap.top().second.first, maxheap.top().second.second});
        maxheap.pop();
    }
    return ans;
}

void Display2DArray(vector<vector<int>> arr)
{
    cout << endl;
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr[0].size(); j++)
        {
            cout << arr[i][j] << " , ";
        }
        cout << endl;
    }
    cout << endl;
}

int main()
{
    vector<vector<int>> points = {{3, 3}, {5, -1}, {-2, 4}};
    vector<vector<int>> ans = kClosest(points, 2);
    Display2DArray(ans);
    return 0;
}