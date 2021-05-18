/*
https://codeforces.com/problemset/problem/69/A
*/

#include <bits/stdc++.h>
#define si(n) scanf("%d", &n)
#define sll(n) scanf("%lld", &n)
#define ll long long
using namespace std;

int main() {
	int n;
	int x, y, z;
	int X=0, Y=0, Z=0;

	si(n);
	while(n--) {
		cin>>x>>y>>z;
		X += x;
		Y += y;
		Z += z;
	}

	if(X|Y|Z) {
		cout<<"NO";
	} else {
		cout<<"YES";
	}
	return 0;
}
