#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

// TIME -- O(n) SPACE -- O(n)
int SumofMiddleElements(vector<int> &arr1, vector<int> &arr2)
{
    vector<int> newArray;

    int i = 0, j = 0;

    while (i < arr1.size() && j < arr2.size())
    {
        if (arr1[i] <= arr2[j])
        {
            newArray.push_back(arr1[i++]);
        }
        else
        {
            newArray.push_back(arr2[j++]);
        }
    }

    while (i < arr1.size())
    {
        newArray.push_back(arr1[i++]);
    }

    while (j < arr2.size())
    {
        newArray.push_back(arr2[j++]);
    }

    int size = newArray.size();
    int median = 0;

    if (size % 2 == 0)
    {
        median = newArray[size / 2] + newArray[size / 2 - 1];
    }
    else
    {
        median = newArray[size / 2];
    }

    return median;
}

// TIME -- O(n) SPACE -- O(1)
int SumofMiddleElements2(vector<int> &arr1, vector<int> &arr2)
{
    int s1 = arr1.size(), s2 = arr2.size();
    int totalSize = s1 + s2;

    int ind1 = totalSize / 2 - 1, ind2 = totalSize / 2, ind1Ele = -1, ind2Ele = -1;
    int i = 0, j = 0, cnt = 0;

    while (i < s1 && j < s2)
    {
        if (arr1[i] <= arr2[j])
        {
            if (cnt == ind1)
                ind1Ele = arr1[i];
            if (cnt == ind2)
                ind2Ele = arr1[i];
            i++;
        }
        else
        {
            if (cnt == ind1)
                ind1Ele = arr2[j];
            if (cnt == ind2)
                ind2Ele = arr2[j];
            j++;
        }
    }

    while (i < s1)
    {
        if (cnt == ind1)
            ind1Ele = arr1[i];
        if (cnt == ind2)
            ind2Ele = arr1[i];

        i++;
    }

    while (j < s2)
    {
        if (cnt == ind1)
            ind1Ele = arr2[j];
        if (cnt == ind2)
            ind2Ele = arr2[j];

        j++;
    }

    if (totalSize % 2 == 0)
    {
        return (ind1Ele + ind2Ele);
    }

    return ind2Ele;
}

// TIME -- O(logn) SPACE -- O(1)
int SumofMiddleElements3(vector<int> &arr1, vector<int> &arr2)
{
    int n1 = arr1.size();
    int n2 = arr2.size();

    if (n1 > n2)
        return SumofMiddleElements3(arr2, arr1);

    int low = 0, high = n1;
    int left = (n1 + n2 + 1) / 2;
    int n = n1 + n2;

    while (low <= high)
    {
        int mid1 = (low + high) / 2;
        int mid2 = left - mid1;

        int l1 = INT_MIN, l2 = INT_MIN;
        int r1 = INT_MAX, r2 = INT_MAX;

        if (mid1 < n1)
            r1 = arr1[mid1];
        if (mid2 < n2)
            r2 = arr2[mid2];

        if (mid1 - 1 >= 0)
            l1 = arr1[mid1 - 1];
        if (mid2 - 1 >= 0)
            l2 = arr2[mid2 - 1];

        if (l1 <= r2 && l2 <= r1)
        {
            if (n % 2 == 1)
                return max(l1, l2);
            return (max(l1, l2) + min(r1, r2));
        }
        else if (l1 > l2)
            high = mid1 - 1;
        else
            low = mid1 + 1;
    }
    return 0;
}
int main()
{
    return 0;
}