#include <iostream>
#include <vector>
using namespace std;

int binarySearch(vector<int> arr, int target, int start, int end)
{
    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            start = mid + 1;
        else
            end = mid - 1;
    }
    return -1;
}

// In this method we assume that the supplied array has infinite elements
int searchInInfiniteArray(vector<int> arr, int target)
{
    // First taking start and end to be 0 and 1 as it's an infinite array and we don't know the end.
    int start = 0, end = 1;

    // Now we will just get the chunks and check target lies in which chunk
    while (arr[end] < target)
    {
        int newStart = end + 1;
        // Doubling the end size
        end = end + (end - start + 1) * 2;
        start = newStart;
    }

    cout << "target =" << target << " --> " << start << " - " << end << endl;
    return binarySearch(arr, target, start, end);
}

int main()
{
    vector<int> arr = {3, 5, 7, 9, 10, 90, 100, 130, 140, 160, 170};

    cout << "10 == " << searchInInfiniteArray(arr, 10) << endl;
    cout << "10 == " << searchInInfiniteArray(arr, -1) << endl;
    cout << "10 == " << searchInInfiniteArray(arr, 31) << endl;
    cout << "10 == " << searchInInfiniteArray(arr, 90) << endl;
    return 0;
}