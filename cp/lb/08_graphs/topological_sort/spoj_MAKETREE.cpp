/*
https://www.spoj.com/problems/MAKETREE/
*/

#include <bits/stdc++.h>

using namespace std;

unordered_map<int, vector<int> > g;
vector<int> indegree;
vector<int> result;
queue<int> src;
int N, K, W;

int main() {

	int u, v, boss0, boss1;
	cin>>N>>K;

	result.assign(N+1, 0);
	indegree.assign(N+1, 0);

	for(u=1; u<=K; u++) {
		cin>>W;
		while(W--) {
			cin>>v;
			g[u].push_back(v);
			indegree[v]++;
		}
	}

	for(u=1; u<=N; u++) {
		if(indegree[u] == 0) {
			src.push(u);
		}
	}

	boss0 = 0;
	while(src.size()) {
		int boss1 = src.front();
		src.pop();

		result[boss1] = boss0;

		for(int v: g[boss1]) {
			indegree[v]--;
			if(indegree[v] == 0) {
				src.push(v);
			}
		}

		boss0 = boss1;
	}

	for(u=1; u<=N; u++) {
		cout<<result[u]<<'\n';
	}


	return 0;
}
