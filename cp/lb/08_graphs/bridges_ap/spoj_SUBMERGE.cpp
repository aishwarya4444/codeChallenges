#include <bits/stdc++.h>

using namespace std;

/*
https://www.spoj.com/problems/SUBMERGE/

articulation points
tarjan

Abdul Bari https://www.youtube.com/watch?v=jFZsDDB0-vo
https://cp-algorithms.com/graph/cutpoints.html

*/

unordered_map<int, vector<int> > g;
vector<bool> visited;
vector<int> tin; // time of entry into node
vector<int> low;
unordered_set<int> articulation_points;
int timer, N, M;

void dfs(int u, int par) {
	int children = 0;

	visited[u] = true;
	tin[u] = low[u] = timer;
	timer++;

	for(int v: g[u]) {
		if(v == par) {
			continue;
		}
		if(visited[v]) {
			// back edge
			low[u] = min(low[u], tin[v]);
		} else {
			dfs(v, u);
			low[u] = min(low[u], low[v]);
			if(low[v]>=tin[u] && par!=-1) {
				// insert in set because "u" might be repeated
				articulation_points.insert(u);
			}
			children++;
		}
	}

	// par==-1 is for arbitrarily chosen root
	if(par==-1 && children>1) {
		articulation_points.insert(u);
	}
}

void find_articulation_points() {
	timer = 1;
	visited.assign(N+1, false);
	tin.assign(N+1, 0);
	low.assign(N+1, 0);
	for(int u=1; u<=N; u++) {
		if(visited[u] == false) {
			dfs(u, -1);
		}
	}

	cout<<articulation_points.size()<<endl;
}

int main() {

	int u, v;

	while(true) {
		cin>>N>>M;
		if(N==0 && M==0) {
			break;
		}

		g.clear();
		visited.clear();
		tin.clear();
		low.clear();
		articulation_points.clear();
		while(M--) {
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}

		find_articulation_points();
	}


	return 0;
}
