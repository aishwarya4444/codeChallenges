/*
https://codeforces.com/problemset/problem/463/B
*/

#include <bits/stdc++.h>
#define si(n) scanf("%d", &n)
#define sll(n) scanf("%lld", &n)
#define ll long long
using namespace std;

int main() {
	int n, height, res=0;

	si(n);
	while(n--) {
		si(height);
		res = max(res, height);
	}

	cout<<res;

	return 0;
}
