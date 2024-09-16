#include <iostream>
using namespace std;

// https://assets.leetcode.com/users/images/4d8fa0c1-0609-4b5c-a20e-07045e3308c6_1636369013.2969224.png

int numTrees(int n)
{

    long ans = 1;
    for (int i = 1; i < n; i++)
    {
        ans = ans * (n + i + 1) / i;
    }

    return ans / n;
}

int main()
{
    cout << numTrees(3) << endl;
    cout << numTrees(5) << endl;
    return 0;
}