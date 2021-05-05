/*
https://www.spoj.com/problems/CAPCITY/

kosaraju
find all SCC having size > 1
*/

#include <bits/stdc++.h>

using namespace std;

unordered_map<int, vector<int> > gr;
unordered_map<int, vector<int> > rg;
map<int, vector<int> > res;
vector<int> rep;
vector<int> city;
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
	cin >> N >> M;

	rep = vector<int>(N+1, 0);
	while(M--) {
		cin >> a >> b;
		gr[a].push_back(b);
		rg[b].push_back(a);
	}

	visited = vector<bool>(N+1, false);
	for(a=1; a<=N; a++) {
		if(visited[a]==false) {
			dfs1(a);
		}
	}

	visited = vector<bool>(N+1, false);
	while(st.size()) {
		a = st.top();
		st.pop();
		if(visited[a]==false) {
			dfs2(a, a);
		}
	}

	for(a=1; a<=N; a++) {
		res[rep[a]].push_back(a);
	}

	for(auto entry: res) {
		if(entry.second.size() > 1) {
			city.insert(city.end(), entry.second.begin(), entry.second.end());
		}
	}

	cout<<city.size()<<endl;
	sort(city.begin(), city.end());
	for(int c: city) {
		cout<<c<<" ";
	}

	return 0;
}
