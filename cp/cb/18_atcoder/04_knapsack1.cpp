/*
https://atcoder.jp/contests/dp/tasks/dp_d
*/

#include<bits/stdc++.h>
using namespace std;

#define ll long long

int N, W;
int w[101];
int v[101];

ll dp[101][100001];

ll solve(int i, int wt) {
    if(wt==W || i>N) {
        return 0;
    }

    if(dp[i][wt] != -1) {
        return dp[i][wt];
    }

    ll ans = solve(i+1, wt);

    if(wt+w[i] <= W) {
        ans = max(ans, v[i] + solve(i+1, wt+w[i]));
    }

    return dp[i][wt] = ans;
}

int main() {
    cin>>N>>W;

    for(int i=1; i<=N; i++) {
        cin>>w[i]>>v[i];
    }
    memset(dp, -1, sizeof dp);
    cout<<solve(1, 0);

    return 0;
}
