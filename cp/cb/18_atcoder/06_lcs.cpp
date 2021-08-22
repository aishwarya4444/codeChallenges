/*
https://atcoder.jp/contests/dp/tasks/dp_f
*/

#include<bits/stdc++.h>
using namespace std;

#define ll long long

int dp[3001][3001];
string s, t, res;

int main() {
    int i, j;
    int S, T;

    cin>>s>>t;

    S = s.size();
    T = t.size();

    s = '_'+s;
    t = '_'+t;

    memset(dp, 0, sizeof dp);
    for(i=1; i<=S; i++) {
        for(j=1; j<=T; j++) {
            if(s[i]==t[j]) {
                dp[i][j] = 1+dp[i-1][j-1];
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    i=S;
    j=T;
    while(i>0 && j>0) {
        if(s[i]==t[j]) {
            res += s[i];
            i--;
            j--;
        } else if(dp[i-1][j] > dp[i][j-1]) {
            i--;
        } else {
            j--;
        }
    }

    reverse(res.begin(), res.end());
    cout<<res;

    return 0;
}
