#include <iostream>
#include <vector>
using namespace std;

/*
A Bitonic Sequence is a sequence of numbers that is first strictly increasing then after a point decreasing.

Examples:
Input :  arr[] = {-3, 9, 18, 20, 17, 5, 1}, key = 20
Output : Found at index 3

Input :  arr[] = {5, 6, 7, 8, 9, 10, 3, 2, 1}, key = 30
Output : Not Found
*/

// Function for binary search in ascending part
int ascendingBinarySearch(vector<int> arr, int low, int high, int key)
{
    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] == key)
            return mid;
        else if (arr[mid] > key)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}
// Function for binary search in descending part
int descendingBinarySearch(vector<int> arr, int low, int high, int key)
{
    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] == key)
            return mid;
        else if (arr[mid] > key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

// find bitonic point (peak point -- element greater than both its neighbours)
int findBitonicPoint(vector<int> arr)
{
    int size = arr.size();
    int start = 0, end = size - 1;
    if (size < 2)
    {
        return 0;
    }

    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        if (mid > 0 && mid < size - 1 && arr[mid] > arr[mid + 1] && arr[mid] > arr[mid - 1])
        {
            return mid;
        }

        else if (arr[mid] < arr[mid + 1])
            start = mid + 1;
        else
            end = mid - 1;
    }

    return -1;
}

int searchBitonic(vector<int> arr, int key)
{
    int size = arr.size();
    int peakEleIndex = findBitonicPoint(arr);

    if (key > arr[peakEleIndex])
        return -1;

    else if (key == arr[peakEleIndex])
        return peakEleIndex;

    else
    {
        int left = ascendingBinarySearch(arr, 0, peakEleIndex - 1, key);
        if (left != -1)
            return left;
        int right = descendingBinarySearch(arr, peakEleIndex + 1, size - 1, key);
        if (right != -1)
            return right;
    }
    return -1;
}

int main()
{
    vector<int> arr = {-8, 1, 2, 3, 4, 5, -2, -3};
    cout << "Search Index = " << searchBitonic(arr, 100) << endl;
    return 0;
}