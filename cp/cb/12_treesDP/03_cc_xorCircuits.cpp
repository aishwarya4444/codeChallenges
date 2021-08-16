/*
https://www.codechef.com/problems/DAGXOR

Sanyam Solution
https://www.codechef.com/viewsolution/26764380
*/

#include<bits/stdc++.h>
using namespace std;

#define ll long long

vector<int> tree[100001];
int t, n;
int dp[100001][4];
const int mod = 1e9+7;

int dfs(int u, int xo, int par) {
    if(u==n) {
        return (xo==0);
    }

    if(dp[u][xo] != -1) {
        return dp[u][xo];
    }

    int ans = 0;
    bool isLeaf = true;

    for(int x=0; x<4; x++) {
        ll val = 1;
        for(int v: tree[u]) {
            if(v != par) {
                isLeaf = false;
                val = (val * dfs(v, xo^x, u)) % mod;
            }
        }
        ans = (ans + val) % mod;
    }

    if(isLeaf) {
        ans = 0;
        for(int x=0; x<4; x++) {
            // all leaves are connected to "n"
            ans = (ans + 1LL*dfs(n, xo^x, u)) % mod;
        }
    }

    return dp[u][xo] = ans;
}

int main() {
    int u, v;

    cin>>t;
    while(t--) {
        cin>>n;

        for(int i=1; i<=n-2; i++) {
            cin>>u>>v;
            tree[u].push_back(v);
            tree[v].push_back(u);
        }

        ll res = 0;
        // for(int x=0; x<4; x++) {
        //     memset(dp, -1, sizeof dp);
        //     res = (res + 1LL*dfs(1, x, 0)) % mod;
        // }
        // cases of xor 0/1/2/3 are symmetric
        // calculate once and multiply by 4
        memset(dp, -1, sizeof dp);
        res = (4LL*dfs(1, 0, 0)) % mod;
        cout<<res<<endl;

        for(int i=1; i<=n; i++) {
            tree[i].clear();
        }
    }

    return 0;
}
