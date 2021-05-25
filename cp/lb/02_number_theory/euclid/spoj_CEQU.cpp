/*
https://www.spoj.com/problems/CEQU/

https://cp-algorithms.com/algebra/linear-diophantine-equation.html
https://cp-algorithms.com/algebra/extended-euclid-algorithm.html
*/

#include <bits/stdc++.h>
#define si(n) scanf("%d", &n)
#define sll(n) scanf("%lld", &n)
#define ll long long
using namespace std;

int main() {
	int t, T;
	ll a, b, c, g;

	si(T);
	for(t=1; t<=T; t++) {
		sll(a);
		sll(b);
		sll(c);

		g = __gcd(a, b);

		cout<<"Case "<<t<<": ";
		if(c%g) {
			cout<<"No\n";
		} else {
			cout<<"Yes\n";
		}
	}

	return 0;
}
