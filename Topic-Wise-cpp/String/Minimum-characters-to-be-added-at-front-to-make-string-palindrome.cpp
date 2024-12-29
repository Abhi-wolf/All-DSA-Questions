#include <iostream>
#include <limits.h>
using namespace std;

int minChars(string str) {
    int n=str.size()-1;
    int mid=(n+1)/2,minAns=INT_MAX;

    for(int i=mid;i>=0;i--) {
        int left=i-1,right=i+1;

        while(left>=0 && right<=n && str[left]==str[right]) {
            left--;
            right++;
        }

        if(left==-1 || right==n+1) {
            int noOfCharsLeft=(left-0+1) + (n-right+1);
            minAns=min(minAns,noOfCharsLeft);
            cout<<"mid = "<<i<<" --> "<<"left = "<<left<<", right = "<<right<<" --> rem = "<<noOfCharsLeft<<"\n";
        }
    }

    for(int i=mid+1;i<=n;i++) {
        int left=i-1,right=i+1;

        while(left>=0 && right<=n && str[left]==str[right]) {
            left--;
            right++;
        }

        if(left==-1 || right==n+1) {
            int noOfCharsLeft=(left-0+1) + (n-right+1);
            minAns=min(minAns,noOfCharsLeft);
            cout<<"mid = "<<i<<" --> "<<"left = "<<left<<", right = "<<right<<" --> rem = "<<noOfCharsLeft<<"\n";
        }
    }

    return minAns;
}

int main() {
    string str1="aacecaaaa";
    string str2="abc";
    string str3="abcdefe";
    string str4="abcdefedcb";
    string str5="abcdefedcba";
    string str6="cbaabcdeedbeecaebbebcbbaabcdeedbeecaebbebcbbaabcdeedbeecaebbebcbadeabaabcdeedbeecaebbebcbbaabcdeedbeecaebbebcbadbaabcdeedbeecaebbebcbbaabcdeedbeecaebbebcbbaabcdeedbeecaebbebcbbaabcdeedbeecaebbebcbbaabcdeedbeecaebbebcbcbaabcdeedbeecaebbebcbbaabcdeedbeecaebbebcbbaabcdeedbeecaebbebcbbaabcdeedbeecaebbebcbbaabcdeedbeecaebbebcbcbeeccbdbbbaabcdeedbeecaebbebcbbaabcdeedbeecaebbebcbdbaabcdeedbeecaebbebcbddebccbbaabcdeedbeecaebbebcbcbddcdbaabcdeedbeecaebbebcbebaabcdeedbeecaebbebcbdabaabcdeedbeecaebbebcbcebaabcdeedbeecaebbebcbbaabcdeedbeecaebbebcbebaabcdeedbeecaebbebcbdcbaabcdeedbeecaebbebcbebbbaabcdeedbeecaebbebcbbbaabcdeedbeecaebbebcbcbaabcdeedbeecaebbebcbdeabedaebaabcdeedbeecaebbebcbecbaabcdeedbeecaebbebcbbaabcdeedbeecaebbebcbbaabcdeedbeecaebbebcbcbaabcdeedbeecaebbebcbbaabcdeedbeecaebbebcbbaabcdeedbeecaebbebcbbaabcdeedbeecaebbebcbbaabcdeedbeecaebbebcbebaabcdeedbeecaebbebcbbbbaabcdeedbeecaebbebcbbaeccbaabcdeedbeecaebbebcbdbecedbaabcdeedbeecaebbebcbbaabcdeedbeecaebbebcbdbaabcdeedbeecaebbebcbdbaabcdeedbeecaebbebcb";

    cout<<str6.size()<<endl;



    // cout<<"Ans1 = "<<minChars(str1)<<"\n\n";
    // cout<<"Ans2 = "<<minChars(str2)<<"\n\n";
    // cout<<"Ans3 = "<<minChars(str3)<<"\n\n";
    // cout<<"Ans4 = "<<minChars(str4)<<"\n\n";
    cout<<"Ans5 = "<<minChars(str6)<<"\n\n";

    return 0;
}
