/*
https://atcoder.jp/contests/dp/tasks/dp_c
*/

#include<bits/stdc++.h>
using namespace std;

#define ll long long

int n;
int v[100001][3];
int dp[100001][2][2][2];

int solve(int i, int a, int b, int c) {
    if(i==n) {
        return 0;
    }

    if(dp[i][a][b][c] != -1) {
        return dp[i][a][b][c];
    }

    int ans = 0;

    if(a==0) {
        ans = max(ans, v[i][0]+solve(i+1, 1, 0, 0));
    }
    if(b==0) {
        ans = max(ans, v[i][1]+solve(i+1, 0, 1, 0));
    }
    if(c==0) {
        ans = max(ans, v[i][2]+solve(i+1, 0, 0, 1));
    }

    return dp[i][a][b][c] = ans;
}

int main() {
    cin>>n;

    for(int i=0; i<n; i++) {
        cin>>v[i][0]>>v[i][1]>>v[i][2];
    }
    memset(dp, -1, sizeof dp);
    cout<<solve(0, 0, 0, 0);

    return 0;
}
