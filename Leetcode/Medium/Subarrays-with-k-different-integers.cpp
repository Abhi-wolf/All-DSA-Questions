#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// not completedS

int subarraysWithKDistinct(vector<int> &nums, int k)
{
    unordered_map<int, int> um;
    int i = 0, j = 0, n = nums.size(), count = 0;

    while (j < n)
    {
        if (um.size() < k)
        {
            um[nums[j]]++;
            j++;

            if (um.size() == k)
                count++;
        }

        else if (um.size() == k && um.find(nums[j]) != um.end())
        {
            count++;
            um[nums[j]]++;
            j++;
        }

        else
        {
            while (um.size() >= k)
            {
                um[nums[i]]--;
                if (um[nums[i]] <= 0)
                    um.erase(nums[i]);

                if (um.size() == k)
                    count++;
                i++;
            }
        }
        // j++;
    }

    return count;
}

int main()
{
    vector<int> nums = {1, 2, 1, 2, 3};
    cout << "\n Ans = " << subarraysWithKDistinct(nums, 2) << endl;
    return 0;
}