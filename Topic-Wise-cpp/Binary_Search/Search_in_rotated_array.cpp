#include <iostream>
using namespace std;
int search(int arr[],int l,int h, int key) {
        int low=l,high=h-1;

        while(low<=high) {
            int mid=low+(high-low)/2;


            if(arr[mid]==key) return mid;

            // Determine which half is sorted
            if (arr[low] <= arr[mid]) { // Left half is sorted
                if (key >= arr[low] && key < arr[mid]) {
                    high = mid - 1; // Key lies in the left half
                } else {
                    low = mid + 1; // Key lies in the right half
                }
            } else { // Right half is sorted
                if (key > arr[mid] && key <= arr[high]) {
                    low = mid + 1; // Key lies in the right half
                } else {
                    high = mid - 1; // Key lies in the left half
                }
            }
        }

        return -1;
    }



int main()
{
    int arr[] = {5, 6, 7, 8, 9, 10, 1, 2, 3};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Answer = " << search(arr, 0, size, 3) << endl;
    cout << "Answer = " << search(arr, 0, size, 8) << endl;
    cout << "Answer = " << search(arr, 0, size, 90) << endl;

    return 0;
}
