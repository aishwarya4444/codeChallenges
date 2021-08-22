/*
https://atcoder.jp/contests/dp/tasks/dp_i
*/

#include<bits/stdc++.h>
using namespace std;

#define ll long long

int n;
// use double instead of float
double p[3000];
double dp[3000][3000];

double solve(int i, int heads) {
    if(i==n) {
        return heads > n-heads;
    }

    // if(dp[i][heads] != 0) {
    if(dp[i][heads] > -1) {
        return dp[i][heads];
    }

    double ans = p[i]*solve(i+1, heads+1) + (1.0-p[i])*solve(i+1, heads);

    return dp[i][heads] = ans;
}
int main() {
    cin>>n;

    for(int i=0; i<n; i++) {
        cin>>p[i];
    }

    memset(dp, -1, sizeof dp);

    // cout<<fixed<<setprecision(10)<<solve(0, 0);
    printf("%.10lf", solve(0, 0));

    return 0;
}

