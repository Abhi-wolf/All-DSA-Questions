#include <iostream>
#include <vector>
#include <unordered_map>
#include <limits.h>
using namespace std;

// TLE
int minSubarray(vector<int> &nums, int p)
{
    long long int totalSum = 0;
    long long int sumToRemove = 0;
    long long int n = nums.size();
    int minLen = INT_MAX;

    for (int x : nums)
        totalSum += x;

    if (totalSum < p)
        return -1;
    else if (totalSum == p || (totalSum % p) == 0)
        return 0;

    for (int i = 0; i < n; i++)
    {
        long long int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += nums[j];

            int remaining = (totalSum - sum) % p;

            if (remaining == 0)
            {
                minLen = min(minLen, (j - i + 1));
            }
        }
    }
    return minLen == n ? -1 : minLen;
}

int minSubarray2(vector<int> &nums, int p)
{
    int n = nums.size();
    int totalSum = 0;

    /*
        tofind = (totalsum - (prefixsum[j]-prefixsum[i]))%p
        tofind = (totalsum - prefixsum[j])%p + prefixsum[i]%p

        prefixsum[i]%p = (prefixsum[i] - totalsum + p)%p  (to stop from becoming out of bound add p)
        needed = (currsum - target + p)%p
    */

    // calculate totalsum (%p) is applied so that sums do not get out of bound
    for (int num : nums)
    {
        totalSum = (totalSum + num) % p;
    }

    int target = totalSum % p;
    if (target == 0)
        return 0;

    // use map to keep track of prefix sum mod p
    unordered_map<int, int> modMap;
    modMap[0] = -1; // to handle where the whole prefix is the answer

    int currSum = 0, minLen = n;

    for (int i = 0; i < n; i++)
    {
        currSum = (currSum + nums[i]) % p;

        // Calculate needed as the difference between currentSum and target, adjusted to be
        // positive by adding p and taking modulo p
        int needed = (currSum - target + p) % p;

        if (modMap.find(needed) != modMap.end())
        {
            minLen = min(minLen, i - modMap[needed]);
        }

        modMap[currSum] = i;
    }

    return minLen == n ? -1 : minLen;
}

int main()
{
    vector<int> nums = {6, 3, 5, 2};
    cout << minSubarray2(nums, 9) << endl;
    return 0;
}