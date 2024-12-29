#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <unordered_map>
using namespace std;

vector<vector<int>> findTriplets(vector<int> &arr)
{
	int size = arr.size();
	vector<vector<int>> res;
	unordered_map<int, vector<pair<int, int>>> um;
	set<vector<int>> st;

	for (int i = 0; i < size; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			int sum = arr[i] + arr[j];

			um[sum].push_back(make_pair(i, j));
		}
	}

	for (int i = 0; i < size; i++)
	{
		int req = 0 - arr[i];

		if (um.find(req) != um.end())
		{
			cout << "found \n";
			vector<pair<int, int>> pairs = um[req];

			for (auto p : pairs)
			{
				if (p.first != i && p.second != i)
				{
					vector<int> triplet = {i, p.first, p.second};
					sort(triplet.begin(), triplet.end());
					st.insert(triplet);
				}
			}
		}
	}

	for (auto x : st)
		res.push_back(x);

	return res;
}

void Display2DArray(vector<vector<int>> arr)
{
	cout << endl;
	for (int i = 0; i < arr.size(); i++)
	{
		for (int j = 0; j < arr[0].size(); j++)
		{
			cout << arr[i][j] << " , ";
		}
		cout << endl;
	}
}

int main()
{
	// vector<int> arr = {0, -1, 2, -3, 1};
	vector<int> arr = {1, -2, 1, 0, 5};
	vector<vector<int>> ans = findTriplets(arr);
	Display2DArray(ans);
	return 0;
}