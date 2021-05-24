/*
https://codeforces.com/problemset/problem/270/A
*/

#include <bits/stdc++.h>
#define si(n) scanf("%d", &n)
#define sll(n) scanf("%lld", &n)
#define ll long long
using namespace std;

int main() {

	// (n-2)180 = a*n
	// n(180-a) = 360
	// n = 360/(180-a)

	int t, a;

	si(t);

	while(t--) {
		si(a);
		if(360%(180-a)) {
			cout<<"NO\n";
		} else {
			cout<<"YES\n";
		}
	}

	return 0;
}
