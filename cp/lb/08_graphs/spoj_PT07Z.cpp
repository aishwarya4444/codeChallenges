/*
https://www.spoj.com/problems/PT07Z/
Longest path in a tree

https://www.geeksforgeeks.org/longest-path-undirected-tree/

                * bfs twice
*/

// short code
#include <bits/stdc++.h>
using namespace std;

#define MAX 10000

vector<int> g[1+MAX];
vector<bool> visited;

pair<int, int> bfs(int u) {
	queue<int> q;
	int level = 0, L;

	visited = vector<bool>(1+MAX, false);
	q.push(u);
	while(q.size()) {
		L = q.size();
		level++;
		while(L--) {
			u = q.front();
			q.pop();
			if(visited[u]) {
				continue;
			}
			visited[u] = true;
			for(auto v: g[u]) {
				if(visited[v]) {
					continue;
				}
				q.push(v);
			}
		}
	}

	return make_pair(u, level-1);
}

int main() {
	int u, v, n, N;

	cin>>N;

	for(n=1; n<N; n++) {
		cin>>u>>v;

		g[u].push_back(v);
		g[v].push_back(u);
	}

	cout<<bfs(bfs(1).first).second<<endl;

	return 0;
}


// long code
#include <bits/stdc++.h>
using namespace std;

vector<int> g[10001];
vector<bool> visited;

int main() {
	int u, v, n, N, L, level;
	queue<int> q, _q;

	cin>>N;

	for(n=1; n<N; n++) {
		cin>>u>>v;

		g[u].push_back(v);
		g[v].push_back(u);
	}

	// bfs 1
	visited = vector<bool>(N+1, false);
	q.push(1);
	while(q.size()) {
		L = q.size();

		while(L--) {
			u = q.front();
			q.pop();
			if(visited[u]) {
				continue;
			}
			visited[u] = true;
			for(auto node: g[u]) {
				if(visited[node]) {
					continue;
				}
				q.push(node);
			}
		}
	}

	// bfs 2
	visited = vector<bool>(N+1, false);
	q.push(u);
	level = 0;
	while(q.size()) {
		level++;
		L = q.size();
		while(L--) {
			u = q.front();
			q.pop();
			if(visited[u]) {
				continue;
			}
			visited[u] = true;
			for(auto node: g[u]) {
				if(visited[node]) {
					continue;
				}
				q.push(node);
			}
		}
	}

	cout<<level-1<<endl;

	return 0;
}