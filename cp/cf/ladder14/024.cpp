/*
https://codeforces.com/problemset/problem/166/A
*/

#include <bits/stdc++.h>
#define si(n) scanf("%d", &n)
#define sll(n) scanf("%lld", &n)
#define ll long long
using namespace std;

struct cmp {
	bool operator()(const pair<int, int> &r1, const pair<int, int> &r2) {
		if(r1.first == r2.first) {
			return r1.second<r2.second;
		}
		return r1.first>r2.first;
	}
};

int main() {
	int n, k, p, t;
	int lo, hi;
	vector<pair<int, int> > res;

	si(n);
	si(k);

	while(n--) {
		si(p);
		si(t);
		res.push_back({p, t});
	}

	sort(res.begin(), res.end(), cmp());

	// cout<<count(res.begin(), res.end(), res[k-1]);
	lo = lower_bound(res.begin(), res.end(), res[k-1], cmp())-res.begin();
	hi = upper_bound(res.begin(), res.end(), res[k-1], cmp())-res.begin();
	cout<<(hi-lo);

	return 0;
}
