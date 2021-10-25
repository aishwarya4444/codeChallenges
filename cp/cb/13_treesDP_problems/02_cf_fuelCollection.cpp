/*
https://codeforces.com/problemset/problem/1084/D

Let's write on edge with length 𝑙 number −𝑙.
Let sum on the path be sum of amounts of gasoline,
which can be bought in cities on this path plus sum of the numbers,
which were written on its edges.

If we don't run out of gasoline on some path,
sum on it will be equal to amount of gasoline at the end of way.
If we run out of gasoline on a path, we can start from the next city after the road,
where it happened, and sum on the path won't decrease.
So, there is a path with maximal sum, where we don't run out of gasoline.
This sum is answer to the problem.

How to find it?
Let 𝑑𝑝𝑖 is maximal sum on vertical way, which starts in vertex 𝑖.
It is not difficult to calculate 𝑑𝑝𝑖, using 𝑑𝑝 values for children of vertex 𝑖.
Every way can be divided to two vertical ways, so we can calculate answer by turning over 𝑖,
which is the highest vertex of a path, and taking the two biggest vertical ways, which starts from vertex 𝑖.

https://codeforces.com/contest/1083/submission/46860277
https://codeforces.com/contest/1083/submission/47500044
https://codeforces.com/contest/1084/submission/46973541
*/

#include<bits/stdc++.h>
using namespace std;

#define ll long long

const int maxN = 300001;
ll w[maxN];
ll dp[maxN];
ll ans = 0;
int n;
unordered_map<int, ll> c[maxN];

void dfs(int curr, int par) {
    dp[curr] = w[curr];
    ans = max(ans, dp[curr]);

    for(auto entry: c[curr]) {
        int child = entry.first;
        int cost = entry.second;
        if(child == par) {
            continue;
        }
        dfs(child, curr);
        ans      = max(ans,     dp[curr] - cost + dp[child]);
        dp[curr] = max(dp[curr], w[curr] - cost + dp[child]);

    }
}

int main() {
    int ui, vi, cost;

    cin >> n;

    for(int u=1; u<=n; u++) {
        cin>>w[u];
    }

    for(int u=2; u<=n; u++) {
        cin>>ui>>vi>>cost;
        c[ui][vi] = cost;
        c[vi][ui] = cost;
    }

    dfs(1, 0);

    cout<<ans;

    return 0;
}
