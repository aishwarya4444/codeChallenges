#include <bits/stdc++.h>

using namespace std;

/*
https://codeforces.com/problemset/problem/193/A
*/

unordered_map<int, vector<int> > g;
vector<bool> visited;
vector<int> tin; // time of entry into node
vector<int> low;
unordered_set<int> articulation_points;
vector<vector<bool> > grid;
queue<pair<int, int> > src;
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
	visited.assign(N*M, false);
	tin.assign(N*M, 0);
	low.assign(N*M, 0);
	for(int u=0; u<N*M; u++) {
		if(visited[u] == false) {
			dfs(u, -1);
		}
	}

	cout<<articulation_points.size()<<endl;
}

void buildGraph() {
	vector<pair<int, int> > dirs = {{-1,0}, {0,1}, {1,0}, {0,-1}};

	while(src.size()) {
		int r = src.front().first;
		int c = src.front().second;
		int u = r*M+c;
		src.pop();
		grid[r][c] = false;

		for(auto dir: dirs) {
			int row = r+dir.first;
			int col = c+dir.second;
			int v = row*M+col;
			if(row<0 || row>=N || col<0 || col>=M || grid[row][col]==false) {
				continue;
			}
			src.push({row, col});
			g[u].push_back(v);
			g[v].push_back(u);
		}


	}
}

int main() {

	char ch;

	cin>>N>>M;
	grid = vector<vector<bool> >(N, vector<bool>(M, false));

	for(int r=0; r<N; r++) {
		for(int c=0; c<M; c++) {
			cin>>ch;
			if(ch=='#') {
				grid[r][c] = true;
				if(src.size() == 0) {
					src.push({r, c});
				}
			}
		}
	}

	buildGraph();

	find_articulation_points();


	return 0;
}
