/*
https://codeforces.com/problemset/problem/32/B
*/

#include <bits/stdc++.h>
#define si(n) scanf("%d", &n)
#define sll(n) scanf("%lld", &n)
#define ll long long
using namespace std;

int main() {
	int n=0;
	string s;

	cin>>s;

	while(n<s.size()) {
		if(s[n]=='.') {
			cout<<0;
			n++;
		} else {
			if(s[n+1]=='.') {
				cout<<1;
			} else {
				cout<<2;
			}
			n+=2;
		}
	}

	return 0;
}
