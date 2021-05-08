/*
https://www.spoj.com/problems/RPLA/
*/

#include <bits/stdc++.h>

using namespace std;

unordered_map<int, vector<int> > g;
unordered_map<int, set<int> > result;
vector<int> indegree;
queue<int> src;
int T, N, R, R1, R2, ranks;

int main() {

	cin>>T;

	for(int t=1; t<=T; t++) {
		cin>>N>>R;

		ranks = 0;
		g.clear();
		result.clear();
		indegree.assign(N, 0);

		while(R--) {
			// R2 -> R1
			cin>>R1>>R2;
			g[R2].push_back(R1);
			indegree[R1]++;
		}

		for(int u=0; u<N; u++) {
			if(indegree[u] == 0) {
				src.push(u);
			}
		}

		while(src.size()) {
			int N = src.size();
			ranks++;

			while(N--) {
				int u = src.front();
				src.pop();

				result[ranks].insert(u);
				for(int v: g[u]) {
					indegree[v]--;
					if(indegree[v] == 0) {
						src.push(v);
					}
				}
			}
		}

		cout<<"Scenario #"<<t<<":\n";
		for(int r=1; r<=ranks; r++) {
			for(int man: result[r]) {
				cout<<r<<' '<<man<<'\n';
			}
		}
	}


	return 0;
}
