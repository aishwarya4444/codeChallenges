/*
https://codeforces.com/problemset/problem/217/A
*/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector<bool> visited;
vector<pair<int, int> > points;

void dfs(int u) {
	visited[u] = true;

	for(int v=0; v<points.size(); v++) {
		if(visited[v]==false &&
			(points[u].first==points[v].first || points[u].second==points[v].second)) {
			dfs(v);
		}
	}
}

int main() {
	int n, x, y, ans=0;

	cin>>n;

	visited.assign(n, false);

	for(int i=0; i<n; i++) {
		cin>>x>>y;
		points.push_back({x, y});
	}

	for(int i=0; i<n; i++) {
		if(visited[i] == false) {
			ans++;
			dfs(i);
		}
	}

	cout<<ans-1;

	return 0;

}