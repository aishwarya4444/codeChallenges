/*
https://www.codechef.com/problems/FAMTREE

Sanyam Solution
https://www.codechef.com/viewsolution/26755182
*/

#include<bits/stdc++.h>
using namespace std;

#define ll long long

vector<int> tree[100001];
int min_wt[100001];
int max_wt[100001];
int wt[100001];
int n;
int ans;

void dfs(int u, int par) {

    int minWt = INT_MAX, maxWt = INT_MIN;
    for(int v: tree[u]) {
        if(v != par) {
            dfs(v, u);
            minWt = min(minWt, min_wt[v]);
            maxWt = max(maxWt, max_wt[v]);
        }
    }

    min_wt[u] = min(wt[u], minWt);
    max_wt[u] = max(wt[u], maxWt);

    if(tree[u].size() != 0) {
        ans = max({ans, abs(wt[u]-minWt), abs(wt[u]-maxWt)});
    }
}

int main() {
    int par, v, root;

    cin>>n;
    for(int v=1; v<=n; v++) {
        cin>>wt[v];
    }

    for(int v=1; v<=n; v++) {
        cin>>par;
        if(par == -1) {
            root = v;
        } else {
            tree[par].push_back(v);
        }
    }

    dfs(root, -1);

    cout<<ans;

    return 0;
}
