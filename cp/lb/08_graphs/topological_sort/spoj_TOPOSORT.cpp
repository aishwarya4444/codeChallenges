/*
https://www.spoj.com/problems/TOPOSORT/
https://www.spoj.com/problems/TOPOSORT2/

https://github.com/arpitbbhayani/spoj/blob/master/TOPOSORT.cpp
https://mysolutions4you.wordpress.com/2018/10/25/spoj-toposorttopological-sorting-solution/
*/

#include <bits/stdc++.h>

using namespace std;

struct comparator {
	bool operator()(const int &n1, const int &n2) {
		return n1 > n2;
	}
};
map<int, set<int>> g;
vector<int> indegree;
priority_queue<int, vector<int>, comparator> src;
queue<int> order;
int n, m, x, y;

int main() {

	cin>>n>>m;
	indegree.assign(n+1, 0);

	while(m--) {
		// x -> y
		cin>>x>>y;
		g[x].insert(y);
		indegree[y]++;
	}

	for(int u=1; u<=n; u++) {
		if(indegree[u] == 0) {
			src.push(u);
		}
	}

	while(src.size()) {
		int u = src.top();
		src.pop();

		order.push(u);
		for(int v: g[u]) {
			indegree[v]--;
			if(indegree[v] == 0) {
				src.push(v);
			}
		}
	}

	if(order.size() != n) {
		cout<<"Sandro fails.";
	} else {
		while(order.size()) {
			cout<<order.front()<<" ";
			order.pop();
		}
	}

	return 0;
}
