#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;

// FIRST METHOD
/*
First, we convert each integer to a string. Then, we sort the array of
strings.

Sorting the numbers in descending order might seem like a good idea, but it
leads to issues when numbers share the same leading digit. For example, sorting
the problem example in descending order gives 9534303, which is incorrect. The
correct number is obtained by swapping the 3 and the 30. To resolve this, during
each comparison in the sort, we compare the numbers formed by concatenating the
pair in both possible orders. This way we ensure the numbers are sorted
correctly.

So in general we make a local decision by comparing pairs of numbers. For any
two numbers, we decide their order based on which concatenation yields a larger
result. For example, given a and b, it compares a+b (here + denotes string
concatenation not addition) with b+a. If a+b is larger, a is placed before b in
the final sequence.
*/
bool cmp(string &a, string &b)
{
    return (a + b) > (b + a);
}
string largestNumber(vector<int> &nums)
{
    vector<string> numstrings;
    string largestnum = "";

    for (int num : nums)
    {
        numstrings.push_back(to_string(num));
    }

    sort(numstrings.begin(), numstrings.end(), cmp);

    if (numstrings[0] == "0")
        return "0";

    for (string str : numstrings)
        largestnum += str;

    return largestnum;
}

// SECOND METHOD (QUICK SORT)
/*
  Quick Sort uses a divide-and-conquer method to sort the numbers. We start by
selecting a pivot and partitioning the list into two parts based on how each
number compares with the pivot. Specifically, we compare concatenated results
like a + pivot with pivot + a.

We recursively sort the two partitions and then combine them. This recursive
sorting ensures that the entire list is ordered such that concatenating all
numbers results in the largest possible number.

After sorting, we concatenate the numbers. If the final string starts with '0',
it means all numbers were zeros, so we return "0". Otherwise, we return the
concatenated result.
  */
void quickSort(vector<int> &nums, int left, int right);
int partition(vector<int> &nums, int left, int right);
bool compare(int a, int b);

string largestNumber2(vector<int> &nums)
{
    int n = nums.size();
    string largestnum = "";
    quickSort(nums, 0, n - 1);

    for (int num : nums)
    {
        largestnum += to_string(num);
    }

    return largestnum[0] == '0' ? "0" : largestnum;
}
bool compare(int a, int b)
{
    return (to_string(a) + to_string(b)) > (to_string(b) + to_string(a));
}
int partition(vector<int> &nums, int left, int right)
{
    int pivot = nums[right];
    int lowInd = left;
    for (int i = left; i < right; i++)
    {
        if (compare(nums[left], pivot))
        {
            swap(nums[lowInd], nums[i]);
            lowInd++;
        }
    }
    swap(nums[right], nums[lowInd]);
    return lowInd;
}

void quickSort(vector<int> &nums, int left, int right)
{
    if (left >= right)
        return;

    int pivot = partition(nums, left, right);

    quickSort(nums, left, pivot - 1);
    quickSort(nums, pivot + 1, right);
}

// THIRD METHOD (MERGE SORT)
vector<int> merge(vector<int> &leftHalf, vector<int> &rightHalf)
{
    vector<int> sortedArray;
    int first = 0, second = 0;

    while (first < leftHalf.size() && second < rightHalf.size())
    {
        if (compare(leftHalf[first], rightHalf[second]))
            sortedArray.push_back(leftHalf[first++]);
        else
            sortedArray.push_back(rightHalf[second++]);
    }

    while (first < leftHalf.size())
    {
        sortedArray.push_back(leftHalf[first++]);
    }

    while (second < rightHalf.size())
    {

        sortedArray.push_back(rightHalf[second++]);
    }

    return sortedArray;
}

vector<int> mergeSort(vector<int> &nums, int left, int right)
{
    if (left >= right)
        return {nums[left]};

    int mid = left + (right - left) / 2;

    vector<int> leftHalf = mergeSort(nums, left, mid);
    vector<int> rightHalf = mergeSort(nums, mid + 1, right);

    return merge(leftHalf, rightHalf);
}
string largestNumber3(vector<int> &nums)
{
    int n = nums.size();
    nums = mergeSort(nums, 0, n - 1);

    string largestnum = "";

    for (int num : nums)
    {
        largestnum += to_string(num);
    }

    return largestnum[0] == '0' ? "0" : largestnum;
}

// FOURTH METHOD (HEAP SORT)
// Comparison function to sort numbers in a custom order
bool compareString(const string &first, const string &second)
{
    return (first + second) < (second + first);
}
string largestNumber4(vector<int> &nums)
{
    priority_queue<string, vector<string>, decltype(&compareString)> maxheap(&compareString);
    int totalLength = 0;

    // convert integers to strings and push them in to maxheap;
    for (int num : nums)
    {
        string strnum = to_string(num);
        totalLength += strnum.size();
        maxheap.push(strnum);
    }

    // build the result string from the maxheap
    string res = "";
    res.reserve(totalLength); // reserve space for efficiency
    while (!maxheap.empty())
    {
        res += maxheap.top();
        maxheap.pop();
    }
    // Handle edge case where the result might be "000...0"
    return (res.empty() || res[0] == '0') ? "0" : res;
}

int main()
{
    vector<int> nums = {3, 30, 34, 5, 9};
    cout << largestNumber(nums) << endl;
    cout << largestNumber2(nums) << endl;
    cout << largestNumber3(nums) << endl;
    return 0;
}