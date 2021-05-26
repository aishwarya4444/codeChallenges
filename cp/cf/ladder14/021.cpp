/*
https://codeforces.com/problemset/problem/437/C



The best way to delete all n nodes is deleting them in decreasing order of their value.

Proof:
Consider each edge (x,y), it will contribute to the total cost vx or vy when it is deleted.
If we delete the vertices in decreasing order, then it will contribute only min(vx,vy), so the total costs is the lowest.



https://codeforces.com/contest/437/submission/57579972
#include<iostream>
using namespace std;
int a[1010],ans,n,m,x,y;
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=m;i++)
	{
		cin>>x>>y;
		ans+=min(a[x],a[y]);
	}
	cout<<ans<<endl;
	return 0;
}
*/

#include <bits/stdc++.h>
#define si(n) scanf("%d", &n)
#define sll(n) scanf("%lld", &n)
#define ll long long
using namespace std;

struct cmp
{
	bool operator()(const pair<int, int> &p1, const pair<int, int> &p2) {
		return p1.second<p2.second;
	}

};

int main() {
	int n, m, v, x, y, total=0;
	unordered_map<int, vector<int> > g;
	unordered_map<int, int> cost;
	vector<bool> visited;
	priority_queue<pair<int, int>, vector<pair<int, int> >, cmp > pq;

	si(n);
	si(m);

	visited.assign(n+1, false);

	for(int i=1; i<=n; i++) {
		si(v);
		cost[i] = v;
		pq.push({i, v});
	}

	while(m--) {
		si(x);
		si(y);
		g[x].push_back(y);
		g[y].push_back(x);
	}

	while(pq.size()) {
		auto node = pq.top();
		pq.pop();

		int parent = node.first;
		visited[parent] = true;
		for(int child: g[parent]) {
			if(visited[child]) continue;
			total += cost[child];
		}
	}

	cout<<total;

	return 0;
}
