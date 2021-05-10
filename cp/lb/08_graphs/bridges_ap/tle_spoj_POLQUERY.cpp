/*
https://www.spoj.com/problems/POLQUERY/

https://codeforces.com/blog/entry/14167
https://github.com/yancouto/maratona-sua-mae/blob/master/Yan/spoj/polquery.cpp
https://github.com/IvanIsCoding/OlympiadSolutions/blob/master/SPOJ/POLQUERY.cpp
https://github.com/gabrielrussoc/competitive-programming/blob/master/spoj/polquery.cpp
*/
#include <bits/stdc++.h>
using namespace std;

unordered_map<int, vector<int> > g;
vector<bool> visited;
vector<int> tin; // time of entry into node
vector<int> low;
unordered_map<int, unordered_set<int> > bridges;
unordered_set<int> articulation_points;
int timer, N, E, Q;
int A, B, C, G1, G2;

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
			if(low[v]>tin[u]) {
				bridges[v].insert(u);
			    bridges[u].insert(v);
			}
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

void find_bridges_and_articulation_points() {
	timer = 1;
	visited.assign(N+1, false);
	tin.assign(N+1, 0);
	low.assign(N+1, 0);
	for(int u=1; u<=N; u++) {
		if(visited[u] == false) {
			dfs(u, -1);
		}
	}
}

void dfsAB(int u, int des, vector<int> &path, vector<int> &result) {
	visited[u] = true;
	path.push_back(u);
	if(u == des) {
		result = path;
		return;
	}

	for(int v: g[u]) {
		if(visited[v]==false) {
			dfsAB(v, des, path, result);
		}
	}
	path.pop_back();
}

void isBridge() {
	vector<int> path, result;

	if(bridges[G1].count(G2) == 0) {
		cout<<"da\n";
		return;
	}
	visited.assign(N+1, false);
	dfsAB(A, B, path, result);
	if(find(result.begin(), result.end(), G1) != result.end()
		&& find(result.begin(), result.end(), G2) != result.end()) {
		cout<<"ne\n";
	} else {
		cout<<"da\n";
	}
}

void isAP() {
	vector<int> path, result;

	if(articulation_points.count(C) == 0) {
		cout<<"da\n";
		return;
	}
	visited.assign(N+1, false);
	visited[C] = true;
	dfsAB(A, B, path, result);
	if(visited[B]) {
		cout<<"da\n";
	} else {
		cout<<"ne\n";
	}
}

int main() {

	int u, v, query;

	cin>>N>>E;

	while(E--) {
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	find_bridges_and_articulation_points();

	cin>>Q;
	while(Q--) {
		cin>>query;
		if(query==1) {
			cin>>A>>B>>G1>>G2;
			isBridge();
		} else {
			cin>>A>>B>>C;
			isAP();
		}
	}


	return 0;
}
