#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(vector<int> &v1, vector<int> &v2)
{
    if (v1[1] == v2[1])
        return v1[0] < v2[0];
    return v1[1] > v2[1];
}

int luckBalance(int k, vector<vector<int>> contests)
{
    sort(contests.begin(), contests.end(), cmp);

    int totalImportantContests = 0;
    int totalLuck = 0, winLuck = 0;
    for (int i = 0; i < contests.size(); i++)
    {
        totalLuck += contests[i][0];
        cout << contests[i][0] << " , " << contests[i][1] << endl;
        if (contests[i][1] == 1)
            totalImportantContests++;
    }

    int canWin = totalImportantContests - k;

    for (int i = 0; i < canWin; i++)
    {
        winLuck += contests[i][0];
    }

    cout << totalLuck << " --> " << winLuck << endl;
    return totalLuck - 2 * winLuck;
}

int main()
{
    vector<vector<int>> contests = {{5, 1}, {2, 1}, {1, 1}, {8, 1}, {10, 0}, {5, 0}};
    cout << luckBalance(3, contests) << endl;
    return 0;
}