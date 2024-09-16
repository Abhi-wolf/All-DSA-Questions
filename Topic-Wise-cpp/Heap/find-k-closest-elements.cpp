#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

/*
You are given a sorted array 'A' of length 'N', two integers 'K' and 'X'. Your task is to print 'K' integers closest
to 'X', if two integers are at the same distance return the smaller one.

The output should also be in sorted order

Note:
An integer 'a' is closer to 'X' than an integer 'b' if:
|a - X| < |b - X|  or (  |a - X| == |b - X| and a < b )
For Example:
if X = 4,  3 is closer to 'X' than 9, as |3-4| < |9-4|  i.e., 1 < 5   and if X = 4, 2 and 6 are equally close to it,
as |2-4| == |6-4| = 2, but we say 2 is closer to 4 than 6, as 2 is smaller.

Constraints:
1 <= T <= 5
1 <= N, K <= 5000
1 <= A[i], X <=10^6

Time Limit: 1 second
Sample Input 1:
2
5 4 3
1 2 3 4 5
5 5 -1
1 2 3 4 5
Sample Output 1:
1 2 3 4
1 2 3 4 5
Explanation For Sample Output 1:
For test case 1:

Subtracting 'X' from all elements of A, and taking the absolute value we get : [2 1 0 1 2]

From this array, we have to pick the 4 smallest numbers, which are A[1], A[2], A[3], and either of A[0] and A[4] as
both are at the same distance.

But since A[0] < A[4] (1 < 4) we pick A[0] (1).

Therefore the answer is [ A[0], A[1], A[2], A[3] ] or [1 2 3 4]

For test case 2:
We take all 5 elements as it demands 5 elements.
Therefore, the answer is [1 2 3 4 5]
Sample Input 2:
2
10 5 30
1 6 9 15 20 26 31 36 39 42
9 1 6
1 1 1 4 5 6 8 9 9
Sample Output 2:
20 26 31 36 39
6

*/

vector<int> KClosest(vector<int> &a, int n, int k, int x)
{
    priority_queue<pair<int, int>> maxheap;
    vector<int> ans;

    for (int i = 0; i < n; i++)
    {
        maxheap.push({abs(a[i] - x), a[i]});

        if (maxheap.size() > k)
            maxheap.pop();
    }

    while (!maxheap.empty())
    {
        ans.push_back(maxheap.top().second);
        maxheap.pop();
    }

    sort(ans.begin(), ans.end());

    return ans;
}

void Display1DArray(vector<int> arr)
{
    cout << endl;
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " , ";
    }
    cout << endl;
}

int main()
{
    vector<int> a = {1, 2, 3, 4, 5};
    vector<int> ans = KClosest(a, 5, 4, 3);
    Display1DArray(ans);
    ans = KClosest(a, 5, 5, -1);
    Display1DArray(ans);
    return 0;
}