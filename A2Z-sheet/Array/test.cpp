#include <iostream>
using namespace std;

// not working
void solve(int x, int y, int steps, int &ans)
{

    if (x > 40 || y > 10001 || x < 1)
        return;

    if (x == y)
    {
        cout << "Equal\n";
        ans = min(ans, steps);
        return;
    }

    if (x % 11 == 0)
        solve(x / 11, y, steps + 1, ans);
    if (x % 5 == 0)
        solve(x / 5, y, steps + 1, ans);

    // solve(x + 1, y, steps + 1, ans);
    // solve(x - 1, y, steps + 1, ans);
}

int minimumOperationsToMakeEqual(int x, int y)
{
    int ans = 100000;
    solve(x, y, 0, ans);
    return ans;
}
int main()
{
    cout << minimumOperationsToMakeEqual(55, 5) << endl;
    return 0;
}