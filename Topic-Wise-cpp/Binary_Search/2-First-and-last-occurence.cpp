#include <iostream>
using namespace std;

int firstOccurence(int arr[], int n, int target)
{
    int start = 0, end = n - 1;
    int occur = -1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (arr[mid] == target)
        {
            occur = mid;
            end = mid - 1;
        }
        else if (arr[mid] > target)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return occur;
}

int lastOccurence(int arr[], int n, int target)
{
    int start = 0, end = n - 1;
    int occur = -1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (arr[mid] == target)
        {
            occur = mid;
            start = mid + 1;
        }
        else if (arr[mid] > target)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return occur;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 4, 4, 4, 5, 6, 7, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << firstOccurence(arr, n, 4) << endl;
    cout << lastOccurence(arr, n, 4) << endl;
    cout << firstOccurence(arr, n, 7) << endl;
    cout << lastOccurence(arr, n, 7) << endl;
    cout << firstOccurence(arr, n, 1) << endl;
    cout << lastOccurence(arr, n, 1) << endl;

    return 0;
}