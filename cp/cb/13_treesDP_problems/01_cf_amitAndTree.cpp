/*
https://codeforces.com/problemset/problem/682/C
https://codeforces.com/blog/entry/45491

Let's do dfs.
Suppose that we now stand at the vertex u.
Let v be some ancestor of vertex u.
Then dist(v,u) = dist(1,u)-dist(1,v).
If dist(v,u)>au, then the vertex u makes v sad.
So you must remove the whole subtree of vertex u.
Accordingly, it is possible to maintain a minimum among dist(1,v) in dfs,
where v is ancestor of u (vertex, in which we now stand).
And if the difference between the dist(1,u) and that minimum is greater than au, then remove au with the whole subtree.

https://codeforces.com/contest/682/submission/100718194
*/

#include<bits/stdc++.h>
using namespace std;

#define ll long long

ll a[100001];
int ans = 0;
int n;
unordered_map<int, ll> c[100001];

void dfs(int curr, int par, ll len, ll minLen) {
    if(len - minLen > a[curr]) {
        return;
    }
    ans++;

    minLen = min(minLen, len);

    for(auto entry: c[curr]) {
        int child = entry.first;
        if(child == par) {
            continue;
        }
        dfs(child, curr, len+entry.second, minLen);
    }
}

int main() {
    int ui, vi, cost;

    cin >> n;

    for(int u=1; u<=n; u++) {
        cin>>a[u];
    }

    for(int u=2; u<=n; u++) {
        cin>>ui>>vi>>cost;
        c[ui][vi] = cost;
        c[vi][ui] = cost;
    }

    dfs(1, 0, 0, INT_MAX);

    cout<<n-ans;

    return 0;
}