/*
https://codeforces.com/problemset/problem/339/B
*/

#include <bits/stdc++.h>
#define si(n) scanf("%d", &n)
#define sll(n) scanf("%lld", &n)
#define ll long long
using namespace std;

int main() {
	int n, m;
	int val, maxVal=0;
	ll res = 0;

	si(n);
	si(m);

	for(int i=0; i<m; i++) {
		si(val);
		maxVal = max(maxVal, val);
		if(val < maxVal) {
			maxVal = val;
			res += n;
		}
	}

	res += val-1;
	cout<<res;

	return 0;
}
