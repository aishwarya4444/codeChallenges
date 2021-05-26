/*
https://codeforces.com/problemset/problem/1472/A
https://codeforces.com/blog/entry/86406
idea is to find out maximum power of 2 that is present in w and h
*/

#include <bits/stdc++.h>
#define si(n) scanf("%d", &n)
#define sll(n) scanf("%lld", &n)
#define ll long long
using namespace std;

int main() {
	int t, w, h, n;

	si(t);

	while(t--) {
		cin>>w>>h>>n;

		int w2 = __gcd(1<<20, w);
		int h2 = __gcd(1<<20, h);

		if(w2*h2 >= n) {
			cout<<"YES\n";
		} else {
			cout<<"NO\n";
		}
	}

	return 0;
}
