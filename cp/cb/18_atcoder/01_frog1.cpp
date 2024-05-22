/*
https://atcoder.jp/contests/dp/tasks/dp_a
*/

#include<bits/stdc++.h>
using namespace std;

#define ll long long

int n;
int h[100001];
ll dp[100001];

ll solve(int i) {
    if(i == n) {
        return 0;
    }

    if(dp[i] != -1) {
        return dp[i];
    }

    ll ans = INT_MAX;

    for(int j=i+1; j<=i+2; j++) {
        if(j>n) continue;
        ans = min( ans, abs(h[i]-h[j]) + solve(j) );
    }

    return dp[i] = ans;
}

int main() {
    cin>>n;
    for(int i=1; i<=n; i++) {
        cin>>h[i];
    }
    memset(dp, -1, sizeof dp);
    cout<<solve(1);

    return 0;
}
