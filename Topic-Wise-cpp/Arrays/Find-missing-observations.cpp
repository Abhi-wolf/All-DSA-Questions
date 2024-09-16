#include <iostream>
#include <vector>
using namespace std;

vector<int> missingRolls(vector<int> &rolls, int mean, int n)
{
    int sum = 0;

    for (int num : rolls)
        sum += num;

    // calculate the remaining sum
    int remainingsum = mean * (n + rolls.size()) - sum;

    // check is possible
    if (remainingsum > 6 * n || remainingsum < n)
        return {};

    // this will be the minimum element for each required elements
    int distributedmean = remainingsum / n;

    // this will be used to complete the sum (used in increasing the value)
    int mod = remainingsum % n;

    vector<int> ans(n, distributedmean);

    // increase the value
    for (int i = 0; i < mod; i++)
        ans[i]++;

    return ans;
}

int main()
{
    return 0;
}