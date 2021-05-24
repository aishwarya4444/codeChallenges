/*
https://codeforces.com/problemset/problem/501/A
*/

#include <bits/stdc++.h>
#define si(n) scanf("%d", &n)
#define sll(n) scanf("%lld", &n)
#define ll long long
using namespace std;

int score(int p, int t) {
	return max(3*p/10, p-(p*t)/250);
}

int main() {

	int a, b, c, d, s1, s2;

	si(a);
	si(b);
	si(c);
	si(d);

	s1 = score(a, c);
	s2 = score(b, d);

	if(s1==s2) {
		cout<<"Tie";
	} else if(s1>s2) {
		cout<<"Misha";
	} else {
		cout<<"Vasya";
	}

	return 0;
}
