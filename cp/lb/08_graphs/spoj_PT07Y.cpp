/*
https://www.spoj.com/problems/PT07Y/

        # logic for graph to be tree:
        #       [a] graph is tree if SCC count = 1
        #       [b] number of nodes - 1 = number of edges
        # approaches:
        #       [a] dfs
        #       [b] union find
*/

// dfs
#include <bits/stdc++.h>
using namespace std;

unordered_map<int, vector<int> > g;
vector<bool> visited;

void dfs(int u) {
	if(visited[u]) {
		return;
	}

	visited[u] = true;
	for(auto v: g[u]) {
		dfs(v);
	}

}

int main() {
	int u, v, N, M;
	bool isTree = true;

	cin>>N>>M;
	if(M != N-1) {
		cout<<"NO\n";
		return 0;
	}

	visited = vector<bool>(N+1, false);

	while(M--) {
		cin>>u>>v;

		g[u].push_back(v);
		g[v].push_back(u);
	}


	dfs(u);

	for(u=1; u<=N; u++) {
		if(visited[u] == false) {
			isTree = false;
			break;
		}
	}

	if(isTree) {
		cout<<"YES\n";
	} else {
		cout<<"NO\n";
	}

	return 0;
}


// union find
#include <bits/stdc++.h>
using namespace std;

vector<int> nodes;

int _find(int n) {
	if(nodes[n] == n) {
		return n;
	}
	return nodes[n] = _find(nodes[n]);
}

void _union(int a, int b) {
	int n1 = _find(a), n2 = _find(b);
	if(n1 == n2) {
		return;
	}
	nodes[n1] = n2;
}

int main() {
	int u, v, N, M, count=0;

	cin>>N>>M;
	if(M != N-1) {
		cout<<"NO\n";
		return 0;
	}

	nodes = vector<int>(N+1, 0);
	for(u=1; u<=N; u++) {
		nodes[u] = u;
	}

	while(M--) {
		cin>>u>>v;

		_union(u, v);
	}


	for(u=1; u<=N; u++) {
		if(count>1) {
			break;
		}
		if(nodes[u] == u) {
			count++;
		}
	}

	if(count==1) {
		cout<<"YES\n";
	} else {
		cout<<"NO\n";
	}

	return 0;
}
