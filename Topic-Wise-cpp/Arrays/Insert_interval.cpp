#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/* Geek has an array of non-overlapping intervals intervals where intervals[i] = [starti, endi] represent the start and the end of the
ith event and intervals is sorted in ascending order by starti. He wants to add a new interval newInterval= [newStart, newEnd] where
newStart and newEnd represent the start and end of this interval.

Help Geek to insert newInterval into intervals such that intervals is still sorted in ascending order by starti and intervals still does
not have any overlapping intervals (merge overlapping intervals if necessary).

Examples:
Input: intervals = [[1,3], [4,5], [6,7], [8,10]], newInterval = [5,6]
Output: [[1,3], [4,7], [8,10]]
Explanation: The newInterval [5,6] overlaps with [4,5] and [6,7].

Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,9]
Output: [[1,2], [3,10], [12,16]]
Explanation: The new interval [4,9] overlaps with [3,5],[6,7],[8,10].

Constraints:
1 ≤ intervals.size() ≤  105
0 ≤ start[i], end[i] ≤ 109 */

vector<vector<int>> insertInterval(vector<vector<int>> &intervals,vector<int> &newInterval) {
        vector<vector<int>>res;
        int n=intervals.size(),i=0;

        // Add all intervals that come before the new interval
        while(i<n && intervals[i][1] < newInterval[0]) {
            res.push_back(intervals[i]);
            i++;
        }

        // Merge all overlapping intervals with the new interval
        while(i<n && intervals[i][0] <= newInterval[1]) {
            newInterval[0]=min(newInterval[0],intervals[i][0]);
            newInterval[1]=max(newInterval[1],intervals[i][1]);
            i++;
        }
        res.push_back(newInterval);

        // Add all the remaining intervals
        while(i<n) {
            res.push_back(intervals[i]);
            i++;
        }
        return res;
    }


void display(vector<vector<int>>res) {
    for(int i=0;i<res.size();i++) {
        for(int j=0;j<res[i].size();j++) {
            cout<<res[i][j]<<", ";
        }
        cout<<endl;
    }
    cout<<endl;
}
int main(){
    vector<vector<int>> intervals1={{1,3}, {4,5}, {6,7}, {8,10}};
    vector<int>newInterval1={5,6};
    vector<vector<int>>res1=insertInterval(intervals1,newInterval1);
    display(res1);

    vector<vector<int>> intervals2={{1,2},{3,5},{6,7},{8,10},{12,16}};
    vector<int>newInterval2={4,9};
    vector<vector<int>>res2=insertInterval(intervals2,newInterval2);
    display(res2);

    vector<vector<int>> intervals3={{1,3},{10,15},{20,30}};
    vector<int>newInterval3={5,6};
    vector<vector<int>>res3=insertInterval(intervals3,newInterval3);
    display(res3);

    return 0;
}
