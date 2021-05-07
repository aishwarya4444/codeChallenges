/*
https://www.spoj.com/problems/BREAK/

similar to BOTTOM -> there we find sink
here we find sources that can cause max damage


https://github.com/krnbatra/SPOJ-Solutions/blob/master/BREAK.cpp

*/
#include <bits/stdc++.h>

using namespace std;

unordered_map<int, vector<int> > gr;
unordered_map<int, vector<int> > rg;
vector<int> connected;
vector<int> rep;
vector<int> indegree;
vector<bool> visited;
stack<int> st;

void dfs1(int a) {
	visited[a] = true;

	for(int b: gr[a]) {
		if(visited[b] == false) {
			dfs1(b);
		}
	}

	st.push(a);
}

void dfs2(int a, int r) {
	visited[a] = true;
	rep[a] = r;

	for(int b: rg[a]) {
		if(visited[b] == false) {
			dfs2(b, r);
		}
	}
}

void dfs3(int u, int &nodes) {
	visited[u] = true;
	nodes++;

	for(int v: gr[u]) {
		if(visited[v]==false) {
			dfs3(v, nodes);
		}
	}
}

int main() {

	int T, N, M, label;
	int a, b;

	// cin>>T;
	scanf("%d", &T);
	while(T--) {
		scanf("%d%d", &N, &M);
		// cin>>N>>M;

		gr.clear();
		rg.clear();
		// "a" trusts "b"
		// edge looks like
		// b -> a
		while(M--) {
			scanf("%d%d", &a, &b);
			// cin >> a >> b;
			gr[b].push_back(a);
			rg[a].push_back(b);
		}

		// dfs for original graph
		visited.assign(N+1, false);
		for(a=1; a<=N; a++) {
			if(visited[a]==false) {
				dfs1(a);
			}
		}

		// dfs for reverse graph
		visited.assign(N+1, false);
		rep.assign(N+1, 0);
		label = 0;
		while(st.size()) {
			a = st.top();
			st.pop();
			if(visited[a]==false) {
				dfs2(a, label);
				label++;
			}
		}

		// DAG of SCC is formed
		// find indegree
		indegree.assign(label, 0);
		for(int u=1; u<=N; u++) {
			for(int v: gr[u]) {
				if(rep[u] != rep[v]) {
					indegree[rep[v]]++;
				}
			}
		}

		// for 0 indegree find max nodes that can be visited
		int maxNodes = 0;
		connected.assign(label, 0);
		for(int u=1; u<=N; u++) {
			if(indegree[rep[u]] == 0 && connected[rep[u]] == 0) {
				int nodes = 0;
				visited.assign(N+1, false);
				dfs3(u, nodes);
				connected[rep[u]] = nodes;
				maxNodes = max(nodes, maxNodes);
			}
		}

		for(int u=1; u<=N; u++) {
			if(connected[rep[u]] == maxNodes) {
				printf("%d ", u);
			}
		}

		printf("\n");

	}

	return 0;
}


/*
Sample Input
3

5 4
3 1
3 2
4 3
5 3

6 5
1 2
2 3
3 1
1 4
5 6

6 6
1 2
3 2
3 4
2 4
2 5
5 6
*/

/*
Sample Output
1 2
4
6
*/