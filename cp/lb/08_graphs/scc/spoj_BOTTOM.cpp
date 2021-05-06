/*
https://www.spoj.com/problems/BOTTOM/
https://vjudge.net/problem/POJ-2553

kosaraju

A correct algorithm : (Not easily available on the internet)

Theorem :
A strongly connected component (all vertices) is sink(i.e. all vertices are sink) if every vertex in a scc is connected to no other scc than itself's.

Find all strongly connected component(scc)s by Kosaraju or Tarjan's algorithm and store them.
Now, for every vertex in a scc, if you find an adjacent vertex (in the adjacency list) let's call it "v" such that v is not in that scc, then discard the whole scc.
That is, when a vertex of a scc(No.1) is adjacent to a different scc(No.2) then discard scc(No.1), otherwise take all vertices of scc(No.1) to the "result" array or container.
Do this for all scc s.
After that, sort the "result" array and print it.


https://github.com/vitsalis/SPOJ/blob/master/BOTTOM/bottom.cpp
https://github.com/akhiluanandh/SPOJ/blob/master/BOTTOM.cpp

*/

#include <bits/stdc++.h>

using namespace std;

unordered_map<int, vector<int> > gr;
unordered_map<int, vector<int> > rg;
vector<int> rep;
vector<bool> sol;
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

int main() {

	int N, M;
	int a, b;

	while(true) {
		cin>>N;
		if(N==0) {
			break;
		}
		cin>>M;

		gr.clear();
		rg.clear();
		rep.assign(N+1, 0);
		while(M--) {
			cin >> a >> b;
			gr[a].push_back(b);
			rg[b].push_back(a);
		}

		visited.assign(N+1, false);
		for(a=1; a<=N; a++) {
			if(visited[a]==false) {
				dfs1(a);
			}
		}

		visited.assign(N+1, false);
		sol.assign(N+1, false);
		while(st.size()) {
			a = st.top();
			st.pop();
			if(visited[a]==false) {
				dfs2(a, a);
				sol[a] = true;
			}
		}

		for(int u=1; u<=N; u++) {
			for(int v: gr[u]) {
				if(rep[u] != rep[v]) {
					sol[rep[u]] = false;
					break;
				}
			}
		}

		for(int u=1; u<=N; u++) {
			if(sol[rep[u]]) {
				cout<<u<<" ";
			}
		}

		cout<<endl;

	}

	return 0;
}
