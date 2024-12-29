#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int hIndex(vector<int>& citations) {
    sort(citations.begin(),citations.end());
            int ans=0,n=citations.size();

            for(int i=n-1;i>=0;i--) {
                ans=max(ans,min(citations[i],(n-i)));
            }

            return ans;
    }

int main() {
    vector<int>citations1={3, 0, 5, 3, 0};
    vector<int>citations2={5, 1, 2, 4, 1};
    vector<int>citations3={0,0};
    vector<int>citations4={8, 12, 10, 12, 9, 12};

    cout<<"Answer = "<<hIndex(citations1)<<endl;
    cout<<"Answer = "<<hIndex(citations2)<<endl;
    cout<<"Answer = "<<hIndex(citations3)<<endl;
    cout<<"Answer = "<<hIndex(citations4)<<endl;

    return 0;
}
