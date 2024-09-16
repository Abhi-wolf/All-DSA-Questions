#include <iostream>
#include <vector>
#include <limits.h>
#include <unordered_map>
#include <map>
#include <queue>
using namespace std;

// TLE
long findMinInWindow(vector<long> arr, int size)
{
    map<long, long> freq;
    map<long, long>::iterator it;
    vector<long> minimums;
    int win = 0, i = 0;

    for (int j = 0; j < arr.size(); j++)
    {
        // add element to the map
        freq[arr[j]]++;

        // increase the size of the window
        win++;

        // if the window size reaches desired size calculate the minimum of the window size
        if (win == size)
        {
            it = freq.begin();
            minimums.push_back(it->first);
        }

        // reset the window size
        if (win >= size)
        {
            while (win >= size)
            {
                freq[arr[i]]--;
                if (freq[arr[i]] == 0)
                    freq.erase(arr[i]);
                i++;
                win--;
            }
        }
    }

    long maxi = LONG_MIN;

    // find the maximum of all the elements of the minimum of window of size
    for (long x : minimums)
    {
        if (x > maxi)
            maxi = x;
    }
    return maxi;
}

// TLE
long findMinInWindow2(vector<long> arr, int size)
{
    map<long, long> freq;
    map<long, long>::iterator it;
    priority_queue<int> pq;
    int win = 0, i = 0;

    for (int j = 0; j < arr.size(); j++)
    {
        // add element to the map
        freq[arr[j]]++;

        // increase the size of the window
        win++;

        // if the window size reaches desired size calculate the minimum of the window size
        if (win == size)
        {
            it = freq.begin();
            pq.push(it->first);
        }

        // reset the window size
        if (win >= size)
        {
            while (win >= size)
            {
                freq[arr[i]]--;
                if (freq[arr[i]] == 0)
                    freq.erase(arr[i]);
                i++;
                win--;
            }
        }
    }

    return pq.empty() ? -1 : pq.top();
}

// Complete the riddle function below.
vector<long> riddle(vector<long> arr)
{
    // complete this function
    vector<long> ans;
    for (int i = 0; i < arr.size(); i++)
    {
        // calculate maximum of each window size
        long maxi = findMinInWindow(arr, i + 1);
        ans.push_back(maxi);
    }

    return ans;
}

void Display1DArray(vector<long> arr)
{
    cout << endl;
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << ", ";
    }
    cout << endl;
}
int main()
{
    // vector<long> arr = {6, 3, 5, 1, 12};
    vector<long> arr = {2, 6, 1, 12};
    vector<long> ans = riddle(arr);
    Display1DArray(ans);
    return 0;
}