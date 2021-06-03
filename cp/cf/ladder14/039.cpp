/*
https://codeforces.com/problemset/problem/416/C
https://codeforces.com/contest/416/submission/6617198

Let's solve this one greedy.
Notice that the optimal solution will be to place first the
groups with biggest sum which they are ready to pay.
For each such group it will be optimal to
allocate the smallest matching table.
The input limits allow to do a full search when looking for a table.
*/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct Group {
	int c, p, i;

	Group(int _c, int _p, int _i) {
		c = _c;
		p = _p;
		i = _i;
	}
};

struct Table {
	int r, i;

	Table(int _r, int _i) {
		r = _r;
		i = _i;
	}
};

bool priceDescending(const Group &g1, const Group &g2) {
	return g1.p>g2.p;
}

bool tableSizeAscending(const Table &t1, const Table &t2) {
	return t1.r<t2.r;
}

bool match(const Table &t, const Group &g) {
	return t.r < g.c;
}

int main() {
	int n, k, profit=0;
	int c, p, r;

	vector<Group> groups;
	vector<Table> tables;
	vector<pair<int, int> > res;

	cin>>n;
	for(int i=1; i<=n; i++) {
		cin>>c>>p;
		groups.push_back({c, p, i});
	}
	sort(groups.begin(), groups.end(), priceDescending);

	cin>>k;
	for(int i=1; i<=k; i++) {
		cin>>r;
		tables.push_back({r, i});
	}
	sort(tables.begin(), tables.end(), tableSizeAscending);

	for(auto gr: groups) {
		auto tableToGive = lower_bound(tables.begin(), tables.end(), gr, match);
		if(tableToGive == tables.end()) continue;
		profit += gr.p;
		res.push_back({gr.i, (*tableToGive).i});
		tables.erase(tableToGive);
	}

	cout<<res.size()<<' '<<profit<<'\n';
	for(auto ans: res) {
		cout<<ans.first<<' '<<ans.second<<'\n';
	}

	return 0;

}
