/*
https://codeforces.com/problemset/problem/664/A

We examine two cases:

a=b — the segment consists of a single number, hence the answer is a.
a<b — we have gcd(a,a+1,a+2,...,b)=gcd(gcd(a,a+1),a+2,...,b)=gcd(1,a+2,...,b)=1.
*/

#include <bits/stdc++.h>
#define si(n) scanf("%d", &n)
#define sll(n) scanf("%lld", &n)
#define ll long long
using namespace std;

int main() {
	string a, b;

	cin>>a>>b;

	if(a==b) {
		cout<<a;
	} else {
		cout<<1;
	}

	return 0;
}
