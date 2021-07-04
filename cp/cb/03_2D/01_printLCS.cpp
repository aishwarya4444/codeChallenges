#include<bits/stdc++.h>
#define ll long long
using namespace std;

string a, b;
int dp[1001][1001];

int main() {
    string result="";

    cin>>a;
    cin>>b;

    for(int r=1; r<=a.size(); r++) {
        for(int c=1; c<=b.size(); c++) {
            if(a[r-1]==b[c-1]) {
                dp[r][c] = 1+dp[r-1][c-1];
            } else {
                dp[r][c] = max(dp[r][c-1], dp[r-1][c]);
            }
        }
    }

    int r=a.size(), c=b.size();
    while(r>0 && c>0) {
        if(a[r-1]==b[c-1]) {
            result = a[r-1]+result;
            r--;
            c--;
        } else if(dp[r-1][c]>dp[r][c-1]) {
            r--;
        } else {
            c--;
        }
    }

    cout<<result;

    return 0;

}
