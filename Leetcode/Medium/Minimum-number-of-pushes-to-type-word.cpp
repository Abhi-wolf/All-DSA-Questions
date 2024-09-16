#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;

bool cmp(pair<char, int> p1, pair<char, int> p2)
{
    return p1.second > p2.second;
}

int minimumPushes(string word)
{
    vector<pair<char, int>> freq2;
    unordered_map<char, int> um2;
    map<char, int> freq1;
    int noOfpushes = 0;

    for (char ch : word)
    {
        if (ch >= 'a' && ch <= 'z')
            freq1[ch]++;
    }

    for (auto x : freq1)
    {
        freq2.push_back({x.first, x.second});
    }

    sort(freq2.begin(), freq2.end(), cmp);

    int num = 2, toPush = 1;
    for (auto x : freq2)
    {
        um2[x.first] = toPush;
        num++;
        if (num == 10)
        {
            toPush += 1;
            num = 2;
        }
    }

    cout << "\n\n";
    for (auto x : freq2)
        cout << x.first << " -- > " << x.second << endl;

    for (char ch : word)
    {
        noOfpushes += um2[ch];
    }

    return noOfpushes;
}

int main()
{
    string w0 = "aabbccddeeffgghhiiiiii";
    string w1 = "xyzxyzxyzxyz";
    string w2 = "abcde";
    string w3 = "abzaqsqcyrbzsrvamylmyxdjl";
    string w4 = "alporfmdqsbhncwyuz";
    // cout << "Pushes = " << minimumPushes(w0) << endl;
    // cout << "Pushes = " << minimumPushes(w1) << endl;
    // cout << "Pushes = " << minimumPushes(w2) << endl;
    cout << "Pushes = \n"
         << minimumPushes(w4) << endl;
    return 0;
}