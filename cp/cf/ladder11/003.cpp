/*
https://codeforces.com/problemset/problem/266/B
*/

#include <bits/stdc++.h>
#define si(n) scanf("%d", &n)
#define sll(n) scanf("%lld", &n)
#define ll long long
using namespace std;

int main() {
	int i, n, t;
	string s;

	si(n);
	si(t);
	cin>>s;

	while(t--) {
		for(i=0; i<=n-2; i++) {
			if(s[i]=='B' && s[i+1]=='G') {
				swap(s[i], s[i+1]);
				i++;
			}
		}
	}

	cout<<s;

	return 0;
}
