#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;


int maxCount(vector<int>& banned, int n, int maxSum) {
        unordered_set<int>st;
        int start=1,sum=0,cnt=0;
        for(int num:banned) st.insert(num);


        while(start<=n) {
            if(st.count(start)==0) {
                sum += start;
                cnt++;
            }
            if(sum>maxSum) return cnt-1;
            start++;
        }

        return cnt;
    }

int main() {
    vector<int>banned1={1,6,5};
    vector<int>banned2={1,2,3,4,5,6,7};
    vector<int>banned3={11};

    cout<<"Result = "<<maxCount(banned1, 5, 6)<<endl;
    cout<<"Result = "<<maxCount(banned2, 8, 1)<<endl;
    cout<<"Result = "<<maxCount(banned3, 7, 50)<<endl;

    return 0;
}
