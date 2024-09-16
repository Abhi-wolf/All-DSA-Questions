#include <iostream>
#include <vector>
using namespace std;

int minimumAbsDifferenceElement(vector<int> arr, int key)
{
    int start = 0, end = arr.size() - 1;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (arr[mid] == key)
            return arr[mid];

        else if (arr[mid] > key)
            end = mid - 1;
        else
            start = mid + 1;
    }

    // if key is not present then the start and end will point in the either side of the
    // key if the key would be present
    int abs1 = abs(key - arr[end]);
    int abs2 = abs(key - arr[start]);

    return abs1 <= abs2 ? arr[end] : arr[start];
}

int main()
{
    vector<int> arr = {1, 3, 8, 10, 15};
    cout << "Answer = " << minimumAbsDifferenceElement(arr, 12) << endl;
    cout << "Answer = " << minimumAbsDifferenceElement(arr, 13) << endl;
    cout << "Answer = " << minimumAbsDifferenceElement(arr, 4) << endl;
    cout << "Answer = " << minimumAbsDifferenceElement(arr, 8) << endl;
    return 0;
}