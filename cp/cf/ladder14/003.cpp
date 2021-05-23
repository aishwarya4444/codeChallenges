/*
https://codeforces.com/problemset/problem/112/A
*/

#include <bits/stdc++.h>
#define si(n) scanf("%d", &n)
#define sll(n) scanf("%lld", &n)
#define ll long long
using namespace std;

int main() {
	string s1, s2;
	int n, N;
	char c1, c2;

	cin>>s1>>s2;

	N = s1.size();
	for(n=0; n<N; n++) {
		c1 = s1[n];
		c2 = s2[n];

		if(c1>='a') c1-=32;
		if(c2>='a') c2-=32;

		if(c1>c2) {
			cout<<1;
			return 0;
		} else if(c1<c2) {
			cout<<-1;
			return 0;
		}
	}

	cout<<0;

	return 0;
}
