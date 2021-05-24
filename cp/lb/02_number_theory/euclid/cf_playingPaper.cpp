/*
https://codeforces.com/contest/527/problem/A
https://codeforces.com/blog/entry/17020
*/

#include <bits/stdc++.h>
#define si(n) scanf("%d", &n)
#define sll(n) scanf("%lld", &n)
#define ll long long
using namespace std;

int main() {
	ll a, b, res=0;

	sll(a);
	sll(b);

	while(b) {
		res += a/b;
		a %= b;
		swap(a, b);
	}

	cout<<res;

	return 0;
}
