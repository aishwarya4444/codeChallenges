/*
https://codeforces.com/problemset/problem/115/A
*/

#include <bits/stdc++.h>
using namespace std;

int indegree[2001];
vector<int> g[2001];

int dfs(int u) {
	int height = 0;

	for(int v: g[u]) {
		height = max(height, dfs(v));
	}

	return 1+height;
}

int main() {
	int n, u, v, group=0;

	cin>>n;
	for(v=1; v<=n; v++) {
		// u -> v
		cin>>u;
		if(u != -1) {
			indegree[v]++;
			g[u].push_back(v);
		}
	}

	for(u=1; u<=n; u++) {
		if(indegree[u] == 0) {
			group = max(group, dfs(u));
		}
	}

	cout<<group;

	return 0;
}