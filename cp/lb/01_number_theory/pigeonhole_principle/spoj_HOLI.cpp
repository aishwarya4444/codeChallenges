/*
http://zobayer.blogspot.com/2014/01/spoj-holi.html
https://programmersought.com/article/87903061702/
http://dipusnotebook.blogspot.com/2019/01/spoj-holi-holiday-accommodation.html
*/

/*
unordered_map gives TLE
vector passes through
*/
#include <bits/stdc++.h>
using namespace std;

int N;
long long total;
// unordered_map<long, unordered_map<long, long> > g;
vector<pair<int, int> > g[100006];

int dfs(int par=-1, int u=1) {
	int v, w, count=1, nodes;

	for(auto entry: g[u]) {
		v = entry.first;
		w = entry.second;
		if(v == par) {
			continue;
		}
		nodes = dfs(u, v);
		total += 2*min(N-nodes, nodes)*w;
		count += nodes;
	}
	return count;
}

int main() {
	int n, t, T;
	int X, Y, Z;

	cin>>T;

	for(t=1; t<=T; t++) {
		cin>>N;

		total = 0;
		for(n=1; n<=N; n++) {
			g[n].clear();
		}

		for(n=1; n<N; n++) {
			cin>>X>>Y>>Z;
			// g[X][Y] = Z;
			// g[Y][X] = Z;
			g[X].push_back({Y, Z});
			g[Y].push_back({X, Z});
		}

		dfs();
		cout<<"Case #"<<t<<": "<<total<<'\n';
	}

	return 0;
}



/************
    TLE
*************/
#include <bits/stdc++.h>
using namespace std;

int N;
unordered_map<long, unordered_map<long, long> > g;
vector<bool> visited;

long countNodes(long u) {
	long count = 1, v;

	if(visited[u]) {
		return 0;
	}
	visited[u] = true;
	for(auto entry: g[u]) {
		v = entry.first;
		count += countNodes(v);
	}
	visited[u] = false;
	return count;
}

long long dist() {
	long long total = 0;
	long u, v, w, count;

	for(auto entry: g) {
		u = entry.first;
		visited[u] = true;
		for(auto ent: g[u]) {
			v = ent.first;
			w = ent.second;
			if(g[u][v] == 0 || g[v][u] == 0) {
				continue;
			}
			count = countNodes(v);
			count = min(count, N-count);
			total += 2*count*w;
			g[u][v] = 0;
			g[v][u] = 0;
		}
		visited[u] = false;
	}
	return total;
}

int main() {
	int n, t, T;
	long X, Y, Z;

	cin>>T;

	for(t=1; t<=T; t++) {
		cin>>N;

		visited = vector<bool>(N+1, false);
		g.clear();

		for(n=1; n<N; n++) {
			cin>>X>>Y>>Z;
			g[X][Y] = Z;
			g[Y][X] = Z;
		}

		cout<<"Case #"<<t<<": "<<dist()<<'\n';
	}

	return 0;
}