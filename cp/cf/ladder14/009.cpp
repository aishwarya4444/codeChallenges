/*
https://codeforces.com/problemset/problem/285/A
*/

#include <bits/stdc++.h>
#define si(n) scanf("%d", &n)
#define sll(n) scanf("%lld", &n)
#define ll long long
using namespace std;

int main() {
	int n, k;

	si(n);
	si(k);

	for(int i=1; i<=k; i++) {
		cout<<n<<' ';
		n--;
	}

	for(int i=1; i<=n; i++) {
		cout<<i<<' ';
	}

	return 0;
}
