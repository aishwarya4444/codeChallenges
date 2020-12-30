/*
https://www.spoj.com/problems/GCPC11J/
                # bfs twice
*/

#include <bits/stdc++.h>
using namespace std;

#define MAX 100000

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

	return make_pair(u, level);
}

int main() {
	int u, v, n, N, T;

	cin>>T;
	while(T--) {
		cin>>N;

		for(n=0; n<N; n++) {
			g[n].clear();
		}

		for(n=1; n<N; n++) {
			cin>>u>>v;

			g[u].push_back(v);
			g[v].push_back(u);
		}

		cout<<bfs(bfs(1).first).second/2<<endl;
	}

	return 0;
}
