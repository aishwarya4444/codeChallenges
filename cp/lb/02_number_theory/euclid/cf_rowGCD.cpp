/*
https://codeforces.com/problemset/problem/1459/C

From basic properties of GCD we know that 𝐺𝐶𝐷(𝑥,𝑦)=𝐺𝐶𝐷(𝑥−𝑦,𝑦).
The same applies for multiple arguments: 𝐺𝐶𝐷(𝑥,𝑦,𝑧,…)=𝐺𝐶𝐷(𝑥−𝑦,𝑦,𝑧,…).
Let's use this for 𝐺𝐶𝐷(𝑎1+𝑏𝑗,…,𝑎𝑛+𝑏𝑗) and subtract 𝑎1+𝑏𝑗 from all other arguments:
    𝐺𝐶𝐷(𝑎1+𝑏𝑗,…,𝑎𝑛+𝑏𝑗)=𝐺𝐶𝐷(𝑎1+𝑏𝑗,𝑎2−𝑎1,…,𝑎𝑛−𝑎1).

If we find 𝐺=𝐺𝐶𝐷(𝑎2−𝑎1,…,𝑎𝑛−𝑎1), then any answer can be found as 𝐺𝐶𝐷(𝑎1+𝑏𝑗,𝐺).
Note that we have to assume that GCD of an empty set is 0.
And 𝐺𝐶𝐷(𝑥,0)=𝑥 for any 𝑥, since 0 is the only number divisible by any other number.

*/

#include <bits/stdc++.h>
#define si(n) scanf("%d", &n)
#define sll(n) scanf("%lld", &n)
#define ll long long
using namespace std;

int main() {
	int i, j, n, m;
	ll G=0, a1, num;

	si(n);
	si(m);

	sll(a1);

	// gcd(a1+bj, a2+bj, a3+bj, a4+bj, ... ai+bj   ... an+bj) ; j belongs to [1,m]
	// gcd(a1+bj, a2-a1, a3-a1, a4-a1, ... ai+bj   ... an-a1) ; j belongs to [1,m]
	// gcd(a1+bj, G) ; j belongs to [1,m]

	for(i=2; i<=n; i++) {
		sll(num);
		G = __gcd(G, abs(num-a1));
	}

	for(j=1; j<=m; j++) {
		sll(num);
		cout<<__gcd(num+a1, G)<<' ';
	}

	return 0;
}
