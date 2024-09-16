#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
{
    vector<vector<int>> merged;
    int i = 0, n = intervals.size();

    while (i < n && intervals[i][1] < newInterval[0])
    {
        merged.push_back(intervals[i]);
        i++;
    }

    while (i < n && intervals[i][0] <= newInterval[1])
    {
        newInterval = {min(newInterval[0], intervals[i][0]), max(newInterval[1], intervals[i][1])};
        i++;
    }

    merged.push_back(newInterval);

    while (i < n)
    {
        merged.push_back(intervals[i]);
        i++;
    }

    return merged;
}

void display(vector<vector<int>> res)
{
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i][0] << " , " << res[i][1] << endl;
    }
    cout << endl;
}

int main()
{
    vector<vector<int>> intervals = {{1, 2}, {3, 5}, {6, 7}, {8, 10}, {12, 16}};
    vector<int> newInterval = {4, 8};
    vector<vector<int>> res = insert(intervals, newInterval);
    display(res);
    return 0;
}