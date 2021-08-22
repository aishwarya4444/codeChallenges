/*
https://atcoder.jp/contests/dp/tasks/dp_g
*/

#include<bits/stdc++.h>
using namespace std;

#define ll long long

int n, m, ans;
vector<int> g[100001];
int dp[100001];

int dfs(int u) {
    if(dp[u] != -1) {
        return dp[u];
    }

    int res = 0;
    for(int v: g[u]) {
        res = max(res, 1+dfs(v));
    }
    return dp[u] = res;
}

int main() {
    int x, y;

    cin>>n>>m;

    for(int i=1; i<=m; i++) {
        cin>>x>>y;
        g[x].push_back(y);
    }

    memset(dp, -1, sizeof dp);
    for(int i=1; i<=n; i++) {
        if(dp[i] == -1) {
            ans = max(ans, dfs(i));
        }
    }

    cout<<ans;

    return 0;
}
