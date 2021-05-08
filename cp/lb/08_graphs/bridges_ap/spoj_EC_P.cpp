#include <bits/stdc++.h>

using namespace std;

/*
https://www.spoj.com/problems/EC_P/

https://leetcode.com/problems/critical-connections-in-a-network/
Abdul Bari https://www.youtube.com/watch?v=jFZsDDB0-vo
https://cp-algorithms.com/graph/bridge-searching.html

tarjan
slightly different from cutpoints

used following to avoid TLE:
[1] map instead of vector for edges
[2] avoid sort
[3] use scanf
*/

unordered_map<int, vector<int> > g;
vector<bool> visited;
vector<int> tin; // time of entry into node
vector<int> low;
// vector<pair<int, int> > edges;
int timer, N, M, bridges;
map<int, set<int> > edges;

void dfs(int u, int par) {
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
			if(low[v]>tin[u]) {
				if(u<v) {
					// edges.push_back({u, v});
					edges[u].insert(v);
				} else {
					// edges.push_back({v, u});
					edges[v].insert(u);
				}
				bridges++;
			}
		}
	}
}

void find_bridges(int nc) {
	bridges = 0;
	timer = 1;
	visited.assign(N+1, false);
	tin.assign(N+1, 0);
	low.assign(N+1, 0);
	for(int u=1; u<=N; u++) {
		if(visited[u] == false) {
			dfs(u, -1);
		}
	}

	cout<<"Caso #"<<nc<<endl;
	if(bridges == 0) {
		cout<<"Sin bloqueos\n";
	} else {
		// sort(edges.begin(), edges.end(), [](const pair<int, int> &e1, const pair<int, int> &e2) {
		// 	if(e1.first == e2.first) {
		// 		return e1.second<e2.second;
		// 	}
		// 	return e1.first<e2.first;
		// });
		// sort(edges.begin(), edges.end());
		cout<<bridges<<endl;
		// for(auto edge: edges) {
		// 	cout<<edge.first<<" "<<edge.second<<endl;
		// }
		for(auto entry: edges) {
			int u = entry.first;
			for(int v: entry.second) {
				cout<<u<<" "<<v<<endl;
			}
		}
	}
}

int main() {

	int nc, NC, u, v;

	scanf("%d", &NC);

	for(nc=1; nc<=NC; nc++) {
		scanf("%d%d", &N, &M);

		g.clear();
		visited.clear();
		tin.clear();
		low.clear();
		edges.clear();
		while(M--) {
			scanf("%d%d", &u, &v);
			g[u].push_back(v);
			g[v].push_back(u);
		}

		find_bridges(nc);
	}

	return 0;
}
