#include <iostream>
using namespace std;

// array is sorted in descending order
// binary search
int binarSearch_Reverse_Sorted_array(int arr[], int n, int target)
{
    int start = 0, end = n - 1;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        if (arr[mid] == target)
            return mid;

        else if (arr[mid] < target)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }

    return -1;
}

int main()
{
    int arr[] = {9, 8, 7, 6, 5, 4, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << binarSearch_Reverse_Sorted_array(arr, n, 4) << endl;
    cout << binarSearch_Reverse_Sorted_array(arr, n, 9) << endl;
    cout << binarSearch_Reverse_Sorted_array(arr, n, 0) << endl;
    cout << binarSearch_Reverse_Sorted_array(arr, n, 100) << endl;
    cout << binarSearch_Reverse_Sorted_array(arr, n, 1) << endl;
    return 0;
}