#include <iostream>
#include <vector>
using namespace std;

/*
You are given an integer num. You can swap two digits at most once to get the maximum valued number.
Return the maximum valued number you can get.

Example 1:
Input: num = 2736
Output: 7236
Explanation: Swap the number 2 and the number 7.

Example 2:
Input: num = 9973
Output: 9973
Explanation: No swap.
*/

// METHOD- 1    TC -- O(n^2)  SC -- O(n)
int maximumSwap(int num)
{
    string numstr = to_string(num);
    int n = numstr.size();
    int maxnum = num;

    // try all possible swaps
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            // swap elements at index i with element at index j
            swap(numstr[i], numstr[j]);

            // update maxnum
            maxnum = max(maxnum, stoi(numstr));

            // backtrack or swap back to restore the original
            swap(numstr[i], numstr[j]);
        }
    }

    return maxnum;
}

// METHOD- 2    TC -- O(n)  SC -- O(n)
int maximumSwap2(int num)
{
    string numstr = to_string(num);
    int n = numstr.size();
    int maxnum = num;
    vector<int> maxRightIndex(n);

    // First pass: Populate maxRightIndex with the index of the largest
    // digit to the right of each position
    maxRightIndex[n - 1] = n - 1;
    for (int i = n - 2; i >= 0; i--)
    {
        maxRightIndex[i] = (numstr[i] > numstr[maxRightIndex[i + 1]])
                               ? i
                               : maxRightIndex[i + 1];
    }

    // Second pass: Find the first place where we can swap to maximize the
    // number
    for (int i = 0; i < n; i++)
    {
        if (numstr[i] < numstr[maxRightIndex[i]])
        {
            swap(numstr[i], numstr[maxRightIndex[i]]);
            return stoi(numstr);
        }
    }

    return num;
}

/*
As we move through the number, we don’t need to know the position of every digit—we only need to know the position
of the largest digit we’ve seen so far.

We start by scanning the number from right to left. As we move, we keep track of the largest digit we’ve encountered.
Whenever we come across a smaller digit, we consider it a candidate for swapping with the largest one we’ve seen.

So we compare each digit with the maximum digit to its right. If it’s smaller, we mark it for swapping. By the time we
finish scanning the number, we’ll know the best swap to make. If we find a smaller digit and a larger one to swap it with,
we perform the swap. Otherwise, we leave the number unchanged.
*/
// METHOD- 3    TC -- O(n)  SC -- O(1)
int maximumSwap3(int num)
{
    string numstr = to_string(num);
    int n = numstr.size();
    int maxdigitind = -1, swapind1 = -1, swapind2 = -1;

    for (int i = n - 1; i >= 0; i--)
    {
        if (maxdigitind == -1 || numstr[i] > numstr[maxdigitind])
        {
            maxdigitind = i; // Update the index of the max digit
        }
        else if (numstr[i] < numstr[maxdigitind])
        {
            swapind1 = i;           // Mark the smaller digit for swapping
            swapind2 = maxdigitind; // Mark the larger digit for swapping
        }
    }

    if (swapind1 != -1 && swapind2 != -1)
    {
        swap(numstr[swapind1], numstr[swapind2]);
    }

    return stoi(numstr);
}

int maximumSwap4(int num)
{
    vector<int> vec;
    while (num > 0)
    {
        vec.push_back(num % 10);
        num /= 10;
    }

    for (int i = vec.size() - 1; i >= 0; i--)
    {

        int larg = i;

        for (int j = 0; j < i; j++)
        {
            if (vec[larg] < vec[j])
                larg = j;
        }

        if (vec[larg] > vec[i])
        {
            swap(vec[larg], vec[i]);
            break;
        }
    }

    num = 0;

    for (int i = vec.size() - 1; i >= 0; i--)
    {
        num = num * 10 + vec[i];
    }

    return num;
}

int main()
{
    int num = 1993;
    cout << maximumSwap(num) << endl;
    cout << maximumSwap2(num) << endl;
    cout << maximumSwap3(num) << endl;
    cout << maximumSwap4(num) << endl;
    return 0;
}