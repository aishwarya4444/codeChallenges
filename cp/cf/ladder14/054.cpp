/*
https://codeforces.com/problemset/problem/427/C
*/

#include<bits/stdc++.h>
#define ll long long
using namespace std;

unordered_map<int, vector<int> > gr;
unordered_map<int, vector<int> > rg;
unordered_map<int, vector<int> > rep;
vector<bool> visited;
vector<int> cost;
stack<int> st;
const int mod = 1e9+7;

void dfs1(int u) {
    visited[u] = true;

    for(int v: gr[u]) {
        if(!visited[v]) {
            dfs1(v);
        }
    }

    st.push(u);
}

void dfs2(int u, int label) {
    visited[u] = true;
    rep[label].push_back(cost[u]);

    for(int v: rg[u]) {
        if(!visited[v]) {
            dfs2(v, label);
        }
    }
}

int main() {
    int n, m, u, v, label;

    cin>>n;

    cost.assign(n+1, 0);

    for(int i=1; i<=n; i++) {
        cin>>cost[i];
    }

    cin>>m;
    for(int i=1; i<=m; i++) {
        cin>>u>>v;
        gr[u].push_back(v);
        rg[v].push_back(u);
    }

    visited.assign(n+1, false);
    for(int i=1; i<=n; i++) {
        if(visited[i]==false) {
            dfs1(i);
        }
    }

    visited.assign(n+1, false);
    label = 1;
    while(st.size()) {
        u = st.top();
        st.pop();
        if(!visited[u]) {
            dfs2(u, label);
            label++;
        }
    }

    ll totalCost = 0LL;
    int minValue;
    int count;
    ll ways = 1LL;
    for(auto entry: rep) {
        minValue = INT_MAX;
        count = 0;
        for(auto price: entry.second) {
            if(minValue == price) {
                count++;
            } else if(minValue>price) {
                minValue = price;
                count = 1;
            }
        }
        totalCost += minValue;
        ways = (ways*count)%mod;
    }

    cout<<totalCost<<' '<<ways;

    return 0;

}
