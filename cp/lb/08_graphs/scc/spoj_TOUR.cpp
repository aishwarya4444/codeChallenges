/*
https://www.spoj.com/problems/TOUR/

objective is to find sources
https://github.com/vitsalis/SPOJ/blob/master/TOUR/tour.cpp

*/

#include <bits/stdc++.h>

using namespace std;

unordered_map<int, vector<int> > gr;
unordered_map<int, vector<int> > rg;
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

int main() {

	int T, N, M;
	int a, b, label;

	scanf("%d", &T);
	while(T--) {
		scanf("%d", &N);

		gr.clear();
		rg.clear();
		for(a=1; a<=N; a++) {
			scanf("%d", &M);
			while(M--) {
				scanf("%d", &b);
				gr[b].push_back(a);
				rg[a].push_back(b);
			}
		}

		visited.assign(N+1, false);
		for(a=1; a<=N; a++) {
			if(visited[a]==false) {
				dfs1(a);
			}
		}

		visited.assign(N+1, false);
		rep.assign(N+1, 0);
		label = 1;
		while(st.size()) {
			a = st.top();
			st.pop();
			if(visited[a]==false) {
				dfs2(a, label);
				label++;
			}
		}

		indegree.assign(N+1, 0);
		for(int u=1; u<=N; u++) {
			for(int v: gr[u]) {
				if(rep[u]!=rep[v]) {
					indegree[rep[v]]++;
				}
			}
		}

		int count = 0;
		for(int l=1; l<label; l++) {
			if(indegree[l]==0) {
				count++;
			}
		}

		if(count>1) {
			printf("0\n");
		} else {
			count = 0;
			for(int u=1; u<=N; u++) {
				if(indegree[rep[u]]==0) {
					count++;
				}
			}
			printf("%d\n", count);
		}

	}

	return 0;
}
