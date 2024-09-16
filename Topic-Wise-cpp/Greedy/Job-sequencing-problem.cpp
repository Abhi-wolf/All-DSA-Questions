#include <bits/stdc++.h>
using namespace std;

/* Given a set of N jobs where each jobi has a deadline and profit associated with it.
Each job takes 1 unit of time to complete and only one job can be scheduled at a time. We earn the profit associated
with job if and only if the job is completed by its deadline.
Find the number of jobs done and the maximum profit.

Note: Jobs will be given in the form (Jobid, Deadline, Profit) associated with that Job. Deadline of the job is the time
before which job needs to be completed to earn the profit.

Example 1:
Input:
N = 4
Jobs = {(1,4,20),(2,1,10),(3,1,40),(4,1,30)}
Output: 2 60
Explanation: Job1 and Job3 can be done with maximum profit of 60 (20+40).

Example 2:
Input:
N = 5
Jobs = {(1,2,100),(2,1,19),(3,2,27),(4,1,25),(5,1,15)}
Output: 2 127
Explanation: 2 jobs can be done with maximum profit of 127 (100+27).

Your Task :
You don't need to read input or print anything. Your task is to complete the function JobScheduling() which takes an
integer N and an array of Jobs(Job id, Deadline, Profit) as input and returns the count of jobs and maximum profit as a
list or vector of 2 elements.

Expected Time Complexity: O(NlogN)
Expected Auxilliary Space: O(N)

Constraints:
1 <= N <= 105
1 <= Deadline <= N
1 <= Profit <= 500*/

struct Job
{
    int id;
    int dead;
    int profit;
};

bool cmp(Job a, Job b)
{
    return a.profit > b.profit;
}

vector<int> JobScheduling(Job arr[], int n)
{
    // sorted all jobs according to profit
    sort(arr, arr + n, cmp);
    int maxDeadline = INT_MIN;

    // find the maximum deadline of a job
    for (int i = 0; i < n; i++)
        maxDeadline = max(maxDeadline, arr[i].dead);

    // track when a job is done (job is done at last moment or if the last moment
    //   then the job is scheduled before its deadline
    vector<int> schedule(maxDeadline + 1, -1);
    int count = 0;
    int maxProfit = 0;

    for (int i = 0; i < n; i++)
    {
        int currId = arr[i].id;
        int currProfit = arr[i].profit;
        int currDead = arr[i].dead;

        for (int k = currDead; k > 0; k--)
        {
            if (schedule[k] == -1)
            {
                schedule[k] = currId;
                maxProfit += currProfit;
                count++;
                break;
            }
        }
    }

    return {count, maxProfit};
}

int main()
{
    Job arr[] = {{1, 4, 20}, {2, 1, 10}, {3, 1, 40}, {4, 1, 30}};
    vector<int> res = JobScheduling(arr, 4);

    cout << "Result = " << res[0] << ", " << res[1] << endl;
    return 0;
}