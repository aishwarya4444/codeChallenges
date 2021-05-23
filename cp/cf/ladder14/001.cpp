/*
https://codeforces.com/problemset/problem/136/A
*/

#include <bits/stdc++.h>
#define si(n) scanf("%d", &n)
#define sll(n) scanf("%lld", &n)
#define ll long long
using namespace std;

int main() {
	int i, n, num;
	vector<pair<int, int> > res;

	si(n);

	for(i=1; i<=n; i++) {
		si(num);
		res.push_back({num, i});
	}

	sort(res.begin(), res.end());

	for(auto entry: res) {
		printf("%d ", entry.second);
	}

	return 0;
}
