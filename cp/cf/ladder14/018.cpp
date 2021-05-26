/*
https://codeforces.com/problemset/problem/337/A
*/

#include <bits/stdc++.h>
#define si(n) scanf("%d", &n)
#define sll(n) scanf("%lld", &n)
#define ll long long
using namespace std;


int main() {
	int n, m, diff;
	vector<int> f;

	si(n);
	si(m);

	f.assign(m, 0);

	for(int &fi: f) {
		si(fi);
	}

	sort(f.begin(), f.end());

	diff = f[n-1]-f[0];
	for(int i=0; i+n-1<m; i++) {
		diff = min(diff, f[i+n-1]-f[i]);
	}

	cout<<diff;

	return 0;
}
