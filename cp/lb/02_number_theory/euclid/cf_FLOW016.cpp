/*
https://www.codechef.com/problems/FLOW016
*/

#include <bits/stdc++.h>
#define si(n) scanf("%d", &n)
#define sll(n) scanf("%lld", &n)
#define ll long long
using namespace std;

int gcd(int a, int b) {
	if(a<b) {
		swap(a, b);
	}
	while(b) {
		a %= b;
		swap(a, b);
	}
	return a;
}

long lcm(int a, int b) {
	return (a/__gcd(a, b))*(long)b; // __gcd used from stl numeric
}

int main() {
	int T, A, B;

	si(T);
	while(T--) {
		si(A);
		si(B);
		cout<<gcd(A,B)<<' '<<lcm(A,B)<<'\n';
	}


	return 0;
}
